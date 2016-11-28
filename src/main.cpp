#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string>
#include "../include/Window.hpp"
#include "../include/Image.hpp"
#include "../include/Tile.hpp"
#include "../include/Unit.hpp"
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
    SDL_Texture *tile_tex_1 = Image::load_texture(GREEN_TILE_PATH, Window::rend);
    SDL_Texture *tile_tex_2 = Image::load_texture(PINK_TILE_PATH, Window::rend);

    Tile **tile_list = (Tile **)malloc(2 * sizeof *tile_list);
    tile_list[0] = new Tile(tile_tex_1, NULL, 100, 150, 50, 50);
    tile_list[1] = new Tile(tile_tex_2, NULL, 150, 150, 50, 50);

    tile_list[0]->add_neighbor(tile_list[1], EAST);

    SDL_Texture *ship_tex = Image::load_texture(RED_SHIP_PATH, Window::rend);
    Unit ship = Unit(ship_tex, NULL, tile_list[1]);
    tile_list[1]->toggle_trans_unit();
    
    TileMap map = TileMap(tile_list, 2);
    map.m_sel_unit = &ship;

    // Final setup
    EventHandler e_handler = EventHandler(&map);
    SDL_Event event;
    double last_time = SDL_GetTicks();
    double curr_time;
    Window::running = true;

    // Main loop
    while (Window::running) {
      SDL_RenderClear(Window::rend);
      while (SDL_PollEvent(&event) != 0) {
        e_handler.handle_event(&event);
      }
      curr_time = SDL_GetTicks();
      map.update(curr_time - last_time);
      last_time = curr_time;
      map.draw(Window::rend);
      SDL_RenderPresent(Window::rend);
    }

    // Cleanup
    SDL_DestroyTexture(tile_tex_1);
    SDL_DestroyTexture(tile_tex_2);
    SDL_DestroyTexture(ship_tex);
    Window::free();
  } else {
    return 1;
  }
  return 0;
}
