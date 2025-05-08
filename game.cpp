#include <sgg/graphics.h>
#include "config.h"
#include "game.h"

int collision_count = 0;

void Game::update()
{
	if (status == STATUS_START)
	{
		updateStartScreen();

	}
	else if (status == STATUS_PLAYING)
	{
		updateLevelScreen();
		if (!player_initialized && graphics::getGlobalTime() > 1000)
		{
			player = new Player(*this); //dhmiourgia paikth
			player_initialized = true;
		}

		if (player)
			player->update();

		checkBurger();
		spawnBurger();


		for (Enemy* enemy : enemies)
		{
			enemy->update();

			if (checkCollision(player, enemy))
			{
				if (status == STATUS_PLAYING)// FIX BUG ENDSCREEN
					collision_count++;
				graphics::playSound(std::string(ASSET_PATH) + "sl.mp3", 0.5f, false);
				delete enemy;
				enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end()); //vgale apo vector to burger pou ekane collision
				break;
			}
		}

		if (player && player->getRemainingLife() <= 0.0f)
		{
			status = STATUS_END; // allaje se endscreen otan teleiwsei h zwh
		}
	}
	else if (status == STATUS_END)
	{
		updateEndScreen();
	}


}



void Game::draw() //analoga to status kane draw to antistoixo screen
{
	if (status == STATUS_START)
	{
		drawStartScreen();
	}
	else if (status == STATUS_PLAYING)
	{
		drawLevelScreen();

		for (Enemy* enemy : enemies) //emfanise ta burger sto vector
		{
			enemy->draw();
		}
	}
	else if (status == STATUS_END)
	{
		drawEndScreen();
	}


}

void Game::spawnBurger()
{
	//kane spawn neo burger otan to prohgoumeno ftasei stin mesh 
	if (enemies.empty() || enemies.back()->getPosY() >= CANVAS_HEIGHT / 2)
	{

		Enemy* burger = new Enemy(*this);
		burger->init();
		enemies.push_back(burger);
	}
}







void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "krab.ttf.ttf"); //fonts
	graphics::playMusic(std::string(ASSET_PATH) + "so.mp3", 0.5f, true, 4000); //mousikh



}

float Game::window2canvasX(float x) //canvas/window settings
{
	return x * CANVAS_WIDTH / (float)window_width;
}

float Game::window2canvasY(float y)
{
	return  y * CANVAS_HEIGHT / (float)window_height;
}

Game::Game()
{

}

void Game::checkBurger()
{

	for (auto it = enemies.begin(); it != enemies.end(); )
	{
		if (!(*it)->isActive())
		{

			if (player)
			{
				player->drainLife(0.2f); // an den anei collision meiwse thn zwh kata 0.2f
			}
			delete* it;
			it = enemies.erase(it); //diagrafh otan den einai active
		}
		else
		{
			++it;
		}
	}

}

bool Game::checkCollision(Player* player, Enemy* enemy)
{
	if (!player || !enemy)
	{
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = enemy->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	//elegxos an ta 2 hitbox akoumpisoun kai ayjhsh ths zwhs tou plankton kata 0.1f
	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		player->gainLife(0.1f);
		return true;
	}
	else
		return false;
}

void Game::updateStartScreen()
{
	//press enter sto startscreen
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		status = STATUS_PLAYING;
	}





}

void Game::updateLevelScreen()
{

}

void Game::updateEndScreen()
{

	//press enter sto endscreen
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		restartGame();
	}
}

