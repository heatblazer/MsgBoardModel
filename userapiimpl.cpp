#include "usrapiimpl.h"

namespace msgboard {


    TimerMessage::TimerMessage()
        : m_msg(nullptr), m_type(TIMER_ACTIVITY_MSG)
    {
        //start timer !!!
        m_timer.start(1500);
    }

    TimerMessage::~TimerMessage()
    {

    }

    void TimerMessage::addMessage(const char *msg)
    {
        m_msg = new QString(msg);
    }

    UserMessage::UserMessage()
        :  m_msg(nullptr), m_type(USER_ACTIVITY_MSG)
    {
        //user event handling (slot or sig )
    }

    UserMessage::~UserMessage()
    {

    }

    void UserMessage::addMessage(const char *msg)
    {
        m_msg = new QString(msg);
    }

    StaticMessage::StaticMessage()
        : m_msg(nullptr), m_type(STATIC_ACTIVITY_MSG)
    {
        //implement custom init for static messsages
    }

    StaticMessage::~StaticMessage()
    {

    }

    void StaticMessage::addMessage(const char *msg)
    {
        m_msg = new QString(msg);
    }

}
