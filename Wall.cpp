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
