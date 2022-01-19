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
	text("SPACEキーで進行　Zキーでタイトルに戻る", 30, 30);
#endif
	game()->button()->rectButton(StageClear.backToTitlePos, game()->container()->data().message.buttonColor, game()->container()->data().message.textColor, StageClear.backToTitleText, StageClear.buttonNameTextSize, StageClear.charaNum);
	game()->button()->rectButton(StageClear.nextPos, game()->container()->data().message.buttonColor, game()->container()->data().message.textColor, StageClear.nextText, StageClear.buttonNameTextSize, StageClear.charaNum);

	game()->button()->drawCursor();
	game()->fade()->draw();
}
void STAGE_CLEAR::nextScene() {
	if (StageClear.goFlag == 0) {
		if (isTrigger(KEY_SPACE) || (isTrigger(MOUSE_LBUTTON) && game()->button()->collisionRect(StageClear.nextPos, StageClear.buttonW, StageClear.buttonH))) {
			setGoFlag(1);
		}
	}
	if(StageClear.returnFlag==0){
		if (isTrigger(KEY_Z)||(game()->button()->collisionRect(StageClear.backToTitlePos, StageClear.buttonW, StageClear.buttonH)&&isTrigger(MOUSE_LBUTTON))) {
			setReturnFlag(1);
		}
	}
	if (StageClear.goFlag == 1|| StageClear.returnFlag == 1) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		if (StageClear.goFlag == 1) {
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
				game()->changeState(GAME::FIFTH);
				break;
			case GAME::FIFTH:
				game()->changeState(GAME::END);
				break;
			}

			game()->changeScene(GAME::STORY_ID);
			setGoFlag(0);
		}
		else if (StageClear.returnFlag == 1) {
		 game()->changeScene(GAME::TITLE_ID);
		 setReturnFlag(0);
		}
	
	}
}
void STAGE_CLEAR::setGoFlag(int flag) {
	StageClear.goFlag = flag;
}
void STAGE_CLEAR::setReturnFlag(int flag) {
	StageClear.returnFlag = flag;
}
