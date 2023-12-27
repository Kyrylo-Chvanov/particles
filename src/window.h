#pragma once

#include <raylib.h>

class Window {
 public:
  Window(int width, int height, const char * title) : width_{width}, height_{height} {
    InitWindow(width, height, title);    
  }
  ~Window() {
    CloseWindow();
  }
  int width() const { return width_; }
  int height() const { return height_; }
 private:
  int width_, height_;
};