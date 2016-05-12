#include "msgboardveiw.h"
#include "types.h"


namespace msgboard
{

MsgBoardView::MsgBoardView(QWidget *parent)
    : QListView(parent)
{

    // this enables emits to a clicked(QMOdelIndex& ind); //
    this->setAttribute(Qt::WA_AcceptTouchEvents, true);

}

MsgBoardView::~MsgBoardView()
{
}

// use the parent`s setModel
void MsgBoardView::setMsgModel(QAbstractItemModel* model)
{
    //((QListView*)this)->setModel(model);
    m_model = (MsgBoardModel*) model;
    setModel(m_model);

    // this will enable the model to recieve info for the row clicked
    m_model->setSelModel(selectionModel());

    // handling from the model
    connect(this, SIGNAL(clicked(QModelIndex)),
            m_model, SLOT(hMsgHideUserActivity()));

}

// use the parent`s show
void MsgBoardView::showMsgModel()
{
    //((QListView*)this)->show();
    show();
}



}
