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

/***********************************************************************************/


    bool MsgBoardModel::insertRows(int row, const QModelIndex &parent)
    {

        int msgSize = m_messages.count();

        beginInsertRows(parent, row, msgSize+row-1);
        insertRow(row, parent);
        endInsertRows();

        return true;
    }


    bool MsgBoardModel::removeRows(int row, int count, const QModelIndex &parent)
    {



        return false;
    }

    bool MsgBoardModel::insertColumns(int column, int count, const QModelIndex &parent)
    {
        int msgSize = m_messages.count();

        beginInsertColumns(parent, column, msgSize);
        insertColumn(2, parent);
        endInsertColumns();

        return true;
    }

    bool MsgBoardModel::removeColumns(int column, int count, const QModelIndex &parent)
    {
        return true;
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



    /**
     * @brief overriden function, set the data and display by role
     * @param the index
     * @param the role
     * @return QVariant
     */
    QVariant MsgBoardModel::data(const QModelIndex &index, int role) const
    {

        int row = index.row();
        int col = index.column();

        switch ( role ) {
        case Qt::DisplayRole:

             return m_messages.at(row)->m_msg;

        case Qt::FontRole:
            if ( m_messages.at(row)->m_type == USER_ACTIVITY_MSG){
                QFont bold;
                bold.setBold(true);
                return bold;

            } else if ( m_messages.at(row)->m_type == TIMER_ACTIVITY_MSG ) {
                QFont bold;
                bold.setItalic(true);
                return bold;

            } else {

            }
            break;

        case Qt::BackgroundRole:
            if ( m_messages.at(row)->m_type == STATIC_ACTIVITY_MSG ) {
                QBrush redBck(Qt::yellow);
                return redBck;

            } else if ( m_messages.at(row)->m_type == TIMER_ACTIVITY_MSG ) {
                QBrush grnBck(Qt::green);
                return grnBck;

            } else {
                QBrush bluBck(Qt::red);
                return bluBck;

            }
            break;

        case Qt::TextAlignmentRole:

            return Qt::AlignAbsolute;

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

/***********************************************************************************/

    void MsgBoardModel::setUserMsg(const QString &msg)
    {
        static int i = 0;

        Msg* m = new Msg(msg, USER_ACTIVITY_MSG, -1);
        m_messages.append(m);
        insertRows(m->m_type, QModelIndex());

    }

    void MsgBoardModel::setTimerMsg(const QString &msg, int timeout)
    {
        Msg* m = new Msg(msg, TIMER_ACTIVITY_MSG, timeout);
        m_messages.append(m);
        insertRows(m->m_type, QModelIndex());

    }

    void MsgBoardModel::setStaticMsg(const QString &msg)
    {
        Msg* m = new Msg(msg, TIMER_ACTIVITY_MSG, -1);
        m_messages.append(m);
        insertRows(m->m_type, QModelIndex());


    }


    void MsgBoardModel::removeMyMsg(const QString &msg)
    {
        // TODO
    }



/************************************************************************/
    void MsgBoardModel::doWork()
    {
        // do some task here if needed
    }

}
