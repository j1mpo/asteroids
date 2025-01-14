#include "level.h"
#include "gamestate.h"
#include "player.h"
#include "asteroid.h"



void Level::update(float dt)
{
	for (auto asteroid : m_asteroids) {
		asteroid->update(dt);
	}
	
	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->update(dt);

	

}

void Level::init()
{
	m_state->getPlayer()->init();

	for (auto p_gob : m_static_object)
		if (p_gob) p_gob->init();

	for (auto p_gob : m_dynamic_object)
		if (p_gob) p_gob->init();
}

void Level::draw()
{
	float w = m_state->getCanvasWidth();
	float h = m_state->getCanvasHeight();

	//float offset_x = m_state->m_global_offset_x + w / 2.0f;
	//float offset_y = m_state->m_global_offset_y + h / 2.0f;

	// Draw background
	graphics::drawRect(m_state->getCanvasWidth(), m_state->getCanvasHeight(), 7.0f * w, 4.0f * w, m_brush_background);

	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->draw();

	for (auto asteroid : m_asteroids) {
		asteroid->draw();
	}

}

Level::Level(const std::string& name) :GameObject(name)
{
	m_brush_background.outline_opacity = 0.0f;
	m_brush_background.texture = m_state->getFullAssetPath("background.png");

	m_asteroids.push_back(new Asteroid(100.0f, -50.0f, 50.0f, 50.0f, "asteroid_1.png"));
	m_asteroids.push_back(new Asteroid(300.0f, -150.0f, 50.0f, 50.0f, "asteroid_2.png"));
	m_asteroids.push_back(new Asteroid(500.0f, -250.0f, 50.0f, 50.0f, "asteroid_3.png"));
	m_asteroids.push_back(new Asteroid(700.0f, -350.0f, 50.0f, 50.0f, "asteroid_4.png"));
}

Level::~Level()
{
	for (auto asteroid : m_asteroids) {
		delete asteroid;
	}
}
