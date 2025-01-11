#pragma once
#include <string>

class GameState;

class GameObject {
protected:
    float m_pos_x, m_pos_y;
    GameState* m_state;
    std::string m_name;

public:
    GameObject(GameState* state, const std::string& name);  // Δήλωση χωρίς σώμα
    virtual void update(float dt) = 0;
    virtual void init() = 0;
    virtual void draw() = 0;

    virtual ~GameObject() {}
};
