#include <stdio.h>
#include <SDL2/SDL.h>
#include "../include/Window.hpp"
#include "../include/Image.hpp"

#define RED_SHIP_PATH "/home/lewis/programs/space-armada/assets/red_ship.png"

/**
 * The starting point for the program.
 */
int main(int argc, char *argv[])
{
  if (Window::init()) {
    SDL_Texture *ship_tex = Image::load_texture(RED_SHIP_PATH, Window::rend);
    SDL_Rect dest_rect;
    dest_rect.x = 10;
    dest_rect.y = 40;
    dest_rect.w = 100;
    dest_rect.h = 50;
    
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
