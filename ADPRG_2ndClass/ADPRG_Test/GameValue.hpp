#pragma once
class PlayerScore {
public:
	static void resetScore();
public:
	static int bonusScore;
	static int killScore;
	static int blockScore;
	static int Level;
};

class GameInfo {
public:
	static void resetInfo();
public:
	static bool cameraMoving;
	static int cp1;
	static int cp2;
	static int cp3;
	static int currCP;
};

