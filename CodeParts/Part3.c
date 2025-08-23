        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawPlane((Vector3){ 0.0f, -0.5f, 0.0f }, (Vector2){ 50.0f, 50.0f }, LIME);

                Vector3 moveDirection = Vector3Subtract(playerPosition, playerPreviousPosition);
                
                float angle = 0.0f;
                
                if (Vector3LengthSqr(moveDirection) > 0.001f) {
                    angle = atan2f(moveDirection.x, moveDirection.z) * RAD2DEG;
                }
                
                rlPushMatrix();
                    rlTranslatef(playerPosition.x, 0.0f, playerPosition.z);
                    rlRotatef(angle, 0.0f, 1.0f, 0.0f);
                    rlTranslatef(-playerPosition.x, 0.0f, -playerPosition.z);
