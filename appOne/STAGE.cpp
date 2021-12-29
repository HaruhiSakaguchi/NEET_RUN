#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"MAP.h"
#include"CHARACTER_MANAGER.h"
#include"PLAYER.h"
#include"STAGE.h"

void STAGE::create() {
	Stage = game()->container()->data().stage;
}
void STAGE::init() {
	game()->map()->init();
	game()->characterManager()->init();
	game()->fade()->inTrigger();
}
void STAGE::update() {
	game()->characterManager()->update();
	game()->map()->update();

	if (isTrigger(KEY_Z)) {
		setHp(1);
	}
	else if (isTrigger(KEY_X)) {
		setHp(0);
	}

}
void STAGE::draw() {
	backGround();
	game()->map()->draw();
	fill(Stage.textColor);
	textSize(Stage.textSize);
	text(Stage.str, Stage.pos.x, Stage.pos.y);


#ifdef _DEBUG
	int stageNum = 0;
	if (game()->curStateId() == GAME::FIRST) {
		stageNum = 1;
	}
	else if (game()->curStateId() == GAME::SECOND) {
		stageNum = 2;
	}
	else if (game()->curStateId() == GAME::THIRD) stageNum = 3;
	else if (game()->curStateId() == GAME::FOURTH)stageNum = 4;
	else if (game()->curStateId() == GAME::END)stageNum = 5;

	fill(Stage.textColor);
	textSize(Stage.textSize);
	text(stageNum, 750, 400);
	textSize(30);
	text("hp=", 0, 30);
	text(Stage.charaHp, 60, 30);
	fill(255, 255, 255);

	text("ZキーでHPを１に、XキーでHPを０に", 90, 30);
	text("SPACEキーで進行　HP１以上でステージクリア、HP０でゲームオーバー", 90, 60);

#endif
	game()->characterManager()->draw();
	game()->fade()->draw();
}
void STAGE::setHp(int setHp) {
	Stage.charaHp = setHp;
}
void STAGE::backGround() {
	clear();
	rectMode(CORNER);
	//imageColor(Stage.backColor);
	image(Stage.backImg, 0, 0);

}
void STAGE::logo(int img, const COLOR& color) {

}
void STAGE::nextScene() {
	if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag() && Stage.charaHp == 1) {
		game()->changeScene(GAME::STAGE_CLEAR_ID);
	}
	else if (game()->fade()->outEndFlag() && Stage.charaHp == 0) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
	if (game()->curStateId() == GAME::END) {
		game()->changeScene(GAME::STORY_ID);
	}
}
