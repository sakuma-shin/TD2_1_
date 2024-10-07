#include"ExMath.h"
#include"Hit.h"

class Wall {
public:


	void Initialize();
	void Update();
	void Draw();

	void DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll);

private:
	int wallNum_;
	Vector2 pos_[8];
	float width;
	float height;
	Corners corners_[8];

	int GH = Novice::LoadTexture("white1x1.png");
	

};