#include <Novice.h>
#include "Player.h"

const char kWindowTitle[] = "LC1C_14_サクマ_シン_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	UINT color = 0;

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update(keys, preKeys);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();

#ifdef _DEBUG
		if (player->GetTime() <= 100) {
			color = BLACK;
		}
		if (player->GetTime() <= 80) {
			color = RED;
		}
		if (player->GetTime() <= 60) {
			color = GREEN;
		}
		if (player->GetTime() <= 40) {
			color = BLUE;
		}
		if (player->GetTime() <= 20) {
			color = WHITE;
		}
		Novice::DrawBox(0, 700, 12 * player->GetTime(), 20, 0.0f, color, kFillModeSolid);
#endif

		Novice::ScreenPrintf(0, 0, "%d", int(player->GetTime()));

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
