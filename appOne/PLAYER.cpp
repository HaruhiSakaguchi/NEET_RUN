#include"window.h"
#include"input.h"
#include"graphic.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "PLAYER.h"
void PLAYER::create() {
    Chara = game()->container()->data().playerChara;
    Player = game()->container()->data().player;
}
void PLAYER::init() {
    Player.stamina = Player.maxStamina;
}
void PLAYER::appear(float wx , float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().playerChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Player.jumpFlag = 0;
    State = STATE::STRUGGLING;
}
void PLAYER::update() {
    Move();
    CollisionWithMap();
    CheckState();
}

void PLAYER::Move(){
    //ジャンプ
    if (Chara.hp > 0) {
        Player.stamina -= Player.staminaDamage;
    }
    if (Player.jumpFlag==0 && (isTrigger(KEY_K)||isTrigger(MOUSE_LBUTTON))) {
        Chara.vy = Player.initVecUp;
        Player.jumpFlag = 1;
    }
    if (Player.jumpFlag==1) {
        Chara.vy += Player.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
    //左右移動
    // 移動ベクトルを決定
    //Chara.vx = 0.0f;
    Player.speed = 3.4f * 6.0f * Player.stamina / 10;
    Chara.vx = Player.speed * delta;
    //Player.stamina -= 0.1f;
    if (Player.stamina <= 1) Player.stamina = 1;
    Chara.animId = Player.rightAnimId;
#if _DEBUG
    if (isPress(KEY_A)) {
        Chara.vx = -Chara.speed * delta;
        Chara.animId = Player.leftAnimId;
    }
    if (isPress(KEY_D)) {
        Chara.vx = Chara.speed * delta;
        Chara.animId = Player.rightAnimId;
    }
    text(Player.stamina, 0, 0);
#endif
    //  移動前に現在のChara.wxをPlayer.curWxにとっておく
    Player.curWx = Chara.wx;
    //  移動
    if (Chara.vx != 0.0f) {//左右キー入力あり
        //とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
        //あとで、マップに食い込んでいたら、元のPlayer.curWxに戻す
        Chara.wx += Chara.vx;
    }
    else {//左右キー入力がないとき
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void PLAYER::CollisionWithMap(){
    MAP* map = game()->map();
    // マップチップとキャラの右
    if (Chara.animId == Player.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //移動予定位置がマップに食い込んでいるので現在の位置に戻す
            Chara.wx = Player.curWx;
        }
    }
    // マップチップとキャラの左
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //または、ウィンドウの左にぶつかったか
            ) {
            Chara.wx = Player.curWx;
        }
    }
    // マップチップとキャラの上
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Player.initVecDown;//落ちていく初速度
    }
    // マップチップとキャラの下
    if (map->collisionCharaBottom(Player.curWx, Chara.wy)) {
        //--「マップチップに食い込んでいる」
        // または「上に立っているとき」もここを通る--
        //ジャンプ（落下）処理の停止
        Player.jumpFlag = 0;
        Chara.vy = 0.0f;
        //強制的に上に立っている位置にする
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Player.jumpFlag = 1;//落ちてくトリガー。このフラッグを立てるだけで落ちていく。
    }
}
void PLAYER::CheckState(){
    //画面の下に落ちた
    if (Chara.wy > height + game()->map()->chipSize()) {
        State = STATE::FALL;
        Chara.hp = 0;
        return;
    }
    //ステージクリアした
    if (Chara.wx > game()->map()->wDispRight()) {
        State = STATE::SURVIVED;
        Chara.hp = 0;
    }
}
void PLAYER::damage() {
    if (Chara.hp > 0) {
        if (Chara.hp == 0) {
            State = STATE::DIED;
            Chara.vy = Player.initVecUp;//はね始めのトリガー
        }
    }
}
void PLAYER::recover() {
    if (Chara.hp > 0) {
        Player.stamina += 10;
        if (Chara.stamina >= Chara.maxStamina) {
            Chara.stamina = Chara.maxStamina;
        }
    }
}
bool PLAYER::died() {
    if (State == STATE::DIED) {
        Chara.vy += Player.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
        draw();
        return true;
    }
    else if (State == STATE::FALL) {
        return true;
    }
    return false;
}
bool PLAYER::survived() { 
    return State == STATE::SURVIVED; 
}
float PLAYER::overCenterVx() {
    //マップをスクロールさせるためのベクトルを求める
    float centerWx = (game()->map()->wx() + width / 2 - game()->map()->chipSize() / 2);
    float overCenterVx = Chara.wx - centerWx;
    if (overCenterVx < 0 || Chara.hp == 0)overCenterVx = 0;
    return overCenterVx;
}
