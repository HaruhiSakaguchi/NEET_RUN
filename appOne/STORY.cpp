#include"STORY.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"MESSAGE.h"
#include"BUTTON.h"
#include"libOne.h"
STORY::STORY(class GAME* game) :
	SCENE(game) {
}
STORY::~STORY() {

}
void STORY::init() {
	game()->fade()->inTrigger();
}
void STORY::create() {
	Story = game()->container()->data().story;
}
void STORY::draw() {
	clear(Story.backColor);

#ifdef _DEBUG
	int i = 0;
	if (game()->curStateId() == GAME::FIRST) {
		i = 1;
	}
	else if (game()->curStateId() == GAME::SECOND) {
		i = 2;
	}
	else if (game()->curStateId() == GAME::THIRD) i = 3;
	else if (game()->curStateId() == GAME::FOURTH)i = 4;
	else if (game()->curStateId() == GAME::END)i = 5;
	fill(Story.textColor);
	textSize(Story.textSize);
	text(i, 750, 400);
	fill(255, 255, 255);
	textSize(30);
	text("SPACE�Ői�s �e�L�X�g��\�����I������X�e�[�W�ց@Z�L�[�ŃX�L�b�v", 30, 30);
#endif

	stroke(Story.backColor);
	textSize(Story.textSize);
	fill(Story.textColor);
	text(Story.str, Story.pos.x, Story.pos.y);

	game()->button()->rectButton(Story.skipButtonPos, game()->container()->data().message.buttonColor,
		game()->container()->data().message.textColor, Story.skipText, Story.skipTextSize, Story.skipCharaNum);
	game()->message()->draw();

	if (Story.Flag == 1) {
		game()->message()->AttentionWindow(Story.text, Story.text2, Story.text3);
	}

	game()->button()->drawCursor();
	game()->fade()->draw();
}
void STORY::nextScene() {
	if (game()->curTextId() == GAME::text_Last) {
		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			if (game()->curStateId() == GAME::FIRST ||
				game()->curStateId() == GAME::SECOND ||
				game()->curStateId() == GAME::THIRD ||
				game()->curStateId() == GAME::FOURTH
				) {
				game()->changeScene(GAME::STAGE_ID);
				game()->message()->init();
			}
			else if (game()->curStateId() == GAME::END)
				game()->changeScene(GAME::ENDING_ID);
		}
	}


	if (Story.Flag == 0 && ((isTrigger(KEY_Z) || isTrigger(MOUSE_RBUTTON)) ||
		(game()->button()->collisionRect(Story.skipButtonPos, Story.skipButtonW, Story.skipButtonH) && isTrigger(MOUSE_LBUTTON)))) {
		setAttentinonFlag(1);
	}
	else {
		if (
			(Story.Flag == 1) &&
			(
				isTrigger(KEY_Z) ||
				(
					(
						game()->button()->collisionRect
						(
							game()->container()->data().message.noPos, game()->container()->data().message.buttonW, game()->container()->data().message.buttonH
						) && isTrigger(MOUSE_LBUTTON))
					)
				)
			)
		{
			setAttentinonFlag(0);
		}
	}

	if (Story.Flag == 1) {
		if (isTrigger(KEY_SPACE) ||
			(
				game()->button()->collisionRect
				(
					game()->container()->data().message.yesPos, game()->container()->data().message.buttonW, game()->container()->data().message.buttonH
				) && isTrigger(MOUSE_LBUTTON))
			)
		{
			game()->fade()->outTrigger();
			setAttentinonFlag(0);
		}
	}

	if (game()->fade()->outEndFlag()) {
		if (game()->curStateId() == GAME::FIRST ||
			game()->curStateId() == GAME::SECOND ||
			game()->curStateId() == GAME::THIRD ||
			game()->curStateId() == GAME::FOURTH
			) {
			game()->changeScene(GAME::STAGE_ID);
			game()->message()->init();
		}
		else if (game()->curStateId() == GAME::END)
			game()->changeScene(GAME::ENDING_ID);
	}
}
void STORY::setAttentinonFlag(int flag) {
	Story.Flag = flag;
}
void STORY::update() {
	if (Story.Flag == 0) {
		if (game()->button()->collisionRect(Story.skipButtonPos, Story.skipButtonW, Story.skipButtonH)) {}
		else {
			game()->message()->nextText();
		}
	}
}

