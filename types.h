#ifndef TYPES_H
#define TYPES_H

#include <QString>


namespace msgboard {

enum MsgType
{
    TIMER_ACTIVITY_MSG = 1,
    USER_ACTIVITY_MSG = 2,
    STATIC_ACTIVITY_MSG = 3
};

enum LogType
{
    INFO_LOG = 1,
    WARN_LOG = 2,
    ERROR_LOG = 3,
    UNKNOWN_LOG = 4
};


// info class
class Msg
{
public:
    Msg(const QString& msg, MsgType type, int timer);
    virtual ~Msg(); // if we need to extend it but we won`t do it
    QString m_msg;
    MsgType m_type;
    int m_timer; // -1 for non timer messages
    int m_index; // reflects to the rows (or cols if needed )
    int m_clicks; // false by default, user has not clicked it

};



class MsgStyleBuilder
{
private:
    enum  Styles {
        COLOR,
        BCK_COLOR,
        SEL_COLOR,
        SEL_BCK_COLOR,
        SIZE,
        MAX
    };

public:
    static MsgStyleBuilder& instance();


    MsgStyleBuilder& setColor(const QString& col);
    MsgStyleBuilder& setBackgroundColor(const QString& col);
    MsgStyleBuilder& setSelectionColor(const QString& col);
    MsgStyleBuilder& setSelBackgroundColor(const QString& col);
    MsgStyleBuilder& setPosition(int x, int y, int w, int h);

    QString         strike(void);

private:
    MsgStyleBuilder();
    virtual ~MsgStyleBuilder();
    static MsgStyleBuilder* s_instance;

    //aggregation of string objects
    QString* m_style[Styles::MAX];

};

}

#endif

