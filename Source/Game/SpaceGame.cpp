#include "SpaceGame.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine.h"
#include "GameData.h"


using namespace parabellum;
bool SpaceGame::initialize()
{



	m_scoreFont = std::make_shared<Font>();
	m_scoreFont->Load("Brianne_s_hand.ttf", 50);

	titleText = std::make_unique<Text>(parabellum::ResourceManager::Instance().GetWithID<parabellum::Font>("Brianne_s_hand.ttf", "start_font", 30.0f));
	titleText->Create(getEngine().getRenderer(), "press k to start", vec3{ 1,1,1 });
	scoreText = std::make_unique<Text>(m_scoreFont);
	scoreText->Create(getEngine().getRenderer(), "" + std::to_string(m_score), vec3{ 0,1,0 });


	m_scene = std::make_unique<Scene>(this);

	json::document_t document;
	json::Load("scene.json", document);
	m_scene->Read(document);
	//declare and create actor list
	std::vector<std::unique_ptr<Actor>> actors;




	return true;

}

void SpaceGame::Update()
{
	float dt = getEngine().getTime().getDeltaTime();

	m_scene->Update(dt); // slow this down for bullet time (except particles)

	switch (current_state) {
	case GameState::Initialize:
		current_state = GameState::Title;
		break;

	case GameState::Title:
		//
		if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_K)) {
			getEngine().getAudioSys().playSound("music");
			current_state = GameState::StartGame;
		}
		m_lives = 3;
		break;

	case GameState::StartGame:
		m_score = 0;
		spawnPlayer();
		current_state = GameState::ComeGetSome;
		break;
	case GameState::ComeGetSome:
		//create player

		enemySpawnTimer -= dt;
		if (enemySpawnTimer <= 0) {
			enemySpawnTimer = 5.0f;
			spawnEnemy();
		}

		break;
	case GameState::HesRottingYouKnow:

		titleText->Create(getEngine().getRenderer(), "you died, press R to restart.", vec3{ 1,0,0 });
		if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_R)) {
			current_state = GameState::StartGame;
		}

		// player dies, you can restart 3 times
		break;
	case GameState::YouFuckingSuck:
		// close game
		break;
	}
}

void SpaceGame::GTFO()
{
}

void SpaceGame::Draw(parabellum::Renderer& renderer)
{
	m_scene->Draw(renderer);
	if (current_state == GameState::Title) {
		titleText->Draw(getEngine().getRenderer(), 25, 25);

	}

	else if (current_state == GameState::HesRottingYouKnow) {
		titleText->Draw(getEngine().getRenderer(), 0, 0);

	}
	else if (current_state == GameState::ComeGetSome) {
		scoreText->Draw(getEngine().getRenderer(), 30, 30);
	}
}

void parabellum::SpaceGame::onPlayerDead()
{
	setLives(getLives() - 1);
	if (getLives() > 0) {
		current_state = GameState::HesRottingYouKnow;
		// you can press R to restart. afterwards the game closes
	}
}

void parabellum::SpaceGame::spawnEnemy() // use Instantiate here later
{
	/*
	Actor* player = m_scene->GetActorByName("player");
	if (player) {
		Transform transform{ vec2{ parabellum::random::getReal(1280.0f), parabellum::random::getReal(1024.0f)  }, 0, 5.0f };

		//auto model = Resources().Get<Texture>("spr_enemy_default.png", getEngine().getRenderer());
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform);
		enemy->name = "enemy";
		enemy->tag = "enemy";
		enemy->speed = 350;

	   // auto spriteRenderer = std::make_unique<parabellum::SpriteRenderer>();
		//spriteRenderer->textureName = "spr_enemy_default.png";

		std::unique_ptr<parabellum::RigidBody> rb = std::make_unique<parabellum::RigidBody>();
		enemy->addComponent(std::move(rb));

		auto collider = std::make_unique<CircleCollide2D>();
		collider->radius = 60;
		enemy->addComponent(std::move(collider));

		//enemy->addComponent(std::move(spriteRenderer));
		auto mesh = std::make_unique<MeshRenderer>();
		mesh->meshName = "Meshes/enemy.txt";
		enemy->addComponent(std::move(mesh));
		m_scene->AddActor(std::move(enemy));
	}


	*/
}
void::parabellum::SpaceGame::spawnPlayer() { // use Instantiate here later
	/*
	player->name = "Player";
	player->tag = "player";
	player->speed = 500;
	player->rotationRate = 2000;

	//components
	auto spriteRenderer = std::make_unique<parabellum::SpriteRenderer>();
	spriteRenderer->textureName = "spr_enemy_default.png";


	auto collider = std::make_unique<CircleCollide2D>();
	collider->radius = 60;
	player->addComponent(std::move(collider));

	std::unique_ptr<parabellum::RigidBody> rb = std::make_unique<parabellum::RigidBody>();
	player->addComponent(std::move(rb));

	player->addComponent(std::move(spriteRenderer)); // you need to transfer ownership, therefore, be sure to std::move!




	m_scene->AddActor(std::move(player));
	*/
	
}
