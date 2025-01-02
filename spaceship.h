#pragma once
#include <string>
#include <sgg/graphics.h>
#include <vector>
#include "bullet.h"

class Spaceship {
public:
    Spaceship(float x, float y, const std::string& texture);

    void update(float dt);
    void draw();
    void shoot();
    void moveLeft(float dt);
    void moveRight(float dt);

    graphics::Brush getBrush() const { return m_brush; }  // ???????? ??? ?????????? getBrush

private:
    float m_pos_x, m_pos_y;
    std::string m_texture;
    graphics::Brush m_brush;  // Brush ??? ?? ?????????????
    std::vector<Bullet> m_bullets;
};
;