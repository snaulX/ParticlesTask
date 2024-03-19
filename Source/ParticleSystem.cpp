#include "ParticleSystem.hpp"
#include "MathUtils.hpp"
#include <cassert>

constexpr float GRAVITY = 18;
constexpr float PARTICLE_RADIUS = 2.5;
constexpr float START_VELOCITY = 3.6;
constexpr float INITIAL_LIFETIME = 4;
constexpr float FALL_TIME = 2.8;
constexpr float RAISE_TIME = INITIAL_LIFETIME - FALL_TIME;

// How this works:
// On CreateFirework, system creates a particles[numParticles] with initial velocity vectors
// around start point with equal distance between all them. It's did by setting cos and sin
// with angle's delta for setting direction and multiplying on velocity for setting velocity.
// Next we separate firework on two parts for more beautiful effect: raise and fall, which
// separated by FALL_TIME time. Raise and Fall math's parts described in ParticleSystem::Update.

void ParticleSystem::Update()
{
    for (auto it = _fireworks.begin(); it != _fireworks.end();)
    {
        Firework& firework = *it;
        float& lifeTime = firework.LifeTime;
        if (lifeTime <= 0)
        {
            // firework is ended, so remove it from _fireworks and
            // from particles count stats
            _statNumParticles -= firework.NumParticles;
            it = _fireworks.erase(it);
            continue;
        }
        float deltaTime = GetFrameTime();
        bool isFalling = lifeTime < FALL_TIME;
        if (isFalling)
        {
            // make particles slightly disappear
            firework.Color.a = lifeTime / FALL_TIME * 255;
        }
        for (int i = 0; i < firework.NumParticles; i++)
        {
            Particle& p = firework.Particles[i];
            Vector2& vel = p.Velocity;
            // we might do it faster with SIMD and/or multithreading
            // or even write a compute shader to offload it on GPU,
            // but current implementation is not so expensive for now
            if (isFalling)
            {
                // Fall part
                // slow down by X axis to 0
                vel.x -= deltaTime * vel.x * FALL_TIME;
                // just fall...
                vel.y = GRAVITY * deltaTime;
            }
            else
            {
                // Raise part
                // non-linear slow down velocity
                // coef gets lesser as we are closer to 'fall' part
                // so 'slowing' gets lesser too
                float coef = deltaTime * (lifeTime - RAISE_TIME);
                vel -= vel * coef;
            }
            p.Position += vel;
        }
        lifeTime -= deltaTime;
        it++;
    }
}

/*
// Uncomment this function and line in Draw() and place image.png with
// folder of binary to get particles as images instead of particles as circles
static Image particleImage{nullptr};
static void DrawImage(const Vector2& pos, Color color)
{
    if (!particleImage.data)
    {
        particleImage = LoadImage("image.png");
        ImageResize(&particleImage, 32, 32);
    }
    for (int i = pos.y; i < particleImage.height + pos.y; ++i)
    {
        for (int j = pos.x; j < particleImage.width + pos.x; ++j)
        {
            DrawPixel(j, i, GetImageColor(particleImage, j - pos.x, i - pos.y) * color);
        }
    }
}
*/

void ParticleSystem::Draw() const
{
    for (const Firework& firework : _fireworks)
    {
        Color color = firework.Color;
        for (int i = 0; i < firework.NumParticles; i++)
        {
            const Vector2& pos = firework.Particles[i].Position;
            DrawCircle(pos.x, pos.y, PARTICLE_RADIUS, color);
            //DrawImage(pos, color); // uncomment this to get particles as images instead of circles
        }
    }
}

void ParticleSystem::CreateFirework(int x, int y, int numParticles, Color color)
{
    assert(numParticles <= MAX_FIREWORK_PARTICLES);

    Firework f{};
    f.LifeTime = INITIAL_LIFETIME;
    f.Color = color;
    f.NumParticles = numParticles;
    float angleDelta = 2 * PI / numParticles;
    for (int i = 0; i < numParticles; i++)
    {
        Particle p{};
        p.Position =
        {
            static_cast<float>(x),
            static_cast<float>(y)
        };
        p.Velocity =
        {
            cosf(i * angleDelta) * START_VELOCITY,
            sinf(i * angleDelta) * START_VELOCITY
        };
        f.Particles[i] = p;
    }
    _statNumParticles += numParticles;
    _fireworks.push_back(f);
}
