#include "../include/Unit.hpp"
#include "../include/Tile.hpp"

/**
 * Create a new Unit with pulling the correct portion of the given texture.
 *
 * @param [in] tex The texture to pull the image from.
 * @param [in] src_rect The rectangle defining where to pull from the texture.
 * @param [in, out] tile The Tile this Unit is occupying or NULL if none. If a
 * tile is provided, the Unit will add itself to the Unit as well.
 */
Unit::Unit(SDL_Texture *tex, SDL_Rect *src_rect, Tile *tile) {
  m_img = new Image(tex, src_rect);
  if (tile != NULL && tile->put_unit(this)) {
    m_tile = tile;
  }
}

/**
 * Free the memory used by this Unit.
 */
Unit::~Unit() {
  if (m_img != NULL) {
    delete m_img;
    m_img = NULL;
  }

  m_tile = NULL;
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
