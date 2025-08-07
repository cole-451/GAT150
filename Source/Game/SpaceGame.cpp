#include "SpaceGame.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Core/Random.h"
#include "Player.h"
#include "Enemy.h"
#include "Math/Transform.h"
#include <memory>
#include "Framework/Scene.h"
#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "GameData.h"
#include "Framework/Game.h"
#include "Resources/ResourceManager.h"

using namespace parabellum;
bool SpaceGame::initialize() 
{
    //m_titleFont = std::make_shared<Font>();

     m_scoreFont = std::make_shared<Font>();
   // m_titleFont->Load("Brianne_s_hand.ttf", 30);
     m_scoreFont->Load("Brianne_s_hand.ttf", 50);

    titleText = std::make_unique<Text>(parabellum::ResourceManager::Instance().GetWithID<parabellum::Font>("Brianne_s_hand.ttf", "start_font", 30));
    titleText->Create(getEngine().getRenderer(), "press k to start", vec3{ 1,1,1 });
    scoreText = std::make_unique<Text>(m_scoreFont);
    scoreText->Create(getEngine().getRenderer(), "" + std::to_string(m_score), vec3{0,1,0});

    m_scene = std::make_unique<Scene>(this);
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
        current_state = GameState::StartGame;
        }
        m_lives = 3;
        break;

    case GameState::StartGame:
        m_score = 0;
       // scoreText->Draw(getEngine().getRenderer(), 25, 25);
        getEngine().getAudioSys().playSound("music");
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
        
        //current_state = GameState::HesRottingYouKnow;
        break;
    case GameState::HesRottingYouKnow:

        titleText->Create(getEngine().getRenderer(), "you died, press R to restart." , vec3{1,0,0});
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
    if (current_state == GameState::Title) {
        titleText->Draw(getEngine().getRenderer(), 25, 25);

    }

    else if (current_state == GameState::HesRottingYouKnow) {
        titleText->Draw(getEngine().getRenderer(), 0, 0);

    }
    else if (current_state == GameState::ComeGetSome) {
        scoreText->Draw(getEngine().getRenderer(), 30, 30);
    }
    m_scene->Draw(renderer);
}

void parabellum::SpaceGame::onPlayerDead()
{
    setLives(getLives()- 1);
    if (getLives() > 0) {
        current_state = GameState::HesRottingYouKnow;
        // you can press R to restart. afterwards the game closes
    }
}

void parabellum::SpaceGame::spawnEnemy()
{
    Actor* player = m_scene->GetActorByName("player");
    if (player) {    
        Transform transform{ vec2{ parabellum::random::getReal() * 1280, parabellum::random::getReal() * 1024 }, 0, 10 };


        std::shared_ptr<Model> model = std::make_shared<Model>(GameData::enemyPoints, vec3{ 1.0f, 0.0f, 0.0f });
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, model);
        enemy->name = "enemy";
        enemy->tag = "enemy";
        enemy->speed = 350;
        m_scene->AddActor(std::move(enemy));
    }

    
    
}
    void::parabellum::SpaceGame::spawnPlayer() {
        //std::shared_ptr<Model> model = std::make_shared<Model>(GameData::shipPoints, vec3{ 1.0f, 0.5f, 0.0f });



        Transform tf(vec2{ 500,500 }, 0.0f, 5.0f);
        auto player = std::make_unique<Player>(tf, Resources().Get<Texture>("spr_enemy_default.png")); // renderer is not in the constructor
        player->name = "Player";
        player->tag = "player";
        player->speed = 500;
        player->rotationRate = 2000;

        m_scene->AddActor(std::move(player));
    }
