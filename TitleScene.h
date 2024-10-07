#include <Novice.h>
#include "Hit.h"
class TitleScene
{
public:
	void Initialize();

	void Update(char keys[256], char preKeys[256]);

	void Draw();

	bool IsFinished() { return isFinished_; }

	Corners PosUpdate(Vector2 pos, float width, float height);

	void DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll);

private:



	int whiteGH = 0;

	Vector2 pos_ = {};

	float width_ = 0;
	float height_ = 0;

	Corners whiteCorners = {};

	bool isFinished_=false;

};

