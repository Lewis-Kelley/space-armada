#include "../include/Tile.hpp"
#include "../include/Unit.hpp"
#include <iostream>

/**
 * Initialize a new Tile object with the given neighbors and rendering info.
 *
 * @param [in] neighbors An array of four Tile pointers representing the
 * neighbors. The order of Tile's is according to the Direction enum.
 * @param [in] tex The background texture for this Tile.
 * @param [in] src_rect The source rectangle for the background image.
 * @param [in] dest_rect The destination rectangle for the background image.
 * @param [in] curr_unit The unit currently occupying this Tile or NULL if none.
 */
Tile::Tile(SDL_Texture *tex, SDL_Rect *src_rect, float dest_x, float dest_y,
           float dest_w, float dest_h) {
  m_neighbors = (Tile **)calloc(4, sizeof *m_neighbors);
  m_curr_unit = NULL;
  m_trans_unit = NULL;
  m_img = new Image(tex, src_rect, dest_x, dest_y, dest_w, dest_h);
  m_accessible = true;
  m_trans_off_x = 0;
  m_trans_off_y = 0;
}

/**
 * Frees the memory used by the Tile.
 */
Tile::~Tile() {
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
  SDL_Rect dest_rect = m_img->get_rect();
  m_img->draw(rend);
  
  if (m_curr_unit != NULL) {
    m_curr_unit->draw(rend, &dest_rect);
  }

  if (m_trans_unit != NULL) {
    if (m_trans_off_x != 0 || m_trans_off_y != 0) {
      dest_rect.x += m_trans_off_x;
      dest_rect.y += m_trans_off_y;
    }

    m_trans_unit->draw(rend, &dest_rect);
  }
}

/**
 * Stores the given Unit as the current Unit if none are present. Returns true
 * in this case. If there is a Unit present, does nothing and returns false.
 *
 * @param [in] new_unit The Unit to store.
 * @return true if successful, false if there was already a Unit present.
 */
bool Tile::put_unit(Unit *new_unit) {
  if (m_curr_unit == NULL) {
    m_curr_unit = new_unit;
    return true;
  }

  return false;
}

/**
 * Move the transient unit to the Tile in the given Direction if possible.
 *
 * @param [in] dir The Direction in which to move the transient unit.
 * @return true if successful, false if failed
 */
bool Tile::move_unit(Direction dir) {
  Tile *target = m_neighbors[dir];

  if (target != NULL && target->m_accessible) {

    m_trans_unit->m_tile = target;
    target->m_trans_unit = m_trans_unit;
    m_trans_unit = NULL;
    
    // TODO Start a gradual movement process.
  }
  
  return target != NULL && target->m_accessible;
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

/**
 * Adds the given Tile as a neighbor in the given direction, both to this Tile
 * and to the passed neighbor Tile if possible.
 *
 * @param [in, out] neighbor The Tile to add as a neighbor and to add a neighbor
 * to.
 * @param [in] dir The direction from this Tile to which to add a neighbor.
 * @return True if successfully added, false if either this Tile or the neighbor
 * already has a neighbor in the given direction.
 */
bool Tile::add_neighbor(Tile *neighbor, Direction dir) {
  if (m_neighbors[dir] == NULL
      && neighbor->m_neighbors[(2 + dir) % 4] == NULL) {
    m_neighbors[dir] = neighbor;
    neighbor->m_neighbors[(2 + dir) % 4] = this;
    
    return true;
  }

  return false;
}

/**
 * Moves the location of where this Tile and any Unit's it contains is drawn by
 * the given amounts.
 *
 * @param [in] delta_x The amount to shift the drawing in the x direction.
 * @param [in] delta_y The amount to shift the drawing in the y direction.
 */
void Tile::move_draw_dest(float delta_x, float delta_y) {
  if (m_img != NULL) {
    m_img->move_dest(delta_x, delta_y);
  }
}
