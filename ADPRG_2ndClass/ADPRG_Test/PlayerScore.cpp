#include "PlayerScore.hpp"

int PlayerScore::bonusScore = 0;
int PlayerScore::killScore = 0;
int PlayerScore::blockScore = 0;

void PlayerScore::resetScore() {
	PlayerScore::bonusScore = 0;
	PlayerScore::killScore = 0;
	PlayerScore::blockScore = 0;
}
