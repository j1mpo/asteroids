#include "asteroid.h"
#include "gamestate.h"

Asteroid::Asteroid(std::string name) : GameObject(name), m_velocity(1.0f) {}

void Asteroid::init()
{
    m_pos_x = 10.0f;
    m_pos_y = 10.0f;
    m_width = 1.0f;
    m_height = 1.0f;

    m_brush_asteroid.fill_opacity = 1.0f;
    m_brush_asteroid.outline_opacity = 0.0f;
    m_brush_asteroid.texture = m_state->getFullAssetPath("asteroid.png");
}

void Asteroid::update(float dt)
{
    m_pos_x += m_velocity * dt;  // ?????? ??? ????????????

    if (m_pos_x > m_state->getCanvasWidth())
        m_pos_x = 0.0f;  // ????????? ??? ???????????? ???? ???? ??? ??? ?????
}

void Asteroid::draw()
{
    graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_brush_asteroid);
}
