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
bool TileMap::move(Direction dir) {
  return m_sel_unit->m_tile->move_unit(dir);
}
