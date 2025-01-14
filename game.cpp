#include <sgg/graphics.h>
#include "config.h"
#include "game.h"


void Game::update()
{
	if (status == STATUS_START)
	{
		updateStartScreen();
	}
	else
	{
		updateLevelScreen();
	}
	
	

	if (!player_initialized && graphics::getGlobalTime() > 1000)
	{
		player = new Player(*this);
		player_initialized = true;
	}

	if (player)
		player->update();

	checkMeterorite();
	spawnMeteorite();

	if (meteorite)
		meteorite->update();

	if (checkCollision())
	{
		delete meteorite;
		meteorite = nullptr;
	}
}



void Game::draw()
{
	if (status == STATUS_START)
	{
		drawStartScreen();
	}
	else
	{
		drawLevelScreen();
	}


}

void Game::spawnMeteorite()
{
	if (!meteorite)  // Αν δεν υπάρχει ήδη μετεωρίτης, τότε δημιουργούμε νέο
	{
		meteorite = new Enemy(*this);  // Δημιουργία νέου μετεωρίτη
		meteorite->init();  // Εκκίνηση του μετεωρίτη
	}
}






void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "font.ttf");
	graphics::playMusic(std::string(ASSET_PATH) + "s.mp3", 0.5f, true, 4000);



}

float Game::window2canvasX(float x)
{
	return x * CANVAS_WIDTH / (float) window_width ;
}

float Game::window2canvasY(float y)
{
	return  y * CANVAS_HEIGHT / (float)window_height;
}

Game::Game()
{

}

void Game::checkMeterorite()
{
	if (meteorite && !meteorite->isActive())
	{
		delete meteorite;
		meteorite = nullptr;
	}

}

bool Game::checkCollision()
{
	if (!player || !meteorite)
	{
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = meteorite->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		player->drainLife(0.1f);
		return true;
	}
	else
		return false;
}

void Game::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		status = STATUS_PLAYING;
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	if (ms.button_left_pressed)
	{
		status = STATUS_PLAYING;
	}
}

void Game::updateLevelScreen()
{

}

void Game::drawStartScreen()
{

	graphics::Brush br;
	char info[40];
	sprintf_s(info, "Press enter to take off");
	graphics::drawText(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, 30, info, br);

	graphics::MouseState ms;
	graphics::getMouseState(ms);

	graphics::drawDisk(window2canvasX(ms.cur_pos_x), window2canvasY(ms.cur_pos_y),10,br);

}

void Game::drawLevelScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "background.png";
	br.outline_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	if (player)
		player->draw();
	if (meteorite)
		meteorite->draw();

	if (player && debug_mode)
	{
		char info[40];
		sprintf_s(info, "Player pos: (%5.1f, %5.1f)", player->getPosX(), player->getPosY());
		graphics::drawText(20, 20, 15, info, br);

	}

	float player_life = player ? player->getRemainingLife() : 0.0f;

	br.outline_opacity = 0.0f;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;
	br.texture = "";
	br.fill_secondary_color[0] = 1.0f * (1.0f - player_life) + player_life * 0.2f;
	br.fill_secondary_color[1] = 0.2f;
	br.fill_secondary_color[2] = 0.2f * (1.0f - player_life) + player_life * 1.0f;
	br.gradient = true;
	br.gradient_dir_u = 1.0f;
	br.gradient_dir_v = 0.0f;

	graphics::drawRect(CANVAS_WIDTH - 100 - ((1.0f - player_life) * 120 / 2), 30, player_life * 120 / 2, 20, br);

	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 20, br);

}

Game::~Game()
{
	if (player)
	{
		delete player;
	}
}
