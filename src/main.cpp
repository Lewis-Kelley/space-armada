#include <stdio.h>
#include <SDL2/SDL.h>
#include "../include/Window.hpp"
#include "../include/Image.hpp"

#define RED_SHIP_PATH "/home/lewis/programs/FreeSpace++/assets/red_ship.png"

/**
 * The starting point for the program.
 */
int main(int argc, char *argv[])
{
  if (Window::init()) {
    SDL_Texture *ship_tex = Image::load_texture(RED_SHIP_PATH, Window::rend);
    SDL_Rect dest_rect;
    dest_rect.x = 0;
    dest_rect.y = 0;
    dest_rect.w = 40;
    dest_rect.h = 40;
    
    Image img = Image(ship_tex, NULL, &dest_rect);

    while (true) {
      SDL_RenderClear(Window::rend);
      img.draw(Window::rend);
      SDL_RenderPresent(Window::rend);
    }
  } else {
    return 1;
  }
  return 0;
}
