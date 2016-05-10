#include "msgboardmodel.h"
#include <QFont>
#include <QBrush>

namespace msgboard {

    MsgBoardModel::MsgBoardModel(int rows, int columns, QObject *parent)
        : m_rows(rows), m_cols(columns), QAbstractListModel(parent)
    {
        //todo:
    }


    MsgBoardModel::~MsgBoardModel()
    {

    }


    /**
     * @brief singleton
     * @return static instance
     */
    MsgBoardModel&  MsgBoardModel::instance(void)
    {
        static MsgBoardModel pInstance;
        return pInstance;
    }


    int MsgBoardModel::rowCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return m_rows;
    }

    int MsgBoardModel::columnCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return m_cols;
    }


    QVariant MsgBoardModel::data(const QModelIndex &index, int role) const
    {

        int row = index.row();
        int col = index.column();

        switch ( role ) {
        case Qt::DisplayRole:
            if ( row == 0 && col == 1 ) return QString("<--left");
            if ( row == 1 && col == 1 ) return QString("right-->");

            return QString("Row%1, Col%2").arg(row+1).arg(col+1);

        case Qt::FontRole:
            if ( row == 0 && col == 0 ) {
                QFont bold;
                bold.setBold(true);
                return bold;
            }

        case Qt::BackgroundRole:
            if ( row == 4 && col == 1 ) {
                QBrush redBck(Qt::red);
                return redBck;
            }

        case Qt::TextAlignmentRole:
            if ( row == 1 && col == 1 ) {
                return Qt::AlignRight + Qt::AlignVCenter;
            }

        case Qt::CheckStateRole:
            if ( row == 1 && col == 0 ) {
                return Qt::Checked;
            }
        }

        return QVariant();
    }

    /*TODO*/
    bool MsgBoardModel::setData(const QModelIndex &index, const QVariant &value, int role) const
    {
        Q_UNUSED(index);
        Q_UNUSED(value);
        Q_UNUSED(role);

        return false;
    }

}//!msgboard
