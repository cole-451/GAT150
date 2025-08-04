#pragma once
#include "Scene.h"

#include <memory>
namespace parabellum {
	class Game {
	public:
		Game() = default;




		virtual bool initialize() = 0;
		virtual void Update() = 0;
		virtual void GTFO() = 0;
		virtual void Draw(class Renderer& renderer) = 0;
		
		void addPoints(int points) {
			m_score += points;
		}

		int getPoints() { return m_score; }

		int getLives() { return m_lives; }

		void setLives(int lives) { m_lives = lives; }
	
	protected:
		//list of what needs to be made?
		//std::unique_ptr<Scene> m_scene;
		int m_score;
		int m_lives;
	};


}