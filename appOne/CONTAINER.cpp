#include"input.h"
#include"graphic.h"
#include"CONTAINER.h"
#include"ANIMS.h"
CONTAINER::~CONTAINER() {
	//１つのアニメーションの開放
	//delete Data.explosionChara.anim;
	delete Data.catChara.anim;
	delete Data.loading.anim;
	//複数のアニメーションの開放
	delete Data.pumpkinChara.anims;
	delete Data.enemyChara.anims;
	delete Data.playerChara.anims;
}
void CONTAINER::load() {
	CreateData();
	LoadGraphics();
}
void CONTAINER::CreateData() {
	//メッセージクラスのデータ
		//ストーリーに使用するウィンドウのデータ
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

	//注意書きに使用するウィンドウのデータ
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
	//ローディングクラスのデータ
	Data.loading.goToTitleTime = 2;
	//タイトルクラスのデータ
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

	//ストーリークラスのデータ
	Data.story.backColor = COLOR(0, 50, 0);
	Data.story.textColor = COLOR(0, 255, 0);
	Data.story.pos.x = 0;
	Data.story.pos.y = 400;
	Data.story.textSize = 300;
	strcpy_s(Data.story.str, "STORY");
	Data.story.Flag = 0;
	Data.story.text = "スキップしますか？ ";
	Data.story.text2 = "  YES";
	Data.story.text3 = "   NO";
	Data.story.skipButtonPos.x = 750;
	Data.story.skipButtonPos.y = 30;

	//ステージクラスのデータ
	Data.stage.backColor;
	Data.stage.textColor = COLOR(0, 255, 0);
	Data.stage.pos.x = 900;
	Data.stage.pos.y = 30;

	Data.stage.textSize = 30;
	strcpy_s(Data.stage.str, "STAGE");
	//ステージクリアクラスのデータ
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
	Data.stageClear.nextText = "    次へ";
	Data.stageClear.backToTitleText = "タイトルに戻る";
	//ゲームオーバークラスのデータ
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
	Data.gameOver.backToTitleText = "タイトルに戻る";
	Data.gameOver.continueText = "  リトライ？";

	//エンディングクラスのデータ
	Data.ending.backColor = COLOR(0, 50, 0);
	Data.ending.textColor = COLOR(0, 255, 0);
	Data.ending.pos.x = 0;
	Data.ending.pos.y = 400;
	Data.ending.textSize = 300;
	strcpy_s(Data.ending.str, "ENDING");
	//メッセージクラスのテキストデータ
	Data.message.text = 0;
	//ストーリー1話のテキスト
	Data.message.text1_1 = "テストメッセージ1";
	Data.message.text1_2 = "テストメッセージ2";//////////////////////////////";26文字限界
	Data.message.text1_3 = "テストメッセージ3";
	Data.message.text1_4 = "テストメッセージ4";
	Data.message.text1_5 = "テストメッセージ5";
	Data.message.text1_6 = "テストメッセージ6";
	Data.message.text1_7 = "テストメッセージ7";
	Data.message.text1_8 = "";
	Data.message.text1_9 = "";
	Data.message.text1_10 = "";
	//ストーリー2話のテキスト
	Data.message.text2_1 = "テストメッセージ8";
	Data.message.text2_2 = "テストメッセージ9";
	Data.message.text2_3 = "テストメッセージ10";
	Data.message.text2_4 = "テストメッセージ11";
	Data.message.text2_5 = "テストメッセージ12";
	Data.message.text2_6 = "";
	Data.message.text2_7 = "";
	Data.message.text2_8 = "";
	Data.message.text2_9 = "";
	Data.message.text2_10 = "";
	//ストーリー3話のテキスト
	Data.message.text3_1 = "テストメッセージ13";
	Data.message.text3_2 = "テストメッセージ14";
	Data.message.text3_3 = "テストメッセージ15";
	Data.message.text3_4 = "テストメッセージ16";
	Data.message.text3_5 = "テストメッセージ17";
	Data.message.text3_6 = "";
	Data.message.text3_7 = "";
	Data.message.text3_8 = "";
	Data.message.text3_9 = "";
	Data.message.text3_10 = "";
	//ストーリー4話のテキスト
	Data.message.text4_1 = "テストメッセージ18";
	Data.message.text4_2 = "テストメッセージ19";
	Data.message.text4_3 = "テストメッセージ20";
	Data.message.text4_4 = "テストメッセージ21";
	Data.message.text4_5 = "テストメッセージ22";
	Data.message.text4_6 = "";
	Data.message.text4_7 = "";
	Data.message.text4_8 = "";
	Data.message.text4_9 = "";
	Data.message.text4_10 = "";
	//ストーリー5話のテキスト
	Data.message.text5_1 = "テストメッセージ23";
	Data.message.text5_2 = "テストメッセージ24";
	Data.message.text5_3 = "テストメッセージ25";
	Data.message.text5_4 = "テストメッセージ26";
	Data.message.text5_5 = "テストメッセージ27";
	Data.message.text5_6 = "";
	Data.message.text5_7 = "";
	Data.message.text5_8 = "";
	Data.message.text5_9 = "";
	Data.message.text5_10 = "";

	Data.message.textLast_1 = "テストメッセージ28";
	Data.message.textLast_2 = "テストメッセージ29";
	Data.message.textLast_3 = "テストメッセージ30";
	Data.message.textLast_4 = "テストメッセージ31";
	Data.message.textLast_5 = "テストメッセージ32";
	Data.message.textLast_6 = "";
	Data.message.textLast_7 = "";
	Data.message.textLast_8 = "";
	Data.message.textLast_9 = "";
	Data.message.textLast_10 = "";
	//キャラ名
	Data.message.chara1 = "モブ1";
	Data.message.chara2 = "モブ2";
	//ステートを次に進めるための空のテキスト
	Data.message.text_Last = "次へ";
	//プレイヤークラスのデータ
	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 1;
	Data.playerChara.groupId = 0;//味方グループは0
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

	//プレイヤークラスのデータ
	Data.enemyChara.charaId = MAP::ENEMY_ID;
	Data.enemyChara.hp = 1;
	Data.enemyChara.groupId = 1;//味方グループは0
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
	
	Data.enemyBulletChara.groupId = 1;//敵グループは1
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
	

	Data.catChara.charaId = MAP::CAT_ID;
	Data.catChara.hp = 1;
	Data.catChara.groupId = 2;//敵グループは1
	Data.catChara.offsetLeft = 10.0f;
	Data.catChara.offsetTop = 10.0f;
	Data.catChara.offsetRight = 30.0f;
	Data.catChara.offsetBottom = 35.0f;
	Data.cat.elapsedTime = 0;
	Data.cat.interval = 0.016f;
	Data.cat.triggerCnt = 60;
	Data.cat.triggerInterval = 240;
	Data.cat.trigger1st = 220;
	Data.cat.trigger2nd = 225;
	Data.cat.trigger3rd = 230;
	Data.cat.trigger4th = 235;
	Data.cat.bulletCharaId = MAP::BAT_BULLET_ID;
	Data.cat.damageTime = 0;
	Data.cat.damageInterval = 5 * 0.016f;
	Data.cat.bulletOffsetX = 20.0f;
	Data.cat.damageColor = COLOR(255, 0, 0, 25);
	Data.cat.normalColor = COLOR(255, 255, 255);
	Data.catChara.speed = -3.4f * 60;

	Data.batBulletChara.charaId = MAP::BAT_BULLET_ID;
	Data.batBulletChara.groupId = 2;//敵グループは1
	Data.batBulletChara.hp = 1;
	Data.batBulletChara.speed = 4.7f * 60;
	Data.batBulletChara.offsetLeft = 20.0f;
	Data.batBulletChara.offsetTop = 20.0f;
	Data.batBulletChara.offsetRight = 30.0f;
	Data.batBulletChara.offsetBottom = 30.0f;

	Data.holeChara.charaId = MAP::MANHOLE_ID;
	Data.holeChara.groupId = 1;//敵グループは1
	Data.holeChara.hp = 1;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numEnemies = 1;
	Data.charaMng.numCats = 10;
	Data.charaMng.numBatBullets = 12;
	Data.charaMng.numEnemyBullets = 20;
	Data.charaMng.numHoles = 2;

	//フェードクラスのデータ
	Data.fade.color = COLOR(60, 60, 60);
	Data.fade.speed = 255 * 2;
	//ボタンクラスのデータ
	Data.button.radius = 5;
	//マップクラスのデータ
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

	Data.holeChara.img = loadImage("assets\\manholeImg.png");

	Data.catChara.img = loadImage("assets\\catImg.png");
	Data.batBulletChara.img = loadImage("assets\\batBullet.png");

	//ANIMS 複数のアニメーションセット
	Data.loading.anim = new ANIM("assets\\loading\\load");
	Data.loading.anim->noLoop();
	
	Data.loading.animData.interval = 0.1f;

	Data.playerChara.anims = new ANIMS("assets\\player");
	Data.playerChara.animData.interval = 0.1f;

	Data.enemyChara.anims = new ANIMS("assets\\player");
	Data.enemyChara.animData.interval = 0.1f;

	
}
