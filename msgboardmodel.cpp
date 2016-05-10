#include "msgboardmodel.h"



MsgBoardModelView::MsgBoardModelView(int rows, int columns, QObject *parent)
    :m_rows(rows), m_cols(columns), QAbstractListModel(parent)
{

}


MsgBoardModelView::~MsgBoardModelView()
{

}


//singleton
MsgBoardModelView*  MsgBoardModelView::getInsance(void)
{
    static MsgBoardModelView pInstance;
    return &pInstance;
}


int MsgBoardModelView::rowCount(const QModelIndex &parent) const
{
    return m_rows;
}

int MsgBoardModelView::columnCount(const QModelIndex &parent) const
{
    return m_cols;
}


QVariant MsgBoardModelView::data(const QModelIndex &index, int role) const
{
    if ( role == Qt::DisplayRole ) {
        return QString("Row%1, Column%2")
                .arg(index.row()+1)
                .arg(index.column()+1);
    }

    return QVariant();
}


