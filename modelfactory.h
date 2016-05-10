#pragma once
#ifndef MODELFACTORY_H
#define MODELFACTORY_H

namespace msgboard {
    class MsgBoardModel;
    class MsgBoardModelLog;

    //конкретна фабрика за продуциране на модели
    class ModelFactory
    {

    public:
        static MsgBoardModel*       getMsgBoardModel(int rows, int cols) ;
        static MsgBoardModelLog*    getMsgBoardModelLog(void);

    };

}//!msgboard
#endif // MODELFACTORY_H

