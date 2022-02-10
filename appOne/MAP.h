#pragma once
#include"GAME_OBJECT.h"
class MAP :
	public GAME_OBJECT
{
public:
	struct DATA {
		const char* fileName = 0;
		const char* fileName1 = 0;
		const char* fileName2 = 0;
		const char* fileName3 = 0;
		const char* fileName4 = 0;
		const char* fileName5 = 0;

		float scale = 1;
		float angle = 0;
		int blockImg = 0;
		int poleImg = 0;
		int chipSize = 0; //�����`�}�b�v�`�b�v�摜�̈�ӂ̃h�b�g��
		char* data = 0; //�f�[�^�z��̃|�C���^
		int cols = 0; //�f�[�^�̗�
		int rows = 0; //�f�[�^�̍s��
		int dispCols = 0;
		int dispRows = 0;
		float wx = 0;//world position x
		float wy = 0;//world position y
		float worldWidth = 0;
		float worldHeight = 0;
		float endWorldX = 0;
		float endWorldY = 0;
		float centerX = 0;
	};
	enum CHARA_ID {
		PLAYER_ID = 'a',
		PLAYER_BULLET_ID = 'b',
		ENEMY_BULLET_ID = 'c',
		CAT_ID = 'd',
		BAT_BULLET_ID = 'e',
		MANHOLE_ID = 'f',
		ENEMY_ID = 'g',
		COKE_ID = 'h',
		TIPS_ID = 'i',
		RAMEN_ID = 'j',
		BEAR_ID = 'k',
		EBIFURAI_ID = 'l',
		RYMAN_ID = 'm',
	};
private:
	DATA Map;
public:
	MAP(class GAME* game);
	~MAP();
	void create();
	void init();
	void update();
	void draw();
	float wx() { return Map.wx; }
	float wy() { return Map.wy; }
	int chipSize() { return Map.chipSize; }
	//�}�b�v�`�b�v�ƃL�����̓����蔻��Ɏg�p����֐��Q---------------------------------------
	bool collisionCheck(float wx, float wy);//���̓����蔻��֐��Q����Ăяo���Ďg���֐�
	bool collisionCharaLeft(float wx, float wy);
	bool collisionCharaRight(float wx, float wy);
	bool collisionCharaTop(float wx, float wy);
	bool collisionCharaBottom(float wx, float wy);
	bool collisionCharaRect(float wLeft, float wTop, float wRight, float wBottom);//�e�p
	//�E�B���h�E�g����݂̂͂�������p---------------------------------------------------
	float wDispLeft();
	float wDispRight();

	float scale() { return Map.scale; }
};

