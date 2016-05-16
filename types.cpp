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
    // explicity null all pointers
    for(int i=0; i < Styles::SIZE; i++) {
        m_style[i] = nullptr;
    }
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
    char s[128]={0};
    sprintf(s, "color: %s;", col.toLocal8Bit().constData());
    m_style[Styles::COLOR] = new QString(s);

    return *s_instance;
}


MsgStyleBuilder&    MsgStyleBuilder::setBackgroundColor(const QString &col)
{
    char s[128]={0};
    sprintf(s, "background-color: %s;", col.toLocal8Bit().constData());
    m_style[MsgStyleBuilder::Styles::BCK_COLOR] = new QString(s);

    return *s_instance;
}


MsgStyleBuilder&    MsgStyleBuilder::setSelBackgroundColor(const QString &col)
{
    char s[128]={0};
    sprintf(s, "selection-background-color: %s;", col.toLocal8Bit().constData());
    m_style[Styles::SEL_BCK_COLOR] = new QString(s);

    return *s_instance;
}

MsgStyleBuilder&    MsgStyleBuilder::setSelectionColor(const QString &col)
{
    char s[128] = {0};
    sprintf(s,"selection-color: %s;", col.toLocal8Bit().constData());
    m_style[Styles::SEL_COLOR] = new QString(s);

    return *s_instance;
}


QString     MsgStyleBuilder::strike()
{
    QString ret_style;
    for(int i=0; i < Styles::SIZE; i++) {
        if (m_style[i]) {
            ret_style.append(m_style[i]);
        }
    }


    return ret_style;
}

}
