#pragma once
#include"ANIM.h"
class LOADING :public SCENE
{
public:
    struct DATA {
        //単体アニメーション
        class ANIM* anim = nullptr;
        ANIM_DATA animData;
        float goToTitleTime = 0;
    };
    DATA Loading;
    LOADING(class GAME* game):SCENE(game){}
    void init();
    void create();
    void draw();
    void update();
    void nextScene();
};

