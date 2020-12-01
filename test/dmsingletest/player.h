#ifndef __PLAYER_H_INCLUDE__
#define __PLAYER_H_INCLUDE__

#include "dmsingleton.h"
#include <iostream>

class CPlayer : public CDMSingleton<CPlayer>
{
    friend class CDMSingleton<CPlayer>;
public:
    CPlayer() {}
    virtual ~CPlayer() {}

    virtual bool Init()
    {
        std::cout << "CPlayer Init" << std::endl;
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

#endif // __PLAYER_H_INCLUDE__
