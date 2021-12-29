#pragma once
#include"TITLE.h"
#include"STORY.h"
#include"STAGE.h"
#include"STAGE_CLEAR.h"
#include"GAME_OVER.h"
#include"ENDING.h"
#include"MAP.h"
#include"FADE.h"
#include"HP_GAUGE.h"
#include"MESSAGE.h"
#include"BUTTON.h"
#include"PLAYER.h"
#include"PUMPKIN.h"
#include"BAT.h"
#include"BAT_BULLET.h"
#include"EXPLOSION.h"
#include"LOADING.h"
#include"CHARACTER_MANAGER.h"
class CONTAINER
{
private:
	struct ALL_DATA {
		TITLE::DATA title;
		STORY::DATA story;
		STAGE::DATA stage;
		STAGE_CLEAR::DATA stageClear;
		GAME_OVER::DATA gameOver;
		ENDING::DATA ending;
		FADE::DATA fade;
		MAP::DATA map;
		HP_GAUGE::DATA hpGauge;
		MESSAGE::DATA message;
		BUTTON::DATA button;
		CHARACTER::DATA playerChara;
		PLAYER::DATA player;
		CHARACTER::DATA pumpkinChara;
		PUMPKIN::DATA pumpkin;
		CHARACTER::DATA batChara;
		BAT::DATA bat;
		CHARACTER::DATA batBulletChara;
		BAT_BULLET::DATA batBullet;
		CHARACTER::DATA explosionChara;
		EXPLOSION::DATA explosion;
		LOADING::DATA loading;
		CHARACTER_MANAGER::DATA charaMng;

	};
	ALL_DATA Data;
	void CreateData();
	void LoadGraphics();
public:
	~CONTAINER();
	void load();
	const ALL_DATA& data() { return Data; }
};


