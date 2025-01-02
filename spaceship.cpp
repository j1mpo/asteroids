#include "Spaceship.h"

Spaceship::Spaceship(float x, float y, const std::string& texture)
    : m_pos_x(x), m_pos_y(y), m_texture(texture) {
    m_brush.texture = texture;  // ???????? ??? ??? (texture) ??? ?? brush
}

void Spaceship::update(float dt) {
    // ????????? ??? bullets
    for (auto& bullet : m_bullets) {
        bullet.update(dt);
    }
}

void Spaceship::draw() {
    // ???????? ??? ??????????????
    graphics::drawRect(m_pos_x, m_pos_y, 64, 64, m_brush);  // ??????????? ?? ?????????????

    // ???????? ??? bullets
    for (auto& bullet : m_bullets) {
        bullet.draw();
    }
}

void Spaceship::shoot() {
    Bullet new_bullet(m_pos_x, m_pos_y - 25.0f, 5.0f, 10.0f, "bullet.png", 0.0f, 10.0f);
    m_bullets.push_back(new_bullet);
}

void Spaceship::moveLeft(float dt) {
    m_pos_x -= 5.0f * dt;
}

void Spaceship::moveRight(float dt) {
    m_pos_x += 5.0f * dt;
}
