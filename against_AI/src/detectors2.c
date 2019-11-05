/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** tic tac toe detectors ai
*/

#include "../include/my.h"
#include "../include/tictactoe.h"

int diag_is_abouttowin(data *game, char c)
{
    if ((game->board[X1][Y1] == c && game->board[X2][Y2] == c &&
            game->board[X3][Y3] == EMP) ||
        (game->board[X1][Y3] == c && game->board[X2][Y2] == c &&
            game->board[X3][Y1] == EMP) ||
        (game->board[X3][Y1] == c && game->board[X2][Y2] == c &&
            game->board[X1][Y3] == EMP) ||
        (game->board[X3][Y3] == c && game->board[X2][Y2] == c &&
            game->board[X1][Y1] == EMP) ||
        (game->board[X1][Y1] == c && game->board[X3][Y3] == c &&
            game->board[X2][Y2] == EMP) ||
        (game->board[X3][Y1] == c && game->board[X1][Y3] == c &&
            game->board[X2][Y2] == EMP))
        return (YES);
    return (NO);
}

int col_is_abouttowin(data *game, char c)
{
    if ((game->board[X1][Y1] == c && game->board[X2][Y1] == c &&
            game->board[X3][Y1] == EMP) ||
        (game->board[X1][Y1] == c && game->board[X3][Y1] == c &&
            game->board[X2][Y1] == EMP) ||
        (game->board[X2][Y1] == c && game->board[X3][Y1] == c &&
            game->board[X1][Y1] == EMP) ||
        (game->board[X1][Y2] == c && game->board[X2][Y2] == c &&
            game->board[X3][Y2] == EMP) ||
        (game->board[X1][Y2] == c && game->board[X3][Y2] == c &&
            game->board[X2][Y2] == EMP) ||
        (game->board[X2][Y2] == c && game->board[X3][Y2] == c &&
            game->board[X1][Y2] == EMP) ||
        (game->board[X1][Y3] == c && game->board[X2][Y3] == c &&
            game->board[X3][Y3] == EMP) ||
        (game->board[X1][Y3] == c && game->board[X3][Y3] == c &&
            game->board[X2][Y3] == EMP) ||
        (game->board[X2][Y3] == c && game->board[X3][Y3] == c &&
            game->board[X1][Y3] == EMP))
        return (YES);
    return (NO);
}

int row_is_abouttowin(data *game, char c)
{
    if ((game->board[X1][Y1] == c && game->board[X1][Y2] == c &&
            game->board[X1][Y3] == EMP) ||
        (game->board[X1][Y1] == c && game->board[X1][Y3] == c &&
            game->board[X1][Y2] == EMP) ||
        (game->board[X1][Y2] == c && game->board[X1][Y3] == c &&
            game->board[X1][Y1] == EMP) ||
        (game->board[X2][Y1] == c && game->board[X2][Y2] == c &&
            game->board[X2][Y3] == EMP) ||
        (game->board[X2][Y1] == c && game->board[X2][Y3] == c &&
            game->board[X2][Y2] == EMP) ||
        (game->board[X2][Y2] == c && game->board[X2][Y3] == c &&
            game->board[X2][Y1] == EMP) ||
        (game->board[X3][Y1] == c && game->board[X3][Y2] == c &&
            game->board[X3][Y3] == EMP) ||
        (game->board[X3][Y1] == c && game->board[X3][Y3] == c &&
            game->board[X3][Y2] == EMP) ||
        (game->board[X3][Y2] == c && game->board[X3][Y3] == c &&
            game->board[X3][Y1] == EMP))
        return (YES);
    return (NO);
}
