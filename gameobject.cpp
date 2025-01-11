#include "gameobject.h"
#include "gamestate.h"



GameObject::GameObject(GameState* state, const std::string& name)
    : m_state(state), m_name(name), m_pos_x(0), m_pos_y(0) {
   
}
