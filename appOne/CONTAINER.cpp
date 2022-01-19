#include"input.h"
#include"graphic.h"
#include"CONTAINER.h"
#include"ANIMS.h"
CONTAINER::~CONTAINER() {
	//�P�̃A�j���[�V�����̊J��
	//delete Data.explosionChara.anim;
	delete Data.batChara.anim;
	delete Data.loading.anim;
	//�����̃A�j���[�V�����̊J��
	delete Data.pumpkinChara.anims;
	delete Data.enemyChara.anims;
	delete Data.playerChara.anims;
}
void CONTAINER::load() {
	CreateData();
	LoadGraphics();
}
void CONTAINER::CreateData() {
	//���b�Z�[�W�N���X�̃f�[�^
		//�X�g�[���[�Ɏg�p����E�B���h�E�̃f�[�^
	Data.message.sw = 3;
	Data.message.textSize = 30;
	Data.message.textPosOfst.x = 50;
	Data.message.textPosOfst.y = 50;
	Data.message.winH = 195;
	Data.message.windowPos.x = width / 2;
	Data.message.windowPos.y = height - Data.message.winH - Data.message.sw + 95;
	Data.message.winW = width - Data.message.sw * 2 - 200;
	Data.message.textPos.x = Data.message.windowPos.x + Data.message.textPosOfst.x - Data.message.winW / 2;
	Data.message.textPos.y = Data.message.windowPos.y + Data.message.textPosOfst.y - Data.message.winH / 2;
	Data.message.charaNameTextSize = 50;
	Data.message.textColor = COLOR(0, 0, 0);
	Data.message.winColor = COLOR(255, 255, 255);
	Data.message.edgeColor = COLOR(0, 0, 0);

	//���ӏ����Ɏg�p����E�B���h�E�̃f�[�^
	Data.message.attentionWinPos.x = Data.message.windowPos.x;
	Data.message.attentionWinPos.y = height - Data.message.winH * 2;
	Data.message.attentionWinColor = COLOR(200, 200, 100);
	Data.message.attentionWinEdgeColor = COLOR(255, 255, 255);
	Data.message.attentionTextColor = COLOR(0, 0, 0);
	Data.message.attentionTextSize = 50;
	Data.message.attentionWinW = Data.message.winW - Data.message.attentionTextSize * 6;
	Data.message.attentionWinH = 200;
	Data.message.attentionTextPos.x = Data.message.attentionWinPos.x + Data.message.textPosOfst.x - Data.message.attentionWinW / 2;
	Data.message.attentionTextPos.y = Data.message.attentionWinPos.y + Data.message.textPosOfst.y - Data.message.attentionWinH / 3;
	Data.message.yesPos.x = Data.message.attentionTextPos.x + 100;
	Data.message.yesPos.y = Data.message.attentionTextPos.y + 50;
	Data.message.noPos.x = Data.message.yesPos.x + 200,
		Data.message.noPos.y = Data.message.yesPos.y;
	Data.message.buttonColor = COLOR(200, 200, 255);
	//���[�f�B���O�N���X�̃f�[�^
	Data.loading.goToTitleTime = 2;
	//�^�C�g���N���X�̃f�[�^
	Data.title.backColor = COLOR(0, 50, 0);
	Data.title.textColor = COLOR(0, 255, 0);
	Data.title.pos.x = 0;
	Data.title.pos.y = 400;
	Data.title.textSize = 300;
	strcpy_s(Data.title.str, "TITLE");
	Data.title.buttonPos.x = width / 2;
	Data.title.buttonPos.y = height / 2 + 100;
	Data.title.buttonRadius = 50;
	Data.title.color1 = COLOR(10, 50, 190);
	Data.title.color2 = COLOR(124, 235, 234);

	//�X�g�[���[�N���X�̃f�[�^
	Data.story.backColor = COLOR(0, 50, 0);
	Data.story.textColor = COLOR(0, 255, 0);
	Data.story.pos.x = 0;
	Data.story.pos.y = 400;
	Data.story.textSize = 300;
	strcpy_s(Data.story.str, "STORY");
	Data.story.Flag = 0;
	Data.story.text = "�X�L�b�v���܂����H ";
	Data.story.text2 = "  YES";
	Data.story.text3 = "   NO";
	Data.story.skipButtonPos.x = 750;
	Data.story.skipButtonPos.y = 30;

	//�X�e�[�W�N���X�̃f�[�^
	Data.stage.backColor;
	Data.stage.textColor = COLOR(0, 255, 0);
	Data.stage.pos.x = 900;
	Data.stage.pos.y = 30;

	Data.stage.textSize = 30;
	strcpy_s(Data.stage.str, "STAGE");
	//�X�e�[�W�N���A�N���X�̃f�[�^
	Data.stageClear.backColor = COLOR(0, 50, 0);
	Data.stageClear.textColor = COLOR(0, 255, 0);
	Data.stageClear.pos.x = 0;
	Data.stageClear.pos.y = 400;
	Data.stageClear.textSize = 190;
	strcpy_s(Data.stageClear.str, "STAGE CLEAR");
	Data.stageClear.nextPos.x = 400;
	Data.stageClear.nextPos.y = 400;
	Data.stageClear.backToTitlePos.x = Data.stageClear.nextPos.x + 250;
	Data.stageClear.backToTitlePos.y = Data.stageClear.nextPos.y;
	Data.stageClear.nextText = "    ����";
	Data.stageClear.backToTitleText = "�^�C�g���ɖ߂�";
	//�Q�[���I�[�o�[�N���X�̃f�[�^
	Data.gameOver.backColor = COLOR(0, 50, 0);
	Data.gameOver.textColor = COLOR(0, 255, 0);
	Data.gameOver.pos.x = 0;
	Data.gameOver.pos.y = 400;
	Data.gameOver.textSize = 230;
	strcpy_s(Data.gameOver.str, "GAME OVER");
	Data.gameOver.continuePos.x = 400;
	Data.gameOver.continuePos.y = 400;
	Data.gameOver.backToTitlePos.x = Data.gameOver.continuePos.x + 250;
	Data.gameOver.backToTitlePos.y = Data.gameOver.continuePos.y;
	Data.gameOver.backToTitleText = "�^�C�g���ɖ߂�";
	Data.gameOver.continueText = "  ���g���C�H";

	//�G���f�B���O�N���X�̃f�[�^
	Data.ending.backColor = COLOR(0, 50, 0);
	Data.ending.textColor = COLOR(0, 255, 0);
	Data.ending.pos.x = 0;
	Data.ending.pos.y = 400;
	Data.ending.textSize = 300;
	strcpy_s(Data.ending.str, "ENDING");
	//���b�Z�[�W�N���X�̃e�L�X�g�f�[�^
	Data.message.text = 0;
	//�X�g�[���[1�b�̃e�L�X�g
	Data.message.text1_1 = "�e�X�g���b�Z�[�W1";
	Data.message.text1_2 = "�e�X�g���b�Z�[�W2";//////////////////////////////";26�������E
	Data.message.text1_3 = "�e�X�g���b�Z�[�W3";
	Data.message.text1_4 = "�e�X�g���b�Z�[�W4";
	Data.message.text1_5 = "�e�X�g���b�Z�[�W5";
	Data.message.text1_6 = "�e�X�g���b�Z�[�W6";
	Data.message.text1_7 = "�e�X�g���b�Z�[�W7";
	Data.message.text1_8 = "";
	Data.message.text1_9 = "";
	Data.message.text1_10 = "";
	//�X�g�[���[2�b�̃e�L�X�g
	Data.message.text2_1 = "�e�X�g���b�Z�[�W8";
	Data.message.text2_2 = "�e�X�g���b�Z�[�W9";
	Data.message.text2_3 = "�e�X�g���b�Z�[�W10";
	Data.message.text2_4 = "�e�X�g���b�Z�[�W11";
	Data.message.text2_5 = "�e�X�g���b�Z�[�W12";
	Data.message.text2_6 = "";
	Data.message.text2_7 = "";
	Data.message.text2_8 = "";
	Data.message.text2_9 = "";
	Data.message.text2_10 = "";
	//�X�g�[���[3�b�̃e�L�X�g
	Data.message.text3_1 = "�e�X�g���b�Z�[�W13";
	Data.message.text3_2 = "�e�X�g���b�Z�[�W14";
	Data.message.text3_3 = "�e�X�g���b�Z�[�W15";
	Data.message.text3_4 = "�e�X�g���b�Z�[�W16";
	Data.message.text3_5 = "�e�X�g���b�Z�[�W17";
	Data.message.text3_6 = "";
	Data.message.text3_7 = "";
	Data.message.text3_8 = "";
	Data.message.text3_9 = "";
	Data.message.text3_10 = "";
	//�X�g�[���[4�b�̃e�L�X�g
	Data.message.text4_1 = "�e�X�g���b�Z�[�W18";
	Data.message.text4_2 = "�e�X�g���b�Z�[�W19";
	Data.message.text4_3 = "�e�X�g���b�Z�[�W20";
	Data.message.text4_4 = "�e�X�g���b�Z�[�W21";
	Data.message.text4_5 = "�e�X�g���b�Z�[�W22";
	Data.message.text4_6 = "";
	Data.message.text4_7 = "";
	Data.message.text4_8 = "";
	Data.message.text4_9 = "";
	Data.message.text4_10 = "";
	//�X�g�[���[5�b�̃e�L�X�g
	Data.message.text5_1 = "�e�X�g���b�Z�[�W23";
	Data.message.text5_2 = "�e�X�g���b�Z�[�W24";
	Data.message.text5_3 = "�e�X�g���b�Z�[�W25";
	Data.message.text5_4 = "�e�X�g���b�Z�[�W26";
	Data.message.text5_5 = "�e�X�g���b�Z�[�W27";
	Data.message.text5_6 = "";
	Data.message.text5_7 = "";
	Data.message.text5_8 = "";
	Data.message.text5_9 = "";
	Data.message.text5_10 = "";
	//�L������
	Data.message.chara1 = "���u1";
	Data.message.chara2 = "���u2";
	//�X�e�[�g�����ɐi�߂邽�߂̋�̃e�L�X�g
	Data.message.text_Last = "����";
	//�v���C���[�N���X�̃f�[�^
	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 1;
	Data.playerChara.groupId = 0;//�����O���[�v��0
	//Data.playerChara.speed = 3.4f * 60;
	Data.playerChara.offsetLeft = 10.0f;
	Data.playerChara.offsetTop = 1.0f;
	Data.playerChara.offsetRight = 40.0f;
	Data.playerChara.offsetBottom = 49.0f;
	Data.player.jumpFlag = 0;
	Data.player.initVecUp = -16.0f;
	Data.player.initVecDown = 3.0f;
	Data.player.charaDamage = 0;
	Data.player.gravity = 48;

	Data.player.damageTime = 0;
	Data.player.damageInterval = 5 * 0.016f;
	Data.player.color = Data.player.normalColor;

	Data.player.damageColor = COLOR(255, 0, 0, 25);
	Data.player.normalColor = COLOR(255, 255, 255);

	//�v���C���[�N���X�̃f�[�^
	Data.enemyChara.charaId = MAP::ENEMY_ID;
	Data.enemyChara.hp = 1;
	Data.enemyChara.groupId = 1;//�����O���[�v��0
	//Data.enemyChara.speed = 3.4f * 60;
	Data.enemyChara.offsetLeft = 10.0f;
	Data.enemyChara.offsetTop = 1.0f;
	Data.enemyChara.offsetRight = 40.0f;
	Data.enemyChara.offsetBottom = 49.0f;
	Data.enemy.jumpFlag = 0;
	Data.enemy.initVecUp = -16.0f;
	Data.enemy.initVecDown = 3.0f;
	Data.enemy.charaDamage = 0;
	Data.enemy.gravity = 48;
	Data.enemy.bulletOffsetX = 20.0f;

	Data.enemy.damageTime = 0;
	Data.enemy.damageInterval = 5 * 0.016f;
	Data.enemy.color = Data.enemy.normalColor;

	
	Data.enemyChara.color = COLOR(0, 0, 0);

	Data.enemy.elapsedTime = 0;
	Data.enemy.interval = 0.016f;
	Data.enemy.triggerCnt = 100;
	Data.enemy.triggerInterval = 400;
	Data.enemy.trigger1st = 220;
	Data.enemy.trigger2nd = 270;
	Data.enemy.trigger3rd = 380;
	Data.enemy.trigger4th = 400;
	Data.enemy.bulletCharaId = MAP::ENEMY_BULLET_ID;

	Data.enemyBulletChara.charaId = MAP::ENEMY_BULLET_ID;
	

	
	Data.enemyBulletChara.groupId = 1;//�G�O���[�v��1
	Data.enemyBulletChara.hp = 1;
	Data.enemyBulletChara.speed = 7.5f * 60;
	Data.enemyBulletChara.offsetLeft = 10.0f;
	Data.enemyBulletChara.offsetTop = 12.0f;
	Data.enemyBulletChara.offsetRight = 40.0f;
	Data.enemyBulletChara.offsetBottom = 40.0f;
	Data.enemyBullet.rightAnimId = 0;
	Data.enemyBullet.leftAnimId = 1;
	Data.enemyBullet.damageInterval = 5 * 0.016f;
	Data.enemyBullet.initVecX = 1;
	Data.enemyBullet.initVecY = 0;
	Data.enemyBullet.gravity = 0.8f * 60;
	Data.enemyBullet.alphaLowVal = 25;
	Data.enemyBullet.damageColor = COLOR(255, 0, 0);
	

	Data.batChara.charaId = MAP::BAT_ID;
	Data.batChara.hp = 1;
	Data.batChara.groupId = 2;//�G�O���[�v��1
	Data.batChara.offsetLeft = 10.0f;
	Data.batChara.offsetTop = 10.0f;
	Data.batChara.offsetRight = 30.0f;
	Data.batChara.offsetBottom = 35.0f;
	Data.bat.elapsedTime = 0;
	Data.bat.interval = 0.016f;
	Data.bat.triggerCnt = 60;
	Data.bat.triggerInterval = 240;
	Data.bat.trigger1st = 220;
	Data.bat.trigger2nd = 225;
	Data.bat.trigger3rd = 230;
	Data.bat.trigger4th = 235;
	Data.bat.bulletCharaId = MAP::BAT_BULLET_ID;
	Data.bat.damageTime = 0;
	Data.bat.damageInterval = 5 * 0.016f;
	Data.bat.bulletOffsetX = 20.0f;
	Data.bat.damageColor = COLOR(255, 0, 0, 25);
	Data.bat.normalColor = COLOR(255, 255, 255);

	Data.batBulletChara.charaId = MAP::BAT_BULLET_ID;
	Data.batBulletChara.groupId = 2;//�G�O���[�v��1
	Data.batBulletChara.hp = 1;
	Data.batBulletChara.speed = 4.7f * 60;
	Data.batBulletChara.offsetLeft = 20.0f;
	Data.batBulletChara.offsetTop = 20.0f;
	Data.batBulletChara.offsetRight = 30.0f;
	Data.batBulletChara.offsetBottom = 30.0f;

	
	Data.charaMng.numPlayers = 1;
	Data.charaMng.numEnemies = 1;
	Data.charaMng.numBats = 5;
	Data.charaMng.numBatBullets = 12;
	Data.charaMng.numEnemyBullets = 12;

	//�t�F�[�h�N���X�̃f�[�^
	Data.fade.color = COLOR(60, 60, 60);
	Data.fade.speed = 255 * 2;
	//�{�^���N���X�̃f�[�^
	Data.button.radius = 5;
	//�}�b�v�N���X�̃f�[�^
	Data.map.fileName = 0;
	Data.map.fileName1 = "assets\\map1.txt";
	Data.map.fileName2 = "assets\\map2.txt";
	Data.map.fileName3 = "assets\\map3.txt";
	Data.map.fileName4 = "assets\\map4.txt";
	Data.map.fileName5 = "assets\\map5.txt";

	Data.map.chipSize = 50;
	Data.map.centerX = width / 2 - Data.map.chipSize / 2;
}
void CONTAINER::LoadGraphics() {
	Data.title.image = loadImage("assets\\startImg.png");
	Data.title.image2 = loadImage("assets\\startButton.png");

	Data.stage.backImg = loadImage("assets\\backImg.png");
	Data.stage.stageClearImg = loadImage("assets\\StageClear.png");
	Data.stage.gameOverImg = loadImage("assets\\GameOver.png");

	Data.map.blockImg = loadImage("assets\\block.png");
	Data.map.goalImg = loadImage("assets\\goal.png");


	Data.enemyBulletChara.img = loadImage("assets\\pumpkin\\1\\pumpkinL01.png");

	Data.batChara.img = loadImage("assets\\bat\\0\\bat01.png");
	Data.batBulletChara.img = loadImage("assets\\batBullet.png");

	//ANIMS �����̃A�j���[�V�����Z�b�g
	Data.loading.anim = new ANIM("assets\\loading\\load");
	Data.loading.anim->noLoop();
	
	Data.loading.animData.interval = 0.1f;

	Data.playerChara.anims = new ANIMS("assets\\player");
	Data.playerChara.animData.interval = 0.1f;

	Data.enemyChara.anims = new ANIMS("assets\\player");
	Data.enemyChara.animData.interval = 0.1f;

	
}
