#include "../include/Unit.hpp"

Unit::Unit(SDL_Texture *tex, SDL_Rect *src_rect) {
  m_img = new Image(tex, src_rect, NULL);
}

void Unit::draw(SDL_Renderer *rend, SDL_Rect *dest_rect) {
  m_img->draw(rend, dest_rect);
}
