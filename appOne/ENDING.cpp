#include "ENDING.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"graphic.h"
#include"input.h"
#include "TITLE.h"
ENDING::ENDING(class GAME* game) :
	SCENE(game) {

}
ENDING::~ENDING() {

}
void ENDING::create() {
	Ending = game()->container()->data().ending;
}
void ENDING::init() {
	game()->fade()->inTrigger();
	game()->changeState(GAME::FIRST);
}
void ENDING::draw() {
	clear(Ending.backColor);
	stroke(Ending.backColor);
	noStroke();
	fill(Ending.textColor);
	textSize(Ending.textSize);
	text(Ending.str, Ending.pos.x, Ending.pos.y);

#ifdef _DEBUG
	textSize(30);
	fill(255, 255, 255);
	text("SPACEキーでタイトルに戻る", 30, 30);
#endif
	game()->fade()->draw();
}
void ENDING::nextScene() {
	if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		game()->changeScene(GAME::TITLE_ID);
		game()->changeState(GAME::FIRST);
		game()->changeText(GAME::text_1);
	}
}
