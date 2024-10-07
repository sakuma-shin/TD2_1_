#include "Player.h"

Player::Player() {

}

Player::~Player() {

}

void Player::Initialize() {

}

void Player::Update(char* keys, char* preKeys) {
	playerPos_.x += moveSpeed_;
	playerPos_.y -= playerJumpPower_;

	playerCorner_ = { {playerPos_.x - 10,playerPos_.y + 10},
		{playerPos_.x + 10,playerPos_.y + 10},
		{playerPos_.x - 10,playerPos_.y - 10},
		{playerPos_.x + 10,playerPos_.y - 10}
	};

	// ジャンプ中ではない場合の処理
	if (!isJump_ && isGround_) {
		// スペースキーが押されている間、ジャンプのための溜めを行う
		if (keys[DIK_SPACE]) {
			if (pushTime_ < maxPushTime_) {
				isHold_ = true;
				pushTime_ += 1;
			}
		}
		// スペースキーが離された時のジャンプ処理
		else if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] && isHold_) {
			isHold_ = false;
			// 溜めた時間に応じてジャンプ力を設定
			if (pushTime_ <= 20) {
				startJumpPower_ = 30;
			}
			else if (pushTime_ > 20 && pushTime_ <= 40) {
				startJumpPower_ = 33;
			}
			else if (pushTime_ > 40 && pushTime_ <= 60) {
				startJumpPower_ = 36;
			}
			else if (pushTime_ > 60 && pushTime_ <= 80) {
				startJumpPower_ = 39;
			}
			else if (pushTime_ > 80 && pushTime_ <= 100) {
				startJumpPower_ = 42;
			}

			// ジャンプ力をプレイヤーに反映
			playerJumpPower_ = startJumpPower_;
			pushTime_ = 0;
			isJump_ = true; // ジャンプ開始
			isGround_ = false;
		}
	}

	// ジャンプ中の処理
	if (isJump_) {
		// プレイヤーのジャンプ力を減少（重力を表現）
		playerJumpPower_ -= downPower_;

		// 2段ジャンプがまだ行われていない場合
		if (!oneMoreJump_) {
			// スペースキーが押されている間、再度ジャンプの溜めを行う
			if (keys[DIK_SPACE]) {
				isHold_ = true;
				pushTime_ += 1;
				downPower_ = 1; // 下降速度を変更
			}
			// スペースキーが離された時の2段ジャンプ処理
			else if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] && isHold_) {
				
				isHold_ = false;
				downPower_ = 3;

				// 溜めた時間に応じて2段ジャンプ力を追加
				if (pushTime_ <= 20) {
					startJumpPower_ = 30;
				}
				else if (pushTime_ > 20 && pushTime_ <= 40) {
					startJumpPower_ = 33;
				}
				else if (pushTime_ > 40 && pushTime_ <= 60) {
					startJumpPower_ = 36;
				}
				else if (pushTime_ > 60 && pushTime_ <= 80) {
					startJumpPower_ = 39;
				}
				else if (pushTime_ > 80 && pushTime_ <= 100) {
					startJumpPower_ = 42;
				}

				// 2段ジャンプ力をプレイヤーに反映
				playerJumpPower_ = startJumpPower_;
				pushTime_ = 0;
				oneMoreJump_ = true; // 2段ジャンプが完了
			}
		}

		// ジャンプ力が0以下になったらジャンプを終了
		if (playerPos_.y > 690) {
			playerPos_.y = 690;
			startJumpPower_ = 0;
			playerJumpPower_ = 0;
			downPower_ = 3;  // 重力をリセット
			oneMoreJump_ = false; // 2段ジャンプリセット
			isJump_ = false; // ジャンプ終了
			isGround_ = true;
		}
	}

	if (playerPos_.x + 10 >= 1280 || playerPos_.x - 10 <= 0) {
		moveSpeed_ *= -1;
	}

}

void Player::Draw() {
	Novice::DrawQuad(int(playerCorner_.leftTop.x), int(playerCorner_.leftTop.y),
		int(playerCorner_.leftDown.x), int(playerCorner_.leftDown.y),
		int(playerCorner_.rightTop.x), int(playerCorner_.rightTop.y),
		int(playerCorner_.rightDown.x), int(playerCorner_.rightDown.y),
		0, 0, 1, 1, textureHandle_, WHITE);
}

uint32_t Player::GetTime() {
	return pushTime_;
}

