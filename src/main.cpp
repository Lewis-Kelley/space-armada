#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string>
#include "../include/Window.hpp"
#include "../include/Image.hpp"
#include "../include/Tile.hpp"
#include "../include/TileMap.hpp"
#include "../include/EventHandler.hpp"

#define ASSETS_DIR std::string("/home/lewis/programs/space-armada/assets/")
#define BLUE_TILE_PATH (ASSETS_DIR + "blue_tile.png")
#define GREEN_TILE_PATH (ASSETS_DIR + "green_tile.png")
#define ORANGE_TILE_PATH (ASSETS_DIR + "orange_tile.png")
#define PINK_TILE_PATH (ASSETS_DIR + "pink_tile.png")
#define RED_SHIP_PATH (ASSETS_DIR + "red_ship.png")

/**
 * The starting point for the program.
 */
int main(int argc, char *argv[]) {
  if (Window::init()) {
    Tile *neighbors[] = {NULL, NULL, NULL, NULL};
    SDL_Texture *tile_tex_1 = Image::load_texture(GREEN_TILE_PATH, Window::rend);
    SDL_Rect dest_rect_1;
    dest_rect_1.x = 100;
    dest_rect_1.y = 150;
    dest_rect_1.w = 50;
    dest_rect_1.h = 50;

    SDL_Texture *tile_tex_2 = Image::load_texture(PINK_TILE_PATH, Window::rend);
    SDL_Rect dest_rect_2;
    dest_rect_2.x = 150;
    dest_rect_2.y = 150;
    dest_rect_2.w = 50;
    dest_rect_2.h = 50;

    SDL_Texture *ship_tex = Image::load_texture(RED_SHIP_PATH, Window::rend);
    Unit ship = Unit(ship_tex, NULL);
    
    Tile **tile_list = (Tile **)malloc(2 * sizeof *tile_list);
    tile_list[0] = new Tile(neighbors, tile_tex_1, NULL, &dest_rect_1, &ship);
    tile_list[1] = new Tile(neighbors, tile_tex_2, NULL, &dest_rect_2, NULL);
    
    TileMap map = TileMap(tile_list, 2);
    EventHandler e_handler = EventHandler(&map);
    SDL_Event event;

    while (true) {
      SDL_RenderClear(Window::rend);
      while (SDL_PollEvent(&event)) {
        e_handler.handle_event(&event);
      }
      map.draw(Window::rend);
      SDL_RenderPresent(Window::rend);
    }
  } else {
    return 1;
  }
  return 0;
}
