#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"STORY.h"
MESSAGE::MESSAGE(class GAME* game) :
	GAME_OBJECT(game) {}
MESSAGE::~MESSAGE() {
}
void MESSAGE::create() {
	Message = game()->container()->data().message;
}
void MESSAGE::draw() {
	RectWindow
	(
		Message.windowPos, Message.winW, Message.winH,
		Message.winColor, Message.edgeColor
	);

	switch (game()->curTextId()) {
		//テキストとステートのIdに応じたテキスト表示する
	case GAME::text_1:
		if (game()->curStateId() == 0) {
			Message.text = Message.text1_1;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == 1) {
			Message.text = Message.text2_1;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_1;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_1;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_1;
		}
		break;
	case GAME::text_2:
		if (game()->curStateId() == 0) {
			Message.text = Message.text1_2;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_2;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_2;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_2;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_2;
		}
		break;
	case GAME::text_3:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_3;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_3;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_3;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_3;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_3;
		}
		break;
	case GAME::text_4:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_4;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_4;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_4;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_4;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_4;
		}
		break;
	case GAME::text_5:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_5;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_5;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_5;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_5;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_5;
		}
		break;
	case GAME::text_6:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_6;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_6;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_6;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_6;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_6;
		}
		break;
	case GAME::text_7:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_7;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_7;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_7;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_7;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_7;
		}
		break;
	case GAME::text_8:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_8;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_8;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_8;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_8;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_8;
		}
		break;
	case GAME::text_9:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_9;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_9;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_9;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_9;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_9;
		}
		break;
	case GAME::text_10:
		if (game()->curStateId() == GAME::FIRST) {
			Message.text = Message.text1_10;
			Message.charactername = Message.chara2;
		}
		if (game()->curStateId() == GAME::SECOND) {
			Message.text = Message.text2_10;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::THIRD) {
			Message.text = Message.text3_10;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::FOURTH) {
			Message.text = Message.text4_10;
			Message.charactername = Message.chara1;
		}
		if (game()->curStateId() == GAME::END) {
			Message.text = Message.text5_10;
		}
		break;
	case GAME::text_Last:
		Message.text = Message.text_Last;
		break;
	}
	fill(Message.textColor);
	textSize(Message.textSize);
	float i = 0;
	if (Message.charactername == "" || game()->curTextId() == GAME::text_Last) {
		i = 0;
	}
	else i = Message.textPosOfst.y;
	text(Message.text, Message.textPos.x, Message.textPos.y + i);
	textSize(Message.charaNameTextSize);
	if (game()->curTextId() != GAME::text_Last) {
		text(Message.charactername, Message.textPos.x - 30, Message.textPos.y + 10);
	}

}
/// <summary>
/// 四角形のウィンドウを表示
/// </summary>
/// <param name="winPos">ウィンドウ本体の座標</param> 
/// <param name="winW">ウィンドウ本体の幅</param>
/// <param name="winH">ウィンドウ本体の高さ</param>
/// <param name="winColor">ウィンドウ本体の色</param>
/// <param name="edgeColor">ウィンドウの縁の色</param>
void MESSAGE::RectWindow
(
	const VECTOR2& winPos,
	float winW, float winH,
	COLOR& winColor, COLOR& edgeColor)
{
	//メッセージウィンドウの表示
	VECTOR2 edgePos(winPos.x, winPos.y);
	float edgeH = winH + game()->container()->data().message.sw * 2;
	float edgeW = winW + game()->container()->data().message.sw * 2;

	rectMode(CENTER);
	fill(edgeColor);
	rect(edgePos.x, edgePos.y, edgeW, edgeH);
	fill(winColor);
	rect(winPos.x, winPos.y, winW, winH);
}
void MESSAGE::nextText() {
	//テキストが入力されていないなら、強制的にラストのテキストを表示する
	if (Message.text == "") {
		game()->changeText(GAME::text_Last);
	}
	//テキストのステートを次に進める
	else {
		if (isTrigger(KEY_SPACE) || isTrigger(MOUSE_LBUTTON)) {
			switch (game()->curTextId()) {
			case GAME::text_1:
				game()->changeText(GAME::text_2);
				break;
			case GAME::text_2:
				game()->changeText(GAME::text_3);
				break;
			case GAME::text_3:
				game()->changeText(GAME::text_4);
				break;
			case GAME::text_4:
				game()->changeText(GAME::text_5);
				break;
			case GAME::text_5:
				game()->changeText(GAME::text_6);
				break;
			case GAME::text_6:
				game()->changeText(GAME::text_7);
				break;
			case GAME::text_7:
				game()->changeText(GAME::text_8);
				break;
			case GAME::text_8:
				game()->changeText(GAME::text_9);
				break;
			case GAME::text_9:
				game()->changeText(GAME::text_10);
				break;
			case GAME::text_10:
				game()->changeText(GAME::text_Last);
				break;
			}
		}
	}
}
void MESSAGE::init() {
	game()->changeText(GAME::text_1);
}
/// <summary>
/// 注意書きを表示するウィンドウ
/// </summary>
/// <param name="text1"></param>
/// <param name="text2"></param>
/// <param name="text3"></param>
void MESSAGE::AttentionWindow(const char* text1, const char* text2, const char* text3) {
	RectWindow(Message.attentionWinPos,
		Message.attentionWinW, Message.attentionWinH,
		Message.attentionWinColor, Message.attentionWinEdgeColor);

	fill(Message.attentionTextColor);
	textSize(Message.attentionTextSize);
	text(text1, Message.attentionTextPos.x, Message.attentionTextPos.y);
	textSize(Message.attentionTextSize - 20);

	game()->button()->rectButton(Message.yesPos, Message.buttonColor, Message.attentionTextColor, text2, Message.buttonNameTextSize, Message.charaNum);
	game()->button()->rectButton(Message.noPos, Message.buttonColor, Message.attentionTextColor, text3, Message.buttonNameTextSize, Message.charaNum);
}
