/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** tic tac toe ai denying player rows columns
*/

#include "../../include/my.h"
#include "../../include/tictactoe.h"

static void choose_col_y(data **g, char c)
{
    if (((*g)->board[X1][Y2] == c && (*g)->board[X1][Y3] == c) ||
        ((*g)->board[X2][Y2] == c && (*g)->board[X2][Y3] == c) ||
        ((*g)->board[X3][Y2] == c && (*g)->board[X3][Y3] == c))
        (*g)->played_y = 1;
    if (((*g)->board[X1][Y1] == c && (*g)->board[X1][Y3] == c) ||
        ((*g)->board[X2][Y1] == c && (*g)->board[X2][Y3] == c) ||
        ((*g)->board[X3][Y1] == c && (*g)->board[X3][Y3] == c))
        (*g)->played_y = 2;
    if (((*g)->board[X1][Y1] == c && (*g)->board[X1][Y2] == c) ||
        ((*g)->board[X2][Y1] == c && (*g)->board[X2][Y2] == c) ||
        ((*g)->board[X3][Y1] == c && (*g)->board[X3][Y2] == c))
        (*g)->played_y = 3;
}

static void choose_col_x(data **g, char c)
{
    if (((*g)->board[X1][Y1] == c && (*g)->board[X1][Y2] == c) ||
        ((*g)->board[X1][Y1] == c && (*g)->board[X1][Y3] == c) ||
        ((*g)->board[X1][Y2] == c && (*g)->board[X1][Y3] == c))
        (*g)->played_x = 1;
    if (((*g)->board[X2][Y1] == c && (*g)->board[X2][Y2] == c) ||
        ((*g)->board[X2][Y1] == c && (*g)->board[X2][Y3] == c) ||
        ((*g)->board[X2][Y2] == c && (*g)->board[X2][Y3] == c))
        (*g)->played_x = 2;
    if (((*g)->board[X3][Y1] == c && (*g)->board[X3][Y2] == c) ||
        ((*g)->board[X3][Y1] == c && (*g)->board[X3][Y3] == c) ||
        ((*g)->board[X3][Y2] == c && (*g)->board[X3][Y3] == c))
        (*g)->played_x = 3;
}

static void choose_row_y(data **g, char c)
{
    if (((*g)->board[X1][Y1] == c && (*g)->board[X2][Y1] == c) ||
        ((*g)->board[X1][Y1] == c && (*g)->board[X3][Y1] == c) ||
        ((*g)->board[X2][Y1] == c && (*g)->board[X3][Y1] == c))
        (*g)->played_y = 1;
    if (((*g)->board[X1][Y2] == c && (*g)->board[X2][Y2] == c) ||
        ((*g)->board[X1][Y2] == c && (*g)->board[X3][Y2] == c) ||
        ((*g)->board[X2][Y2] == c && (*g)->board[X3][Y2] == c))
        (*g)->played_y = 2;
    if (((*g)->board[X1][Y3] == c && (*g)->board[X2][Y3] == c) ||
        ((*g)->board[X1][Y3] == c && (*g)->board[X3][Y3] == c) ||
        ((*g)->board[X2][Y3] == c && (*g)->board[X3][Y3] == c))
        (*g)->played_y = 3;
}

static void choose_row_x(data **g, char c)
{
    if (((*g)->board[X2][Y1] == c && (*g)->board[X3][Y1] == c) ||
        ((*g)->board[X2][Y2] == c && (*g)->board[X3][Y2] == c) ||
        ((*g)->board[X2][Y3] == c && (*g)->board[X3][Y3] == c))
        (*g)->played_x = 1;
    if (((*g)->board[X1][Y1] == c && (*g)->board[X3][Y1] == c) ||
        ((*g)->board[X1][Y2] == c && (*g)->board[X3][Y2] == c) ||
        ((*g)->board[X1][Y3] == c && (*g)->board[X3][Y3] == c))
        (*g)->played_x = 2;
    if (((*g)->board[X1][Y1] == c && (*g)->board[X2][Y1] == c) ||
        ((*g)->board[X1][Y2] == c && (*g)->board[X2][Y2] == c) ||
        ((*g)->board[X1][Y3] == c && (*g)->board[X2][Y3] == c))
        (*g)->played_x = 3;
}

void choose_rowcol(data *game, int id)
{
    if (id == 1) {
        choose_row_x(&game, game->p1);
        choose_row_y(&game, game->p1);
        return;
    }
    if (!id) {
        choose_col_x(&game, game->p1);
        choose_col_y(&game, game->p1);
    } else if (id == 3) {
        choose_row_x(&game, game->p2);
        choose_row_y(&game, game->p2);
    } else {
        choose_col_x(&game, game->p2);
        choose_col_y(&game, game->p2);
    }
}
