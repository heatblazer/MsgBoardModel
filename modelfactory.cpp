#include "modelfactory.h"
#include "msgboardmodel.h"

namespace msgboard {

    //Nothing just compile the factory
    struct MsgBoardModelLog
    {

    };

    MsgBoardModel* ModelFactory::getMsgBoardModel(void)
    { 
        return MsgBoardModel::instance();
    }


    MsgBoardModelLog*   ModelFactory::getMsgBoardModelLog(void)
    {
        return NULL;
    }

}
