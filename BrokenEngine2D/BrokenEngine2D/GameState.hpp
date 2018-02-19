#ifndef GAMESTATE_H
#define GAMESTATE_H
#pragma once

#include "Input.hpp"
#include "Graphics.hpp"


class StateBasedGame;
class GameState
{
public:
	virtual bool onCreate() = 0;
	virtual bool onUpdate(Input t_input, StateBasedGame& t_game, float t_elapsedTime) = 0;
	virtual bool onRender(Graphics& t_graphics) = 0;
};

#endif
