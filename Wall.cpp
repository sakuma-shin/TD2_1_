#include "Wall.h"

void Wall::Initialize()
{
}

void Wall::Update()
{
}

void Wall::Draw()
{
	for (int i = 0;i < 8;i++) {
		DrawQuad(corners_[i], GH, 1, 1, WHITE, 0.0f);
	}
}

void Wall::DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll) {
	Novice::DrawQuad(int(a.leftTop.x - scroll), int(a.leftTop.y), int(a.rightTop.x - scroll), int(a.rightTop.y), int(a.leftDown.x - scroll), int(a.leftDown.y), int(a.rightDown.x - scroll), int(a.rightDown.y), 0, 0, imageWidth, imageHeight, imageGH, color);
}

void Wall::Stage1Initialize()
{
	const int wallNum = 10;
	float heightTotal = 400;

	//‰º‚Ì•Ç
	height_[0] = 20.0f;
	height_[2] = 80.0f;
	height_[4] = 140.0f;
	height_[6] = 170.0f;
	height_[8] = 260.0f;

	//ã‚Ì•Ç
	height_[1] = heightTotal - height_[0];
	height_[3] = heightTotal - height_[2];
	height_[5] = heightTotal - height_[4];
	height_[7] = heightTotal - height_[6];
	height_[9] = heightTotal - height_[8];

	for (int i = 0;i < wallNum;i++) {
		width_[wallNum] = 25.0f;
	}



}

void Wall::Stage2Initialize()
{
	const int wallNum = 20;
}

void Wall::Stage3Initialize()
{
	const int wallNum = 28;
}
