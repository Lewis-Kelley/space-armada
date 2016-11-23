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
