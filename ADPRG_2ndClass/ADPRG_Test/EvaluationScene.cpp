#include "EvaluationScene.hpp"
#include "GameValue.hpp"


EvaluationScene::EvaluationScene() : AbstractScene(SceneManager::EVAL_SCENE_NAME) {

}

void EvaluationScene::onLoadResources() {

}

// executes everything needed for the scene
void EvaluationScene::onLoadObjects() {
	CameraManager::getInstance()->resetCamera();
	this->loadUI();
}

void EvaluationScene::onUnloadResources() {

}

// loads the Evaluation box as well as the score of the player
void EvaluationScene::loadUI() {
	EvaluationBox* evalBox = new EvaluationBox("evalBox");
	this->registerObject(evalBox);

	UIiMage* item = new UIiMage("Item"); // the bonus item for the level
	evalBox->attachChild(item);

	UIText* continueText = new UIText("ContinueText", "nes", sf::Color::White, sf::Color::Transparent);
	this->registerObject(continueText);
	continueText->setText("Press Enter to Continue");
	continueText->setPosition((Game::WINDOW_WIDTH/2) + 470, (Game::WINDOW_HEIGHT / 2) + 240);
	continueText->setSize(13.f);

	UIText* playerText = new UIText("PlayerText", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(playerText);
	playerText->setText("Player 1");
	playerText->setPosition(40.f, -180.0f);
	playerText->setSize(30.f);

	UIText* bonusScore = new UIText("BonusScore", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(bonusScore);
	bonusScore->setText(std::to_string(PlayerScore::bonusScore));
	bonusScore->setPosition(10.f, -60.0f);
	bonusScore->setSize(40.f);

	UIText* killScore = new UIText("killScore", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(killScore);
	killScore->setText(std::to_string(PlayerScore::killScore));
	killScore->setPosition(10.f, -10.0f);
	killScore->setSize(40.f);

	UIText* blockScore = new UIText("BlockScore", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(blockScore);
	blockScore->setText(std::to_string(PlayerScore::blockScore));
	blockScore->setPosition(10.f, 40.0f);
	blockScore->setSize(40.f);

	UIText* totalText = new UIText("TotalText", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(totalText);
	totalText->setText("TOTAL");
	totalText->setPosition(10.f, 115.0f);
	totalText->setSize(30.f);

	UIText* totalScore = new UIText("TotalScore", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(totalScore);
	totalScore->setText(std::to_string(PlayerScore::bonusScore + PlayerScore::killScore + PlayerScore::blockScore));
	totalScore->setPosition(5.f, 180.0f);
	totalScore->setSize(30.f);


}
