/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** tic tac toe game loop
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/tictactoe.h"

static void play(data **game)
{
    (*game)->board[(*game)->played_xc][(*game)->played_yc] = (*game)->p1;
    my_putstr("Player placed a piece on ");
    my_putnbr((*game)->played_x);
    my_putchar(',');
    my_putnbr((*game)->played_y);
    my_putchar('\n');
    for (uint i = 0; i < HEIGHT_BOARD; i++)
        my_putstr((*game)->board[i]);
}

static int get_x(data **game)
{
    char *entry = NULL;
    size_t buff = 0;
    int ret_v;

    (*game)->played_x = 0;
    my_putstr("Line: ");
    while (!(*game)->played_x) {
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (quit(entry));
        (*game)->played_x = my_getnbr(entry);
        if ((*game)->played_x != 1 &&
            (*game)->played_x != 2 &&
            (*game)->played_x != 3)
            (*game)->played_x = (err_out_of_range(0)) ? 0 : 0;
    }
    free(entry);
    return (SUCCESS);
}

static int get_y(data **game)
{
    char *entry = NULL;
    size_t buff = 0;
    int ret_v;

    (*game)->played_y = (my_putstr("Row: ")) ? 0 : 0;
    while (!(*game)->played_y) {
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (quit(entry));
        (*game)->played_y = my_getnbr(entry);
        if ((*game)->played_y != 1 && (*game)->played_y != 2 &&
            (*game)->played_y != 3) {
            err_out_of_range(1);
            get_x(game);
            get_y(game);
            return (SUCCESS);
        }
    }
    free(entry);
    return (SUCCESS);
}

static int user_play(data *game)
{
    int ret_v;

    my_putstr("\n\nYour turn:\n");
    do {
        ret_v = get_x(&game);
    } while (ret_v != END_OF_FILE && check_played_x(game) == FAILURE);
    if (ret_v == END_OF_FILE)
        return (END_OF_FILE);
    do {
        ret_v = get_y(&game);
        while (ret_v != END_OF_FILE && check_played_xy(game) == FAILURE) {
            do {
                ret_v = get_x(&game);
            } while (ret_v != END_OF_FILE && check_played_x(game) == FAILURE);
            ret_v = get_y(&game);
        }
    } while (ret_v != END_OF_FILE && check_played_xy(game) == FAILURE);
    if (ret_v == END_OF_FILE)
        return (END_OF_FILE);
    convert_values(&game);
    play(&game);
    return (SUCCESS);
}

int game_loop(data *game)
{
    uchar whose_turn = AI;
    int ret_v;

    for (uchar over = FALSE; over != TRUE;) {
        whose_turn = switch_turn(whose_turn);
        if (whose_turn == USER)
            ret_v = user_play(game);
        else
            ai_play(game);
        if (ret_v == END_OF_FILE)
            return (END_OF_FILE);
        if (!(is_there_any_hole_left(game) == YES && !is_win(game)))
            over = TRUE;
    }
    if (!is_win(game))
        whose_turn = DRAW;
    return (whose_turn);
}
