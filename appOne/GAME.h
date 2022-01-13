#pragma once
#include"input.h"
class GAME
{
private:
	class CONTAINER* Container = 0;
public:
	class CONTAINER* container() { return Container; }
public:
	enum SCENE_ID {
		LOADING_ID,
		TITLE_ID,
		STORY_ID,
		STAGE_ID,
		STAGE_CLEAR_ID,
		GAME_OVER_ID,
		ENDING_ID,
		NUM_SCENES
	};
	enum STATE_ID {
		FIRST,
		SECOND,
		THIRD,
		FOURTH,
		END,
		NUM_STATES
	};
	enum TEXT_ID {
		text_1,
		text_2,
		text_3,
		text_4,
		text_5,
		text_6,
		text_7,
		text_8,
		text_9,
		text_10,
		text_Last,
		NUM_TEXTS
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId = LOADING_ID;

	class SCENE* CurScene = nullptr;
	class FADE* Fade = nullptr;
	class MESSAGE* Message;
	class HP_GAUGE* HpGauge;
	class BUTTON* Button;
	class MAP* Map = nullptr;
	class LOADING* Loading = nullptr;
	STATE_ID CurStateId = FIRST;
	TEXT_ID CurTextId = text_1;
	class CHARACTER_MANAGER* CharacterManager = nullptr;
public:
	class MAP* map() { return Map; }
	class FADE* fade() { return Fade; }
	class CHARACTER_MANAGER* characterManager() { return CharacterManager; }
	class HP_GAUGE* hpGauge() { return HpGauge; }
	class MESSAGE* message() { return Message; }
	class BUTTON* button() { return Button; }
	class LOADING* loading() { return Loading; }
public:
	void changeScene(SCENE_ID sceneId);
	void changeState(STATE_ID stateId);
	void changeText(TEXT_ID textId);
	SCENE_ID curSceneId() { return CurSceneId; }
	STATE_ID curStateId() { return CurStateId; }
	TEXT_ID curTextId() { return CurTextId; }
//ゲームマネージャー
public:
	GAME();
	~GAME();
	void run();
};

