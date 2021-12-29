#include "HP_GAUGE.h"
#include"CONTAINER.h"
#include"GAME.h"
HP_GAUGE::HP_GAUGE(class GAME* game) :
	GAME_OBJECT(game) {}
HP_GAUGE::~HP_GAUGE() {}
void HP_GAUGE::create() {
	//HpGauge = game()->container()->data().hpGauge();
}
void HP_GAUGE::draw() {

}



