#include <QTableView>
#include <QApplication>
#include "msgboardmodel.h"
#include "modelfactory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableView tableView;
    MsgBoardModelView* myModel = ModelFactory::getMsgBoardModelView(10, 2);


    tableView.setModel((QAbstractListModel*)myModel);

    tableView.show();

    return a.exec();
}
