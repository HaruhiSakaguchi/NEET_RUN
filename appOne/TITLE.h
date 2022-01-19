#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        float textSize = 0;
        int image = 0;
        int image2 = 0;
        int flag = 0;
        COLOR textColor;
        COLOR backColor;
        VECTOR2 pos;
        char str[16];
        float buttonRadius = 0;
        float buttonNameTextSize = 40;
        float charaNum = 7.5f;
        VECTOR2 buttonPos;
        float buttonW = buttonNameTextSize * charaNum;
        float buttonH = buttonNameTextSize * 3;
        COLOR color1;
        COLOR color2;
        const char* text1 = "ゲームスタート";

    };
private:
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void create();
    void draw();
    void nextScene();
    void init();
    void setFlag(int flag);
};

