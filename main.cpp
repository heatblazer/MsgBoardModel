#include <QTableView>
#include <QApplication>
#include "msgboardmodel.h"
#include "modelfactory.h"
#include "usrapiimpl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableView tableView;

    UserApiInterface* uapi = new UserMessage;

    uapi->addMessage("alabala");


    ///remove decoration
    //tableView.setWindowFlags(Qt::CustomizeWindowHint);

    QAbstractItemModel* myModel = (QAbstractListModel*) ModelFactory::getMsgBoardModelView(10, 2);

    tableView.setModel(myModel);

    tableView.show();

    return a.exec();
}
