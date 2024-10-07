#pragma once

#include <Hit.h>

class Player
{
public:
	Player();

	~Player();

	void Initialize();

	void Update(char* keys, char* preKeys);

	void Draw();

	uint32_t GetTime();


private:

	float startJumpPower_ = 0;

	float playerJumpPower_ = 0;

	uint32_t textureHandle_ = Novice::LoadTexture("./Resources/white1x1.png");

	uint32_t pushTime_ = 0;

	const uint32_t maxPushTime_ = 100;;

	float moveSpeed_ = 7.5f;

	Vector2 playerPos_ = { 20,690 };

	Corners playerCorner_;

	bool isJump_ = false;
};

