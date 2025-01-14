#pragma once

#include "player.h"
#include "Enemy.h"

class Game
{
//void spawnMeteorite();

	typedef enum { STATUS_START, STATUS_PLAYING } status_t;
	Player* player = nullptr;
	bool player_initialized = false;
	bool debug_mode = false;
	Enemy* meteorite = nullptr;
	void spawnMeteorite();
	void checkMeterorite();
	bool checkCollision();
	status_t status = STATUS_START;

	unsigned int window_width = WINDOW_WIDTH,
				window_height = WINDOW_HEIGHT;




	void updateStartScreen();
	void updateLevelScreen();
	void drawStartScreen();
	void drawLevelScreen();

	
	//bool Game::checkCollision()
	//{

		//return false;
	//}

	//void Game::update()
	//{

		//if (!player_initialized && graphics::getGlobalTime() > 1000)
		//{
		//	player = new Player(*this);
	//		player_initialized = true;

		//}

	//}

public:
	void setDebugModel(bool d) { debug_mode = d; }
	bool getDebugModel() const { return debug_mode; }
	void update();
	void draw();
	void init();
	unsigned int getWindowWidth() { return window_width; }
	unsigned int getWindowHeight() { return window_height; }
	float window2canvasX(float x);
	float window2canvasY(float y);
	void setWindowDimensions(unsigned int w, unsigned int h) { window_width = w; window_height = h; }

	Game();
	~Game();




};
