
#include "dmsingleton.h"

class CPlayer : public CDMSingleton<CPlayer>
{
    friend class CDMSingleton<CPlayer>;
public:
    CPlayer() {}
    virtual ~CPlayer() {}

    virtual bool Init()
    {
        return true;
    }
    virtual bool UnInit()
    {
        return true;
    }

    virtual void Release()
    {
        Destroy();
    }
};

int main()
{
    CDMSingletonFrame::Instance()->Init();
    CDMSingletonFrame::Instance()->UnInit();
    CDMSingletonFrame::Instance()->Release();

    return 0;
}
