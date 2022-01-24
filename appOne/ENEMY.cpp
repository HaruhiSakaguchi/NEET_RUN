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
    //�W�����v
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
    //���E�ړ�
    // �ړ��x�N�g��������
    //Chara.vx = 0.0f;
    Enemy.speed = 3.4f * 6.0f * Enemy.stamina / 10;
    Chara.vx = Enemy.speed * delta;
    //Enemy.stamina -= 0.1f;
    if (Enemy.stamina <= 1) Enemy.stamina = 1;
    Chara.animId = Enemy.rightAnimId;
   

    //  �ړ��O�Ɍ��݂�Chara.wx��Enemy.curWx�ɂƂ��Ă���
    Enemy.curWx = Chara.wx;
    //  �ړ�
    if (Chara.vx != 0.0f) {//���E�L�[���͂���
        //�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.wx���X�V���Ă���
        //���ƂŁA�}�b�v�ɐH������ł�����A����Enemy.curWx�ɖ߂�
        Chara.wx += Chara.vx;
    }
    else {//���E�L�[���͂��Ȃ��Ƃ�
        Chara.animData.imgIdx = 0;
        Chara.animData.elapsedTime = -delta;
    }
}
void ENEMY::CollisionWithMap() {
    MAP* map = game()->map();
    // �}�b�v�`�b�v�ƃL�����̉E
    if (Chara.animId == Enemy.rightAnimId) {
        if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
            //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
            Chara.wx = Enemy.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̍�
    else {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < map->wx() //�܂��́A�E�B���h�E�̍��ɂԂ�������
            ) {
            Chara.wx = Enemy.curWx;
        }
    }
    // �}�b�v�`�b�v�ƃL�����̏�
    if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Enemy.initVecDown;//�����Ă��������x
    }
    // �}�b�v�`�b�v�ƃL�����̉�
    if (map->collisionCharaBottom(Enemy.curWx, Chara.wy)) {
        //--�u�}�b�v�`�b�v�ɐH������ł���v
        // �܂��́u��ɗ����Ă���Ƃ��v��������ʂ�--
        //�W�����v�i�����j�����̒�~
        Enemy.jumpFlag = 0;
        Chara.vy = 0.0f;
        //�����I�ɏ�ɗ����Ă���ʒu�ɂ���
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {
        Enemy.jumpFlag = 1;//�����Ă��g���K�[�B���̃t���b�O�𗧂Ă邾���ŗ����Ă����B
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
    //�e����----------------------------------------------------------------
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
