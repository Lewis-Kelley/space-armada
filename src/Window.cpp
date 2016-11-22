#include "../include/Window.hpp"

SDL_Window * Window::window;
SDL_Renderer * Window::rend;
int Window::width;
int Window::height;

/**
 * Initializes the window and renderer.
 *
 * @return true if successful, false if failed
 */
bool Window::init() {
  free();
  
  width = INIT_WIDTH;
  height = INIT_HEIGHT;
  
  if (SDL_Init(SDL_INIT_VIDEO) >= 0) {
    window = SDL_CreateWindow("FreeSpace++",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
      printf("Window could not be created.\nSDL error: %s.\n", SDL_GetError());
      width = 0;
      height = 0;
      return false;
    }

    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
                              | SDL_RENDERER_PRESENTVSYNC);

    if (rend == NULL) {
      printf("Renderer could not be created.\nSDL error: %s.\n",
             SDL_GetError());
      return false;
    }

    // Set default color
    SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
      printf("SDL_image could not initialize.\nSDL_image error: %s.\n",
             IMG_GetError());
      return false;
    }
  } else { // Init failed
    printf("SDL failed to initialize.\nSDL error: %s.\n", SDL_GetError());
    return false;
  }

  return true;
}

/**
 * Frees the memory used by the window and renderer and quits SDL.
 */
void Window::free() {
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}
