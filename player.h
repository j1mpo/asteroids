// Player.h

#pragma once
#include "gameobject.h"
#include "box.h"
#include <sgg/graphics.h>

class Player : public GameObject, public Box
{
    graphics::Brush m_brush_player;

public:
    // ???, ? ????????????? ????? ??? ???????????? ??? GameObject ?? ?? GameState*
    Player(GameState* state, std::string name = "Player") : GameObject(state, name) {}

    void update(float dt) override;
    void init() override;
    void draw() override;
};
