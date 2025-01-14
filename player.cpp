#include "player.h"
#include "game.h"
#include <sgg/graphics.h>

Player::Player(const Game& mygame)
    : GameObject(mygame)
{
}




void Player::update() {
   // float delta_time = dt / 1000.0f;

    if (graphics::getKeyState(graphics::SCANCODE_A))
    {
        pos_x -= speed * graphics::getDeltaTime() / 10.0f;
    }
    if (graphics::getKeyState(graphics::SCANCODE_D))
    {
        pos_x += speed * graphics::getDeltaTime() / 10.0f;
    }if (graphics::getKeyState(graphics::SCANCODE_W))
    {
        pos_y -= speed * graphics::getDeltaTime() / 10.0f;
    }if (graphics::getKeyState(graphics::SCANCODE_S))
    {
        pos_y += speed * graphics::getDeltaTime() / 10.0f;
    }
    if (graphics::getKeyState(graphics::SCANCODE_DOWN))
    {
    
    height -= 0.01f * graphics::getDeltaTime();
    if (height < 0.1f)
        height = 0.1f;
    }
    if (graphics::getKeyState(graphics::SCANCODE_UP))
    {

        height += 0.01f * graphics::getDeltaTime();
        if (height > 3.0f)
            height = 3.0f;
    }

    //GameObject::update(dt);
}

void Player::init() {
    
   // m_pos_x = 5.0f;
    //m_pos_y = 5.0f;

    // Κανονικό sprite του Player
    //m_brush_player.fill_opacity = 1.0f;
    //outline_opacity = 0.0f;
   // m_brush_player.texture = m_state->getFullAssetPath("t2.png.png");

    // Αρχικοποίηση για το glow brush
    //m_brush_glow = m_brush_player;  // Ξεκινάμε με τις ρυθμίσεις του brush του παίκτη
    //m_brush_glow.fill_opacity = 0.5f;  // Ρύθμιση διαφάνειας για το glow
    //m_brush_glow.outline_opacity = 0.0f;

    // Τοποθέτηση του παίκτη στο κέντρο της οθόνης
   // float w = m_state->getCanvasWidth();
   // float h = m_state->getCanvasHeight();
    //m_pos_x = w / 0.45f;  // Κέντρο X
   // m_pos_y = h / 0.45f;  // Κέντρο Y

}

void Player::draw() 
{

    // Σχεδιάζουμε το Glow Effect γύρω από το sprite με μεγαλύτερο μέγεθος
    //graphics::drawRect(m_pos_x, m_pos_y, 10.0f, 10.0f, m_brush_glow);  // Μεγαλύτερο μέγεθος για το glow

   // graphics::drawRect(m_pos_x, m_pos_y, 6.0f, 6.0f, m_brush_player);
    
    float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime() / 10);
    
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    graphics::setOrientation(-90.f);
    graphics::setScale(height, height);
    br.fill_opacity = 1.0f;
    br.texture = std::string(ASSET_PATH) + "t2.png.png";
    graphics::drawRect(pos_x, pos_y, 100, 100, br);

    graphics::resetPose();

    br.texture = "";
    br.fill_color[0] = 1.0f;
    br.fill_color[1] = 0.5f + glow * 0.5f;
    br.fill_color[2] = 0.0f;
    br.fill_secondary_color[0] = 0.3f;
    br.fill_secondary_color[1] = 0.1f;
    br.fill_secondary_color[2] = 0.0f;
    br.fill_opacity = 1.0f;
    br.fill_secondary_opacity = 0.0f;
    br.gradient = true;
    graphics::setScale(height, height);
    graphics::drawDisk(pos_x - 50 * height, pos_y, 20, br);
    graphics::resetPose();


    if (game.getDebugModel())
    {
        br.outline_opacity = 1.0f;
        br.texture = "";
        br.fill_color[0] = 0.3f;
        br.fill_color[1] = 1.0f;
        br.fill_color[2] = 0.3f;
        br.fill_opacity = 0.3f;
        br.gradient = false;
        Disk hull = getCollisionHull();
        graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);
    }



}



Disk Player::getCollisionHull() const
{
    Disk disk;
    disk.cx = pos_x;
    disk.cy = pos_y;
    disk.radius = 55.0f;
    return disk;
}
