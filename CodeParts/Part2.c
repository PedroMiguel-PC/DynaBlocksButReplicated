{
    InitWindow(screenWidth, screenHeight, "DynaBlocksButReplicated");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = playerPosition;
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        playerPreviousPosition = playerPosition;

        if (IsKeyDown(KEY_W)) playerPosition.z -= 0.1f;
        if (IsKeyDown(KEY_S)) playerPosition.z += 0.1f;
        if (IsKeyDown(KEY_A)) playerPosition.x -= 0.1f;
        if (IsKeyDown(KEY_D)) playerPosition.x += 0.1f;
        
        Vector3 cameraDirection = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
        Vector3 cameraRight = Vector3CrossProduct(cameraDirection, camera.up);
        
        if (IsKeyDown(KEY_RIGHT)) {
            camera.position = Vector3Add(camera.position, Vector3Scale(cameraRight, 0.1f));
        }
        if (IsKeyDown(KEY_LEFT)) {
            camera.position = Vector3Subtract(camera.position, Vector3Scale(cameraRight, 0.1f));
        }
        
        if (IsKeyDown(KEY_UP)) {
            camera.position = Vector3Add(camera.position, Vector3Scale(cameraDirection, 0.1f));
        }
        if (IsKeyDown(KEY_DOWN)) {
            camera.position = Vector3Subtract(camera.position, Vector3Scale(cameraDirection, 0.1f));
        }

        camera.target = playerPosition;

        BeginDrawing();