// GameState.cpp

#include "gamestate.h"
#include "level.h"
#include "player.h"

void GameState::init()
{
    // ??? ??????? ?? GameState ??? ?? ????????? ??? ????? ??? ???? Player
    m_current_level = new Level("Level0");
    m_current_level->init();

    m_player = new Player(this, "Player"); // ??????? ??? GameState ??? Player
    m_player->init();

    graphics::preloadBitmaps(getAssetDir());
    graphics::setFont(m_asset_path + "font.ttf");
}
