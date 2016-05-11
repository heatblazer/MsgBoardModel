#pragma once
#ifndef MSGBOARDVEIW_H
#define MSGBOARDVEIW_H

#include <QAbstractItemView>
#include <QListView>
#include <QList>
#include "msgboardmodel.h"


namespace msgboard {

    class Msg;

    class MsgBoardView : QListView
    {

    public:
        MsgBoardView(QWidget *parent = 0);
        virtual ~MsgBoardView();

        /**
         * @brief setMsgModel: it will call the paren`ts setModel(...); however you can override it
         * @param QAbstractItemModel
         */
        virtual void setMsgModel(QAbstractItemModel* model);

        /**
         * @brief it will call the parent`s show(...) but it can be overriden if needed
         */
        virtual void showMsgModel(void);

    protected:

    private:
        MsgBoardModel* m_model;


        friend class MsgBoardModel;
    };

}
#endif // MSGBOARDVEIW_H
