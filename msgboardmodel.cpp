#include "msgboardmodel.h"
#include "types.h"

#include <QFont>
#include <QBrush>
#include <QLabel>
#include <QVariant>

namespace msgboard {

    MsgBoardModel*  MsgBoardModel::pInstance = nullptr;


    MsgBoardModel::MsgBoardModel(int rows, int columns, QObject *parent)
        : m_rows(rows), m_cols(columns), QAbstractListModel(parent)
    {

    }


    MsgBoardModel::~MsgBoardModel()
    {

    }


    /**
     * @brief singleton ( NOT  THREAD SAFE!!! )
     * @return static instance
     */
    MsgBoardModel*  MsgBoardModel::instance(void)
    {
        if ( pInstance == 0 ) {
            pInstance = new MsgBoardModel;
        }

        return pInstance;
    }


    /**
     * @brief UNUSED (do not delete for now )
     * @param parent
     * @return
     */
    int MsgBoardModel::rowCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return m_rows;
    }

    /**
     * @brief UNUSED ( do not delete for now )
     * @param parent
     * @return
     */
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
            if ( row == 0 && col == 0 ) {
                return QString("TEST MESSAGE");
            }
            break;

        case Qt::FontRole:
            if ( row == 0 && col == 0 ) {
                QFont bold;
                bold.setBold(true);
                return bold;
            }
            break;

        case Qt::BackgroundRole:
            if ( row == 0 && col == 0 ) {
                QBrush redBck(Qt::red);
                return redBck;
            }
            break;

        case Qt::TextAlignmentRole:
            if ( row == 0 && col == 0 ) {
                return Qt::AlignAbsolute;
            }
            break;

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

}
