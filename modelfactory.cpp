#include "modelfactory.h"
#include "msgboardmodel.h"

namespace msgboard {

    //Nothing just compile the factory
    struct MsgBoardModelLog
    {

    };

    MsgBoardModel* ModelFactory::getMsgBoardModel(int rows, int cols)
    {
        return new MsgBoardModel(rows, cols);
    }


    MsgBoardModelLog*   ModelFactory::getMsgBoardModelLog(void)
    {
        return NULL;
    }

}//!msgboard
