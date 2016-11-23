/** @file
 */

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL2/SDL.h>
#include "KeyHandler.hpp"
#include "TileMap.hpp"

/**
 * Handles SDL_Events.
 */
class EventHandler {
private:
  TileMap *m_map;

  void key_down(SDL_Keycode keycode);
  void key_up(SDL_Keycode keycode);
  void on_move(Control move);
  void on_cam(Control move);
  void on_quit();

public:
  EventHandler(TileMap *map) { m_map = map; }
  void handle_event(SDL_Event *event);
};

#endif