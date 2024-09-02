#ifndef GAME_STATE
#define GAME_STATE


#include "gameplay.h"
#include "levelEditor.h"


#define GAME_STATE_MAIN_MENU 0
#define GAME_STATE_GAME 1
#define GAME_STATE_EDITOR 2
#define GAME_STATE_LEVEL_SCREEN 3

struct GameState{
    int currentState;
    Gameplay* gameplay;
    LevelEditor* editor;
    int nextLevel;
};
typedef struct GameState GameState;


GameState* getGameState();
void changeGameState(GameState* gamestate, int newState);
void disposeGameState(GameState* gamestate);
void updateGameState(GameState* gamestate);
void goToNextLevel(GameState* gamestate);


#endif