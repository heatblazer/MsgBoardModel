#include <QTableView>
#include <QListView>
#include <QApplication>
#include "msgboardmodel.h"
#include "modelfactory.h"
#include "usrapiimpl.h"
#include "types.h"
#include "msgboardveiw.h"

using namespace  msgboard;

/* View the crash course here:
 http://doc.qt.io/qt-4.8/modelview.html
*/

// test the classes in main
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MsgBoardModel* myModel = ModelFactory::getMsgBoardModel();


    myModel->setTimerMsg("128381231283123", 2000);

    MsgBoardView* myView = new MsgBoardView();


    myView->setMsgModel((QAbstractItemModel*)myModel);
    myView->showMsgModel();

   // delete myView;

    // qtcreator to step with the debuger . . .  nothing
    int asasa = 100000;

    return a.exec();
}
