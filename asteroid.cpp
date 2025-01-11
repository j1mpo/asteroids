#include "asteroid.h"
#include <sgg/graphics.h>

Asteroid::Asteroid(float x, float y, float width, float height, const std::string& texture)
    : m_box(x, y, width, height) {
    m_brush.texture = texture;
}

void Asteroid::update(float dt) {
    m_box.m_pos_y += m_box.velocity * dt;
}

void Asteroid::draw() {
    graphics::drawRect(m_box.m_pos_x, m_box.m_pos_y, m_box.m_width, m_box.m_height, m_brush);
}

void Asteroid::explode() {
    // Εδώ προσθέτουμε λογική για την έκρηξη
    // Αυτό μπορεί να περιλαμβάνει τη διαγραφή του μετεωρίτη ή τη μετατροπή του σε ερείπια
}
