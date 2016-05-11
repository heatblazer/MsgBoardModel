#pragma once
#ifndef MSGBOARDVEIW_H
#define MSGBOARDVEIW_H

#include <QAbstractItemView>
#include <QListView>
#include <QList>

namespace msgboard {

    class MsgBoardModel;
    class Msg;

    class MsgBoardView : QListView
    {

    public:
        MsgBoardView(QWidget *parent = 0);
        virtual ~MsgBoardView();

        virtual void setMsgModel(QAbstractItemModel* model);
        virtual void showModel(void);

    protected:

    private:
        QList<Msg*> m_messages;
        MsgBoardModel* m_model;

    };

}
#endif // MSGBOARDVEIW_H
