#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"  // <--- Adicione esta linha
#include <math.h>

// Dimensões da janela
const int screenWidth = 800;
const int screenHeight = 450;

// Posição inicial do nosso personagem
Vector3 playerPosition = { 0.0f, 0.0f, 0.0f };

// Posição do personagem no frame anterior, para calcular o movimento
Vector3 playerPreviousPosition = { 0.0f, 0.0f, 0.0f };

int main(void)
{
    // Inicializar a janela
    InitWindow(screenWidth, screenHeight, "DynaBlocksButReplicated");

    // Inicializar a câmera em 3D
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = playerPosition;
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Configuração de FPS
    SetTargetFPS(60);

    // Loop principal do jogo
    while (!WindowShouldClose())
    {
        // Salva a posição atual do personagem antes de atualizar
        playerPreviousPosition = playerPosition;

        // Movimento do Personagem com WASD
        if (IsKeyDown(KEY_W)) playerPosition.z -= 0.1f;
        if (IsKeyDown(KEY_S)) playerPosition.z += 0.1f;
        if (IsKeyDown(KEY_A)) playerPosition.x -= 0.1f;
        if (IsKeyDown(KEY_D)) playerPosition.x += 0.1f;
        
        // Controle da Câmera com as setas para um movimento lateral "travado"
        Vector3 cameraDirection = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
        Vector3 cameraRight = Vector3CrossProduct(cameraDirection, camera.up);
        
        if (IsKeyDown(KEY_RIGHT)) {
            camera.position = Vector3Add(camera.position, Vector3Scale(cameraRight, 0.1f));
        }
        if (IsKeyDown(KEY_LEFT)) {
            camera.position = Vector3Subtract(camera.position, Vector3Scale(cameraRight, 0.1f));
        }
        
        // Aumenta e diminui a distância da câmera do alvo com as setas
        if (IsKeyDown(KEY_UP)) {
            camera.position = Vector3Add(camera.position, Vector3Scale(cameraDirection, 0.1f));
        }
        if (IsKeyDown(KEY_DOWN)) {
            camera.position = Vector3Subtract(camera.position, Vector3Scale(cameraDirection, 0.1f));
        }

        // A câmera continua olhando para o jogador
        camera.target = playerPosition;

        // Começar o desenho
        BeginDrawing();

            // Limpar o fundo
            ClearBackground(RAYWHITE);

            // Começar o modo de desenho 3D
            BeginMode3D(camera);

                // Desenhar o "chão" verde (plataforma)
                DrawPlane((Vector3){ 0.0f, -0.5f, 0.0f }, (Vector2){ 50.0f, 50.0f }, LIME);

                // CALCULAR A DIREÇÃO E O ÂNGULO DO MOVIMENTO
                Vector3 moveDirection = Vector3Subtract(playerPosition, playerPreviousPosition);
                
                // Variável para armazenar o ângulo de rotação
                float angle = 0.0f;
                
                // Rotaciona apenas se o personagem estiver se movendo
                if (Vector3LengthSqr(moveDirection) > 0.001f) {
                    angle = atan2f(moveDirection.x, moveDirection.z) * RAD2DEG;
                }
                
                // Aplica a rotação ao grupo de objetos do personagem
                rlPushMatrix();
                    rlTranslatef(playerPosition.x, 0.0f, playerPosition.z);
                    rlRotatef(angle, 0.0f, 1.0f, 0.0f);
                    rlTranslatef(-playerPosition.x, 0.0f, -playerPosition.z);

                    // Desenhar o peitoral
                    Vector3 torsoPosition = Vector3Add(playerPosition, (Vector3){ 0.0f, 1.0f, 0.0f });
                    DrawCube(torsoPosition, 1.0f, 2.0f, 0.5f, RED);

                    // Desenhar a cabeça
                    Vector3 headPosition = Vector3Add(playerPosition, (Vector3){ 0.0f, 2.5f, 0.0f });
                    DrawSphere(headPosition, 0.5f, BLUE);

                    // Desenhar os braços
                    Vector3 armLeftPosition = Vector3Add(playerPosition, (Vector3){ -0.7f, 1.0f, 0.0f });
                    DrawCube(armLeftPosition, 0.5f, 1.5f, 0.5f, LIGHTGRAY);

                    Vector3 armRightPosition = Vector3Add(playerPosition, (Vector3){ 0.7f, 1.0f, 0.0f });
                    DrawCube(armRightPosition, 0.5f, 1.5f, 0.5f, LIGHTGRAY);

                    // Desenhar as pernas
                    Vector3 legLeftPosition = Vector3Add(playerPosition, (Vector3){ -0.25f, -0.5f, 0.0f });
                    DrawCube(legLeftPosition, 0.5f, 1.5f, 0.5f, DARKGRAY);

                    Vector3 legRightPosition = Vector3Add(playerPosition, (Vector3){ 0.25f, -0.5f, 0.0f });
                    DrawCube(legRightPosition, 0.5f, 1.5f, 0.5f, DARKGRAY);
                
                // Restaura a matriz de transformação
                rlPopMatrix();

            // Terminar o modo de desenho 3D
            EndMode3D();

            // Mensagens na tela
            DrawText("Character Control:WASD", 10, 10, 20, DARKGRAY);
            DrawText("Camera Control:<-Left Right->", 10, 30, 20, DARKGRAY);

        EndDrawing();
    }

    // Fechar a janela e liberar recursos
    CloseWindow();

    return 0;
}