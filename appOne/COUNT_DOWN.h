#pragma once
#include"COLOR.h"
#include "SCENE.h"
class COUNT_DOWN :
    public SCENE
{
public:
    struct DATA {
        int maxCount = 100;
        int count = maxCount;
        int image = 0;
        float textSize = 0;
        COLOR imageColor;
    };
private:
    DATA CD;
public:
    COUNT_DOWN(class GAME* game) :SCENE(game) {}
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
    void setCount(int count);
};

