#include "gamestate.h"
#include "player.h"
#include "level.h"

GameState* GameState::m_unique_instance = nullptr;

GameState::GameState() {
    // Αρχικοποίηση του game state
}

void GameState::init() {
    m_player = new Player("Player1");
    m_player->init();

    m_current_level = new Level();
    m_current_level->init();


}

void GameState::draw() {
    // Σχεδίαση του παιχνιδιού
    if (!m_current_level)
        return;

    m_current_level->draw();
}

void GameState::update(float dt) {
    // Ενημέρωση του παιχνιδιού
    if (dt > 500)
        return;


    if (!m_current_level)
        return;

    m_current_level->update(dt);
}

GameState* GameState::getInstance() {
    if (m_unique_instance == nullptr) {
        m_unique_instance = new GameState();
    }
    return m_unique_instance;
}

GameState::~GameState() {
    if (m_player)
        delete m_player;
}

std::string GameState::getAssetDir() {
    return m_asset_path;
}

std::string GameState::getFullAssetPath(const std::string& asset) {
    return m_asset_path + asset;
}
