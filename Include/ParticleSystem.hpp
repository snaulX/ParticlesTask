#pragma once

#include <vector>
#include "raylib.h"

constexpr int MAX_FIREWORK_PARTICLES = 32;

struct Particle
{
    Vector2 Position;
    Vector2 Velocity;
};

struct Firework
{
    float LifeTime;
    Color Color;
    int NumParticles;
    Particle Particles[MAX_FIREWORK_PARTICLES];
};

class ParticleSystem
{
public:
    ParticleSystem() = default;
    ~ParticleSystem() = default;

    void Update();
    void Draw() const;
    void CreateFirework(int x, int y, int numParticles, Color color);

    [[nodiscard]] int GetNumParticles() const { return _statNumParticles; }
    [[nodiscard]] int GetNumFireworks() const { return _fireworks.size(); }

private:
    std::vector<Firework> _fireworks;
    int _statNumParticles = 0;
};