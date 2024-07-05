#ifndef G_FRAMEWORK
#define G_FRAMEWORK


#include "raylib.h"
#include "gutil.h"
#include <math.h>
#include <string.h>
#include "gcollections.h"
#include <stdlib.h>
#include <stdio.h>


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define DEFAULT_CAMERA_ZOOM 2.8f


#define LAYER_BACKGROUND 0
#define LAYER_WORLD 1
#define LAYER_OBJECTS 2
#define LAYER_EFFECTS 3
#define LAYER_UI 4
#define LAYER_STATIC_UI 5
#define LAYER_COUNT LAYER_STATIC_UI + 1

#define FLIP_NONE 0
#define FLIP_HORIZONTAL 1
#define FLIP_VERTICAL 2
#define FLIP_BOTH 4

// misc
int getGlobalTimer();

// camera
void screenShake(float ammount);
void updateCamera();
Vector2 getInWorldMousePosition();
Vector2 getOnScreenMousePosition();
void setCameraPos(Vector2 pos);
void addCameraZoom(float zoom);
void setCameraZoom(float zoom);
void resetCameraZoom();


// drawing
void drawRFSC(int spriteIndex, int x, int y, float rotation, int flip, float scale, Color c, int layer);
void drawRSC(int spriteIndex, int x, int y, float rotation, float scale, Color c, int layer);
void drawFSC(int spriteIndex, int x, int y, int flip, float scale, Color c, int layer);

void drawR(int spriteIndex, int x, int y, float rotation, int layer);
void drawC(int spriteIndex, int x, int y, Color c, int layer);
void drawS(int spriteIndex, int x, int y, float scale, int layer);
void drawF(int spriteIndex, int x, int y, int flip, int layer);
void draw(int spriteIndex, int x, int y, int layer);

void drawFancyText(const char* text, int x, int y, int scale, Color color);


// sounds
void playSound(const char* soundName);

// music
void playMusic(int songId);

// controll functions
void fUpdate();
void initFramework();
void disposeFramework();


// fonts
void drawText(const char* text, int x, int y, float scale, Color color, int layer);
void drawTextF(const char* text, int x, int y, float scale, Color color, int layer, ...);
void textF(const char* text, int x, int y, ...);



#endif
