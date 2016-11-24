/**@file
 */

#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>
#include "Image.hpp"
#include "../src/Direction.cpp"

class Unit;

/**
 * Holds the information necessary for a single tile in the map.
 */
class Tile {
private:
  Unit *m_curr_unit; ///< The Unit occupying this Tile or NULL if empty.
  Unit *m_trans_unit; ///< Any Unit that is passing through this Tile.
  Image *m_img; ///< The background image.
  int m_trans_off_x; ///< The current x offset of the trans_unit
  int m_trans_off_y; ///< The current y offset of the trans_unit
  
public:
  Tile **m_neighbors; ///< Collection of 4 Tile pointers for each neighbor.
  bool m_accessible; ///< true if selected unit can walk here, false otherwise.
  
  Tile(SDL_Texture *tex, SDL_Rect *src_rect, SDL_Rect *dest_rect);
  ~Tile();
  void draw(SDL_Renderer *rend);
  bool put_unit(Unit *new_unit);
  bool move_unit(Direction dir);
  bool toggle_trans_unit();
  bool add_neighbor(Tile *neighbor, Direction dir);
};

#endif
