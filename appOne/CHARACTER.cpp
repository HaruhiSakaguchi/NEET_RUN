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
}
void CHARACTER::appear(float wx, float wy, float vx, float vy) {
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.hp = 1;
}
void CHARACTER::update() {
    float px = Chara.wx - game()->map()->wx();
    if (px < -game()->map()->chipSize()) {
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
            px, py, Chara.angle, Chara.scale);
    }
    else if (Chara.anim) {
        fill(Chara.color);
        Chara.anim->draw(&Chara.animData,
            px, py, Chara.angle, Chara.scale);
    }
    else {
        fill(Chara.color);
        image(Chara.img, px, py, Chara.angle, Chara.scale);
    }
}
void CHARACTER::damage() {
    if (Chara.hp > 0) {
        Chara.hp--;
    }
}
void CHARACTER::damage2() {
    if (Chara.hp > 0) {
        Chara.hp--;
    }
}
void CHARACTER::damage3() {
    if (Chara.hp > 0) {
        Chara.hp--;
    }
}
void CHARACTER::recover() {
    if (Chara.hp > 0) {
        if (Chara.stamina >= Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
void CHARACTER::recover2() {
    if (Chara.hp > 0) {
        if (Chara.stamina >= Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
void CHARACTER::recover3() {
    if (Chara.hp > 0) {
        if (Chara.stamina >= Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
void CHARACTER::effect() {
    if (Chara.hp > 0) {
        Chara.hp--;
    }
}