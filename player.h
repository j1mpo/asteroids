#pragma once
#include "gameobject.h"
#include "box.h"
#include <sgg/graphics.h>

class Player : public GameObject {
    graphics::Brush m_brush_player;
    Box m_box;

public:
    // Default Constructor
    Player() : GameObject(nullptr, "Default"), m_box(0, 0, 1, 1) {}

    // Constructor με παραμέτρους
    Player(GameState* state, const std::string& name = "Player")
        : GameObject(state, name), m_box(0, 0, 1, 1) {
    }

    void update(float dt) override;
    void init() override;
    void draw() override;
};
