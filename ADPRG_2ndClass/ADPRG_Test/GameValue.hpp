#pragma once
// holds classes with static values for storing and passing information between scenes

class PlayerScore {
public:
	static void resetScore();  // resets every value for this class
public:
	static int bonusScore;
	static int killScore;
	static int blockScore;
	static int Level;
};

class GameInfo {
public:
	static void resetInfo(); // resets every value for this class
public:
	static bool cameraMoving;
	static int cp1;
	static int cp2;
	static int cp3;
	static int currCP;
};

