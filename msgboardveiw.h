#ifndef MSGBOARDVEIW_H
#define MSGBOARDVEIW_H

#include <QListView>    // inherite


#include "msgboardmodel.h"


namespace msgboard {

class Msg;

class MsgBoardView : QListView
{

public:
    MsgBoardView(QWidget *parent = 0);
    virtual ~MsgBoardView();

    virtual void setMsgModel(QAbstractItemModel* model);
    virtual void showMsgModel(void);

protected:

private:
    MsgBoardModel* m_model;

};

}
#endif // MSGBOARDVEIW_H
