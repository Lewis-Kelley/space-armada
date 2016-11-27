/** @file
 */

/**
 * Describes which controls are currently being pressed.
 */
enum Control {
  NONE = 0,
  QUIT = 1,
  MOVE_RIGHT = 2 * QUIT,
  MOVE_UP = 2 * MOVE_RIGHT,
  MOVE_LEFT = 2 * MOVE_UP,
  MOVE_DOWN = 2 * MOVE_LEFT,
  MOVE_ALL = MOVE_RIGHT | MOVE_UP | MOVE_LEFT | MOVE_DOWN,
  CAM_RIGHT = 4 * MOVE_DOWN,
  CAM_UP = 2 * CAM_RIGHT,
  CAM_LEFT = 2 * CAM_UP,
  CAM_DOWN = 2 * CAM_LEFT,
  CAM_ALL = CAM_RIGHT | CAM_UP | CAM_LEFT | CAM_DOWN
};
