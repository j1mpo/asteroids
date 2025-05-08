#pragma once
#include <vector>
#include "player.h"
#include "Enemy.h"

class Game
{
	std::vector<Enemy*> enemies; //burgers
	typedef enum { STATUS_START, STATUS_PLAYING, STATUS_END } status_t; //status othonis
	Player* player = nullptr;
	bool player_initialized = false;
	bool debug_mode = false;
	Enemy* burger = nullptr;
	void spawnBurger();
	void checkBurger();
	bool checkCollision(Player* player, Enemy* enemy);
	status_t status = STATUS_START;

	unsigned int window_width = WINDOW_WIDTH,
		window_height = WINDOW_HEIGHT;




	void updateStartScreen();
	void updateLevelScreen();
	void updateEndScreen();
	void drawStartScreen();
	void drawLevelScreen();
	void drawEndScreen();



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
	void restartGame();
	Game();
	~Game();




};
