#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"  
#include <math.h>

const int screenWidth = 800;
const int screenHeight = 450;

Vector3 playerPosition = { 0.0f, 0.0f, 0.0f };

Vector3 playerPreviousPosition = { 0.0f, 0.0f, 0.0f };

int main(void)