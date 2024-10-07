#include <Novice.h>
#include"Easing.h"
#include"ExMath.h"
#include"Hit.h"
#include"Wall.h"
#include"GamePlayScene.h"
#include"TitleScene.h"

enum Scene {

	kUnknown,
	kTitle,
	kPlay
};

Scene scene = kUnknown;

GamePlayScene* gameScene = nullptr;
TitleScene* titleScene = nullptr;

void ChangeScene();
void UpdateScene();
void DrawScene();

// キー入力結果を受け取る箱
char keys[256] = { 0 };
char preKeys[256] = { 0 };

const char kWindowTitle[] = "LC1C_14_サクマ_シン_タイトル";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	

	scene = kTitle;
	gameScene = new GamePlayScene();
	gameScene->Initialize();

	titleScene = new TitleScene();
	titleScene->Initialize();


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
		ChangeScene();
		UpdateScene();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		DrawScene();
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

void ChangeScene() {
	switch (scene) {
	case kTitle:
		if (titleScene->IsFinished()) {

			gameScene = new GamePlayScene();
			gameScene->Initialize();
			scene = Scene::kPlay;

			delete titleScene;
			titleScene = nullptr;
			gameScene = new GamePlayScene();
			gameScene->Initialize();
		}
		break;

	case kPlay:
		if (gameScene->IsFinished()) {
			scene = Scene::kTitle;

			titleScene = new TitleScene();
			titleScene->Initialize();

			delete gameScene;
			gameScene = nullptr;

			titleScene = new TitleScene();
			titleScene->Initialize();

		}
		break;
	}
}

void UpdateScene() {
	switch (scene) {
	case kTitle:
		titleScene->Update(keys,preKeys);
		break;

	case kPlay:
		gameScene->Update(keys, preKeys);
		break;
	}
}

void DrawScene() {
	switch (scene) {
	case kTitle:
		titleScene->Draw();
		break;

	case kPlay:
		gameScene->Draw();
		break;
	}
}

