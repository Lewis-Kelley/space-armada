#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#define INIT_WIDTH 500
#define INIT_HEIGHT 500

/**
 * A primarily static class that holds the current width, height, window, and
 * renderer. It handles initialization and destruction of everything.
 */
class Window {
public:
  static SDL_Window *window;
  static SDL_Renderer *rend;
  static int width;
  static int height;
  static bool init();
  static void free();
};

#endif
