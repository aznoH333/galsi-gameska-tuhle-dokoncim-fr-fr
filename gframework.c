#ifndef G_FRAMEWORK
#define G_FRAMEWORK

#include "raylib.h"
#include <math.h>
//------------------------------------------------------
// Conf
//------------------------------------------------------
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const char* WINDOW_NAME = "template window";
const int DEFAULT_SPRITE_SIZE = 32;
const float DEFAULT_CAMERA_ZOOM = 2.0f;
const int SPRITE_ORIGIN_OFFSET = DEFAULT_SPRITE_SIZE >> 1;




//------------------------------------------------------
// sprites
//------------------------------------------------------
struct FrameworkSpriteSheet{
	Texture2D spriteSheetTexture;
	int width;
	int height;

};
typedef struct FrameworkSpriteSheet FrameworkSpriteSheet;

FrameworkSpriteSheet mainSpriteSheet;
FrameworkSpriteSheet initSpriteSheet(){
	FrameworkSpriteSheet out;
	out.spriteSheetTexture = LoadTexture("resources/spritesheet.png");
	out.width = out.spriteSheetTexture.width / DEFAULT_SPRITE_SIZE;
	out.height = out.spriteSheetTexture.height / DEFAULT_SPRITE_SIZE;
	
	return out;
}

void unloadSpriteSheet(FrameworkSpriteSheet spriteSheet){
	UnloadTexture(spriteSheet.spriteSheetTexture);
}




//------------------------------------------------------
// Variables
//------------------------------------------------------
FrameworkSpriteSheet loadedSheet;
RenderTexture2D renderTexture;
Vector2 actualCameraPos = {0,0};
Camera2D cam;
float scalingFactor;
int renderTextureOffset;
float screenShakeAmmount = 0.0f;
int fTimer = 0;

//------------------------------------------------------
// camera
//------------------------------------------------------
void screenShake(float ammount){
	screenShakeAmmount += ammount;
}

void updateCamera(){
	screenShakeAmmount = fmin(screenShakeAmmount, 10);
	Vector2 vec = {actualCameraPos.x + sin(fTimer) * screenShakeAmmount, actualCameraPos.y + cos(fTimer) * screenShakeAmmount};
	cam.target = vec;

	if (screenShakeAmmount < 0.1f){
		screenShakeAmmount = 0;
	}else {
		screenShakeAmmount *= 0.2f;
	}

}

Vector2 getInWorldMousePosition(){
	Vector2 out = GetMousePosition();
	
	out.x /= cam.zoom;
	out.y /= cam.zoom;

	out.x += cam.target.x;
	out.y += cam.target.y;

	return out;
}

void setCameraPos(Vector2 pos){
	actualCameraPos = pos;
}



//------------------------------------------------------
// drawing
//------------------------------------------------------


void drawRC(int spriteIndex, int x, int y, float rotation, Color c){
	Rectangle src = {(spriteIndex % loadedSheet.width) * DEFAULT_SPRITE_SIZE, floor((float)spriteIndex / (float)loadedSheet.width) *
	DEFAULT_SPRITE_SIZE, DEFAULT_SPRITE_SIZE, DEFAULT_SPRITE_SIZE};
	Rectangle dest = {x + SPRITE_ORIGIN_OFFSET, y + SPRITE_ORIGIN_OFFSET, DEFAULT_SPRITE_SIZE, DEFAULT_SPRITE_SIZE};
	Vector2 origin = {SPRITE_ORIGIN_OFFSET, SPRITE_ORIGIN_OFFSET};



	DrawTexturePro(loadedSheet.spriteSheetTexture, src, dest, origin, rotation, c);

}

void drawR(int spriteIndex, int x, int y, float rotation){
	drawRC(spriteIndex, x, y, rotation, WHITE);
}

void drawC(int spriteIndex, int x, int y, Color c){
	drawRC(spriteIndex, x, y, 0.0f, c);
}

void draw(int spriteIndex, int x, int y){	
	drawC(spriteIndex, x, y, WHITE);
}




void fDrawBegin(){
	BeginTextureMode(renderTexture);
    BeginMode2D(cam);
	updateCamera();
	fTimer++;
}

void fDrawEnd(){
	EndMode2D();
    EndTextureMode();
    
    BeginDrawing();
    ClearBackground(BLACK);
    Rectangle r = { 0, 0, (float)(renderTexture.texture.width), (float)(-renderTexture.texture.height) };
    Rectangle r2 = { renderTextureOffset, 0, (float)(GetScreenWidth()) * scalingFactor, (float)(GetScreenHeight()) };
    Vector2 v = {0, 0};
    DrawTexturePro(renderTexture.texture,r,r2,v,0,WHITE);

    EndDrawing();
}

void drawFancyText(const char* text, int x, int y, int scale, Color color){
	int shadowOffset = fmax(scale / 10.0f, 1);
	DrawText(text, x + shadowOffset, y, scale, GRAY);
	DrawText(text, x, y, scale, color);

}

//------------------------------------------------------
// init
//------------------------------------------------------
void initFramework(){
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
	SetTargetFPS(60);
	renderTexture = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
	loadedSheet = initSpriteSheet();
	scalingFactor = SCREEN_WIDTH /(float)(GetScreenWidth());
	renderTextureOffset = ((GetScreenWidth()) / 2) - (SCREEN_WIDTH / 2);
	//ToggleFullscreen();
	cam.zoom = DEFAULT_CAMERA_ZOOM;
}

//------------------------------------------------------
// dispose
//------------------------------------------------------
void disposeFramework(){
	unloadSpriteSheet(loadedSheet);
	UnloadRenderTexture(renderTexture);
	CloseWindow();
}


#endif
