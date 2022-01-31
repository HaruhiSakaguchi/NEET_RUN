#include"input.h"
#include"graphic.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"ANIMS.h"
CONTAINER::~CONTAINER() {
	//�P�̃A�j���[�V�����̊J��
	//delete Data.explosionChara.anim;
	delete Data.catChara.anim;
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

	Data.message.textLast_1 = "�e�X�g���b�Z�[�W28";
	Data.message.textLast_2 = "�e�X�g���b�Z�[�W29";
	Data.message.textLast_3 = "�e�X�g���b�Z�[�W30";
	Data.message.textLast_4 = "�e�X�g���b�Z�[�W31";
	Data.message.textLast_5 = "�e�X�g���b�Z�[�W32";
	Data.message.textLast_6 = "";
	Data.message.textLast_7 = "";
	Data.message.textLast_8 = "";
	Data.message.textLast_9 = "";
	Data.message.textLast_10 = "";
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
	Data.playerChara.offsetLeft = 10.0f * Data.map.scale;
	Data.playerChara.offsetTop = 1.0f * Data.map.scale;
	Data.playerChara.offsetRight = 40.0f * Data.map.scale;
	Data.playerChara.offsetBottom = 49.0f * Data.map.scale;
	Data.playerChara.maxStamina = 100;
	Data.playerChara.stamina = 0;
	Data.player.maxStamina = Data.playerChara.maxStamina;
	Data.player.jumpFlag = 0;
	Data.player.initVecUp = -16.0f * Data.map.scale;
	Data.player.initVecDown = 3.0f * Data.map.scale;
	Data.player.gravity = 48;

	Data.playerChara.knockBackVx = 100;
	Data.playerChara.knockBackVy = 100;

	Data.playerChara.damageTime = 0;
	Data.playerChara.damageInterval = 5 * 0.016f;
	Data.player.color = Data.player.normalColor;

	Data.player.damageColor = COLOR(255, 0, 0, 25);
	Data.player.normalColor = COLOR(255, 255, 255);

	//�v���C���[�N���X�̃f�[�^
	Data.enemyChara.charaId = MAP::ENEMY_ID;
	Data.enemyChara.hp = 1;
	Data.enemyChara.groupId = 1;//�����O���[�v��0
	//Data.enemyChara.speed = 3.4f * 60;
	Data.enemyChara.offsetLeft = 10.0f * Data.map.scale;
	Data.enemyChara.offsetTop = 1.0f * Data.map.scale;
	Data.enemyChara.offsetRight = 40.0f * Data.map.scale;
	Data.enemyChara.offsetBottom = 49.0f * Data.map.scale;
	Data.enemy.jumpFlag = 0;
	Data.enemy.initVecUp = -16.0f * Data.map.scale;
	Data.enemy.initVecDown = 3.0f * Data.map.scale;
	Data.enemy.charaDamage = 0;
	Data.enemy.gravity = 48;
	Data.enemy.bulletOffsetX = 20.0f * Data.map.scale;
	Data.enemyChara.maxStamina = 100;
	Data.enemyChara.stamina = 0;
	Data.enemy.maxStamina = Data.playerChara.maxStamina;

	Data.enemyChara.damageTime = 0;
	Data.enemyChara.damageInterval = 5 * 0.016f;
	Data.enemy.color = Data.enemy.normalColor;

	Data.enemyChara.knockBackVx = -100;
	Data.enemyChara.knockBackVy = 100;
	
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
	Data.enemyBulletChara.offsetLeft = 10.0f * Data.map.scale;
	Data.enemyBulletChara.offsetTop = 12.0f * Data.map.scale;
	Data.enemyBulletChara.offsetRight = 40.0f * Data.map.scale;
	Data.enemyBulletChara.offsetBottom = 40.0f * Data.map.scale;
	Data.enemyBullet.rightAnimId = 0;
	Data.enemyBullet.leftAnimId = 1;
	Data.enemyBullet.damageInterval = 5 * 0.016f;
	Data.enemyBullet.initVecX = 1;
	Data.enemyBullet.initVecY = 0;
	Data.enemyBullet.gravity = 0.8f * 60;
	Data.enemyBullet.alphaLowVal = 25;
	Data.enemyBullet.damageColor = COLOR(255, 0, 0);
	

	Data.catChara.charaId = MAP::CAT_ID;
	Data.catChara.hp = 1;
	Data.catChara.groupId = 2;//�G�O���[�v��1
	Data.catChara.offsetLeft = 10.0f * Data.map.scale;
	Data.catChara.offsetTop = 10.0f * Data.map.scale;
	Data.catChara.offsetRight = 30.0f * Data.map.scale;
	Data.catChara.offsetBottom = 35.0f * Data.map.scale;
	Data.catChara.speed = -3.4f * 60;

	Data.cokeChara.charaId = MAP::COKE_ID;
	Data.cokeChara.hp = 1;
	Data.cokeChara.groupId = 2;
	Data.cokeChara.offsetLeft = 20.0f * Data.map.scale;
	Data.cokeChara.offsetTop = 20.0f * Data.map.scale;
	Data.cokeChara.offsetRight = 30.0f * Data.map.scale;
	Data.cokeChara.offsetBottom = 30.0f * Data.map.scale;

	Data.tipsChara.charaId = MAP::TIPS_ID;
	Data.tipsChara.hp = 1;
	Data.tipsChara.groupId = 2;
	Data.tipsChara.offsetLeft = 20.0f * Data.map.scale;
	Data.tipsChara.offsetTop = 20.0f * Data.map.scale;
	Data.tipsChara.offsetRight = 30.0f * Data.map.scale;
	Data.tipsChara.offsetBottom = 30.0f * Data.map.scale;

	Data.ramenChara.charaId = MAP::RAMEN_ID;
	Data.ramenChara.hp = 1;
	Data.ramenChara.groupId = 2;
	Data.ramenChara.offsetLeft = 20.0f * Data.map.scale;
	Data.ramenChara.offsetTop = 20.0f * Data.map.scale;
	Data.ramenChara.offsetRight = 30.0f * Data.map.scale;
	Data.ramenChara.offsetBottom = 30.0f * Data.map.scale;

	Data.bearChara.charaId = MAP::BEAR_ID;
	Data.bearChara.hp = 1;
	Data.bearChara.groupId = 2;
	Data.bearChara.offsetLeft = 20.0f * Data.map.scale;
	Data.bearChara.offsetTop = 20.0f * Data.map.scale;
	Data.bearChara.offsetRight = 30.0f * Data.map.scale;
	Data.bearChara.offsetBottom = 30.0f * Data.map.scale;

	Data.batBulletChara.charaId = MAP::BAT_BULLET_ID;
	Data.batBulletChara.groupId = 2;//�G�O���[�v��1
	Data.batBulletChara.hp = 1;
	Data.batBulletChara.speed = 4.7f * 60;
	Data.batBulletChara.offsetLeft = 20.0f * Data.map.scale;
	Data.batBulletChara.offsetTop = 20.0f * Data.map.scale;
	Data.batBulletChara.offsetRight = 30.0f * Data.map.scale;
	Data.batBulletChara.offsetBottom = 30.0f * Data.map.scale;

	Data.holeChara.charaId = MAP::MANHOLE_ID;
	Data.holeChara.groupId = 1;//�G�O���[�v��1
	Data.holeChara.hp = 1;
	Data.holeChara.offsetLeft = 20.0f * Data.map.scale;
	Data.holeChara.offsetTop = 20.0f * Data.map.scale;
	Data.holeChara.offsetRight = 30.0f * Data.map.scale;
	Data.holeChara.offsetBottom = 30.0f * Data.map.scale;

	Data.ebifuraiChara.charaId = MAP::EBIFURAI_ID;
	Data.ebifuraiChara.hp = 1;
	Data.ebifuraiChara.speed = -2.5f * 60;
	Data.ebifuraiChara.groupId = 2;
	Data.ebifuraiChara.offsetLeft = 20.0f* Data.map.scale;
	Data.ebifuraiChara.offsetTop = 20.0f * Data.map.scale;
	Data.ebifuraiChara.offsetRight = 30.0f * Data.map.scale;
	Data.ebifuraiChara.offsetBottom = 30.0f * Data.map.scale;
	Data.ebifurai.jumpFlag = 0;
	Data.ebifurai.initVecUp = -16.0f;
	Data.ebifurai.initVecDown = 3.0f;
	Data.ebifurai.gravity = 48;

	Data.rymanChara.charaId = MAP::RYMAN_ID;
	Data.rymanChara.hp = 1;
	Data.rymanChara.speed = -4.0f * 60;
	Data.rymanChara.groupId = 2;
	Data.rymanChara.offsetLeft = 20.0f * Data.map.scale;
	Data.rymanChara.offsetTop = 20.0f * Data.map.scale;
	Data.rymanChara.offsetRight = 30.0f * Data.map.scale;
	Data.rymanChara.offsetBottom = 30.0f * Data.map.scale;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numEnemies = 1;
	Data.charaMng.numCats = 10;
	Data.charaMng.numBatBullets = 12;
	Data.charaMng.numEnemyBullets = 20;
	Data.charaMng.numHoles = 2;
	Data.charaMng.numCokes = 5;
	Data.charaMng.numTips = 3;
	Data.charaMng.numBears = 2;
	Data.charaMng.numRamens = 1;
	Data.charaMng.numEbifurais = 4;
	Data.charaMng.numRymans = 2;


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

	Data.map.chipSize = 100;
	Data.map.scale = 2;
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

	Data.holeChara.img = loadImage("assets\\manholeImg.png");
	Data.cokeChara.img = loadImage("assets\\cokeImg.png");
	Data.tipsChara.img = loadImage("assets\\tipsImg.png");
	Data.ramenChara.img = loadImage("assets\\ramenImg.png");
	Data.bearChara.img = loadImage("assets\\bearImg.png");

	Data.catChara.img = loadImage("assets\\catImg.png");
	Data.batBulletChara.img = loadImage("assets\\batBullet.png");

	Data.ebifuraiChara.img = loadImage("assets\\ebihuraiImg.png");
	Data.rymanChara.img = loadImage("assets\\salary-manImg.png");

	//ANIMS �����̃A�j���[�V�����Z�b�g
	Data.loading.anim = new ANIM("assets\\loading\\load");
	Data.loading.anim->noLoop();
	
	Data.loading.animData.interval = 0.1f;

	Data.playerChara.anims = new ANIMS("assets\\player");
	Data.playerChara.animData.interval = 0.1f;

	Data.enemyChara.anims = new ANIMS("assets\\player");
	Data.enemyChara.animData.interval = 0.1f;

	
}
