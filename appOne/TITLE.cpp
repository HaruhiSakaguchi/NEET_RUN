#include"GAME.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"graphic.h"
#include"input.h"
#include"STAGE.h"
#include"BUTTON.h"
#include"TITLE.h"
TITLE::TITLE(class GAME* game) :
	SCENE(game) {

}
TITLE::~TITLE() {

}
void TITLE::create() {
	Title = game()->container()->data().title;
}
void TITLE::init() {
	game()->fade()->inTrigger();
}
void TITLE::draw() {
	clear();
	game()->button()->selectButton(1, Title.buttonPos, Title.buttonRadius, Title.color1, Title.color2, Title.text1, Title.buttonNameTextSize, Title.charaNum);
	COLOR color;
	COLOR normalColor;
	COLOR collisionColor(200, 200, 200, 128);
	rectMode(CORNER);
	imageColor(normalColor);
	image(Title.image, 0, 0);
	rectMode(CENTER);
	if (game()->button()->collisionRect(Title.buttonPos, Title.buttonW, Title.buttonH)) {
		color = collisionColor;
	}
	else {
		color = normalColor;
	}
	imageColor(normalColor);

	image(Title.image2, Title.buttonPos.x, Title.buttonPos.y);

	imageColor(color);
	image(Title.image2, Title.buttonPos.x, Title.buttonPos.y);

	textSize(30);
	fill(200, 126, 44);
	text(Title.chapter, width-100, height-50);

#ifdef _DEBUG
	fill(255, 255, 255);
	textSize(30);
	//text("SPACE?Ői?s", 30, 30);
#endif
	game()->button()->drawCursor();
	game()->fade()->draw();

}
void TITLE::update() {
	chapter();

}
void TITLE::nextScene() {
	if(Title.flag==0){
		if ((game()->button()->collisionRect(Title.buttonPos, Title.buttonW, Title.buttonH)
			&& isTrigger(MOUSE_LBUTTON))||(isTrigger(KEY_SPACE))){
			setFlag(1);
		}
	}
	else if(Title.flag == 1){
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
	switch (Title.chapter) {
	case 1:
		game()->changeState(GAME::FIRST);
		break;
	case 2:
		game()->changeState(GAME::SECOND);
		break;
	case 3:
		game()->changeState(GAME::THIRD);
		break;
	case 4:
		game()->changeState(GAME::FOURTH);
		break;
	case 5:
		game()->changeState(GAME::FIFTH);
		break;
	}
		game()->changeScene(GAME::STORY_ID);
		setFlag(0);
	}
}
void TITLE::chapter() {
	if (isTrigger(KEY_Z)) {
		setChapter(1);
	}
	if (isTrigger(KEY_X)) {
		setChapter(2);
	}
	if (isTrigger(KEY_C)) {
		setChapter(3);
	}
	if (isTrigger(KEY_V)) {
		setChapter(4);
	}
	if (isTrigger(KEY_B)) {
		setChapter(5);
	}
}
void TITLE::setFlag(int flag) {
	Title.flag = flag;
}
void TITLE::setChapter(int chapter) {
	Title.chapter = chapter;
}