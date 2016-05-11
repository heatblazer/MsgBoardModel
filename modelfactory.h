#pragma once
#ifndef MODELFACTORY_H
#define MODELFACTORY_H

namespace msgboard {
    class MsgBoardModel;
    class MsgBoardModelLog;

    class ModelFactory
    {

    public:
        static MsgBoardModel*       getMsgBoardModel(void) ;
        static MsgBoardModelLog*    getMsgBoardModelLog(void);

    };

}
#endif // MODELFACTORY_H

