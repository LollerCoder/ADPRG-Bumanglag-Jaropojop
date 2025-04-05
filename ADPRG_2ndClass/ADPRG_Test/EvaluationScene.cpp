#include "EvaluationScene.hpp"
#include "PlayerScore.hpp"

EvaluationScene::EvaluationScene() : AbstractScene(SceneManager::EVAL_SCENE_NAME) {

}

void EvaluationScene::onLoadResources() {

}

void EvaluationScene::onLoadObjects() {
	this->loadUI();
}

void EvaluationScene::onUnloadResources() {
	PlayerScore::resetScore();
}

void EvaluationScene::loadUI() {
	EvaluationBox* evalBox = new EvaluationBox("evalBox");
	this->registerObject(evalBox);

	UIText* playerText = new UIText("PlayerText", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(playerText);
	playerText->setText("Player 1");
	playerText->setPosition(40.f, -180.0f);
	playerText->setSize(30.f);

	UIText* birdScore = new UIText("BirdSore", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(birdScore);
	birdScore->setText(std::to_string(PlayerScore::birdScore));
	birdScore->setPosition(20.f, 0.0f);
	birdScore->setSize(30.f);

	UIText* blockScore = new UIText("BlockScore", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(blockScore);
	blockScore->setText(std::to_string(PlayerScore::blockScore));
	blockScore->setPosition(20.f, 50.0f);
	blockScore->setSize(30.f);

	UIText* totalText = new UIText("TotalText", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(totalText);
	totalText->setText("TOTAL");
	totalText->setPosition(20.f, 115.0f);
	totalText->setSize(30.f);

	UIText* totalScore = new UIText("TotalScore", "nes", sf::Color::White, sf::Color::Transparent);
	evalBox->attachChild(totalScore);
	totalScore->setText(std::to_string(PlayerScore::bonusScore));
	totalScore->setPosition(5.f, 180.0f);
	totalScore->setSize(30.f);


}
