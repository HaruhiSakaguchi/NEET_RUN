#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"BUTTON.h"
#include"STAGE.h"
#include"GAME_OVER.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {
}
GAME_OVER::~GAME_OVER() {

}
void GAME_OVER::create() {
	GameOver = game()->container()->data().gameOver;
}
void GAME_OVER::init() {
	game()->fade()->inTrigger();
}
void GAME_OVER::draw() {
	clear(GameOver.backColor);
	stroke(GameOver.backColor);
	fill(GameOver.textColor);
	textSize(GameOver.textSize);
	text(GameOver.str, GameOver.pos.x, GameOver.pos.y);

	game()->button()->rectButton(GameOver.backToTitlePos, game()->container()->data().message.buttonColor, game()->container()->data().message.textColor, GameOver.backToTitleText, GameOver.buttonNameTextSize, GameOver.charaNum);
	game()->button()->rectButton(GameOver.continuePos, game()->container()->data().message.buttonColor, game()->container()->data().message.textColor, GameOver.continueText, GameOver.buttonNameTextSize, GameOver.charaNum);
	game()->button()->drawCursor();

	game()->fade()->draw();
#ifdef _DEBUG
	textSize(30);
	fill(255, 255, 255);
	text("Zキーでタイトルに戻る　Xキーでリトライ", 30, 30);
#endif
}
void GAME_OVER::nextScene() {
	//タイトルに戻る
	if (GameOver.returnFlag == 0) {
		if (isTrigger(KEY_Z)||(game()->button()->collisionRect(GameOver.backToTitlePos, GameOver.buttonW, GameOver.buttonH)&&isTrigger(MOUSE_LBUTTON))){
			setReturnFlag(1);
		}
	}
	//リトライ
	if (GameOver.retryFlag == 0) {
		if (isTrigger(KEY_X)||(game()->button()->collisionRect(GameOver.continuePos, GameOver.buttonW, GameOver.buttonH)&&isTrigger(MOUSE_LBUTTON))) {
			setRetryFlag(1);
		}
	}
	if(GameOver.returnFlag==1||GameOver.retryFlag==1){
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		if (GameOver.returnFlag == 1) {
			game()->changeState(GAME::FIRST);
			game()->changeScene(GAME::TITLE_ID);
			setReturnFlag(0);
		}
		else if (GameOver.retryFlag == 1) {
			game()->changeScene(GAME::STAGE_ID);
			setRetryFlag(0);
		}
	}
    
}
void GAME_OVER::setRetryFlag(int flag) {
	GameOver.retryFlag = flag;
}
void GAME_OVER::setReturnFlag(int flag) {
	GameOver.returnFlag = flag;
}

