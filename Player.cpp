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

	if (!isJump_) {
		if (keys[DIK_SPACE]) {
			if (pushTime_ < maxPushTime_) {
				pushTime_ += 1;
			}
		}
		else if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE]) {
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
			playerJumpPower_ = startJumpPower_;
			pushTime_ = 0;
			isJump_ = true;
		}
	}

	if (isJump_) {
		playerJumpPower_ -= 3;
		if (playerJumpPower_ <= -startJumpPower_) {
			startJumpPower_ = 0;
			playerJumpPower_ = 0;
			isJump_ = false;
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

