#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
#include "GAME_OBJECT.h"
class MESSAGE :
    public GAME_OBJECT
{
public:
    struct DATA {
        //ストーリーで使用するウィンドウ
        VECTOR2 windowPos;//ウィンドウの位置
        VECTOR2 textPos; //テキストの位置
        VECTOR2 textPosOfst;
        float winH = 0;
        float winW = 0;
        float textSize = 0;
        float sw = 0; //strokeWight
        COLOR edgeColor;
        COLOR textColor;
        COLOR winColor;
        //注意書きに使用するウィンドウ
        VECTOR2 attentionTextPos;
        VECTOR2 attentionWinPos;
        float attentionWinW = 0;
        float attentionWinH = 0;
        float attentionTextSize = 0;
        COLOR attentionTextColor;
        COLOR attentionWinColor;
        COLOR attentionWinEdgeColor;
        //ストーリーで使用するテキスト
        const char* text = 0;

        const char* text1_1 = 0;
        const char* text1_2 = 0;
        const char* text1_3 = 0;
        const char* text1_4 = 0;
        const char* text1_5 = 0;
        const char* text1_6 = 0;
        const char* text1_7 = 0;
        const char* text1_8 = 0;
        const char* text1_9 = 0;
        const char* text1_10 = 0;

        const char* text2_1 = 0;
        const char* text2_2 = 0;
        const char* text2_3 = 0;
        const char* text2_4 = 0;
        const char* text2_5 = 0;
        const char* text2_6 = 0;
        const char* text2_7 = 0;
        const char* text2_8 = 0;
        const char* text2_9 = 0;
        const char* text2_10 = 0;

        const char* text3_1 = 0;
        const char* text3_2 = 0;
        const char* text3_3 = 0;
        const char* text3_4 = 0;
        const char* text3_5 = 0;
        const char* text3_6 = 0;
        const char* text3_7 = 0;
        const char* text3_8 = 0;
        const char* text3_9 = 0;
        const char* text3_10 = 0;

        const char* text4_1 = 0;
        const char* text4_2 = 0;
        const char* text4_3 = 0;
        const char* text4_4 = 0;
        const char* text4_5 = 0;
        const char* text4_6 = 0;
        const char* text4_7 = 0;
        const char* text4_8 = 0;
        const char* text4_9 = 0;
        const char* text4_10 = 0;

        const char* text5_1 = 0;
        const char* text5_2 = 0;
        const char* text5_3 = 0;
        const char* text5_4 = 0;
        const char* text5_5 = 0;
        const char* text5_6 = 0;
        const char* text5_7 = 0;
        const char* text5_8 = 0;
        const char* text5_9 = 0;
        const char* text5_10 = 0;

        const char* text_Last = 0;

        //会話シーンでキャラ名を表示するためのデータ
        float charaNameTextSize = 0;
        const char* charactername = 0;
        const char* chara1 = 0;
        const char* chara2 = 0;

        float buttonNameTextSize = 30;
        float charaNum = 4;
        VECTOR2 buttonPos;
        float buttonW = buttonNameTextSize * charaNum;
        float buttonH = buttonNameTextSize * 1.5f;
        VECTOR2 yesPos;
        VECTOR2 noPos;
        COLOR buttonColor;
    };
private:
    DATA Message;
public:
    MESSAGE(class GAME* game);
    ~MESSAGE();
    void create();
    void draw();
    void nextText();
    void init();
    void RectWindow(
        const VECTOR2& winPos,
        float winW, float winH,
        COLOR& winColor, COLOR& edgeColor
    );
    void AttentionWindow(const char* text1, const char* text2, const char* text3);

};

