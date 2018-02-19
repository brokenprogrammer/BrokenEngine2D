#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H
#pragma once

#include "BrokenEngine2D.hpp"
#include "Input.hpp"
#include "Graphics.hpp"

class SimpleGame : public BrokenEngine2D
{
public:
	SimpleGame() : BrokenEngine2D() {}
	SimpleGame(Graphics* t_graphics) : BrokenEngine2D(t_graphics) {}
	SimpleGame(const SimpleGame&) = default;

	SimpleGame& operator =(const SimpleGame&) = default;

	~SimpleGame();

private :
	virtual void gameLoop();

protected:
	virtual bool onCreate() = 0;
	virtual bool onUpdate(Input t_input, float t_elapsedTime) = 0;
	virtual bool onRender(Graphics& t_graphics) = 0;
};

#endif
