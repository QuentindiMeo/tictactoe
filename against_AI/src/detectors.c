/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** tic tac toe detectors
*/

#include "../include/my.h"
#include "../include/tictactoe.h"

static int someone_won(char **board, char p)
{
    if ((board[X1][Y1] == p && board[X2][Y1] == p && board[X3][Y1] == p) ||
        (board[X1][Y2] == p && board[X2][Y2] == p && board[X3][Y2] == p) ||
        (board[X1][Y3] == p && board[X2][Y3] == p && board[X3][Y3] == p) ||
        (board[X1][Y1] == p && board[X1][Y2] == p && board[X1][Y3] == p) ||
        (board[X2][Y1] == p && board[X2][Y2] == p && board[X2][Y3] == p) ||
        (board[X3][Y1] == p && board[X3][Y2] == p && board[X3][Y3] == p) ||
        (board[X1][Y1] == p && board[X2][Y2] == p && board[X3][Y3] == p) ||
        (board[X1][Y3] == p && board[X2][Y2] == p && board[X3][Y1] == p))
        return (TRUE);
    return (FALSE);
}

int is_win(data *game)
{
    if (someone_won(game->board, game->p1) ||
        someone_won(game->board, game->p2))
        return (TRUE);
    return (FALSE);
}

void convert_values(data **game)
{
    if ((*game)->played_x == 1)
        (*game)->played_xc = X1;
    if ((*game)->played_x == 2)
        (*game)->played_xc = X2;
    if ((*game)->played_x == 3)
        (*game)->played_xc = X3;
    if ((*game)->played_y == 1)
        (*game)->played_yc = Y1;
    if ((*game)->played_y == 2)
        (*game)->played_yc = Y2;
    if ((*game)->played_y == 3)
        (*game)->played_yc = Y3;
}

int is_there_any_hole_left(data *game)
{
    if (game->board[X1][Y1] != EMP &&
        game->board[X1][Y2] != EMP &&
        game->board[X1][Y3] != EMP &&
        game->board[X2][Y1] != EMP &&
        game->board[X2][Y2] != EMP &&
        game->board[X2][Y3] != EMP &&
        game->board[X3][Y1] != EMP &&
        game->board[X3][Y2] != EMP &&
        game->board[X3][Y3] != EMP)
        return (NO);
    return (YES);
}

int switch_turn(int id)
{
    int save = id;

    if (save == USER)
        id = AI;
    if (save == AI)
        id = USER;
    return (id);
}
