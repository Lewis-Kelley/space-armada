#include "../include/TileMap.hpp"

/**
 * Free the entire map by deallocating each Tile.
 */
void TileMap::free() {
  if (m_map != NULL) {
    for (int i = 0; i < m_size; i++) {
      delete m_map[i];
    }
    
    delete m_map;
  }
  m_map = NULL;
}

/**
 * Free the entire map by deallocating each Tile.
 */
TileMap::~TileMap() {
  free();
}

/**
 * Replace any existing map with a new map loaded from the file at the given
 * path.
 *
 * @param [in] file_name The file to load from.
 */
void load(std::string file_name) {
  // TODO Implement stubbed function.
}

/**
 * Draw the entire map by calling each Tile's draw procedure.
 * 
 * @param rend The renderer to draw with.
 */
void TileMap::draw(SDL_Renderer *rend) {
  if (m_map != NULL) {
    for (int i = 0; i < m_size; i++) {
      m_map[i]->draw(rend);
    }
  }
}

/**
 * Moves the currently selected Unit in the desired direction if possible.
 * 
 * @param [in] dir The direction to move the current unit in.
 * @return true if successfully moved the unit, false if failed.
 */
bool TileMap::move_sel_unit(Direction dir) {
  return m_sel_unit->m_tile->move_unit(dir);
}

/**
 * Moves all the images contained in this map according to the given camera
 * motion. Note that the given movement directions are of the camera. This means
 * that if the user presses camera up, you would pass a position delta_y.
 *
 * @param [in] delta_x The change in x position of the camera.
 * @param [in] delta_y The change in y position of the camera.
 */
void TileMap::move_camera(float delta_x, float delta_y) {
  for (int i = 0; i < m_size; i++) {
    if (m_map[i] != NULL) {
      m_map[i]->move_draw_dest(-delta_x, -delta_y);
    }
  }
}

/**
 * Handles all the updates to the items in the map.
 *
 * @param [in] delta The time since the last tick.
 */
void TileMap::update(double delta) {
  move_camera(m_cam_vel_x * delta, m_cam_vel_y * delta);
}
