#pragma once
#include <QString>

namespace msgboard {

    enum MsgType
    {
        TIMER_ACTIVITY_MSG = 1,
        USER_ACTIVITY_MSG = 2,
        STATIC_MSG = 3
    };

    // info class
    class Msg
    {
    public:
        Msg(const QString& msg, MsgType type, int timer);
        virtual ~Msg(); //if we need to extend it

        QString m_msg;
        MsgType m_type;
        int m_timer; //-1 for non timer messages

    };

}
