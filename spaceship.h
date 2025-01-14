pragma once
#include <vector>
#include <string>
#include "Box.h"
#include "Bullet.h"
#include <sgg/graphics.h>

class Spaceship {
public:
    Spaceship(float x, float y, const std::string& texture);

    void update(float dt);
    void draw();
    void shoot(std::vector<Bullet>& bullets);
    void moveLeft(float dt);
    void moveRight(float dt);
    void moveUp(float dt);
    void moveDown(float dt);
    bool checkCollision(const Box& otherBox);

private:
    Box m_box;
    std::string m_texture;
    graphics::Brush m_brush;
};
