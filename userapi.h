#pragma once
#ifndef USERAPI_H
#define USERAPI_H

class UserApi;


class UserApiInterface
{
    //interface class
public:
    UserApiInterface();
    virtual ~UserApiInterface() = 0;
    virtual void addMessage(const char* msg) = 0;

};





#endif // USERAPI_H
