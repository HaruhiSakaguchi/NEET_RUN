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

#ifdef _DEBUG
	fill(255, 255, 255);
	textSize(30);
	//text("SPACE‚Åis", 30, 30);
	game()->button()->selectButton(1, Title.buttonPos, Title.buttonRadius, Title.color1, Title.color2, Title.text1, Title.buttonNameTextSize, Title.charaNum);
#endif
	game()->button()->drawCursor();
	game()->fade()->draw();

}
void TITLE::nextScene() {
	if(Title.flag==0){
		if ((game()->button()->collisionRect(Title.buttonPos, Title.buttonW, Title.buttonH)
			&& isTrigger(MOUSE_LBUTTON))||(isTrigger(KEY_SPACE))){
			setFlag(1);
		}
	}
	else if(Title.flag==1)
		game()->fade()->outTrigger();
	if (game()->fade()->outEndFlag()) {
		game()->changeScene(GAME::STORY_ID);
		setFlag(0);
	}
}
void TITLE::setFlag(int flag) {
	Title.flag = flag;
}