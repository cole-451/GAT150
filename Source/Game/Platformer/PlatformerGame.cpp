#include "PlatformerGame.h"
#include "Engine.h"
namespace parabellum {
	bool PlatformerGame::initialize() {
		
		OBSERVER_ADD("player_dead");
		OBSERVER_ADD("add_points"); // these are events that this game is specifically looking for. use these with onNotify if needed.
		OBSERVER_ADD("add_time");

		m_scene = std::make_unique<Scene>(this);

		m_scoreFont = std::make_shared<Font>();
		m_scoreFont->Load("Fonts/Brianne_s_hand.ttf", 100);

		titleText = std::make_unique<Text>(parabellum::ResourceManager::Instance().GetWithID<parabellum::Font>("Fonts/Brianne_s_hand.ttf", "start_font", 100.0f));
		titleText->Create(getEngine().getRenderer(), "press k to start!", vec3{ 1,1,1 });
		scoreText = std::make_unique<Text>(m_scoreFont);
		scoreText->Create(getEngine().getRenderer(), "" + std::to_string(m_score), vec3{ 0,1,0 });

		m_scene->Load("Scenes/level.json");
		m_scene->Load("Scenes/prototypes.json");

		return true;
	}

	void PlatformerGame::Update() {
		switch (current_state)
		{
		case parabellum::PlatformerGame::GameState::Initialize:
			current_state = GameState::Title;
			break;
		case parabellum::PlatformerGame::GameState::Title:
			if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_K)) {
				getEngine().getAudioSys().playSound("platformer_music");
				current_state = GameState::StartGame;
			}
			break;
		case parabellum::PlatformerGame::GameState::StartGame:
			spawnPlayer();

			current_state = GameState::ComeGetSome;

			break;
		case parabellum::PlatformerGame::GameState::ComeGetSome:
			enemySpawnTimer -= getEngine().getTime().getDeltaTime();
			if (enemySpawnTimer <= 0) {
				enemySpawnTimer = 7.0f;
				spawnEnemy();
			}
			//Create a timer in the header for how long you have to live.
			timeToBleed -= getEngine().getTime().getDeltaTime();
			if (timeToBleed <= 0) {
				//current_state = GameState::HesRottingYouKnow;
			}

			//add points for moving crates off of the map, as well as destroying them

			
			

			

			
			break;
		case parabellum::PlatformerGame::GameState::HesRottingYouKnow:
			titleText->Create(getEngine().getRenderer(), "Game Over! Press R to restart.", vec3{ 1,0,0 });
			if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_R)) current_state = GameState::StartGame;
			break;
		case parabellum::PlatformerGame::GameState::YouFuckingSuck:
			break;
		default:
			break;

		}
		m_scene->Update(getEngine().getTime().getDeltaTime());
	}

	void PlatformerGame::GTFO() {

	}

	void PlatformerGame::Draw(class Renderer& renderer) {
		m_scene->Draw(renderer);
		if (current_state == GameState::Title) {
			titleText->Draw(getEngine().getRenderer(), 400, 400);

		}

		else if (current_state == GameState::HesRottingYouKnow) {
			titleText->Draw(getEngine().getRenderer(), 300, 400);

		}
		else if (current_state == GameState::ComeGetSome) {
			scoreText->Draw(getEngine().getRenderer(), 30, 30);
		}
	}

	void PlatformerGame::OnNotify(const Event& event) {
		if (event.id == "add_points") {
			m_game->addPoints(100);
			scoreText->Draw(getEngine().getRenderer(), 30, 30);

		}
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
		auto enemy = Instantiate("platformenemy");
		m_scene->AddActor(std::move(enemy));
	}
	
}