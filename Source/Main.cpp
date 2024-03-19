#include "raylib.h"
#include "UserInterface.hpp"
#include "Label.hpp"
#include "VBox.hpp"
#include "ParticleSystem.hpp"

constexpr int SCREEN_WIDTH = 600;
constexpr int SCREEN_HEIGHT = 800;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Particles Task");
    SetTargetFPS(120); // do not uncap FPS or particles will move very fast

    UserInterface ui;
    VBox infoBox;
    Label fpsLabel("120 FPS");
    Label numParticlesLabel("Count of particles: 0");
    Label numFireworksLabel("Count of fireworks: 0");

    infoBox.AddChild(&fpsLabel);
    infoBox.AddChild(&numParticlesLabel);
    infoBox.AddChild(&numFireworksLabel);
    ui.AddWidget(&infoBox);

    ParticleSystem particleSystem;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Input check
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            // TODO: rewrite it with one Random and bitwise shifts
            Color fireworkColor
            {
                static_cast<unsigned char>(GetRandomValue(0, 255)), // R
                static_cast<unsigned char>(GetRandomValue(0, 255)), // G
                static_cast<unsigned char>(GetRandomValue(0, 255)), // B
                255,                                                // A
            };
            //fireworkColor = BLACK;
            particleSystem.CreateFirework(
                GetMouseX(),
                GetMouseY(),
                GetRandomValue(15, 20),
                fireworkColor
            );
        }

        // Update
        {
            particleSystem.Update();
            //DrawFPS(0, 0); // In the test task, I'll use a custom label for this purpose
            fpsLabel.SetText(std::to_string(GetFPS()) + " FPS");
            numParticlesLabel.SetText(
                "Count of particles: " + std::to_string(particleSystem.GetNumParticles())
            );
            numFireworksLabel.SetText(
                "Count of fireworks: " + std::to_string(particleSystem.GetNumFireworks())
            );
        }

        // Draw
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            particleSystem.Draw();
            ui.Draw();
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}
