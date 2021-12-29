#include"graphic.h"
#include"CONTAINER.h"
#include"ANIMS.h"
CONTAINER::~CONTAINER() {
    //１つのアニメーションの開放
    delete Data.explosionChara.anim;
    delete Data.batChara.anim;
	delete Data.loading.anim;
    //複数のアニメーションの開放
    delete Data.pumpkinChara.anims;
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
	Data.stage.backColor = COLOR(0, 50, 0);
	Data.stage.textColor = COLOR(0, 255, 0);
	Data.stage.pos.x = 0;
	Data.stage.pos.y = 400;

	Data.stage.textSize = 300;
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
	//キャラ名
	Data.message.chara1 = "モブ1";
	Data.message.chara2 = "モブ2";
	//ステートを次に進めるための空のテキスト
	Data.message.text_Last = "次へ";
	//プレイヤークラスのデータ
	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 1;
	Data.playerChara.groupId = 0;//味方グループは0
	Data.playerChara.speed = 3.4f * 60;
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

    Data.pumpkinChara.charaId = MAP::PUMPKIN_ID;
    Data.pumpkinChara.groupId = 1;//敵グループは1
    Data.pumpkinChara.hp = 4;
    Data.pumpkinChara.speed = 1.4f * 60;
    Data.pumpkinChara.offsetLeft = 10.0f;
    Data.pumpkinChara.offsetTop = 12.0f;
    Data.pumpkinChara.offsetRight = 40.0f;
    Data.pumpkinChara.offsetBottom = 40.0f;
    Data.pumpkin.rightAnimId = 0;
    Data.pumpkin.leftAnimId = 1;
    Data.pumpkin.damageInterval = 5*0.016f;
    Data.pumpkin.initVecX = -1;
    Data.pumpkin.initVecY = 0;
    Data.pumpkin.gravity = 0.8f * 60;
    Data.pumpkin.alphaLowVal = 25;
    Data.pumpkin.damageColor = COLOR(255, 0, 0);
    Data.pumpkin.explosionCharaId = MAP::EXPLOSION_ID;

    Data.batChara.charaId = MAP::BAT_ID;
    Data.batChara.hp = 10;
    Data.batChara.groupId = 1;//敵グループは1
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
    Data.bat.damageInterval = 5*0.016f;
    Data.bat.bulletOffsetX = 20.0f;
    Data.bat.explosionCharaId = MAP::EXPLOSION_ID;
    Data.bat.damageColor = COLOR(255, 0, 0, 25);
    Data.bat.normalColor = COLOR(255, 255, 255);

    Data.batBulletChara.charaId = MAP::BAT_BULLET_ID;
    Data.batBulletChara.groupId = 1;//敵グループは1
    Data.batBulletChara.hp = 1;
    Data.batBulletChara.speed = 4.7f*60;
    Data.batBulletChara.offsetLeft = 20.0f;
    Data.batBulletChara.offsetTop = 20.0f;
    Data.batBulletChara.offsetRight = 30.0f;
    Data.batBulletChara.offsetBottom = 30.0f;

    Data.explosionChara.charaId = MAP::EXPLOSION_ID;
    Data.explosionChara.hp = 1;
    Data.explosionChara.color = COLOR(255, 255, 255, 220);
    Data.explosion.appearOffsetX = -25;
    Data.explosion.appearOffsetY = -25;

    Data.charaMng.numPlayers = 1;
    Data.charaMng.numPumpkins = 5;
    Data.charaMng.numBats = 5;
    Data.charaMng.numBatBullets = 12;
    Data.charaMng.numExplosions = 2;

	//フェードクラスのデータ
	Data.fade.color = COLOR(60, 60, 60);
	Data.fade.speed = 255 * 2;
	//ボタンクラスのデータ
	Data.button.radius = 5;
	//マップクラスのデータ
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
    
   
    Data.batBulletChara.img = loadImage("assets\\batBullet.png");

    //ANIMS 複数のアニメーションセット
	Data.loading.anim = new ANIM("assets\\loading\\load");
	Data.loading.anim->noLoop();
	//Data.loadingChara.animData.elapsedTime = 0.1f;
	Data.loading.animData.interval = 0.1f;

    Data.playerChara.anims = new ANIMS("assets\\player");
    Data.playerChara.animData.interval = 0.1f;

    Data.pumpkinChara.anims = new ANIMS("assets\\pumpkin");
    Data.pumpkinChara.animData.interval = 0.1f;

    //ANIM １つのアニメーションセット
    Data.batChara.anim = new ANIM("assets\\bat\\0");
    Data.batChara.animData.interval = 0.1f;

    Data.explosionChara.anim = new ANIM("assets\\explosion\\0");
    Data.explosionChara.anim->noLoop();
    Data.explosionChara.animData.interval = 0.032f;
}