void Game::drawStartScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "bikini.png"; //background start
	br.outline_opacity = 0.0f;


	graphics::drawRect(window_width / 2, window_height / 2, window_width, window_height, br);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);



	char info[40];
	sprintf_s(info, " Press enter for krabby patties ");




	float font_size = 25;
	float text_x = CANVAS_WIDTH / 3.5; //topothetish keimenou
	float text_y = CANVAS_HEIGHT / 5.5;
	br.fill_color[0] = 1.0f; //kitrino (rgb)
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 0.0f;

	graphics::drawText(text_x, text_y, font_size, info, br);


	/* ???????? ??? ??????? ??? ??????????
	float image_size_width = 144; // ?????? ??????? (1.2 ????? ?????????? ??? ??? ??????)
	float image_size_height = 96; // ???? ??????? (1.2 ????? ?????????? ??? ??? ??????)
	float x_offset = CANVAS_WIDTH / 2 - (image_size_width * 2.5f); // ???????? ??? ???????? ??? ???????????

	std::string characters[] = {
		"k.png",
		"sa.png",
		"pat.png",
		"sp.png"
	};

	// ???????? ??? ??????? ??? ??? ???????? ???? ????
	for (int i = 0; i < 4; ++i)
	{
		br.texture = std::string(ASSET_PATH) + characters[i];
		graphics::drawRect(x_offset + (i * (image_size_width + 20)), CANVAS_HEIGHT - image_size_height / 2, image_size_width, image_size_height, br);
	}

	// ??????? ??? ?? ???????
	char info[40];
	float text_y = CANVAS_HEIGHT - image_size_height / 2 - 25; // ?????????? ???????? ???? ??? ??? ??????
	float font_size = 20;
	for (int i = 0; i < 4; ++i)
	{
		sprintf_s(info, "Press %c for %s", "kspb"[i], characters[i].substr(0, characters[i].find('.')).c_str());
		br.fill_color[0] = 1.0f; // ??????? ?????
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.0f;
		graphics::drawText(x_offset + (i * (image_size_width + 20)), text_y, font_size, info, br);
	}
	*/





}

void Game::drawLevelScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "out1.png"; //background
	br.outline_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 3, CANVAS_WIDTH, CANVAS_WIDTH, br);

	if (player)
		player->draw();
	if (burger)
		burger->draw();

	if (player && debug_mode)
	{
		char info[40];
		sprintf_s(info, "Player pos: (%5.1f, %5.1f)", player->getPosX(), player->getPosY()); //emfanizei cords an thesw DebugModel true
		graphics::drawText(20, 20, 15, info, br);

	}


	//counter
	char collision_info[40];
	sprintf_s(collision_info, "Krabby Patties: %d", collision_count);
	br.fill_color[0] = 1.0f; // kitrino
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 0.0f;
	graphics::drawText(20, 350, 25, collision_info, br);


	//lifebar
	float player_life = player ? player->getRemainingLife() : 0.0f;

	br.outline_opacity = 0.0f;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;
	br.texture = "";
	br.fill_secondary_color[0] = 1.0f * (1.0f - player_life);  //allajh xrwmatos kathws xanei zwh
	br.fill_secondary_color[1] = 1.0f * player_life;
	br.fill_secondary_color[2] = 0.0f;
	br.gradient = true;
	br.gradient_dir_u = 1.0f;
	br.gradient_dir_v = 0.0f;


	graphics::drawRect(CANVAS_WIDTH - 100 - ((1.0f - player_life) * 120 / 2), 30, player_life * 120, 20, br); //zwh

	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 20, br);	//perigramma

}

void Game::drawEndScreen()
{

	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "end.png";
	br.outline_opacity = 0.0f;

	graphics::drawRect(window_width / 2, window_height / 2, window_width, window_height, br);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	// game over
	char text[40];
	sprintf_s(text, "Game Over! Final Score: %d", collision_count);
	br.fill_color[0] = 1.0f; //kitrino
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 0.0f;
	graphics::drawText(CANVAS_WIDTH / 3, CANVAS_HEIGHT / 3, 30, text, br);

	//  "Press Enter to Restart"
	sprintf_s(text, "Press Enter to Restart");
	graphics::drawText(CANVAS_WIDTH / 3, CANVAS_HEIGHT / 3 + 50, 20, text, br);
}



void Game::restartGame()
{
	// Reset player and enemies
	if (player)
	{
		delete player;
		player = nullptr;
	}
	for (auto enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();

	// Reset metavlites
	player_initialized = false;
	collision_count = 0;
	status = STATUS_START; // start screen
}

Game::~Game()
{
	if (player)
	{
		delete player;
	}
}
