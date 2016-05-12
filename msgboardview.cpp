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

// use the parent`s setModel
void MsgBoardView::setMsgModel(QAbstractItemModel* model)
{
    //((QListView*)this)->setModel(model);
    setModel(model);
}

// use the parent`s show
void MsgBoardView::showMsgModel()
{
    //((QListView*)this)->show();
    show();
}

}
