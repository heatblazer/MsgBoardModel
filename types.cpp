#include "types.h"




namespace msgboard
{

    Msg::Msg(const QString& msg, MsgType type, int timer)
        : m_msg(msg), m_type(type), m_timer(timer)
    {

    }

    Msg::~Msg()
    {

    }

}
