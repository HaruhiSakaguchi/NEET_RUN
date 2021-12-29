#pragma once
#include "SCENE.h"
class GAME_OVER :
    public SCENE
{
public:
    struct DATA {
        float textSize = 0;
        COLOR textColor;
        COLOR backColor;
        VECTOR2 pos;
        char str[16];

        VECTOR2 backToTitlePos;
        VECTOR2 continuePos;
        float buttonNameTextSize = 30;
        float charaNum = 7;
        float buttonW = buttonNameTextSize * charaNum;
        float buttonH = buttonNameTextSize * 1.5f;
        const char* continueText;
        const char* backToTitleText;
    };
private:
    DATA GameOver;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void create();
    void draw();
    void nextScene();
    void init();
};

