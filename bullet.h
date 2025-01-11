#pragma once
#include "box.h"
#include <sgg/graphics.h>

class Bullet {
public:
    Bullet(float x, float y, float width, float height, const std::string& texture)
        : m_box(x, y, width, height) {
    }

    void update(float dt);
    void draw();
    bool checkCollision(Box& otherBox);
    void destroy();

private:
    Box m_box;
    graphics::Brush m_brush;
};
