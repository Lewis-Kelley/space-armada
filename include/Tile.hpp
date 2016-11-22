/**@file
 */

#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>
#include "Image.hpp"
#include "Direction.cpp"

class Tile {
private:
  //Unit *m_curr_unit; ///< The Unit occupying this Tile or NULL if empty.
  //Unit *m_trans_unit; ///< Any Unit that is passing through this Tile.
  Image img; ///< The background image.
  
public:
  Tile *m_neighbors;
  bool m_accessible;
  
  Tile(Tile neighbors[4]);
  void draw_tile(SDL_Renderer *rend);
  bool move_unit(Direction dir);
};

#endif
