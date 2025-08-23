                    Vector3 torsoPosition = Vector3Add(playerPosition, (Vector3){ 0.0f, 1.0f, 0.0f });
                    DrawCube(torsoPosition, 1.0f, 2.0f, 0.5f, RED);

                    Vector3 headPosition = Vector3Add(playerPosition, (Vector3){ 0.0f, 2.5f, 0.0f });
                    DrawSphere(headPosition, 0.5f, BLUE);

                    Vector3 armLeftPosition = Vector3Add(playerPosition, (Vector3){ -0.7f, 1.0f, 0.0f });
                    DrawCube(armLeftPosition, 0.5f, 1.5f, 0.5f, LIGHTGRAY);

                    Vector3 armRightPosition = Vector3Add(playerPosition, (Vector3){ 0.7f, 1.0f, 0.0f });
                    DrawCube(armRightPosition, 0.5f, 1.5f, 0.5f, LIGHTGRAY);

                    Vector3 legLeftPosition = Vector3Add(playerPosition, (Vector3){ -0.25f, -0.5f, 0.0f });
                    DrawCube(legLeftPosition, 0.5f, 1.5f, 0.5f, DARKGRAY);

                    Vector3 legRightPosition = Vector3Add(playerPosition, (Vector3){ 0.25f, -0.5f, 0.0f });
                    DrawCube(legRightPosition, 0.5f, 1.5f, 0.5f, DARKGRAY);
                
                rlPopMatrix();

            EndMode3D();