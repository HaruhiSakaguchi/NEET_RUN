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
    //�W�����v
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
    //���E�ړ�
    // �ړ��x�N�g��������
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
    //  �ړ��O�Ɍ��݂�Chara.wx��Player.curWx�ɂƂ��Ă���
    Player.curWx = Chara.wx;
    //  �ړ�
    if (Chara.vx != 0.0f) {//���E�L�[���͂���
        //�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.wx���X�V���Ă���
        //���ƂŁA�}�b�v�ɐH������ł�����A����Player.curWx�ɖ߂�
        Chara.wx += Chara.vx;
    }
    else {//���E�L�[���͂��Ȃ��Ƃ�
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void PLAYER::CollisionWithMap(){
    MAP* map = game()->map();
    // �}�b�v�`�b�v�ƃL�����̉E
    if (Chara.animId == Player.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
            Chara.wx = Player.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̍�
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //�܂��́A�E�B���h�E�̍��ɂԂ�������
            ) {
            Chara.wx = Player.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̏�
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Player.initVecDown;//�����Ă��������x
    }
    // �}�b�v�`�b�v�ƃL�����̉�
    if (map->collisionCharaBottom(Player.curWx, Chara.wy)) {
        //--�u�}�b�v�`�b�v�ɐH������ł���v
        // �܂��́u��ɗ����Ă���Ƃ��v��������ʂ�--
        //�W�����v�i�����j�����̒�~
        Player.jumpFlag = 0;
        Chara.vy = 0.0f;
        //�����I�ɏ�ɗ����Ă���ʒu�ɂ���
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Player.jumpFlag = 1;//�����Ă��g���K�[�B���̃t���b�O�𗧂Ă邾���ŗ����Ă����B
    }
}
void PLAYER::CheckState(){
    //��ʂ̉��ɗ�����
    if (Chara.wy > height + game()->map()->chipSize()) {
        State = STATE::FALL;
        Chara.hp = 0;
        return;
    }
    //�X�e�[�W�N���A����
    if (Chara.wx > game()->map()->wDispRight()) {
        State = STATE::SURVIVED;
        Chara.hp = 0;
    }
}
void PLAYER::damage() {
    if (Chara.hp > 0) {
        if (Chara.hp == 0) {
            State = STATE::DIED;
            Chara.vy = Player.initVecUp;//�͂ˎn�߂̃g���K�[
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
    //�}�b�v���X�N���[�������邽�߂̃x�N�g�������߂�
    float centerWx = (game()->map()->wx() + width / 2 - game()->map()->chipSize() / 2);
    float overCenterVx = Chara.wx - centerWx;
    if (overCenterVx < 0 || Chara.hp == 0)overCenterVx = 0;
    return overCenterVx;
}
