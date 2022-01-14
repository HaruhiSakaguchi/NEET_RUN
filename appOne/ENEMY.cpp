#include"graphic.h"
#include"ANIMS.h"
#include"GAME_OBJECT.h"
#include"GAME.h"
#include"MAP.h"
#include"CONTAINER.h"
#include"ENEMY.h"
ENEMY::ENEMY(GAME*game):
	GAME_OBJECT(game){}
void ENEMY::create(){
}
void ENEMY::init() {
    Enemy.hp = 0;
}
void ENEMY::update(){
	Enemy.wx += Enemy.speed;
}
void ENEMY::launch() {

}
void ENEMY::appear(float wx, float wy, float vx, float vy) {
    Enemy.wx = wx;
    Enemy.wy = wy;
    Enemy.hp = 1;
}
void ENEMY::draw() {
    imageColor(Enemy.color);
    float px = Enemy.wx - game()->map()->wx();
    float py = Enemy.wy - game()->map()->wy();
    if (Enemy.anims) {
        Enemy.anims->anim(Enemy.animId)->draw(&Enemy.animData,
            px, py, Enemy.angle, Enemy.scale);
    }
    else if (Enemy.anim) {
        Enemy.anim->draw(&Enemy.animData,
            px, py, Enemy.angle, Enemy.scale);
    }
    
}
void ENEMY::damage() {
    if (Enemy.hp > 0) {
        Enemy.hp--;
    }
}
void ENEMY::recover() {
    if (Enemy.hp > 0) {
        Enemy.stamina += 10;
        if (Enemy.stamina >= Enemy.maxStamina) {
            Enemy.stamina = Enemy.maxStamina;
        }
    }
}

