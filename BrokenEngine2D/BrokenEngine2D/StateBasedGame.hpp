#ifndef STATEBASEDGAME_H
#define STATEBASEDGAME_H
#pragma once

#include "BrokenEngine2D.hpp"
#include "GameState.hpp"
#include <map>

class StateBasedGame : public BrokenEngine2D
{
public:
	StateBasedGame() : BrokenEngine2D() {}
	StateBasedGame(Graphics* t_graphics) : BrokenEngine2D(t_graphics) {}
	StateBasedGame(const StateBasedGame&) = default;

	StateBasedGame& operator =(const StateBasedGame&) = default;

	~StateBasedGame();

	void addState(std::string t_name, GameState *t_state);
	void enterState(std::string t_name);

private:
	virtual void gameLoop();

	GameState *m_activeState;
	std::map<std::string, GameState*> m_gamestates;
};

#endif
