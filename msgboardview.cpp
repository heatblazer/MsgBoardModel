#include "msgboardveiw.h"
#include "types.h"

namespace msgboard
{

    MsgBoardView::MsgBoardView(QWidget *parent)
        : QListView(parent)
    {

    }


    MsgBoardView::~MsgBoardView()
    {

    }


    void MsgBoardView::setMsgModel(QAbstractItemModel* model)
    {
        ((QListView*)this)->setModel(model);
    }

    void MsgBoardView::showModel()
    {
        ((QListView*)this)->show();
    }
}
