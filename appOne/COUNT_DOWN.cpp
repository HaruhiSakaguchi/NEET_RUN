#include"CONTAINER.h"
#include"GAME.h"
#include"FADE.h"
#include"input.h"
#include"graphic.h"
#include"window.h"
#include "COUNT_DOWN.h"
void COUNT_DOWN::create() {
	CD = game()->container()->data().cd;
}
void COUNT_DOWN::init() {
	setCount(CD.maxCount);
	game()->fade()->inTrigger();
}
void COUNT_DOWN::update() {
	CD.count -= delta;
}
void COUNT_DOWN::draw() {
	rectMode(CORNER);
	image(CD.image, 0, 0);
	textSize(CD.textSize);
	text(CD.count/10, width / 2, height / 2);
	game()->fade()->draw();
}
void COUNT_DOWN::nextScene() {
	if (CD.count <= 0) {
		game()->fade()->outTrigger();
	}
	if(game()->fade()->outEndFlag()){
		game()->changeScene(GAME::STAGE_ID);
	}
}
void COUNT_DOWN::setCount(int count) {
	CD.count = count;
}

