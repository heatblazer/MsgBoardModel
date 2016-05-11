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

    //tableView.setWindowFlags(Qt::CustomizeWindowHint);

    MsgBoardModel* myModel = ModelFactory::getMsgBoardModel();

    Msg m0("sdasdasdas", STATIC_MSG, -1);
    Msg m1("sdasdasdas", STATIC_MSG, -1);
    Msg m2("sdasdasdas", STATIC_MSG, -1);
    Msg m3("sdasdasdas", STATIC_MSG, -1);
    Msg m4("last message", STATIC_MSG, -1);

    myModel->setMyMsg(m0);
    myModel->setMyMsg(m1);
    myModel->setMyMsg(m2);
    myModel->setMyMsg(m3);
    myModel->setMyMsg(m4);



    MsgBoardView* myView = new MsgBoardView();


    myView->setMsgModel((QAbstractItemModel*)myModel);
    myView->showMsgModel();

   // delete myView;

    // qtcreator to step with the debuger . . .  nothing
    int asasa = 100000;

    return a.exec();
}
