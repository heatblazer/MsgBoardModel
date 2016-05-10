#pragma once
#ifndef MODELFACTORY_H
#define MODELFACTORY_H

class MsgBoardModelView;
class MsgBoardModelLog;


//конкретна фабрика за продуциране на модели
class ModelFactory
{

public:
    static MsgBoardModelView*   getMsgBoardModelView(int rows, int cols) ;
    static MsgBoardModelLog*    getMsgBoardModelLog(void);

};

#endif // MODELFACTORY_H
