/** @file
 */

/**
 * Describes which controls are currently being pressed.
 */
enum Control {
  NONE = 0,
  MOVE_RIGHT = 1,
  MOVE_UP = 2,
  MOVE_LEFT = 4,
  MOVE_DOWN = 8,
  MOVE_ALL = MOVE_RIGHT | MOVE_UP | MOVE_LEFT | MOVE_DOWN,
  CAM_RIGHT = 16,
  CAM_UP = 32,
  CAM_LEFT = 64,
  CAM_DOWN = 128,
  CAM_ALL = CAM_RIGHT | CAM_UP | CAM_LEFT | CAM_DOWN
};
