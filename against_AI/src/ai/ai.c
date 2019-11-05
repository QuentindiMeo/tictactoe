/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** tic tac toe artificial intelligence main
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/tictactoe.h"

static void play(data **game)
{
    (*game)->board[(*game)->played_xc][(*game)->played_yc] = (*game)->p2;
    my_putstr("AI placed a piece on ");
    my_putnbr((*game)->played_x);
    my_putchar(',');
    my_putnbr((*game)->played_y);
    my_putchar('\n');
    for (uint i = 0; i < HEIGHT_BOARD; i++)
        my_putstr((*game)->board[i]);
}

static void choose_random(data **g)
{
    if ((*g)->board[X1][Y1] == EMP ||
        (*g)->board[X1][Y3] == EMP ||
        (*g)->board[X3][Y1] == EMP ||
        (*g)->board[X3][Y3] == EMP)
        choose_corners(g);
    else if ((*g)->board[X2][Y1] == EMP ||
             (*g)->board[X1][Y2] == EMP ||
             (*g)->board[X3][Y2] == EMP ||
             (*g)->board[X2][Y3] == EMP)
        choose_diamond(g);
    else {
        (*g)->played_x = 2;
        (*g)->played_y = 2;
    }
}

void ai_play(data *game)
{
    int rv1[3] = {row_is_abouttowin(game, game->p2),
                  col_is_abouttowin(game, game->p2),
                  diag_is_abouttowin(game, game->p2)};
    int rv2[3] = {row_is_abouttowin(game, game->p1),
                  col_is_abouttowin(game, game->p1),
                  diag_is_abouttowin(game, game->p1)};

    my_putstr("\n\nAI's turn...\n");
    if (rv1[0] || rv1[1] || rv1[2])
        choose_win(game, rv1);
    else if (rv2[0] || rv2[1] || rv2[2])
        deny_player(game, rv2);
    else
        choose_random(&game);
    convert_values(&game);
    play(&game);
}
