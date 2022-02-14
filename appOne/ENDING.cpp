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
	image(Ending.backImg, 0, 0);

#ifdef _DEBUG
	textSize(30);
	fill(255, 255, 255);
	text("SPACEキーでタイトルに戻る", 30, 30);
#endif
	game()->fade()->draw();
}
void ENDING::nextScene() {
	if (curImageNum == E5) {
		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
			game()->fade()->outTrigger();
		}
	}
	if (game()->fade()->outEndFlag()) {
		game()->changeScene(GAME::TITLE_ID);
		game()->changeState(GAME::FIRST);
		game()->changeText(GAME::text_1);
	}
}
void ENDING::update() {
	if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
		switch (curImageNum) {
		case E1:
			setImageNum(E2);
			break;
		case E2:
			setImageNum(E3);
			break;
		case E3:
			setImageNum(E4);

			break;
		case E4:
			setImageNum(E5);
			break;
		default:
			break;
		}
	}
	setImage();
}
void ENDING::setImage() {
	switch (curImageNum) {
	case E1:
		Ending.backImg = Ending.img[0];
		break;
	case E2:
		Ending.backImg = Ending.img[1];
		break;
	case E3:
		Ending.backImg = Ending.img[2];
		break;
	case E4:
		Ending.backImg = Ending.img[3];
		break;
	case E5:
		Ending.backImg = Ending.img[4];
		break;
	default :
		Ending.backImg = Ending.img[4];
		break;
	}
}
