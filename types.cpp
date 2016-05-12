#include "types.h"


namespace msgboard
{

Msg::Msg(const QString& msg, MsgType type, int timer, bool clicked)
    : m_msg(msg), m_type(type), m_timer(timer), m_clicked(clicked),
      m_index(-1)
{

}

Msg::~Msg()
{

}

}
