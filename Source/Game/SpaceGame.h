#pragma once
#include "Framework/Game.h"
#include "Framework/Scene.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include <memory>


namespace parabellum{

class SpaceGame : public parabellum::Game, public IObserver {
public:
	enum class GameState {
		Initialize,
		Title,
		StartGame,
		ComeGetSome, // game state
		HesRottingYouKnow, //death
		YouFuckingSuck, // gameover
	};
	SpaceGame() = default;

	bool initialize() override;

	void Update() override;

	void GTFO() override;

	void Draw(class Renderer& renderer) override;

	void onPlayerDead();
private:

	void spawnPlayer();

	void spawnEnemy();
	// Inherited via Game



	std::unique_ptr<parabellum::Scene> m_scene;

	std::unique_ptr<SpaceGame> m_game;

	GameState current_state = GameState::Initialize;

	float enemySpawnTimer = 0;

	std::shared_ptr<Font> m_titleFont;

	std::shared_ptr<Font> m_scoreFont;

	std::unique_ptr<Text> titleText;

	std::unique_ptr<Text> scoreText;


	// Inherited via IObserver
	void OnNotify(const Event& event) override;

};
}