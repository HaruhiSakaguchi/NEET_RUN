#pragma once
#include"GAME_OBJECT.h"
#include"COLOR.h"
#include"ANIMS.h"
class CHARACTER :
    public GAME_OBJECT
{
public:
    struct DATA {
        //�����A�j��or�P�̃A�j��or�Î~����g�p����
        //�����A�j���[�V����
        class ANIMS* anims = nullptr;
        int animId = 0;
        //�P�̃A�j���[�V����
        class ANIM* anim = nullptr;
        ANIM_DATA animData;
        //�Î~��
        int img = 0;
        //�����F
        COLOR color;

        char charaId = 0;
        int groupId = 0;
        float wx = 0;
        float wy = 0;
        float vx = 0;
        float vy = 0;
        float speed = 0;
        float angle = 0;
        float damageTime = 0;
        float damageInterval = 0;
        float stamina = 0;
        float maxStamina = 0;
        float knockBackVx = 0;
        float knockBackVy = 0;


        int hp = 0;
        float offsetLeft = 0;
        float offsetTop = 0;
        float offsetRight = 0;
        float offsetBottom = 0;
    };
protected:
    DATA Chara;
public:
    CHARACTER(class GAME* game);
    virtual void create();
    virtual void init();
    virtual void appear(float wx, float wy, float vx, float vy);
    virtual void update();
    virtual void draw();
    virtual void Sdamage();
    virtual void Mdamage();
    virtual void Ldamage();
    virtual void Ddamage();
    virtual void Srecover();
    virtual void Mrecover();
    virtual void Lrecover();
    virtual void knock();
    virtual void fall();
    virtual void caught();
    virtual void noDamage();
    int   hp() { return Chara.hp; }
    float stamina() { return Chara.stamina; }
    int   groupId() { return Chara.groupId; }
    char  charaId() { return Chara.charaId; }
    float wLeft() { return Chara.wx + Chara.offsetLeft; }
    float wTop() { return Chara.wy + Chara.offsetTop; }
    float wRight() { return Chara.wx + Chara.offsetRight; }
    float wBottom() { return Chara.wy + Chara.offsetBottom; }
    void setImgIdx(int i) { Chara.animData.imgIdx = i; }
};

