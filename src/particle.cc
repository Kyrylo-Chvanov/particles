#include "particle.h"

void Particle::CalculateSpeed() {
  Vector2 mouse_pos = GetMousePosition();
  Vector2 direction_vec = DirectionVec(pos_, mouse_pos);
  float abs_dir_vec = Abs(direction_vec);
  Vector2 direction_unit_vec = Vector2{direction_vec.x / abs_dir_vec, direction_vec.y / abs_dir_vec};
  float abs_force = /*kGravConstant */ ((particle_mass * cursor_mass) / abs_dir_vec);
  Vector2 force = {abs_force * direction_unit_vec.x, abs_force * direction_unit_vec.y};
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    force.x = -force.x;
    force.y = -force.y;
    speed_.x += force.x;
    speed_.y += force.y;
  } else if (10 < abs_dir_vec) { // 10 just because
    speed_.x += force.x;
    speed_.y += force.y;
  } 
}

void Particle::Update() {
  
  if (!IsMouseButtonDown(MOUSE_RIGHT_BUTTON) && IsCursorOnScreen()) {
    CalculateSpeed();
  }
  speed_.x *= 0.99;
  speed_.y *= 0.99;

  pos_.x += speed_.x;
  pos_.y += speed_.y;

  if (pos_.x > GetScreenWidth() || pos_.x < 0) {
    speed_.x = -speed_.x;
  }

  if (pos_.y > GetScreenHeight() || pos_.y < 0) {
    speed_.y = -speed_.y;
  }

}