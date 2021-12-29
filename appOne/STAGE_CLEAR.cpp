//#include"libOne.h"
#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"BUTTON.h"
#include "STAGE_CLEAR.h"
STAGE_CLEAR::STAGE_CLEAR(class GAME* game) :
	SCENE(game) {
}
STAGE_CLEAR::~STAGE_CLEAR() {

}
void STAGE_CLEAR::create() {
	StageClear = game()->container()->data().stageClear;
}
void STAGE_CLEAR::init() {
	game()->fade()->inTrigger();
}
void STAGE_CLEAR::draw() {
	stroke(StageClear.backColor);
	noStroke();
	clear(StageClear.backColor);
	fill(StageClear.textColor);
	textSize(StageClear.textSize);
	text(StageClear.str, StageClear.pos.x, StageClear.pos.y);

#ifdef _DEBUG
	textSize(30);
	fill(255, 255, 255);
	text("SPACEキーで進行", 30, 30);
#endif
	game()->button()->rectButton(StageClear.backToTitlePos, game()->container()->data().message.buttonColor, game()->container()->data().message.textColor, StageClear.backToTitleText, StageClear.buttonNameTextSize, StageClear.charaNum);
	game()->button()->rectButton(StageClear.nextPos, game()->container()->data().message.buttonColor, game()->container()->data().message.textColor, StageClear.nextText, StageClear.buttonNameTextSize, StageClear.charaNum);

	game()->button()->drawCursor();
	game()->fade()->draw();
}
void STAGE_CLEAR::nextScene() {
	if (isTrigger(KEY_SPACE) || (isTrigger(MOUSE_LBUTTON) && game()->button()->collisionRect(StageClear.nextPos, StageClear.buttonW, StageClear.buttonH))) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag() && game()->button()->collisionRect(StageClear.nextPos, StageClear.buttonW, StageClear.buttonH)) {
		switch (game()->curStateId()) {
		case GAME::FIRST:
			game()->changeState(GAME::SECOND);
			break;
		case GAME::SECOND:
			game()->changeState(GAME::THIRD);
			break;
		case GAME::THIRD:
			game()->changeState(GAME::FOURTH);
			break;
		case GAME::FOURTH:
			game()->changeState(GAME::END);
			break;
		}
		game()->changeScene(GAME::STORY_ID);
	}
	if (game()->button()->collisionRect(StageClear.backToTitlePos, StageClear.buttonW, StageClear.buttonH)) {
		if (isTrigger(MOUSE_LBUTTON)) {
			game()->fade()->outTrigger();
		}
	    if (game()->fade()->outEndFlag()) {
		    game()->changeScene(GAME::TITLE_ID);
	    }
	}
}
