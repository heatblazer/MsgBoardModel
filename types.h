#pragma once

class QString;
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
        Msg(const QString msg, MsgType type, int timer);
        ~Msg(); //I don`t need to extend it for now!

        QString m_msg;
        MsgType m_type;
        int m_timer; //-1 for non timer messages

    };

}//!msgboard
