#ifndef DELETEME_H
#define DELETEME_H

#include "msgboardmodel.h"

namespace msgboard {
class ModelTest : QObject
{
    Q_OBJECT

public:
    ModelTest();
    ~ModelTest();

    void addModel(MsgBoardModel* m);
    void startTest1(void);
    MsgBoardModel& getMsgBoardRef(void);

public slots:
    void testDeletionByIndex(void);

private:
    QTimer*             m_timer;
    MsgBoardModel*      m_ref;
};

}
#endif // DELETEME_H
