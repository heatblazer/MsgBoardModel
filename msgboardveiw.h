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


    protected:

    private:
        QList<Msg*> m_messages;
        MsgBoardModel* m_model;

    };

}
#endif // MSGBOARDVEIW_H
