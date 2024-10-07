#pragma once
#include <Novice.h>
#include "Hit.h"
class GamePlayScene
{
public:
	void Initialize();

	void Update(char keys[256], char preKeys[256]);

	void Draw();

	Corners PosUpdate(Vector2 pos, float width, float height);

	bool IsFinished() { return isFinished_; }

	void DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll);

private:


	enum Stage {
		STAGE1,
		STAGE2,
		STAGE3
	};

	Stage stage = STAGE1;

	bool isFinished_ = false;

	

	int whiteGH = 0;

	Vector2 pos_;
	float width_=0.0f;
	float height_=0.0f;

	Corners whiteCorners_ = {};
	
};

