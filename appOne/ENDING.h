#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
#include "SCENE.h"
class ENDING :
    public SCENE
{
public:
    struct DATA {
        float textSize = 0;
        COLOR textColor;
        COLOR backColor;
        VECTOR2 pos;
        char str[16];
    };
private:
    DATA Ending;
public:
    ENDING(class GAME* game);
    ~ENDING();
    void create();
    void draw();
    void nextScene();
    void init();
};

