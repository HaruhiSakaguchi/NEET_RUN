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
	//�v�����[�O�N���X�̃f�[�^
	Data.message.sw = 3;
	Data.prologue.textSize = 30;
	Data.prologue.textPosOfst.x = 50;
	Data.prologue.textPosOfst.y = 50;
	Data.prologue.winH = 195;
	Data.prologue.windowPos.x = width / 2;
	Data.prologue.windowPos.y = height - Data.message.winH - Data.message.sw + 95;
	Data.prologue.winW = width - Data.message.sw * 2 - 200;
	Data.prologue.textPos.x = Data.message.windowPos.x + Data.message.textPosOfst.x - Data.message.winW / 2;
	Data.prologue.textPos.y = Data.message.windowPos.y + Data.message.textPosOfst.y - Data.message.winH / 2;
	Data.prologue.charaNameTextSize = 50;
	Data.prologue.textColor = COLOR(0, 0, 0);
	Data.prologue.winColor = COLOR(255, 255, 255);
	Data.prologue.edgeColor = COLOR(0, 0, 0);
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
	Data.stageClear.nextPos.x = 200;
	Data.stageClear.nextPos.y = height / 2;
	Data.stageClear.backToTitlePos.x = Data.stageClear.nextPos.x + 650;
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
	Data.gameOver.continuePos.x = 200;
	Data.gameOver.continuePos.y = height/ 2;
	Data.gameOver.backToTitlePos.x = Data.gameOver.continuePos.x + 650;
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

	//�J�E���g�_�E���N���X�̃f�[�^
	Data.cd.textSize = 100;

	//���b�Z�[�W�N���X�̃e�L�X�g�f�[�^
	Data.message.text = 0;
	//�X�g�[���[1�b�̃e�L�X�g
	Data.message.text1_1 = "                ";
	Data.message.text1_2 = "                ";//////////////////////////////";26�������E
	Data.message.text1_3 = "����A�v���[���g�����̂����I�H���肪�Ƃ�";
	Data.message.text1_4 = "�ł����ꍂ�������񂶂�Ȃ��H";
	Data.message.text1_5 = "����قǂł��`";
	Data.message.text1_6 = "�܂����A�p�`���R�ŏ�������������Ȃ����낤��";
	Data.message.text1_7 = "�c�c";
	Data.message.text1_8 = "�c�c�c�c";
	Data.message.text1_9 = "����";
	Data.message.text1_10 = "���H";
	Data.message.text1_11 = "���̂��A";
	Data.message.text1_12 = "�o�J���q���[�I�I";
	Data.message.text1_13 = "";
	Data.message.text1_14 = "";
	Data.message.text1_15 = "";
	Data.message.text1_16 = "";
	Data.message.text1_17 = "";
	Data.message.text1_18 = "";
	Data.message.text1_19 = "";
	Data.message.text1_20 = "";
	
	//�X�g�[���[2�b�̃e�L�X�g
	Data.message.text2_1 = "           ";
	Data.message.text2_2 = "�͂��A�͂��B�炱�����񂾂�`�N�V���[...�I�I";
	Data.message.text2_3 = "�Ă߂��A�Ȃ߂Ă�̂��I�I";
	Data.message.text2_4 = "�c�c�c�c�B";
	Data.message.text2_5 = "�`�b�I���O�������Ȃ��ȁH�������A�邩��w";
	Data.message.text2_6 = "�i���ꂪ�p���n������B�d���Ƃ���΂₾��...�B�j";
	Data.message.text2_7 = "����σj�[�g�ō��A...�񂥁I�H";
	Data.message.text2_8 = "�Ȃ񂩌����Ă�C��...�B�Ă����������Ă���...�I�H";
	Data.message.text2_9 = "�����������������������������I�I�I�I�I�I�I";
	Data.message.text2_10 = "������i��...�I���ɂ��点���������I�I�I";
	Data.message.text2_11 = "�Ȃ�ł��ꂥ�I�H";
	Data.message.text2_12 = "";
	Data.message.text2_13 = "";
	Data.message.text2_14 = "";
	Data.message.text2_15 = "";
	Data.message.text2_16 = "";
	Data.message.text2_17 = "";
	Data.message.text2_18 = "";
	Data.message.text2_19 = "";
	Data.message.text2_20 = "";
	//�X�g�[���[3�b�̃e�L�X�g
	Data.message.text3_1 = "�x�����E����...���āA����́I";
	Data.message.text3_2 = "�@�@�@�@�@�@�@�@�@�@�@�@";
	Data.message.text3_3 = "�i���̔ޏ��I���������Ă���邩�炫����...�I�j";
	Data.message.text3_4 ="���x�悩�����A����΂���ɒǂ��Ă�...";
	Data.message.text3_5 = "���̐l���V�������l�Ȃ́H";
	Data.message.text3_6 = "�́H";
	Data.message.text3_7 = "�������y�������������B���ɂ͂����̘b�������Ă���Ȃ��̂�...";
	Data.message.text3_8 = "�����̂��Ǝ̂Ă��Ⴄ�́H��������Ă���Ȃ��́H";
	Data.message.text3_9 = "���H�������";
	Data.message.text3_10 = "�V�s�����̓z�ɂƂ���O��...";
	Data.message.text3_11 = "������A���̂�";
	Data.message.text3_12 = "�����ꏏ�ɐ����Ȃ���...";
	Data.message.text3_13 = "";
	Data.message.text3_14 = "";
	Data.message.text3_15 = "";
	Data.message.text3_16 = "";
	Data.message.text3_17 = "";
	Data.message.text3_18 = "";
	Data.message.text3_19 = "";
	Data.message.text3_20 = "";
	//�X�g�[���[4�b�̃e�L�X�g
	Data.message.text4_1 = "�Ȃ�ŒN�����̘b�����˂��񂾂�I�I";
	Data.message.text4_2 = "����͂��O���l�̘b�����˂����炾��";
	Data.message.text4_3 = "�����H�Ȃ񂾂Ƃ�m...�q�F�b�I";
	Data.message.text4_4 = "�@�@�@�@�@�@�@�@�@�@�@";
	Data.message.text4_5 = "���O�����ꂿ���Ƃ��ޏ��̂�ɂ��Ă񂾂�";
	Data.message.text4_6 = "����̂��Ƃ����Ƒ厖�ɂ����";
	Data.message.text4_7 = "�́H��Ȃ��Ƃ��Ă˂���I���������Ȃ�...";
	Data.message.text4_8 = "�i...�����S�R���Ȃ��Ă˂���������ȁj";
	Data.message.text4_9 = "���Ă������Ȃɐl��Ƃ̂��Ƃ�...";
	Data.message.text4_10 = "�V�n���������I�I";
	Data.message.text4_11 = "";
	Data.message.text4_12 = "";
	Data.message.text4_13 = "";
	Data.message.text4_14 = "";
	Data.message.text4_15 = "";
	Data.message.text4_16 = "";
	Data.message.text4_17 = "";
	Data.message.text4_18 = "";
	Data.message.text4_19 = "";
	Data.message.text4_20 = "";
	//�X�g�[���[5�b�̃e�L�X�g
	Data.message.text5_1 = "�@�@�@�@�@�@�@�@�@";
	Data.message.text5_2 = "�͂��A���ǉƂɋA���Ă����܂���...";
	Data.message.text5_3 = "�������܁`";
	Data.message.text5_4 = "�i�Ă������A���΂ɕꂿ���̋@�������Ă��ȁH�j";
	Data.message.text5_5 = "�c�c�c�c";
	Data.message.text5_6 = "�����A���̂�������";
	Data.message.text5_7 = "���H";
	Data.message.text5_8 = "�������łȂ��Đl�l�ɂ܂Ŗ��f��...";
	Data.message.text5_9 = "�p�`���R�ɋ��n�ɂ�肽�����肾��...";
	Data.message.text5_10 = "����Ȃ񂶂�A���̐l�ɍ��킹��炪�Ȃ���I";
	Data.message.text5_11 = "�����A�҂��Ă悩�������...�I�I�I";
	Data.message.text5_12 = "";
	Data.message.text5_13 = "";
	Data.message.text5_14 = "";
	Data.message.text5_15 = "";
	Data.message.text5_16 = "";
	Data.message.text5_17 = "";
	Data.message.text5_18 = "";
	Data.message.text5_19 = "";
	Data.message.text5_20 = "";
	//�X�g�[���[�ŏI�b�̃e�L�X�g
	Data.message.textLast_1 = "���A���������R���r�j�ɓ����Ă����񂾂���...";
	Data.message.textLast_2 = "���肪�Ƃ��������܂����`";
	Data.message.textLast_3 = "�V�s�A�A���";
	Data.message.textLast_4 = "�ӂ����H";
	Data.message.textLast_5 = "��������x������ˁA�ق�A���ꎝ����";
	Data.message.textLast_6 = "���A���A�������������񂶂�...";
	Data.message.textLast_7 = "���̂��߂Ɏ��𔃂����Ǝv���Ă�񂾂�";
	Data.message.textLast_8 = "�������Ē��܂ň��ݖ�������";
	Data.message.textLast_9 = "...�ꂿ����D���I�I�I�I�I�I";
	Data.message.textLast_10 = "���邳����I�I�I�I�I�I";
	Data.message.textLast_11 = "�@�@�@�@�@�@�@�@�@�@�@";
	Data.message.textLast_12 = "";
	Data.message.textLast_13 = "";
	Data.message.textLast_14 = "";
	Data.message.textLast_15 = "";
	Data.message.textLast_16 = "";
	Data.message.textLast_17 = "";
	Data.message.textLast_18 = "";
	Data.message.textLast_19 = "";
	Data.message.textLast_20 = "";
	//�L������
	Data.message.space = "                ";
	//�X�e�[�g�����ɐi�߂邽�߂̋�̃e�L�X�g
	Data.message.text_Last = "             ";
	//�v���C���[�N���X�̃f�[�^
	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 1;
	Data.playerChara.groupId = 0;//�����O���[�v��0
	Data.playerChara.offsetLeft = 10.0f * 2;
	Data.playerChara.offsetTop = 1.0f * 2;
	Data.playerChara.offsetRight = 60.0f * 2;
	Data.playerChara.offsetBottom = 60.0f * 2;
	Data.playerChara.knockBackVx = 100;
	Data.playerChara.knockBackVy = 100;
	Data.playerChara.maxStamina = 100;
	Data.playerChara.stamina = 0;
	Data.player.jumpFlag = 0;
	Data.player.initVecUp = -16.0f *1.1f;
	Data.player.initVecDown = 3.0f *1.1f;
	Data.player.gravity = 48;
	Data.playerChara.damageTime = 0;
	Data.playerChara.damageInterval = 5 * 0.016f*2;
	Data.player.damageColor = COLOR(255, 0, 0, 25);
	Data.player.normalColor = COLOR(255, 255, 255);

	//�G�l�~�[�N���X�̃f�[�^
	Data.enemyChara.charaId = MAP::ENEMY_ID;
	Data.enemyChara.hp = 1;
	Data.enemyChara.groupId = 1;//�����O���[�v��0
	Data.enemyChara.offsetLeft = 10.0f * 2;
	Data.enemyChara.offsetTop = 1.0f * 2;
	Data.enemyChara.offsetRight = 60.0f * 2;
	Data.enemyChara.offsetBottom = 55.0f * 2;
	Data.enemyChara.maxStamina = 190;
	Data.enemyChara.stamina = 0;
	Data.enemyChara.damageTime = 0;
	Data.enemyChara.damageInterval = 5 * 0.016f * 2;
	Data.enemyChara.knockBackVx = -100;
	Data.enemyChara.knockBackVy = 100;
	Data.enemyChara.color = COLOR(0, 0, 0);
	Data.enemy.jumpFlag = 0;
	Data.enemy.initVecUp = -16.0f * 1.1f;
	Data.enemy.initVecDown = 3.0f * 1.1f;
	Data.enemy.charaDamage = 0;
	Data.enemy.gravity = 48;
	Data.enemy.bulletOffsetX = 20.0f * 2;
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
	Data.enemyBulletChara.offsetLeft = 10.0f * 2;
	Data.enemyBulletChara.offsetTop = 12.0f * 2;
	Data.enemyBulletChara.offsetRight = 60.0f * 2;
	Data.enemyBulletChara.offsetBottom = 60.0f * 2;
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
	Data.catChara.offsetLeft = 10.0f * 2;
	Data.catChara.offsetTop = 10.0f * 2;
	Data.catChara.offsetRight = 90.0f * 2;
	Data.catChara.offsetBottom = 60.0f * 2;
	Data.catChara.speed = -3.4f * 60;

	Data.cokeChara.charaId = MAP::COKE_ID;
	Data.cokeChara.hp = 1;
	Data.cokeChara.groupId = 2;
	Data.cokeChara.offsetLeft = 20.0f * 2;
	Data.cokeChara.offsetTop = 20.0f * 2;
	Data.cokeChara.offsetRight = 50.0f * 2;
	Data.cokeChara.offsetBottom = 70.0f * 2;

	Data.tipsChara.charaId = MAP::TIPS_ID;
	Data.tipsChara.hp = 1;
	Data.tipsChara.groupId = 2;
	Data.tipsChara.offsetLeft = 20.0f * 2;
	Data.tipsChara.offsetTop = 20.0f * 2;
	Data.tipsChara.offsetRight = 70.0f * 2;
	Data.tipsChara.offsetBottom = 70.0f * 2;

	Data.ramenChara.charaId = MAP::RAMEN_ID;
	Data.ramenChara.hp = 1;
	Data.ramenChara.groupId = 2;
	Data.ramenChara.offsetLeft = 20.0f * 2-5;
	Data.ramenChara.offsetTop = 20.0f * 2;
	Data.ramenChara.offsetRight = 120.0f * 2-5;
	Data.ramenChara.offsetBottom = 70.0f * 2;

	Data.bearChara.charaId = MAP::BEAR_ID;
	Data.bearChara.hp = 1;
	Data.bearChara.groupId = 2;
	Data.bearChara.offsetLeft = 20.0f * 2;
	Data.bearChara.offsetTop = 20.0f * 2;
	Data.bearChara.offsetRight = 70.0f * 2;
	Data.bearChara.offsetBottom = 70.0f * 2;

	Data.batBulletChara.charaId = MAP::BAT_BULLET_ID;
	Data.batBulletChara.groupId = 2;//�G�O���[�v��1
	Data.batBulletChara.hp = 1;
	Data.batBulletChara.speed = 4.7f * 60;
	Data.batBulletChara.offsetLeft = 20.0f * 2;
	Data.batBulletChara.offsetTop = 20.0f * 2;
	Data.batBulletChara.offsetRight = 35.0f * 2;
	Data.batBulletChara.offsetBottom = 30.0f * 2;

	Data.holeChara.charaId = MAP::MANHOLE_ID;
	Data.holeChara.groupId = 1;//�G�O���[�v��1
	Data.holeChara.hp = 1;
	Data.holeChara.offsetLeft = 20.0f * 2;
	Data.holeChara.offsetTop = 0.0f * 2;
	Data.holeChara.offsetRight = 70.0f * 2;
	Data.holeChara.offsetBottom = 80.0f * 2;

	Data.ebifuraiChara.charaId = MAP::EBIFURAI_ID;
	Data.ebifuraiChara.hp = 1;
	Data.ebifuraiChara.speed = -2.5f * 60;
	Data.ebifuraiChara.groupId = 2;
	Data.ebifuraiChara.offsetLeft = 20.0f* 2;
	Data.ebifuraiChara.offsetTop = 20.0f * 2;
	Data.ebifuraiChara.offsetRight = 50.0f * 2;
	Data.ebifuraiChara.offsetBottom = 70.0f * 2;
	Data.ebifurai.jumpFlag = 0;
	Data.ebifurai.initVecUp = -16.0f;
	Data.ebifurai.initVecDown = 3.0f;
	Data.ebifurai.gravity = 48;

	Data.rymanChara.charaId = MAP::RYMAN_ID;
	Data.rymanChara.hp = 1;
	Data.rymanChara.speed = -4.0f * 60;
	Data.rymanChara.groupId = 2;
	Data.rymanChara.offsetLeft = 20.0f * 2-5;
	Data.rymanChara.offsetTop = 20.0f * 2;
	Data.rymanChara.offsetRight = 50.0f * 2-10-5;
	Data.rymanChara.offsetBottom = 70.0f * 2;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numEnemies = 1;
	Data.charaMng.numCats = 10;
	Data.charaMng.numBatBullets = 12;
	Data.charaMng.numEnemyBullets = 20;
	Data.charaMng.numHoles = 3;
	Data.charaMng.numCokes = 7;
	Data.charaMng.numTips = 4;
	Data.charaMng.numBears = 3;
	Data.charaMng.numRamens = 5;
	Data.charaMng.numEbifurais = 6;
	Data.charaMng.numRymans = 5;


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
	Data.map.scale = 1;
	Data.map.centerX = width / 2 - Data.map.chipSize / 2;
}
void CONTAINER::LoadGraphics() {
	Data.title.image = loadImage("assets\\startImg.png");
	Data.title.image2 = loadImage("assets\\startButton.png");

	Data.story.backImg[0] = loadImage("assets\\�X�g�[���[�w�i\\�X�g�[���[�w�i\\home.png");
	Data.story.backImg[1] = loadImage("assets\\�X�g�[���[�w�i\\�X�g�[���[�w�i\\kouji.png");
	Data.story.backImg[2] = loadImage("assets\\�X�g�[���[�w�i\\�X�g�[���[�w�i\\roji_01.png");
	Data.story.backImg[3] = loadImage("assets\\�X�g�[���[�w�i\\�X�g�[���[�w�i\\roji_02.png");
	Data.story.backImg[4] = loadImage("assets\\�X�g�[���[�w�i\\�X�g�[���[�w�i\\store.png");

	Data.stage.backImg = loadImage("assets\\back.png");

	Data.stageClear.img = loadImage("assets\\���U���g\\���U���g\\sc.png");

	Data.gameOver.retryImg = loadImage("assets\\���U���g\\���U���g\\retry.png");
	Data.gameOver.gotoTitleImg = loadImage("assets\\���U���g\\���U���g\\title.png");
	Data.gameOver.retryImg2 = loadImage("assets\\���U���g\\���U���g\\retry.png");
	Data.gameOver.gotoTitleImg2 = loadImage("assets\\���U���g\\���U���g\\title.png");

	Data.stageClear.nextButtonImg = loadImage("assets\\���U���g\\���U���g\\next.png");
	Data.stageClear.gotoTitleButtonImg = loadImage("assets\\���U���g\\���U���g\\title.png");
	Data.stageClear.nextButtonImg2 = loadImage("assets\\���U���g\\���U���g\\next.png");
	Data.stageClear.gotoTitleButtonImg2 = loadImage("assets\\���U���g\\���U���g\\title.png");
	Data.gameOver.img = loadImage("assets\\���U���g\\���U���g\\go.png");

	Data.map.blockImg = loadImage("assets\\block.png");
	Data.map.poleImg = loadImage("assets\\item\\item\\��Q��\\hole_2.png");
	
	Data.cd.image = Data.stage.backImg;
	Data.enemyBulletChara.img1 = loadImage("assets\\item\\item\\�G�A�C�e��\\okan_book.png");
	Data.enemyBulletChara.img2 = loadImage("assets\\item\\item\\�G�A�C�e��\\light.png");
	Data.enemyBulletChara.img3= loadImage("assets\\item\\item\\�G�A�C�e��\\candy.png");
	Data.enemyBulletChara.img4= loadImage("assets\\item\\item\\�G�A�C�e��\\cut.png");

	Data.holeChara.img = loadImage("assets\\item\\item\\��Q��\\skull.png");
	Data.cokeChara.img = loadImage("assets\\item\\item\\��\\cola.png");
	Data.tipsChara.img = loadImage("assets\\item\\item\\��\\potato.png");
	Data.ramenChara.img = loadImage("assets\\item\\item\\��\\men.png");
	Data.bearChara.img = loadImage("assets\\item\\item\\��\\Beer.png");

	Data.catChara.img = loadImage("assets\\item\\item\\��Q��\\cat.png");
	Data.batBulletChara.img = loadImage("assets\\batBullet.png");

	Data.ebifuraiChara.img = loadImage("assets\\item\\item\\��Q��\\fry.png");
	Data.rymanChara.img = loadImage("assets\\item\\item\\��Q��\\human.png");

	Data.ending.img[0] =loadImage("assets\\�G���h���[��\\end_01.png");
	Data.ending.img[1] =loadImage("assets\\�G���h���[��\\end_02.png");
	Data.ending.img[2] =loadImage("assets\\�G���h���[��\\end_03.png");
	Data.ending.img[3] =loadImage("assets\\�G���h���[��\\end_04.png");
	Data.ending.img[4] =loadImage("assets\\�G���h���[��\\end_05.png");

	//ANIMS �����̃A�j���[�V�����Z�b�g
	Data.loading.anim = new ANIM("assets\\loading\\load");
	Data.loading.anim->noLoop();
	
	Data.loading.animData.interval = 0.1f;

	Data.playerChara.anims = new ANIMS("assets\\player");
	Data.playerChara.animData.interval = 0.1f;

	Data.enemyChara.anims = new ANIMS("assets\\player");
	Data.enemyChara.animData.interval = 0.1f;

	Data.message.okanDefImg = loadImage("assets\\okan\\okan\\01.png");
	Data.message.okanAngImg = loadImage("assets\\okan\\okan\\02.png");
	Data.message.okanHpImg  = loadImage("assets\\okan\\okan\\03.png");
	Data.message.okanSpImg  = loadImage("assets\\okan\\okan\\04.png");
	Data.message.okanDlImg  = loadImage("assets\\okan\\okan\\05.png");

	/*Data.message.neetDefImg = loadImage("assets\\okan\\okan\\01.png");
	Data.message.neetAngImg = loadImage("assets\\okan\\okan\\02.png");
	Data.message.neetHpImg = loadImage("assets\\okan\\okan\\03.png");
	Data.message.neetSpImg = loadImage("assets\\okan\\okan\\04.png");
	Data.message.neetPnImg = loadImage("assets\\okan\\okan\\04.png");
	Data.message.neetDlImg = loadImage("assets\\okan\\okan\\05.png");*/

	
	Data.message.onisanDefImg = loadImage("assets\\oni-san\\oni-san\\01_df.png");
	Data.message.onisanAngImg = loadImage("assets\\oni-san\\oni-san\\02_ag.png");
	Data.message.onisanHpImg  = loadImage("assets\\oni-san\\oni-san\\03_hp.png");
	Data.message.onisanSpImg  = loadImage("assets\\oni-san\\oni-san\\04_sp.png");
	Data.message.onisanDlImg  = loadImage("assets\\oni-san\\oni-san\\05_dl.png");

	
	Data.message.menheraDefImg = loadImage("assets\\menhera\\menhera\\01_df.png");
	Data.message.menheraAngImg = loadImage("assets\\menhera\\menhera\\02_ag.png");
	Data.message.menheraHpImg  = loadImage("assets\\menhera\\menhera\\03_hp.png");
	Data.message.menheraSpImg  = loadImage("assets\\menhera\\menhera\\04_sp.png");
	Data.message.menheraDlImg  = loadImage("assets\\menhera\\menhera\\05_dl.png");

	
	Data.message.chinpiraDefImg = loadImage("assets\\chinpira\\chinpira\\01_df.png");
	Data.message.chinpiraAngImg = loadImage("assets\\chinpira\\chinpira\\02_ag.png");
	Data.message.chinpiraHpImg  = loadImage("assets\\chinpira\\chinpira\\03_hp.png");
	Data.message.chinpiraSpImg  = loadImage("assets\\chinpira\\chinpira\\04_sp.png");
	Data.message.chinpiraDlImg  = loadImage("assets\\chinpira\\chinpira\\05_dl.png");

	
	
	
}
