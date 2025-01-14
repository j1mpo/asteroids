#pragma once
#include "gameobject.h"
#include "sgg/graphics.h"
#include <list>
#include "asteroid.h"
#include <string>

class Level : public GameObject {

	graphics::Brush m_brush_background;
	std::vector<Asteroid*> m_asteroids;
	float m_center_x = 0.5f;
	float m_center_y = 0.5f;

	std::vector<GameObject*> m_static_object;
	std::list<GameObject*> m_dynamic_object;

public:
	void update(float dt) override;
	void init() override;
	void draw() override;
	Level(const std::string& name = "level0");
	~Level();
};
