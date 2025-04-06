#include "EvaluationScene.hpp"
#include "PlayerScore.hpp"
#include "CameraManager.hpp"

EvaluationScene::EvaluationScene() : AbstractScene(SceneManager::EVAL_SCENE_NAME) {

}

void EvaluationScene::onLoadResources() {

}

void EvaluationScene::onLoadObjects() {
	Game::cp1 = false;
	Game::cp2 = false;
	Game::cp3 = false;
	Game::cp4 = false;
	Game::cp5 = false;
	Game::cp6 = false;
	CameraManager::getInstance()->resetCamera();
	this->loadUI();
}

void EvaluationScene::onUnloadResources() {

}

void EvaluationScene::loadUI() {
	EvaluationBox* evalBox = new EvaluationBox("evalBox");
	this->registerObject(evalBox);

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
