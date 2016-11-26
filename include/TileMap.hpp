/** @file
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include "Tile.hpp"
#include "Unit.hpp"

/**
 * Handles a full grid of Tile's.
 */
class TileMap {
private:
  Tile **m_map;
  short m_size;

  void free();
public:
  Unit *m_sel_unit;
  float m_cam_vel_x;
  float m_cam_vel_y;
  
  TileMap() {};

  // Debugging constructor:
  TileMap(Tile **map, short size) {
    m_map = map;
    m_size = size;
  }
  
  ~TileMap();
  void load(std::string file_name);
  void draw(SDL_Renderer *rend);  
  bool move_sel_unit(Direction dir);
  void move_camera(float delta_x, float delta_y);
  void update(double delta);
};

#endif
