#include "GameValue.hpp"

int PlayerScore::bonusScore = 0;
int PlayerScore::killScore = 0;
int PlayerScore::blockScore = 0;
int PlayerScore::Level = 0;

void PlayerScore::resetScore() {
	PlayerScore::bonusScore = 0;
	PlayerScore::killScore = 0;
	PlayerScore::blockScore = 0;
}

bool GameInfo::cameraMoving = false;
int GameInfo::cp1 = 0;
int GameInfo::cp2 = 0;
int GameInfo::cp3 = 0;
int GameInfo::currCP = -1;

void GameInfo::resetInfo() {
	GameInfo::cameraMoving = false;
	GameInfo::cp1 = 0;
	GameInfo::cp2 = 0;
	GameInfo::cp3 = 0;
	GameInfo::currCP = -1;
}
