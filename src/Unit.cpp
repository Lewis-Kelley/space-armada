#include "../include/Unit.hpp"

/**
 * Create a new Unit with pulling the correct portion of the given texture.
 *
 * @param [in] tex The texture to pull the image from.
 * @param [in] src_rect The rectangle defining where to pull from the texture.
 */
Unit::Unit(SDL_Texture *tex, SDL_Rect *src_rect) {
  m_img = new Image(tex, src_rect, NULL);
}

/**
 * Free the memory used by this Unit.
 */
Unit::~Unit() {
  delete m_img;
}

/**
 * Draw the Unit at the given location.
 *
 * @param [in] rend The renderer with which to draw the Unit.
 * @param [in] dest_rect How and where to draw the Unit.
 */
void Unit::draw(SDL_Renderer *rend, SDL_Rect *dest_rect) {
  m_img->draw(rend, dest_rect);
}
