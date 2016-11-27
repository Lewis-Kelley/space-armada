#include "../include/KeyHandler.hpp"

Control KeyHandler::key_status;

/**
 * Takes a keycode and updates the current keymap accordingly. It returns NONE
 * if the control was already being pressed, but otherwise it returns the
 * corresponding control.
 *
 * @param [in] keycode The key that was pressed.
 * @return NONE if the control in question was already active, otherwise returns
 * the control corresponding to the pressed key
 */
Control KeyHandler::pressed_key(SDL_Keycode keycode) {
  Control selected = NONE;
  Control exclusive_to = NONE;
  
  switch (keycode) {
  case SDLK_RIGHT:
    selected = MOVE_RIGHT;
    exclusive_to = MOVE_ALL;
    break;
  case SDLK_UP:
    selected = MOVE_UP;
    exclusive_to = MOVE_ALL;
    break;
  case SDLK_LEFT:
    selected = MOVE_LEFT;
    exclusive_to = MOVE_ALL;
    break;
  case SDLK_DOWN:
    selected = MOVE_DOWN;
    exclusive_to = MOVE_ALL;
    break;
    
  case SDLK_s:
    selected = CAM_RIGHT;
    exclusive_to = CAM_ALL;
    break;
  case SDLK_w:
    selected = CAM_UP;
    exclusive_to = CAM_ALL;
    break;
  case SDLK_a:
    selected = CAM_LEFT;
    exclusive_to = CAM_ALL;
    break;
  case SDLK_r:
    selected = CAM_DOWN;
    exclusive_to = CAM_ALL;
    break;
  default:
    return NONE;
  }

  if ((key_status & selected) == 0) {
    key_status = (Control)(key_status & ~exclusive_to);
    key_status = (Control)(key_status | selected);
  } else {
    selected = NONE;
  }

  return selected;
}

/**
 * Takes a keycode and updates the current keymap accordingly. It returns the
 * control corresponding to the released key.
 *
 * @param [in] keycode The key that was pressed.
 * @return NONE if failed to identify the released key, otherwise
 * returns the control corresponding to the pressed key
 */
Control KeyHandler::released_key(SDL_Keycode keycode) {
  Control selected = NONE;
  
  switch (keycode) {
  case SDLK_RIGHT:
    selected = MOVE_RIGHT;
    key_status = (Control)(key_status & ~MOVE_RIGHT);
    break;
  case SDLK_UP:
    selected = MOVE_UP;
    key_status = (Control)(key_status & ~MOVE_UP);
    break;
  case SDLK_LEFT:
    selected = MOVE_LEFT;
    key_status = (Control)(key_status & ~MOVE_LEFT);
    break;
  case SDLK_DOWN:
    selected = MOVE_DOWN;
    key_status = (Control)(key_status & ~MOVE_DOWN);
    break;
        
  case SDLK_s:
    selected = CAM_RIGHT;
    key_status = (Control)(key_status & ~CAM_RIGHT);
    break;
  case SDLK_w:
    selected = CAM_UP;
    key_status = (Control)(key_status & ~CAM_UP);
    break;
  case SDLK_a:
    selected = CAM_LEFT;
    key_status = (Control)(key_status & ~CAM_LEFT);
    break;
  case SDLK_r:
    selected = CAM_DOWN;
    key_status = (Control)(key_status & ~CAM_DOWN);
    break;
  default:
    break;
  }

  return selected;
}
