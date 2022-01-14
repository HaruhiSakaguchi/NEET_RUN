#pragma once
#include"graphic.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"GAME.h"
#include"GAME_OBJECT.h"
class ENEMY :
    public GAME_OBJECT
{
public:
    struct DATA {
        float speed = 0;
        float stamina = 0;
        float maxStamina = 0;
        float wx = 0;
        float wy = 0;
        class ANIMS* anims = nullptr;
        int animId = 0;
        class ANIM* anim = nullptr;
        ANIM_DATA animData;
        COLOR color;

        char charaId = 0;
        int groupId = 0;
        float angle = 0;
        float scale = 1;
        float offsetLeft = 0;
        float offsetTop = 0;
        float offsetRight = 0;
        float offsetBottom = 0;
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
    virtual void draw();
    virtual void damage();
    virtual void recover();
    virtual void appear(float wx, float wy, float vx, float vy);
    int   hp() { return Enemy.hp; }
    float stamina() { return Enemy.stamina; }
    int   groupId() { return Enemy.groupId; }
    char  charaId() { return Enemy.charaId; }
    float wLeft() { return Enemy.wx + Enemy.offsetLeft; }
    float wTop() { return Enemy.wy + Enemy.offsetTop; }
    float wRight() { return Enemy.wx + Enemy.offsetRight; }
    float wBottom() { return Enemy.wy + Enemy.offsetBottom; }
    void setImgIdx(int i) { Enemy.animData.imgIdx = i; }
};

