#include "bullet.h"
#include "box.h"

void Bullet::update(float dt) {
    m_box.m_pos_y -= 500.0f * dt; // Κίνηση προς τα πάνω
}

void Bullet::draw() {
    graphics::drawRect(m_box.m_pos_x, m_box.m_pos_y, m_box.m_width, m_box.m_height, m_brush);
}

bool Bullet::checkCollision(Box& otherBox) {
    return m_box.intersect(otherBox);
}

void Bullet::destroy() {
    // Διαγραφή της σφαίρας
    m_box = Box(); // Επαναφορά σε αρχικές τιμές ή όποια άλλη λογική
}
