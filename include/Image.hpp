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
public:
  SDL_Rect *m_dest_rect; ///< The destination retangle of the Image.
  
  /**
   * Creates a new Image from the given SDL_Texture using the given parameters.
   *
   * @param [in] tex The SDL_Texture that actually holds the image to render.
   * @param [in] dest_rect The destination rectangle of the Image or NULL if the
   * image will take up the whole screen.
   * @param [in] src_rect The source rectangle of the Image or NULL if the whole
   * image is to be used.
   */
  Image(SDL_Texture *tex, SDL_Rect *src_rect, SDL_Rect *dest_rect) {
    m_tex = tex;
    m_src_rect = src_rect;
    m_dest_rect = dest_rect;
  }

  ~Image();

  /**
   * Draws the given Image to the screen using rend.
   *
   * @param [in] rend The SDL_Renderer to be used to draw the image.
   */
  void draw(SDL_Renderer *rend) {
    SDL_RenderCopy(rend, m_tex, m_src_rect, m_dest_rect);
  }

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
   * @param delta_x The amount to shift in the x direction.
   * @param delta_y The amount to shift in the y direction.
   */
  void move_dest(int delta_x, int delta_y) {
    m_dest_rect->x += delta_x;
    m_dest_rect->y += delta_y;
  }

  static SDL_Texture * load_texture(std::string file_name, SDL_Renderer *rend);
};

#endif
