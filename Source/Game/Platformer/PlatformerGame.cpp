#include "PlatformerGame.h"
#include "Engine.h"
namespace parabellum {
	bool PlatformerGame::initialize() {
		
		OBSERVER_ADD("player_dead");
		OBSERVER_ADD("add_points");
		m_scene = std::make_unique<Scene>(this);

		m_scene->Load("Scenes/level.json");
		m_scene->Load("Scenes/prototypes.json");

		return true;
	}

	void PlatformerGame::Update() {
		switch (current_state)
		{
		case parabellum::PlatformerGame::GameState::Initialize:
			current_state = GameState::StartGame;
			break;
		case parabellum::PlatformerGame::GameState::Title:
			break;
		case parabellum::PlatformerGame::GameState::StartGame:
			spawnPlayer();

			current_state = GameState::ComeGetSome;

			break;
		case parabellum::PlatformerGame::GameState::ComeGetSome:
			
			break;
		case parabellum::PlatformerGame::GameState::HesRottingYouKnow:
			break;
		case parabellum::PlatformerGame::GameState::YouFuckingSuck:
			break;
		default:
			break;

		}m_scene->Update(getEngine().getTime().getDeltaTime());
	}

	void PlatformerGame::GTFO() {

	}

	void PlatformerGame::Draw(class Renderer& renderer) {
		m_scene->Draw(renderer);
	}

	void PlatformerGame::OnNotify(const Event& event) {

	}

	void PlatformerGame::onPlayerDead() {

	}

	void PlatformerGame::spawnPlayer() {
		auto player = Instantiate("platformplayer");
		//if (player) {
		m_scene->AddActor(std::move(player));

		//}
		//else {
			//Logger::Error("Cannot spawn player!");
		//}
	}

	void PlatformerGame::spawnEnemy() {
		auto enemy = Instantiate("enemy");
		m_scene->AddActor(std::move(enemy));
	}
}