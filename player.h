#pragma once
#include "gameobject.h"
#include "box.h"
#include <sgg/graphics.h>

class Player : public GameObject {
   
    //graphics::Brush m_brush_player;  // Brush για το κανονικό sprite
    //graphics::Brush m_brush_glow;    // Brush για το glow effect
    graphics::Brush m_brush_player;
    Box m_box;

public:
    // Default Constructor
    //Player() : GameObject("Default"), m_box(0, 0, 1, 1) {}

    // Constructor με παραμέτρους
    Player(std::string name) : GameObject(name), m_box(0, 0, 1, 1) {}

    void update(float dt) override;
    void init() override;
    void draw() override;



};
