#include "gamestate.h"
#include "player.h"

GameState* GameState::m_unique_instance = nullptr;

GameState::GameState() {
    // Αρχικοποίηση του game state
}

void GameState::init() {
    m_player = new Player();
    m_player->init();
}

void GameState::draw() {
    // Σχεδίαση του παιχνιδιού
    m_player->draw();
}

void GameState::update(float dt) {
    // Ενημέρωση του παιχνιδιού
    m_player->update(dt);
}

GameState* GameState::getInstance() {
    if (!m_unique_instance) {
        m_unique_instance = new GameState();
    }
    return m_unique_instance;
}

GameState::~GameState() {
    delete m_player;
}
