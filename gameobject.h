#pragma once
#include <string>

class GameState;

class GameObject {
protected:
    float m_pos_x, m_pos_y;
    GameState* m_state;
    std::string m_name;
    bool m_active = true;

public:
    GameObject(const std::string& name = "");  // Δήλωση χωρίς σώμα
    virtual void update(float dt) = 0;
    virtual void init() {}
    virtual void draw() {}
    bool isActive() { return m_active; }
    void setActive(bool a) { m_active = a; }

    virtual ~GameObject() {}
};
