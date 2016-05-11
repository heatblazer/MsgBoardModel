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


        friend class MsgBoardModel;
        friend class MsgBoardModelLog;

    };

}
#endif // MODELFACTORY_H

