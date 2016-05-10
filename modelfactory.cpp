#include "modelfactory.h"
#include "msgboardmodel.h"

//Nothing just compile the factory
struct MsgBoardModelLog
{

};

MsgBoardModelView* ModelFactory::getMsgBoardModelView(int rows, int cols)
{
    return new MsgBoardModelView(rows, cols);
}


MsgBoardModelLog*   ModelFactory::getMsgBoardModelLog(void)
{
    return NULL;
}
