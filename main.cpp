#include <QTableView>
#include <QApplication>
#include "msgboardmodel.h"
#include "modelfactory.h"
#include "usrapiimpl.h"



/* View the crash course here:
 http://doc.qt.io/qt-4.8/modelview.html
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableView tableView;


    UserApiInterface* uapi = new UserMessage;
    UserApiInterface* tapi = new TimerMessage;
    UserApiInterface* sapi = new StaticMessage;

    uapi->addMessage("user message");
    tapi->addMessage("timer message");
    sapi->addMessage("static message");

    ///remove decoration
    tableView.setWindowFlags(Qt::CustomizeWindowHint);


    QAbstractItemModel* myModel = (QAbstractListModel*) ModelFactory::getMsgBoardModelView(10, 2);

    tableView.setModel(myModel);

    tableView.show();

    return a.exec();
}
