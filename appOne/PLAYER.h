#pragma once
#include "CHARACTER.h"
class PLAYER :
    public CHARACTER
{
public:
    struct DATA {
        int charaDamage = 0;

        int rightAnimId = 0;
        int leftAnimId = 1;
        int jumpFlag = 0;
        float stamina = 0;
        float maxStamina = 100;
        float speed = 0;
        float maxSpeed = 0;
        float curWx = 0;
        float initVecUp = 0;
        float initVecDown = 0;
        float gravity = 0;
        char bulletCharaId = 0;
        float damageTime = 0;
        float damageInterval = 0;
        float staminaDamage = 0.01f;
        COLOR color;
        COLOR damageColor;
        COLOR normalColor;
    };
private:
    DATA Player;
    enum class STATE_ID { STRUGGLING, DIED, FALL, SURVIVED };
    STATE_ID StateId = STATE_ID::STRUGGLING;
    
public:
    PLAYER(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
private:
    void Move();
    void CollisionWithMap();
    void CheckState();
public:
    void damage();
    void damage2();
    void damage3();
    void recover();
    void recover2();
    void recover3();
    void effect();
    void init();
    bool died();
    bool survived();
    float overCenterVx();

    
    STATE_ID stateId() { return StateId; }
    float stamina() { return Player.stamina; }
};
