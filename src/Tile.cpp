#include "../include/Tile.hpp"

/**
 * Initialize a new Tile object with the given neighbors and rendering info.
 *
 * @param neighbors An array of four Tile pointers representing the neighbors.
 * The order of Tile's is according to the Direction enum.
 * @param tex The background texture for this Tile.
 * @param src_rect The source rectangle for the background image.
 * @param dest_rect The destination rectangle for the background image.
 */
Tile::Tile(Tile *neighbors[4], SDL_Texture *tex,
           SDL_Rect *src_rect, SDL_Rect *dest_rect) {
  m_img = new Image(tex, src_rect, dest_rect);
  m_neighbors = neighbors;
  m_accessible = false;
}

/**
 * Draw this Tile and any Unit's it contains using the given renderer.
 *
 * @param rend The renderer to draw with.
 */
void Tile::draw(SDL_Renderer *rend) {
  m_img->draw(rend);
  m_curr_unit->draw(rend, m_img->m_dest_rect);
  // Draw m_trans_unit
}

/**
 * Move the transient unit to the Tile in the given Direction if possible.
 *
 * @param dir The Direction in which to move the transient unit.
 * @return true if successful, false if failed
 */
bool Tile::move_unit(Direction dir) {
  Tile *target = m_neighbors[dir];
  if (target->m_accessible) {
    // Move unit
  }

  return target->m_accessible;
}

/**
 * Either pull the stored unit into the trans unit or vice versa.
 *
 * @return true if successfully swapped, false otherwise
 */
bool Tile::toggle_trans_unit() {
  if (m_curr_unit == NULL) {
    if (m_trans_unit != NULL) {
      m_curr_unit = m_trans_unit;
      m_trans_unit = NULL;
    } else {
      return false;
    }
  } else {
    if (m_trans_unit == NULL) {
      m_trans_unit = m_curr_unit;
      m_curr_unit = NULL;
    } else {
      return false;
    }
  }

  return true;
}
