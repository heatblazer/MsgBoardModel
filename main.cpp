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

    QListView tableView;

//the messages to display
    Msg m1("some msg", TIMER_ACTIVITY_MSG, 10);
    Msg m2("some msg", USER_ACTIVITY_MSG, -1);
    Msg m3("some msg", STATIC_MSG, -1);

// deprecated
    UserApiInterface* uapi = new UserMessage;
    UserApiInterface* tapi = new TimerMessage;
    UserApiInterface* sapi = new StaticMessage;

    uapi->addMessage("user message");
    tapi->addMessage("timer message");
    sapi->addMessage("static message");

    //tableView.setWindowFlags(Qt::CustomizeWindowHint);


    MsgBoardModel* myModel = ModelFactory::getMsgBoardModel();

    MsgBoardView* myView = new MsgBoardView();

    myView->setMsgModel((QAbstractItemModel*)myModel);
    myView->showModel();

    return a.exec();
}
