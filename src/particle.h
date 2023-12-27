#pragma once

#include <raylib.h>
#include <cmath>

class Particle {
 public:
  Particle(const Vector2 &pos, const float size, const Color color) : 
    pos_{pos}, size_{size, size}, color_{color} {}
  void Draw() const { DrawRectangleV(pos_, size_, color_); }
  void Update();
 private:
  Vector2 DirectionVec(const Vector2 &point_1, const Vector2 &point_2) const { return Vector2{point_2.x - point_1.x, point_2.y - point_1.y}; }
  float Abs(const Vector2 &vec) const { return std::sqrt(vec.x * vec.x + vec.y * vec.y); }
  void CalculateSpeed();
  Vector2 pos_, size_, speed_;
  Color color_;
  // static constexpr double kGravConstant = 6.6743015e-11;
  static constexpr double particle_mass = 1;
  static constexpr double cursor_mass = 10;
};