#include"ExMath.h"
#include"Hit.h"

class Wall {
public:


	void Initialize();
	void Update();
	void Draw();

	void DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll);

	void Stage1Initialize();
	void Stage2Initialize();
	void Stage3Initialize();



private:

	Vector2 pos_[28];
	float width_[28];
	float height_[28];
	Corners corners_[28];

	int GH = Novice::LoadTexture("white1x1.png");


};