#pragma once
#include "CHARACTER.h"
class ENEMY :
    public CHARACTER
{
public:
    struct DATA {
        float speed;
        float stamina = 0;
        float maxStanima = 0;

        int hp = 0;

    };
protected:
    DATA Enemy;
public:
    ENEMY(class GAME* game);
    virtual void create();
    virtual void init();
    virtual void launch();
    virtual void update();

};

