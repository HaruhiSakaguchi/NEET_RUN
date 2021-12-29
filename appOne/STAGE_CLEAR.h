#pragma once
#include "SCENE.h"
#include"COLOR.h"
#include"VECTOR2.h"
class STAGE_CLEAR :
    public SCENE
{
public:
    struct DATA {
        float textSize = 0;
        COLOR textColor;
        COLOR backColor;
        VECTOR2 pos;
        char str[16];
        int image = 0;
        VECTOR2 backToTitlePos;
        VECTOR2 nextPos;
        float buttonNameTextSize = 30;
        float charaNum = 7;
        float buttonW = buttonNameTextSize * charaNum;
        float buttonH = buttonNameTextSize * 1.5f;
        const char* nextText;
        const char* backToTitleText;
    };
private:
    DATA StageClear;
public:
    STAGE_CLEAR(class GAME* game);
    ~STAGE_CLEAR();
    void draw();
    void nextScene();
    void create();
    void init();
};

