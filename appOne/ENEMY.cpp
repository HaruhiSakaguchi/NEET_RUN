#include"window.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"STAGE.h"
#include"ENEMY_BULLET.h"
#include"ENEMY.h"
void ENEMY::create() {
    Chara = game()->container()->data().enemyChara;
    Enemy = game()->container()->data().enemy;
}
void ENEMY::init() {
    Chara.hp = 0;
    Enemy.stamina = Enemy.maxStamina;
    Enemy.triggerCnt = game()->container()->data().enemy.triggerCnt;
}
void ENEMY::appear(float wx, float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().enemyChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Enemy.jumpFlag = 0; 
    Enemy.triggerCnt = game()->container()->data().enemy.triggerCnt;
    StateId = STATE_ID::STRUGGLING;
   
}
void ENEMY::update() {
    if (game()->container()->data().stage.count == 0||game()->container()->data().stage.flag==0) {
        Move();
    }
    CollisionWithMap();
    checkState();
    
}
void ENEMY::jump() {
    if (Enemy.jumpFlag == 0 ) {
        Chara.vy = Enemy.initVecUp;
        Enemy.jumpFlag = 1;
    }
    if (Enemy.jumpFlag == 1) {
        Chara.vy += Enemy.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
}
void ENEMY::checkState() {
    if (Chara.wx > game()->map()->wDispRight()) {
        StateId = STATE_ID::SURVIVED;
        Chara.hp = 0;
    }
    
}
void ENEMY::Move() {
    //ジャンプ
    jump();
    launch();
    if (Chara.hp > 0) {
        Enemy.stamina -= Enemy.staminaDamage;
    }
    //if (Enemy.jumpFlag == 0 && (isTrigger(KEY_K) || isTrigger(MOUSE_LBUTTON))) {
    //    Chara.vy = Enemy.initVecUp;
    //    Enemy.jumpFlag = 1;
   // }
   // if (Enemy.jumpFlag == 1) {
   // Chara.vy += Enemy.gravity * delta;
     //   Chara.wy += Chara.vy * 60 * delta;
    //}
    //左右移動
    // 移動ベクトルを決定
    //Chara.vx = 0.0f;
    Enemy.speed = 3.4f * 6.0f * Enemy.stamina / 10;
    Chara.vx = Enemy.speed * delta;
    //Enemy.stamina -= 0.1f;
    if (Enemy.stamina <= 1) Enemy.stamina = 1;
    Chara.animId = Enemy.rightAnimId;
   

    //  移動前に現在のChara.wxをEnemy.curWxにとっておく
    Enemy.curWx = Chara.wx;
    //  移動
    if (Chara.vx != 0.0f) {//左右キー入力あり
        //とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
        //あとで、マップに食い込んでいたら、元のEnemy.curWxに戻す
        Chara.wx += Chara.vx;
    }
    else {//左右キー入力がないとき
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void ENEMY::CollisionWithMap() {
    MAP* map = game()->map();
    // マップチップとキャラの右
    if (Chara.animId == Enemy.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //移動予定位置がマップに食い込んでいるので現在の位置に戻す
            Chara.wx = Enemy.curWx;
        }
    }
    // マップチップとキャラの左
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //または、ウィンドウの左にぶつかったか
            ) {
            Chara.wx = Enemy.curWx;
        }
    }
    // マップチップとキャラの上
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Enemy.initVecDown;//落ちていく初速度
    }
    // マップチップとキャラの下
    if (map->collisionCharaBottom(Enemy.curWx, Chara.wy)) {
        //--「マップチップに食い込んでいる」
        // または「上に立っているとき」もここを通る--
        //ジャンプ（落下）処理の停止
        Enemy.jumpFlag = 0;
        Chara.vy = 0.0f;
        //強制的に上に立っている位置にする
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Enemy.jumpFlag = 1;//落ちてくトリガー。このフラッグを立てるだけで落ちていく。
    }
}

void ENEMY::Sdamage() {
    if (Chara.hp > 0) {
        Enemy.stamina -= 10;
    }
}
void ENEMY::Mdamage() {
    if (Chara.hp > 0) {
        Enemy.stamina -= 20;
    }
}
void ENEMY::Ldamage() {
    if (Chara.hp > 0) {
        Enemy.stamina -= 30;
    }
}
void ENEMY::Srecover() {
    if (Chara.hp > 0) {
        Enemy.stamina += 10;
        if (Chara.stamina > Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
void ENEMY::Mrecover() {
    if (Chara.hp > 0) {
        Enemy.stamina += 20;
        if (Chara.stamina > Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
void ENEMY::Lrecover() {
    if (Chara.hp > 0) {
        Enemy.stamina += 30;
        if (Chara.stamina > Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
void ENEMY::launch() {
    //弾発射----------------------------------------------------------------
    Enemy.elapsedTime += delta;
    if (Enemy.elapsedTime >= Enemy.interval) {
        Enemy.elapsedTime -= Enemy.interval;
        ++Enemy.triggerCnt %= Enemy.triggerInterval;
        if (Enemy.triggerCnt == Enemy.trigger1st ||
            Enemy.triggerCnt == Enemy.trigger2nd ||
            Enemy.triggerCnt == Enemy.trigger3rd ||
            Enemy.triggerCnt == Enemy.trigger4th  ) {
            Chara.animId = game()->container()->data().enemyBullet.leftAnimId;
            game()->characterManager()->appear(Enemy.bulletCharaId,
                Chara.wx + Enemy.bulletOffsetX, Chara.wy, 1, 0);
        }
    }
}
bool ENEMY::survived() {
    return StateId == STATE_ID::SURVIVED;
}
