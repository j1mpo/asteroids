#include "spaceship.h"
#include <sgg/graphics.h>

Spaceship::Spaceship(float x, float y, const std::string& texture)
    : m_box(x, y, 50, 50), m_texture(texture) {
    m_brush.texture = m_texture;
}

void Spaceship::update(float dt) {
    // Handle movement
}

void Spaceship::draw() {
    graphics::drawRect(m_box.m_pos_x, m_box.m_pos_y, m_box.m_width, m_box.m_height, m_brush);
}

void Spaceship::shoot(std::vector<Bullet>& bullets) {
    Bullet newBullet(m_box.m_pos_x, m_box.m_pos_y, 10, 20, "bullets.png");
    bullets.push_back(newBullet);
}

void Spaceship::moveLeft(float dt) {
    m_box.m_pos_x -= m_box.velocity * dt;
}

void Spaceship::moveRight(float dt) {
    m_box.m_pos_x += m_box.velocity * dt;
}

void Spaceship::moveUp(float dt) {
    m_box.m_pos_y -= m_box.velocity * dt;
}

void Spaceship::moveDown(float dt) {
    m_box.m_pos_y += m_box.velocity * dt;
}

bool Spaceship::checkCollision(const Box& otherBox) {
    return m_box.intersect(otherBox);
}
