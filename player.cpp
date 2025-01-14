#include "player.h"
#include "gamestate.h"
#include <sgg/graphics.h>

void Player::update(float dt) {
    float delta_time = dt / 1000.0f;

    if (graphics::getKeyState(graphics::SCANCODE_A)) m_pos_x -= 65.0f * delta_time;
    if (graphics::getKeyState(graphics::SCANCODE_D)) m_pos_x += 65.0f * delta_time;
    if (graphics::getKeyState(graphics::SCANCODE_W)) m_pos_y -= 65.0f * delta_time;
    if (graphics::getKeyState(graphics::SCANCODE_S)) m_pos_y += 65.0f * delta_time;

    //GameObject::update(dt);
}

void Player::init() {
    
    m_pos_x = 5.0f;
    m_pos_y = 5.0f;

    // Κανονικό sprite του Player
    m_brush_player.fill_opacity = 1.0f;
    m_brush_player.outline_opacity = 0.0f;
    m_brush_player.texture = m_state->getFullAssetPath("t2.png.png");

    // Αρχικοποίηση για το glow brush
    //m_brush_glow = m_brush_player;  // Ξεκινάμε με τις ρυθμίσεις του brush του παίκτη
    //m_brush_glow.fill_opacity = 0.5f;  // Ρύθμιση διαφάνειας για το glow
    //m_brush_glow.outline_opacity = 0.0f;

    // Τοποθέτηση του παίκτη στο κέντρο της οθόνης
    float w = m_state->getCanvasWidth();
    float h = m_state->getCanvasHeight();
    m_pos_x = w / 0.45f;  // Κέντρο X
    m_pos_y = h / 0.45f;  // Κέντρο Y

}

void Player::draw() {

    // Σχεδιάζουμε το Glow Effect γύρω από το sprite με μεγαλύτερο μέγεθος
    //graphics::drawRect(m_pos_x, m_pos_y, 10.0f, 10.0f, m_brush_glow);  // Μεγαλύτερο μέγεθος για το glow

    graphics::drawRect(m_pos_x, m_pos_y, 6.0f, 6.0f, m_brush_player);
}
