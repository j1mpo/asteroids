#include "player.h"
#include "gamestate.h"
#include <sgg/graphics.h>

void Player::update(float dt) {
    float delta_time = dt / 1000.0f;

    if (graphics::getKeyState(graphics::SCANCODE_A)) m_pos_x -= 10.0f * delta_time;
    if (graphics::getKeyState(graphics::SCANCODE_D)) m_pos_x += 10.0f * delta_time;
    if (graphics::getKeyState(graphics::SCANCODE_W)) m_pos_y -= 10.0f * delta_time;
    if (graphics::getKeyState(graphics::SCANCODE_S)) m_pos_y += 10.0f * delta_time;
}

void Player::init() {
    m_brush_player.fill_opacity = 1.0f;
    m_brush_player.outline_opacity = 0.0f;
    m_brush_player.texture = m_state->getFullAssetPath("hero.png");
}

void Player::draw() {
    graphics::drawRect(m_pos_x, m_pos_y, 1.0f, 1.0f, m_brush_player);
}
