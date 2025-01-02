#include "player.h"

void Player::update(float dt)
{
    float delta_time = dt / 1000.0f;
    const float v = 10.0f;

    if (graphics::getKeyState(graphics::SCANCODE_A))
        m_pos_x -= v * delta_time;
    if (graphics::getKeyState(graphics::SCANCODE_D))
        m_pos_x += v * delta_time;
    if (graphics::getKeyState(graphics::SCANCODE_W))
        m_pos_y -= v * delta_time;
    if (graphics::getKeyState(graphics::SCANCODE_S))
        m_pos_y += v * delta_time;

    m_state->m_global_offset_x = m_state->getCanvasWidth() / 2.0f - m_pos_x;
    m_state->m_global_offset_y = m_state->getCanvasHeight() / 2.0f - m_pos_y;
}

void Player::init()
{
    m_pos_x = 5.0f;
    m_pos_y = 5.0f;

    m_state->m_global_offset_x = m_state->getCanvasWidth() / 2.0f - m_pos_x;
    m_state->m_global_offset_y = m_state->getCanvasHeight() / 2.0f - m_pos_y;

    m_brush_player.fill_opacity = 1.0f;
    m_brush_player.outline_opacity = 0.0f;
    m_brush_player.texture = m_state->getFullAssetPath("hero.png");
}

void Player::draw()
{
    graphics::drawRect(m_state->getCanvasWidth() * 0.5f, m_state->getCanvasHeight() * 0.5f, 1.0f, 1.0f, m_brush_player);
}
