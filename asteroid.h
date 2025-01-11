#pragma once
#include "box.h"
#include <sgg/graphics.h>

class Asteroid {
public:
    Asteroid(float x, float y, float width, float height, const std::string& texture);

    void update(float dt);
    void draw();
    void explode();  // Λογική για την έκρηξη του μετεωρίτη
    Box getBox() { return m_box; }

private:
    Box m_box;
    graphics::Brush m_brush;
};
