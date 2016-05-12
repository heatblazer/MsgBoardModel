#include "msgboardmodel.h"

// Qt headers //
#include <QBrush>
#include <QFont>
#include <QLabel>
#include <QModelIndex>
#include <QVariant>\

// Local headers //
#include "types.h"

namespace msgboard {

MsgBoardModel*  MsgBoardModel::sInstance = nullptr;


MsgBoardModel::MsgBoardModel(QObject *parent) :
    QAbstractListModel(parent)
{
    connect(&m_msgHidingTick, SIGNAL(timeout()), this, SLOT(hMsgHideTick()));
    m_msgHidingTick.start(200); // 200ms check
}


MsgBoardModel::~MsgBoardModel()
{
}


// deincrement the time of all time-messages
// remove all timeouted messages
void MsgBoardModel::hMsgHideTick()
{
    // fixed buf - last element is at -1 from the max size //
    for(int i = m_messages.count()-1; i >= 0; --i) {
        Msg * m = m_messages.at(i);
        if ( (m->m_type == TIMER_ACTIVITY_MSG) && (m->m_timer > 0) ) {
            m->m_timer -= 200;

            if (m->m_timer <= 0) {
                beginRemoveRows(QModelIndex(), i, i);
                m_messages.removeAt(i);
                endRemoveRows();
            }
        }
    }

}


/**
 * @brief singleton ( NOT  THREAD SAFE!!! )
 * @return static instance
 */
MsgBoardModel*  MsgBoardModel::instance(void)
{
    if (sInstance == nullptr) {
        sInstance = new MsgBoardModel;
    }

    return sInstance;
}


/**
 * @brief UNUSED (do not delete for now )
 * @param parent
 * @return
 */
int MsgBoardModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_messages.count();
}


/**
 * @brief UNUSED ( do not delete for now )
 * @param parent
 * @return
 */
int MsgBoardModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    // we are list
    return 1;
}


///
/// @brief overriden function, set the data and display by role
/// @param the index
/// @param the role
/// @return QVariant
///
QVariant MsgBoardModel::data(const QModelIndex &index, int role) const
{
    QVariant res;

    if (!index.isValid()) {
        return res; // no data for root
    }

    const int row = index.row();

    switch (role) {
    case Qt::DisplayRole:

        res = m_messages.at(row)->m_msg;
        break;

    case Qt::FontRole:
        if ( m_messages.at(row)->m_type == USER_ACTIVITY_MSG) {
            QFont bold;
            bold.setBold(true);
            res = bold;
        } else if ( m_messages.at(row)->m_type == TIMER_ACTIVITY_MSG ) {
            QFont bold;
            bold.setItalic(true);
            res = bold;

        } else {

        }
        break;

    case Qt::ForegroundRole:
        if ( m_messages.at(row)->m_type == STATIC_ACTIVITY_MSG ) {
            QBrush redBck(Qt::yellow);
            res = redBck;

        } else if ( m_messages.at(row)->m_type == TIMER_ACTIVITY_MSG ) {
            QBrush grnBck(Qt::green);
            res = grnBck;

        } else {
            QBrush bluBck(Qt::red);
            res = bluBck;
        }
        break;

    default :
        break;

    }

    return res;
}


bool MsgBoardModel::setData(const QModelIndex& index, const QVariant& value,
                            int role)
{
    Q_UNUSED(value);

    if (!index.isValid()) {
        return false;   // can't set root data
    }

    if (role == ROLE_USER_ACTIVITY) {
        // remove the message
        const int row = index.row();
        if (m_messages.at(row)->m_type == USER_ACTIVITY_MSG) {
            beginRemoveRows(QModelIndex(), row, row);
            m_messages.removeAt(row);
            endRemoveRows();
        }
        return true;
    }

    return false;
}


//
// user api part
//


void MsgBoardModel::addUserMsg(const QString& msg)
{
    const int size = m_messages.count();

    Msg* m = new Msg(msg, USER_ACTIVITY_MSG, -1);

    beginInsertRows(QModelIndex(), size, size);
    m_messages.append(m);
    endInsertRows();
}


void MsgBoardModel::addTimerMsg(const QString& msg, int timeout)
{
    const int size = m_messages.count();

    Msg* m = new Msg(msg, TIMER_ACTIVITY_MSG, timeout);

    beginInsertRows(QModelIndex(), size, size);
    m_messages.append(m);
    endInsertRows();
}

void MsgBoardModel::addStaticMsg(const QString& msg)
{
    const int size = m_messages.count();

    Msg* m = new Msg(msg, TIMER_ACTIVITY_MSG, -1);

    beginInsertRows(QModelIndex(), size, size);
    m_messages.append(m);
    endInsertRows();
}


void MsgBoardModel::removeMsg(const QString& msg)
{
    for (int i = 0; i < m_messages.count(); ++i) {
        if (m_messages.at(i)->m_msg == msg ) {
            // remove it
            beginRemoveRows(QModelIndex(), i, i);
            m_messages.removeAt(i);
            endRemoveRows();
        }
    }
}

}
