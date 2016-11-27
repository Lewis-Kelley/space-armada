/** @file
 */
#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

/**
 * Handles a single image, it's origin SDL_Texture as well as the origin and
 * destination SDL_Rect.
 */
class Image {
private:
  SDL_Texture *m_tex; ///< The SDL_Texture that actually holds the image.
  SDL_Rect *m_src_rect; ///< The source rectangle of the Image.
  float* m_dest; ///< An array of information for the destination of the image.
  
  enum Dest_Field {
    X = 0,
    Y = 1,
    W = 2,
    H = 3
  };
public:
  Image(SDL_Texture *tex, SDL_Rect *src_rect, float dest_x, float dest_y,
        float dest_w, float dest_h);
  Image(SDL_Texture *tex, SDL_Rect *src_rect);
  ~Image();

  SDL_Rect get_rect();
  void draw(SDL_Renderer *rend);

  /**
   * Draws the given Image to the screen using rend.
   *
   * @param [in] rend The SDL_Renderer to be used to draw the image.
   * @param [in] dest_rect Where to draw the image.
   */
  void draw(SDL_Renderer *rend, SDL_Rect *dest_rect) {
    SDL_RenderCopy(rend, m_tex, m_src_rect, dest_rect);
  }

  /**
   * Moves the destination rectangle by some amount. Primarily to be used by the
   * camera.
   *
   * @param [in] delta_x The amount to shift in the x direction.
   * @param [in] delta_y The amount to shift in the y direction.
   */
  void move_dest(float delta_x, float delta_y) {
    m_dest[X] += delta_x;
    m_dest[Y] += delta_y;
  }

  static SDL_Texture * load_texture(std::string file_name, SDL_Renderer *rend);
};

#endif
