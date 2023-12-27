#include <ctime>
#include <vector>
#include <raylib.h>
#include <cstdlib>
#include "particle.h"
#include "window.h"

unsigned char rand_interval(const unsigned char min, const unsigned char max) {
  return rand()%(max-min + 1) + min;
}

int main() {
  std::srand(std::time(nullptr));

  Window window{1280, 720, "Particles"};  
  SetTargetFPS(60);
  std::vector<Particle> particles;
  const float rows = window.width();
  const float columns = window.height();
  particles.reserve(rows * columns);
  Color color{rand_interval(0, 200), rand_interval(0, 200), rand_interval(0, 200), 255};
  for (float i{0}; i < rows; i += 4) {
    for (float j{0}; j < columns; j += 4) {
      particles.emplace_back(Particle{Vector2{i, j}, 1, color});
    }
  }
  while (!WindowShouldClose()) {
    for (auto &particle : particles) {
      particle.Update();
    }
    BeginDrawing();
      ClearBackground(WHITE);
      for (const auto &particle : particles) {
        particle.Draw();
      }
    EndDrawing();
  }
}