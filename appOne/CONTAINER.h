#pragma once
#include"LOADING.h"
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
#include"CHARACTER_MANAGER.h"
class CONTAINER
{
private:
	struct ALL_DATA {
		//シーン
		LOADING::DATA loading;
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
		//キャラクターの実体
		PLAYER::DATA player;
		PUMPKIN::DATA pumpkin;
		BAT::DATA bat;
		BAT_BULLET::DATA batBullet;
		EXPLOSION::DATA explosion;
		//キャラクタークラス用
		CHARACTER::DATA playerChara;
		CHARACTER::DATA pumpkinChara;
		CHARACTER::DATA batChara;
		CHARACTER::DATA batBulletChara;
		CHARACTER::DATA explosionChara;
		//キャラクターマネージャー
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


