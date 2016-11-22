#ifndef IMAGE_H
#define IMAGE_H

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
  SDL_Rect *m_dest_rect; ///< The destination retangle of the Image.
  SDL_Rect *m_src_rect; ///< The source rectangle of the Image.
public:
  /**
   * Creates a new Image from the given SDL_Texture using the given parameters.
   *
   * @param [in] tex The SDL_Texture that actually holds the image to render.
   * @param [in] dest_rect The destination rectangle of the Image or NULL if the
   * image will take up the whole screen.
   * @param [in] src_rect The source rectangle of the Image or NULL if the whole
   * image is to be used.
   */
  Image(SDL_Texture *tex, SDL_Rect *dest_rect, SDL_Rect *src_rect) {
    m_tex = tex;
    m_dest_rect = dest_rect;
    m_src_rect = src_rect;
  }

  /**
   * Draws the given Image to the screen using rend.
   *
   * @param [in] rend The SDL_Renderer to be used to draw the image.
   */
  void draw(SDL_Renderer *rend) {
    SDL_RenderCopy(rend, m_tex, m_src_rect, m_dest_rect);
  }

  static SDL_Texture * load_texture(std::string file_name, SDL_Renderer *rend);
};

#endif
