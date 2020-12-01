
#include "dmsingleton.h"
#include "player.h"
#include "monster.h"

int main()
{
    CDMSingletonFrame::Instance()->Init();
    CDMSingletonFrame::Instance()->UnInit();
    CDMSingletonFrame::Instance()->Release();

    return 0;
}
