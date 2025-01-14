#pragma once
//#include <string>
#include "util.h"

class Collidable
{
public:
    virtual Disk getCollisionHull() const = 0;


};

class GameObject {

protected:
    const class Game& game;

    //protected:
       // float m_pos_x, m_pos_y;
       // GameState* m_state;
       // std::string m_name;
       // bool m_active = true;

public:

    GameObject(const class Game& mygame); //std::string& name = "");  // ?????? ????? ????
    virtual void update() = 0;
    virtual void init() = 0;
    virtual void draw() = 0;
    //bool isActive() { return m_active; }
    //void setActive(bool a) { m_active = a; }

   // virtual ~GameObject() {}
};
