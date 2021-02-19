
#include "dmsingleton.h"
#include "player.h"
#include "monster.h"
#include "gtest.h"

TEST(dmsingletontest, dmsingletontest)
{
    CDMSingletonFrame::Instance()->Init();
    CDMSingletonFrame::Instance()->UnInit();
    CDMSingletonFrame::Instance()->Release();
}
