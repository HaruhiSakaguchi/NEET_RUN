#include"graphic.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"CHARACTER.h"
CHARACTER::CHARACTER(GAME* game) :
    GAME_OBJECT(game) {
}
void CHARACTER::create() {
}
void CHARACTER::init() {
    Chara.hp = 0;
    Chara.angle = 0;
    Chara.stamina = 0;
}
void CHARACTER::appear(float wx, float wy, float vx, float vy) {
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.hp = 1;
    Chara.stamina = Chara.maxStamina;
}
void CHARACTER::update() {
    float px = Chara.wx - game()->map()->wx();
    if (px < -game()->map()->chipSize()) {
        Chara.hp = 0;
    }
    if (Chara.wx < game()->map()->wDispLeft()) {
        Chara.hp = 0;
    }
   
}
void CHARACTER::draw() {
    imageColor(Chara.color);
    float px = Chara.wx - game()->map()->wx();
    float py = Chara.wy - game()->map()->wy();
    if (Chara.anims) {
        fill(Chara.color);
        Chara.anims->anim(Chara.animId)->draw(&Chara.animData,
            px, py, Chara.angle, game()->map()->scale());
    }
    else if (Chara.anim) {
        fill(Chara.color);
        Chara.anim->draw(&Chara.animData,
            px, py, Chara.angle, game()->map()->scale());
    }
    else {
        fill(Chara.color);
        image(Chara.img, px, py, Chara.angle, game()->map()->scale());
    }
}
void CHARACTER::Sdamage() {
    if (Chara.hp > 0) {
        if (Chara.damageTime == 0) {
            Chara.stamina -= 10;
        }
        Chara.damageTime = Chara.damageInterval;
    }
}
void CHARACTER::Mdamage() {
    if (Chara.hp > 0) {
        if (Chara.damageTime == 0) {
            Chara.stamina -= 20;
        }
        Chara.damageTime = Chara.damageInterval;
    }
}
void CHARACTER::Ldamage() {
    if (Chara.hp > 0) {
        if (Chara.damageTime == 0) {
            Chara.stamina -= 30;
        }
        Chara.damageTime = Chara.damageInterval;
    }
}
void CHARACTER::Ddamage() {
    if (Chara.hp > 0) {
        Chara.hp--;
    }
}
void CHARACTER::Srecover() {
    if (Chara.hp > 0) {
        Chara.stamina += 10;
        if (Chara.stamina >= Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
void CHARACTER::Mrecover() {
    if (Chara.hp > 0) {
        Chara.stamina += 20;
        if (Chara.stamina >= Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
void CHARACTER::Lrecover() {
    if (Chara.hp > 0) {
        Chara.stamina += 30;
        if (Chara.stamina >= Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
void CHARACTER::knock() {
    Chara.wx += Chara.knockBackVx;
    Chara.wy -= Chara.knockBackVy;
}
void CHARACTER::fall() {

}
void CHARACTER::caught() {

}
void CHARACTER::noDamage() {

}
