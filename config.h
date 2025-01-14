#pragma once

// Διαστάσεις οθόνης
#define CANVAS_WIDTH  1000
#define CANVAS_HEIGHT 500

// Διαδρομή για τα assets
#define ASSET_PATH "assets/"

// Άλλες ρυθμίσεις
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600
#define GAME_DEBUG 

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
