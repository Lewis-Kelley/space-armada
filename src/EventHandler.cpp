#include "../include/EventHandler.hpp"

/**
 * Do all actions necessary for the given event.
 *
 * @param [in] event The event to handle.
 */
void EventHandler::handle_event(SDL_Event *event) {
  switch(event->type) {
  case SDL_KEYDOWN:
    if(event->key.repeat == 0) {
      key_down(event->key.keysym.sym);
    }
    break;
  case SDL_KEYUP :
    key_up(event->key.keysym.sym);
    break;
  case SDL_MOUSEMOTION:
    //EMPTY
    break;
  case SDL_MOUSEBUTTONDOWN:
    switch(event->button.button) {
    case SDL_BUTTON_LEFT:
      //EMPTY
      break;
    case SDL_BUTTON_RIGHT:
      //EMPTY
      break;
    case SDL_BUTTON_MIDDLE:
      //EMPTY
      break;
    }
    break;
  case SDL_MOUSEBUTTONUP:
    switch(event->button.button) {
    case SDL_BUTTON_LEFT:
      //EMPTY
      break;
    case SDL_BUTTON_RIGHT:
      //EMPTY
      break;
    case SDL_BUTTON_MIDDLE:
      //EMPTY
      break;
    }
    break;
  case SDL_QUIT:
    on_quit();
    break;
  case SDL_WINDOWEVENT:
    //EMPTY
    break;
  case SDL_TEXTINPUT:
    //EMPTY
    break;
  case SDL_SYSWMEVENT:
    //EMPTY
    break;
  default:
    printf("Unhandled event: %d.\n", event->type);
    break;
  }
}

/**
 * Handles any actions necessary for the given key_pressed event.
 * 
 * @param [in] keycode The key that was pressed.
 */
void EventHandler::key_down(SDL_Keycode keycode) {
  Control res = KeyHandler::pressed_key(keycode);

  if ((res & MOVE_ALL) != 0) {
    on_move(res);
  } else if ((res & CAM_ALL) != 0) {
    on_cam(res);
  }
}

/**
 * Handles any actions necessary for the given key_released event.
 * 
 * @param [in] keycode The key that was released.
 */
void EventHandler::key_up(SDL_Keycode keycode) {
  Control res = KeyHandler::released_key(keycode);
}

void EventHandler::on_move(Control move) {
  Direction dir;
  switch (move) {
  case MOVE_RIGHT:
    dir = EAST;
    break;
  case MOVE_UP:
    dir = NORTH;
    break;
  case MOVE_LEFT:
    dir = WEST;
    break;
  case MOVE_DOWN:
    dir = SOUTH;
    break;
  default:
    printf("Unrecognized move control %d.\n", move);
    return;
  }
  
  m_map->move(dir);
}

void EventHandler::on_cam(Control move) {
  // TODO Complete stubbed function
}

void EventHandler::on_quit() {
  // TODO Complete stubbed function
}
