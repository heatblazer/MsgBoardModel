#include "types.h"


namespace msgboard
{

Msg::Msg(const QString& msg, MsgType type, int timer)
    : m_msg(msg), m_type(type), m_timer(timer), m_clicks(0),
      m_index(-1)
{

}

Msg::~Msg()
{

}


MsgStyleBuilder*    MsgStyleBuilder::s_instance = nullptr;


MsgStyleBuilder::MsgStyleBuilder()
{
    // set some defaults
}


MsgStyleBuilder::~MsgStyleBuilder()
{

}


MsgStyleBuilder&    MsgStyleBuilder::instance()
{
    if (s_instance==nullptr) {
        s_instance = new MsgStyleBuilder;
    }
    return *s_instance;
}

MsgStyleBuilder&    MsgStyleBuilder::setColor(const QString& col)
{
    m_style[MsgStyleBuilder::Styles::COLOR] = col;
    return *s_instance;
}


MsgStyleBuilder&    MsgStyleBuilder::setBackgroundColor(const QString &col)
{
    m_style[MsgStyleBuilder::Styles::BCK_COLOR] = col;
    return *s_instance;
}


MsgStyleBuilder&    MsgStyleBuilder::setSelBackgroundColor(const QString &col)
{
    m_style[MsgStyleBuilder::Styles::SEL_BCK_COLOR] = col;
    return *s_instance;
}

MsgStyleBuilder&    MsgStyleBuilder::setSelectionColor(const QString &col)
{
    m_style[MsgStyleBuilder::Styles::SEL_COLOR] = col;
    return *s_instance;
}


QString     MsgStyleBuilder::strike()
{
    static char style[1024] = {0};

    sprintf(style, "color: %s;"
                   "background-color: %s;"
                   "selection-color: %s;"
                   "selection-background-color: %s;",
            m_style[0].toLocal8Bit().constData(),
            m_style[1].toLocal8Bit().constData(),
            m_style[2].toLocal8Bit().constData(),
            m_style[3].toLocal8Bit().constData()
            );

    QString ret_style(style);
    return ret_style;
}

}
