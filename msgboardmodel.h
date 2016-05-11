#pragma once
#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>   // inherite
#include <QTimer>               // member

namespace msgboard {
class Msg;

class MsgBoardModel : public QAbstractListModel
{
    Q_OBJECT
    // when tested factory I`ll protect the construction of the classes
public:
    enum MsgBoardRoles {
        ROLE_USER_ACTIVITY = Qt::UserRole + 1
    };

    // user api
    void addUserMsg(const QString& msg);
    void addTimerMsg(const QString& msg, int timeout);
    void addStaticMsg(const QString& msg);
    void removeMsg(const QString& msg);

    // view api
    virtual int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);

    // singletion
    static MsgBoardModel* instance(void);

private:
    explicit MsgBoardModel(QObject* parent = nullptr);
    virtual ~MsgBoardModel();

private slots:
    void hMsgHideTick();

private:
    static MsgBoardModel* sInstance;

    // list of custom messages added
    QList<Msg*> m_messages;
    QTimer      m_msgHidingTick;
};

}   // namespace msgboard


#endif // MODEL_H

