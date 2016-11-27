/** @file
 */

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL2/SDL.h>
#include "Window.hpp"
#include "KeyHandler.hpp"
#include "TileMap.hpp"

#define CAM_SPEED 0.2

/**
 * Handles SDL_Event's.
 */
class EventHandler {
private:
  TileMap *m_map; ///< The map associated with this EventHandler.

  void key_down(SDL_Keycode keycode);
  void key_up(SDL_Keycode keycode);
  void on_move_press(Control move);
  void on_cam_press(Control move);
  void on_move_rel(Control move);
  void on_cam_rel(Control move);
  void on_quit();

public:
  EventHandler(TileMap *map) { m_map = map; }
  void handle_event(SDL_Event *event);
};

#endif
