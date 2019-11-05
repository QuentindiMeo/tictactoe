/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** tic tac toe ai denying player
*/

#include "../../include/my.h"
#include "../../include/tictactoe.h"

void choose_diamond(data **g)
{
    if ((*g)->board[X2][Y1] == EMP) {
        (*g)->played_x = 2;
        (*g)->played_y = 1;
        return;
    }
    if ((*g)->board[X1][Y2] == EMP) {
        (*g)->played_x = 1;
        (*g)->played_y = 2;
        return;
    }
    if ((*g)->board[X3][Y2] == EMP) {
        (*g)->played_x = 3;
        (*g)->played_y = 2;
        return;
    }
    if ((*g)->board[X2][Y3] == EMP) {
        (*g)->played_x = 2;
        (*g)->played_y = 3;
        return;
    }
}

void choose_corners(data **g)
{
    if ((*g)->board[X1][Y1] == EMP) {
        (*g)->played_x = 1;
        (*g)->played_y = 1;
        return;
    }
    if ((*g)->board[X1][Y3] == EMP) {
        (*g)->played_x = 1;
        (*g)->played_y = 3;
        return;
    }
    if ((*g)->board[X3][Y1] == EMP) {
        (*g)->played_x = 3;
        (*g)->played_y = 1;
        return;
    }
    if ((*g)->board[X3][Y3] == EMP) {
        (*g)->played_x = 3;
        (*g)->played_y = 3;
        return;
    }
}

static void choose_diag(data **g, char c)
{
    if (((*g)->board[X1][Y3] == c && (*g)->board[X2][Y2] == c) ||
        ((*g)->board[X3][Y3] == c && (*g)->board[X2][Y2] == c))
        (*g)->played_y = 1;
    if (((*g)->board[X1][Y1] == c && (*g)->board[X3][Y3] == c) ||
        ((*g)->board[X1][Y3] == c && (*g)->board[X3][Y1] == c))
        (*g)->played_y = 2;
    if (((*g)->board[X1][Y1] == c && (*g)->board[X2][Y2] == c) ||
        ((*g)->board[X3][Y1] == c && (*g)->board[X2][Y2] == c))
        (*g)->played_y = 3;
    if (((*g)->board[X3][Y1] == c && (*g)->board[X2][Y2] == c) ||
        ((*g)->board[X3][Y3] == c && (*g)->board[X2][Y2] == c))
        (*g)->played_x = 1;
    if (((*g)->board[X1][Y1] == c && (*g)->board[X3][Y3] == c) ||
        ((*g)->board[X1][Y3] == c && (*g)->board[X3][Y1] == c))
        (*g)->played_x = 2;
    if (((*g)->board[X1][Y1] == c && (*g)->board[X2][Y2] == c) ||
        ((*g)->board[X1][Y3] == c && (*g)->board[X2][Y2] == c))
        (*g)->played_x = 3;
}

void deny_player(data *game, int *have_to_target)
{
    if (have_to_target[0])
        choose_rowcol(game, 0);
    else if (have_to_target[1])
        choose_rowcol(game, 1);
    else
        choose_diag(&game, game->p1);
}

void choose_win(data *game, int *have_to_target)
{
    if (have_to_target[0])
        choose_rowcol(game, 2);
    else if (have_to_target[1])
        choose_rowcol(game, 3);
    else
        choose_diag(&game, game->p2);
}
