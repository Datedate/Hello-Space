#include <math.h>
#include "DxLib.h"
#define PI (3.141592654)
int gpUpdateKey(void);
void gpCalc(void);
void gpDraw(void);
int Key[256];			// キーが押されているフレーム数を格納する
/*int x = 320, y = 240;
int Handle;*/
/*int SelectNum = 0;		// 現在の選択番号
int i;
typedef struct {
	int x, y;		// 座標格納用変数
	char name[128];	// 項目名格納用変数
}MenuElement_t;
MenuElement_t MenuElement[5] = {
	{ 80,100,"ゲームスタート" },		// タグの中身の順番に格納される。xに80,yに100が、nameに"ゲームスタート"が。
	{ 100,150,"おまけ" },
	{ 100,200,"ヘルプ" },
	{ 100,250,"コンフィング" },
	{ 100,300,"ゲーム終了" },
};*/
int WINAPI WinMain(HINSTANCE histance, HINSTANCE hprevInstance, LPSTR ipCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);	// ウィンドウの初期化裏画面設定

	//int x = 0;
	int Handle[3];
	int Count = 0;		// カウンタ
	LoadDivGraph("../Picture_素材/Material_02.png",3,3,1,14,16,Handle);		// 3つに画像を分割してロード
	float x = 320, y = 240, angle = 0, speed = 1;
	// while(裏画面を表画面に反映、メッセージ処理、画面クリア)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 /*&& gpUpdateKey()==0*/) {
	
		x += cos(angle)*speed;						// x座標を更新
		y += sin(angle)*speed;						// y座標を更新
		/*gpCalc();							// 計算フェーズ
		gpDraw();							// 描画フェーズ*/
		/*DrawRotaGraph(420, (int)(400 - sin(PI/2/120 * Count) * 300), 1.0, 0.0, Handle, TRUE);	// 画像の描画
		DrawRotaGraph(220, (int)(400- (sin(-PI/2+PI/120*Count)+ 1)/2*300),1.0, 0.0, Handle, TRUE);	// 画像の描画*/
		/*
		DrawGraph(0, Count % 50, Handle, TRUE);		// 周期50カウントでループ表示をする
		DrawGraph(100, Count % 100, Handle, TRUE);	// 周期100カウントでループ表示をする
		DrawGraph(200, Count % 150, Handle, TRUE);	// 周期150カウントでループ表示をする
		*/
		if (CheckHitKey(KEY_INPUT_Z) == 1) {		// zが押されていたら変数の中身を変更
			x = 320;				// 初期座標にセット
			y = 240;
			angle = GetRand(10000) / 10000.f*(PI * 2);	// 0~PI*2の乱数を生成
			speed = 0.5f + GetRand(10000) / 10000.f * 2;// 0.5~2.5の乱数を生成
		}
		DrawRotaGraph(x, y, 1.0, angle + PI / 2, Handle[0], TRUE);	// 弾を描画
		DrawFormatString(0, 0, GetColor(255, 255, 255), "angle=%.2f, speed=%2f\n", angle, speed);
	}
	DxLib_End();									// DXライブラリ終了処理
	return 0;
}
/*int gpUpdateKey(void) {
	char tmpKey[256];				// 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey);		// 全てのキーの入力状態を得る
	for (int i = 0;i < 256;i++) {
		if (tmpKey[i] != 0) {		// i番のキーコードに対応するキーが押されていたら
			Key[i]++;				// 加算
		}
		else {						// 押されていなければ
			Key[i] = 0;				// 0にする
		}
	}
	return 0;
}*/
/*void gpCalc() {
	if (Key[KEY_INPUT_DOWN] == 1) {			// 下のキーが押された瞬間だけ処理
		SelectNum = (SelectNum + 1) % 5;	// 現在の選択項目を一つ下にずらす（ループする）
	}
	if (Key[KEY_INPUT_UP] == 1) {			// 上のキーが押された瞬間だけ処理
		SelectNum = (SelectNum + 4) % 5;	// 現在の選択項目を一つ上にずらす（ループする）
	}
		for (i = 0;i < 5;i++) {			// メニュー項目数である5個ループ処理
			if (i == SelectNum) {			// 今処理しているのが、選択番号と同じ要素なら
				MenuElement[i].x = 80;		// x座標を　80にする
			}
			else {							// 今処理しているのが、選択番号以外なら
				MenuElement[i].x = 100;		// x座標を　100にする
			}
		}
	
}*/
/*
void gpDraw(void) {
	DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	for (i = 0;i < 5;i++) {
		DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(255, 255, 255), MenuElement[i].name);
	}
}*/