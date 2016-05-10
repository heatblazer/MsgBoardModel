#pragma once
#ifndef USRAPIIMPL_H
#define USRAPIIMPL_H

#include "userapi.h"
#include "types.h"
#include <QtCore>

class TimerMessage;
class UserMessage;
class StaticMessage;


class TimerMessage : public UserApiInterface
{
public:
    explicit TimerMessage();
    virtual ~TimerMessage();

    virtual void addMessage(const char *msg);
private:
    QString* m_msg;
    MsgType m_type; //enum types
    QTimer m_timer;

};

class UserMessage : public UserApiInterface
{
 public:
    explicit UserMessage();
    virtual ~UserMessage();

    virtual void addMessage(const char *msg);

private:
    QString* m_msg;
    MsgType m_type; //enum types
    //Qevents here also

};

class StaticMessage : public UserApiInterface
{
public:
    explicit StaticMessage();
    virtual ~StaticMessage();

    virtual void addMessage(const char *msg);

private:
    void removeUsrMsg(const char* msg);
    QString* m_msg;
    MsgType m_type; //enum types

};

#endif // USRAPIIMPL_H
