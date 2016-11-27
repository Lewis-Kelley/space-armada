#include "../include/Image.hpp"

/**
 * Creates a new Image from the given SDL_Texture using the given parameters.
 *
 * @param [in] tex The SDL_Texture that actually holds the image to render.
 * @param [in] src_rect The source rectangle of the Image or NULL if the whole
 * image is to be used.
 * @param [in] dest_x The x coordinate at which to draw the image.
 * @param [in] dest_y The y coordinate at which to draw the image.
 * @param [in] dest_w The width for which to draw the image.
 * @param [in] dest_h The height for which to draw the image.
 */
Image::Image(SDL_Texture *tex, SDL_Rect *src_rect, float dest_x, float dest_y,
             float dest_w, float dest_h) {
  m_tex = tex;
  m_src_rect = src_rect;
  m_dest = (float *)malloc(4 * sizeof *m_dest);
  m_dest[X] = dest_x;
  m_dest[Y] = dest_y;
  m_dest[W] = dest_w;
  m_dest[H] = dest_h;
}

/**
 * Create a new Image from the given SDL_Texture using the given source
 * parameters.
 *
 * @param [in] tex The SDL_Texture that actually holds the image to render.
 * @param [in] src_rect The source rectangle of the Image or NULL if the whole
 * image is to be used.
 */
Image::Image(SDL_Texture *tex, SDL_Rect *src_rect) {
  m_tex = tex;
  m_src_rect = src_rect;
  m_dest = NULL;
}

/**
 * Frees the memory used by the Image, specifically the SDL_Rect's. The
 * SDL_Texture is not affected by this.
 */
Image::~Image() {
  if (m_src_rect != NULL) {
    delete m_src_rect;
    m_src_rect = NULL;
  }

  if (m_dest != NULL) {
    free(m_dest);
    m_dest = NULL;
  }
}

SDL_Rect Image::get_rect() {
  SDL_Rect ret;

  ret.x = m_dest[X];
  ret.y = m_dest[Y];
  ret.w = m_dest[W];
  ret.h = m_dest[H];

  return ret;
}

/**
 * Draws the given Image to the screen using rend.
 *
 * @param [in] rend The SDL_Renderer to be used to draw the image.
 */
void Image::draw(SDL_Renderer *rend) {
  SDL_Rect rect = get_rect();
  SDL_RenderCopy(rend, m_tex, m_src_rect, &rect);
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
