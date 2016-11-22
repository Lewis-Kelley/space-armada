#ifndef UNIT_H
#define UNIT_H

#include "Image.hpp"

/**
 * Superclass for all the different Unit's in the map.
 */
class Unit {
private:
  Image *m_img;
  
public:
  Unit(SDL_Texture *tex, SDL_Rect *src_rect);
  void draw(SDL_Renderer *rend, SDL_Rect *dest_rect);
};

#endif
