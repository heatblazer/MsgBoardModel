// Qt headers //
#include <QApplication>
#include <QListView>
#include <QTableView>

// Local headers //
#include "msgboardmodel.h"
#include "msgboardveiw.h"
#include "types.h"
#include "usrapiimpl.h"


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

    myView->setMsgModel((QAbstractItemModel*)myModel);
    \
    myModel->addTimerMsg("128381231283123", 2000);
    myModel->addTimerMsg("128381231283123", 12000);
    myModel->addTimerMsg("128381231283123", 1000);
    myModel->addTimerMsg("128381231283123", 33000);

    myModel->addUserMsg("dfsdfgfgfggghgh");
    myModel->addUserMsg("dfsdfgfgfggghgh");
    myModel->addUserMsg("dfsdfgfgfggghgh");
    myModel->addUserMsg("dfsdfgfgfggghgh");
    myModel->addUserMsg("dfsdfgfgfggghgh");

    myModel->addStaticMsg("------2-2--2-2-2-");

    myView->showMsgModel();


    return a.exec();
}
