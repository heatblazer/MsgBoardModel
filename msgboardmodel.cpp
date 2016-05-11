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

            if ( !m_messages.empty() ) {
                return m_messages.at(this->index(row, col).column())->m_msg;
            }

            break;

        case Qt::FontRole:
            if ( m_messages.at(row)->m_type == USER_ACTIVITY_MSG){
                QFont bold;
                bold.setBold(true);
                return bold;
            }
            break;

        case Qt::BackgroundRole:
            if ( m_messages.at(row)->m_type == USER_ACTIVITY_MSG ) {
                QBrush redBck(Qt::red);
                return redBck;
            } else if ( m_messages.at(row)->m_type == TIMER_ACTIVITY_MSG ) {
                QBrush grnBck(Qt::green);
                return grnBck;
            } else {

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


    void MsgBoardModel::setUserMsg(const QString &msg)
    {
        static int i = 0;

        Msg* m = new Msg(msg, USER_ACTIVITY_MSG, -1);
        m_messages.append(m);

    }

    void MsgBoardModel::setTimerMsg(const QString &msg, int timeout)
    {
        Msg* m = new Msg(msg, TIMER_ACTIVITY_MSG, timeout);
        m_messages.append(m);
    }

    void MsgBoardModel::setStaticMsg(const QString &msg)
    {
        Msg* m = new Msg(msg, TIMER_ACTIVITY_MSG, -1);
        m_messages.append(m);
    }


    void MsgBoardModel::removeMyMsg(const QString &msg)
    {
        // TODO
    }


}
