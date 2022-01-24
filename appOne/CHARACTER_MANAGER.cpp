#include"GAME.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"ENEMY.h"
#include"PLAYER.h"
#include"ENEMY_BULLET.h"
#include"CAT.h"
#include"BAT_BULLET.h"
#include"HOLE.h"
#include"CHARACTER_MANAGER.h"
CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game) :
    GAME_OBJECT(game) {
}
CHARACTER_MANAGER::~CHARACTER_MANAGER() {
    for (int i = 0; i < Total; i++) {
        delete Characters[i];
    }
    delete[] Characters;
}
void CHARACTER_MANAGER::create() {
    CharaMng = game()->container()->data().charaMng;

    Total = 0;
    Total += CharaMng.numPlayers;
    Total += CharaMng.numEnemies;
    Total += CharaMng.numEnemyBullets;
    Total += CharaMng.numCats;
    Total += CharaMng.numBatBullets;
    Total += CharaMng.numHoles;
    Characters = new CHARACTER * [Total];

    Player = new PLAYER(game());
    Enemy = new ENEMY(game());
    int i, j = 0;
    for (i = 0; i < CharaMng.numPlayers; i++)       Characters[j++] = Player;
    for (i = 0; i < CharaMng.numEnemies; i++)      Characters[j++] = Enemy;
    for (i = 0; i < CharaMng.numEnemyBullets; i++)    Characters[j++] = new ENEMY_BULLET(game());
    for (i = 0; i < CharaMng.numCats; i++)          Characters[j++] = new CAT(game());
    for (i = 0; i < CharaMng.numBatBullets; i++)    Characters[j++] = new BAT_BULLET(game());
    for (i = 0; i < CharaMng.numHoles; i++)    Characters[j++] = new HOLE(game());
    for (int i = 0; i < Total; i++) {
        Characters[i]->create();
    }
}
void CHARACTER_MANAGER::init() {
    for (int i = 0; i < Total; i++) {
        Characters[i]->init();
    }
}
void CHARACTER_MANAGER::appear(char charaId, float wx, float wy, float vx, float vy) {
    // charaId�Ŏw�肳�ꂽ�L�������o��������
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->charaId() == charaId) {
            if (Characters[i]->hp() <= 0) {
                Characters[i]->appear(wx, wy, vx, vy);
                break;
            }
        }
    }
}
void CHARACTER_MANAGER::update() {

    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->update();
        }
    }
    //�L�����ƃL�����̓����蔻��---------------------------------------------------
    for (int i = 0; i < Total - 1; i++) {
        if (Characters[i]->hp() == 0) {
            continue;// ��������i++�ɖ߂�
        }
        for (int j = i + 1; j < Total; j++) {
            if (Characters[j]->hp() == 0) {
                continue;// ��������j++�ɖ߂�
            }
            //���Ԃǂ����͓����蔻�肵�Ȃ�
            if (Characters[i]->groupId() == Characters[j]->groupId()) {
                continue;// ��������j++�ɖ߂�
            }
            //�����蔻��
            if (Characters[i]->wLeft() < Characters[j]->wRight() &&
                Characters[j]->wLeft() < Characters[i]->wRight() &&
                Characters[i]->wTop() < Characters[j]->wBottom() &&
                Characters[j]->wTop() < Characters[i]->wBottom()) {
                //��������
                //�v���C���[�̓����蔻��
                if (Characters[i]->charaId() == 'a') {
                    if (Characters[j]->charaId() == 'c') {
                        Characters[i]->Sdamage();
                        Characters[j]->Ddamage();
                    }
                    if (Characters[j]->charaId() == 'd') {
                        Characters[i]->Sdamage();
                    }
                    if (Characters[j]->charaId() == 'g'|| Characters[j]->charaId() == 'f') {
                        Characters[i]->Ddamage();
                    }
                    if (Characters[j]->charaId() == 'e') {
                        Characters[i]->Srecover();
                    }

                }
                if (Characters[j]->charaId() == 'a') {
                    if (Characters[i]->charaId() == 'c') {
                        Characters[i]->Sdamage();
                        Characters[j]->Ddamage();
                    }
                    if (Characters[i]->charaId() == 'd') {
                        Characters[j]->Sdamage();
                    }
                    if (Characters[i]->charaId() == 'g' || Characters[i]->charaId() == 'f') {
                        Characters[j]->Ddamage();
                    }
                    if (Characters[i]->charaId() == 'e') {
                        Characters[j]->Srecover();
                        Characters[i]->Ddamage();
                    }

                }
                //�G�̓����蔻��
                if (Characters[i]->charaId() == 'g') {
                    if (Characters[j]->charaId() == 'd') {
                        Characters[i]->Mrecover();
                        Characters[j]->Ddamage();
                    }

                }
                if (Characters[j]->charaId() == 'g') {
                    if (Characters[i]->charaId() == 'd') {
                        Characters[j]->Mrecover();
                        Characters[i]->Ddamage();
                    }
                    

                }


            }
        }
    }
}
void CHARACTER_MANAGER::draw() {
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->draw();
        }
    }
}
