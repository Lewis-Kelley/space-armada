/** @file
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include "Tile.hpp"

/**
 * Handles a full grid of Tile's.
 */
class TileMap {
private:
  Tile **m_map;
  int m_size;

  void free();
public:
  TileMap() {};

  // Debugging constructor:
  TileMap(Tile **map, int size) {
    m_map = map;
    m_size = size;
  }
  
  ~TileMap();
  void load(std::string file_name);
  void draw(SDL_Renderer *rend);
};

#endif
