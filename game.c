/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include "gframework.h"
#include "gutil.h"
#include "raylib.h"

#include "levelEditor.h"
#include "gamestate.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    initFramework();


    GameState* game = getGameState();

    // TODO
    // 1. get some decent tunes
    // 2. sometimes camera flashes when changing markers
    // 3. scripting
    // 4. boss enemy
    // 7. better ui
    // 8. actually functional main menu
    // 9. hide cursor
    // 10. clean up console
    // 11. change default zoom
    // 12. enemy scaling broke again
    // 13. player to world collisions are still fucked
    // 14. enemies dont despawn properly?
    // 15. projectile flags
    // 16. phasing projectile
    // 17. animated projectile
    // 18. decalles projectile
    // 19. canon turret
    // 20. goomba stomping ????
    // 21. add more sounds for enemies
    // 22. death scream
    // 23. projectile shoot sounds

    // Main game loop
    while (!WindowShouldClose())
    {
        updateGameState(game);
        textF("fps %d", 10, 10, GetFPS());
        fUpdate();
    }
    
    disposeGameState(game);
	disposeFramework();
    

    return 0;
}
