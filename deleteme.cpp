#include "deleteme.h"

namespace msgboard {

ModelTest::ModelTest() {}
ModelTest::~ModelTest() {}

void ModelTest::testDeletionByIndex()
{
    // deletes a random element at fixed time interval

    int ind = qrand() % m_ref->rowCount(QModelIndex());
    m_ref->removeMsgById(ind);

}

void ModelTest::startTest1(void)
{
    connect(m_timer, SIGNAL(timeout()), this, SLOT(testDeletionByIndex()));
    m_timer->start();
}

void ModelTest::addModel(MsgBoardModel* m)
{
    m_ref = m;
    m_timer = new QTimer(this);
    m_timer->setInterval(5000);
    m_timer->start();
}


MsgBoardModel& ModelTest::getMsgBoardRef(void)
{
    return *m_ref;
}



}
