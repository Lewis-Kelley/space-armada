#include "../include/Tile.hpp"

/**
 * Initialize a new Tile object with the given neighbors and rendering info.
 *
 * @param neighbors An array of four Tile pointers representing the neighbors.
 * The order of Tile's is according to the Direction enum.
 * @param tex The background texture for this Tile.
 * @param src_rect The source rectangle for the background image.
 * @param dest_rect The destination rectangle for the background image.
 * @param curr_unit The unit currently occupying this Tile or NULL if none.
 */
Tile::Tile(Tile *neighbors[4], SDL_Texture *tex,
           SDL_Rect *src_rect, SDL_Rect *dest_rect, Unit *curr_unit) {
  m_curr_unit = curr_unit;
  m_trans_unit = NULL;
  m_img = new Image(tex, src_rect, dest_rect);
  m_neighbors = neighbors;
  m_accessible = false;
}

/**
 * Frees the memory used by the Tile.
 */
Tile::~Tile() {
  if (m_curr_unit != NULL) {
    delete m_curr_unit;
  }

  if (m_trans_unit != NULL) {
    delete m_trans_unit;
  }

  if (m_img != NULL) {
    delete m_img;
  }
}

/**
 * Draw this Tile and any Unit's it contains using the given renderer.
 *
 * @param [in] rend The renderer to draw with.
 */
void Tile::draw(SDL_Renderer *rend) {
  m_img->draw(rend);

  if (m_curr_unit != NULL) {
    m_curr_unit->draw(rend, m_img->m_dest_rect);
  }

  if (m_trans_unit != NULL) {
    SDL_Rect trans_rect;
    if (m_trans_off_x == 0 && m_trans_off_y == 0) {
      trans_rect = *m_img->m_dest_rect;
    } else {
      trans_rect.x = m_img->m_dest_rect->x + m_trans_off_x;
      trans_rect.y = m_img->m_dest_rect->y + m_trans_off_y;
      trans_rect.w = m_img->m_dest_rect->w;
      trans_rect.h = m_img->m_dest_rect->h;
    }
    
    m_trans_unit->draw(rend, &trans_rect);
  }
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
