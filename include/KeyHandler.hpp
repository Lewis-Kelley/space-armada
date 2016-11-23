/** @file
 */

#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <SDL2/SDL.h>
#include "Control.hpp"

class KeyHandler {
private:
  static Control key_status;
  
public:
  static Control pressed_key(SDL_Keycode keycode);
  static Control released_key(SDL_Keycode keycode);
};

#endif
