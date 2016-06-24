// Qt headers //
#include <QApplication>
#include <QListView>
#include <QTableView>
#include <QTimer>

// Local headers //
#include "msgboardmodel.h"
#include "msgboardveiw.h"
#include "types.h"
#include "usrapiimpl.h"

// to be deleted
#include "deleteme.h"

using namespace  msgboard;


/* View the crash course here:
 http://doc.qt.io/qt-4.8/modelview.html
*/

// test the classes in main
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MsgBoardModel* myModel = MsgBoardModel::instance();
    MsgBoardView*  myView = new MsgBoardView();


    // delete the tests //
    ModelTest* test1 = new ModelTest();
    test1->addModel(myModel);

    myView->setMsgModel((QAbstractItemModel*)myModel);
    \
    myModel->addTimerMsg("first", 5000);
    myModel->addTimerMsg("pre last", 12000);
    myModel->addTimerMsg("before firs", 3000);
    myModel->addTimerMsg("lastest", 18000);

    myModel->addUserMsg("message 1");
    myModel->addUserMsg("message 2");
    myModel->addUserMsg("message 3");
    myModel->addUserMsg("message 4");
    myModel->addUserMsg("message 5");
    myModel->addStaticMsg("------2-2--2-2-2-");

    myView->showMsgModel();

    // delete the tests //
  //  test1->startTest1();

    return a.exec();
}
