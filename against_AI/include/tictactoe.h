/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** tic tac toe header
*/

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

struct data {
    char **board;
    char p1;
    char p2;
    int played_x;
    int played_y;
    int played_xc;
    int played_yc;
};
typedef struct data data;

typedef enum {
    P1 = 'X',
    P2 = 'O',
    HEIGHT_BOARD = 11,
    LENGTH_BOARD = 17,
    X1 = 1,
    X2 = 5,
    X3 = 9,
    Y1 = 2,
    Y2 = 8,
    Y3 = 14,
    EMP = ' ',
} default_tictactoe_t;

typedef enum {
    DRAW = 0,
    USER = 1,
    AI = 2,
    W_DRAW = 0,
    W_USER = 1,
    W_AI = 2,
    END_OF_ARGS = -1,
} return_values_tictactoe_t;

int err_out_of_range(int id);
char *err_invalid_arg(void);

void choose_diamond(data **g);
void choose_corners(data **g);
void choose_rowcol(data *game, int id);
void choose_win(data *game, int *have_to_target);
void deny_player(data *game, int *have_to_target);
int diag_is_abouttowin(data *game, char c);
int col_is_abouttowin(data *game, char c);
int row_is_abouttowin(data *game, char c);
int is_win(data *game);

void ai_play(data *game);

int check_played_xy(data *game);
int check_played_x(data *game);

void convert_values(data **game);
int is_there_any_hole_left(data *game);
int switch_turn(int id);
int game_loop(data *game);

int quit(char *to_be_freed);
data *freer(data *game);
data *mallocator(void);

int get_parameters(int ac, char **av, data *game);
void setup(data **game);

#endif
