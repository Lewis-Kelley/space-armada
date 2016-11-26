/** @file
 */
#ifndef UNIT_H
#define UNIT_H

#include "Image.hpp"

class Tile;

/**
 * Superclass for all the different Unit's in the map.
 */
class Unit {
private:
  Image *m_img;
  
public:
  Tile *m_tile;
  
  Unit(SDL_Texture *tex, SDL_Rect *src_rect, Tile *tile);
  ~Unit();
  void draw(SDL_Renderer *rend, SDL_Rect *dest_rect);
};

#endif
