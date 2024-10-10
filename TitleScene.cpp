#include "TitleScene.h"


void TitleScene::Initialize()
{
	whiteGH = Novice::LoadTexture("white1x1.png");
	pos_ = { 640.0f, 360.0f };
	width_ = 1280.0f;
	height_ = 720.0f;

	whiteCorners = PosUpdate(pos_, width_, height_);
}

void TitleScene::Update(char keys[256],char preKeys[256])
{
	if (keys[DIK_SPACE]&&!preKeys[DIK_SPACE]) {
		isFinished_ = true;
	}

	whiteCorners = PosUpdate(pos_, width_, height_);
}

void TitleScene::Draw()
{
	DrawQuad(whiteCorners, whiteGH, 1, 1, RED, 0.0f);
}

Corners TitleScene::PosUpdate(Vector2 pos, float width, float height)
{
	Corners c = {};

	c.leftTop.x = (pos.x - width / 2.0f);
	c.leftTop.y = (pos.y - height / 2.0f);

	c.rightTop.x = ((pos.x + width / 2.0f));
	c.rightTop.y = (pos.y - height / 2.0f);

	c.leftDown.x = (pos.x - width / 2.0f);
	c.leftDown.y = ((pos.y + height / 2.0f));

	c.rightDown.x = ((pos.x + width / 2.0f));
	c.rightDown.y = ((pos.y + height / 2.0f));

	return c;
}

void TitleScene::DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll)
{
	Novice::DrawQuad(int(a.leftTop.x - scroll), int(a.leftTop.y), int(a.rightTop.x - scroll), int(a.rightTop.y), int(a.leftDown.x - scroll), int(a.leftDown.y), int(a.rightDown.x - scroll), int(a.rightDown.y), 0, 0, imageWidth, imageHeight, imageGH, color);
}
