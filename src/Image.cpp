#include "../include/Image.hpp"

/**
 * Frees the memory used by the Image, specifically the SDL_Rect's. The
 * SDL_Texture is not affected by this.
 */
Image::~Image() {
  if (m_src_rect != NULL) {
    delete m_src_rect;
  }

  if (m_dest_rect != NULL) {
    delete m_dest_rect;
  }
}

/**
 * Creates a new texture from the given file_name.
 *
 * @param [in] file_name The path to the image file to load.
 * @param [in] rend The window's renderer
 * @return A new SDL_Texture from the loaded image file.
 */
SDL_Texture * Image::load_texture(std::string file_name, SDL_Renderer *rend) {
  SDL_Texture *tex = NULL;
  SDL_Surface *img = IMG_Load(file_name.c_str());
  
  if (img) {
    // Set invisible color
    SDL_SetColorKey(img, SDL_TRUE, SDL_MapRGB(img->format, 0xFF, 0x00, 0xFF));

    // Create texture from the surface
    tex = SDL_CreateTextureFromSurface(rend, img);

    if (!tex) {
      printf("Unable to create texture from path %s.\nSDL error: %s.\n",
             file_name.c_str(), SDL_GetError());
    }
  } else {
    printf("Unable to load image from path %s.\nSDL_Image error: %s.\n",
           file_name.c_str(), IMG_GetError());
  }

  return tex;
}
