#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "CAT.h"
void CAT::create() {
    Chara = game()->container()->data().catChara;
    Cat = game()->container()->data().cat;
}
void CAT::appear(float wx, float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().catChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
    Cat.triggerCnt = game()->container()->data().cat.triggerCnt;
}
void CAT::update() {
    ////こうもり弾発射----------------------------------------------------------------
    //Cat.elapsedTime += delta;
    //if (Cat.elapsedTime >= Cat.interval) {
    //    Cat.elapsedTime -= Cat.interval;
    //    ++Cat.triggerCnt %= Cat.triggerInterval;
    //    if (Cat.triggerCnt == Cat.trigger1st ||
    //        Cat.triggerCnt == Cat.trigger2nd ||
    //        Cat.triggerCnt == Cat.trigger3rd ||
    //        Cat.triggerCnt == Cat.trigger4th) {
    //        game()->characterManager()->appear(Cat.bulletCharaId,
    //            Chara.wx - Cat.bulletOffsetX, Chara.wy, -1, 1);
    //    }
    //}
    Chara.vx = Chara.speed * delta;
    Chara.wx += Chara.vx;
    //マップ------------------------------------------------------------------------
    // ウィンドウの外に出た
    if (Chara.wx < game()->map()->wDispLeft()) {
        Chara.hp = 0;
    }
    //ダメージを受けたときちょっとだけ透明化する------------------------------------
    if (Cat.damageTime > 0) {
        Cat.damageTime -= delta;
        Chara.color = Cat.damageColor;
    }
    else {
        Chara.color = Cat.normalColor;
    }
}
