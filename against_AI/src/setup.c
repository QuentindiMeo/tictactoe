/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** setup tic tac toe
*/

#include <stdlib.h>
#include <getopt.h>
#include "../include/my.h"
#include "../include/tictactoe.h"

static int isok(char c)
{
    if (c < 33 || c > 126)
        return (FALSE);
    return (TRUE);
}

static char *do_switch(char c, char *optarg, data **game)
{
    switch (c) {
    case '1' :
        if (my_strlen(optarg) > 1 || !isok(*optarg))
            return (err_invalid_arg());
        (*game)->p1 = (*optarg);
        break;
    case '2' :
        if (my_strlen(optarg) > 1 || !isok(*optarg))
            return (err_invalid_arg());
        (*game)->p2 = (*optarg);
        break;
    case '?' :
        my_putstr("Try './tictactoe --help' for more information.\n");
        return (NULL);
        break;
    default :
        break;
    }
    return ("-");
}

static struct option *set_longopts(void)
{
    struct option *longopts = malloc(sizeof(struct option) * 2);

    longopts[0].name = "player";
    longopts[0].has_arg = 1;
    longopts[0].flag = NULL;
    longopts[0].val = '1';
    longopts[1].name = "ai";
    longopts[1].has_arg = 1;
    longopts[1].flag = NULL;
    longopts[1].val = '2';
    return (longopts);
}

int get_parameters(int ac, char **av, data *game)
{
    char c = 0;
    struct option *longopts = set_longopts();

    do {
        c = getopt_long(ac, av, "1:2:", longopts, NULL);
        if (do_switch(c, optarg, &game) == NULL) {
            free(longopts);
            return (FAILURE);
        }
    } while (c != END_OF_ARGS);
    free(longopts);
    return (SUCCESS);
}

void setup(data **game)
{
    for (int i = 0; i < 3; i++)
        my_strcpy((*game)->board[i], "     |     |     ");
    for (int i = 4; i < 7; i++)
        my_strcpy((*game)->board[i], "     |     |     ");
    for (int i = 8; i < HEIGHT_BOARD; i++)
        my_strcpy((*game)->board[i], "     |     |     ");
    my_strcpy((*game)->board[3], "-----+-----+-----");
    my_strcpy((*game)->board[7], "-----+-----+-----");
    for (int i = 0; i < HEIGHT_BOARD; i++) {
        (*game)->board[i][LENGTH_BOARD] = '\n';
        (*game)->board[i][LENGTH_BOARD + 1] = 0;
    }
    (*game)->p1 = P1;
    (*game)->p2 = P2;
    (*game)->played_x = 0;
    (*game)->played_y = 0;
    (*game)->played_xc = 0;
    (*game)->played_yc = 0;
}
