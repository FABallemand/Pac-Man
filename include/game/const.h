// Window =====================================================================
#define WINDOW_W 700    //!< Window width
#define WINDOW_H 900    //!< Window height
#define FRAME_DELAY 16; //!< Delay between each frame

// Game =======================================================================
#define NB_ROWS 27    //!< Number of rows
#define NB_COLUMNS 21 //!< Number of columns
#define MAZE_W 166    //< Maze width
#define MAZE_H 216    //!< Maze height

// Objects ====================================================================

// Cell ===================================================
#define CELL_SIZE 32 //!< Cell size

// Moveable ===============================================
#define NB_DIRECTION 4
#define NB_MOVING_SPRITE 3
#define NB_SPRITE_FRAME 3 //!< Number of frame each sprite is displayed before going to the next sprite in the animation

// PacMan
#define PACMAN_W 16         //!< PacMan width
#define PACMAN_H 16         //!< PacMan height
#define SECONDARY_PACMAN_W  11 //!< PacMan width secondary sprite
#define SECONDARY_PACMAN_H  11//!< PacMan height secondary sprite
#define PACMAN_SPEED 1      //!< PacMan speed
#define NB_DYING_SPRITES 10 //!< Number of sprites in the dying animation

// Ghost
#define SPRITE_GHOST_W 16 //!< Ghost width (on sprite)
#define SPRITE_GHOST_H 16 //!< Ghost height (on sprite)
#define GHOST_W 16        //!< Ghost width
#define GHOST_H 16        //!< Ghost height

// Eateable ===============================================

// Gomme
#define GOMME_W 10      //!< Gomme width
#define GOMME_H 10      //!< Gomme heigth
#define GOMME_OFFSET 10 //!< Gomme offset (position offset relative to the position of the cell)
#define GOMME_SCORE 1   //!< Gomme score

// Super-Gomme
#define SUPER_GOMME_W 10     //!< Gomme width
#define SUPER_GOMME_H 10     //!< Gomme heigth
#define SUPER_GOMME_OFFSET 2 //!< Gomme offset (position offset relative to the position of the cell)
#define SUPER_GOMME_SCORE 2  //!< Super-Gomme score

// Fruit
#define FRUIT_SCORE 3 //!< Fruit score