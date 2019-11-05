/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** tic tac toe avoid overwriting
*/

#include "../include/my.h"
#include "../include/tictactoe.h"

int check_played_xy(data *game)
{
    int x = game->played_x == 1 ? X1 : (game->played_x == 2 ? X2 : X3);
    int y = game->played_y == 1 ? Y1 : (game->played_y == 2 ? Y2 : Y3);

    if (game->board[x][y] != EMP) {
        my_putstr("Error: this place is already taken\n");
        return (FAILURE);
    }
    return (SUCCESS);
}

int check_played_x(data *game)
{
    if ((game->played_x == 1 && game->board[X1][Y1] != EMP &&
        game->board[X1][Y2] != EMP && game->board[X1][Y3] != EMP) ||
        (game->played_x == 2 && game->board[X2][Y1] != EMP &&
        game->board[X2][Y2] != EMP && game->board[X2][Y3] != EMP) ||
        (game->played_x == 3 && game->board[X3][Y1] != EMP &&
        game->board[X3][Y2] != EMP && game->board[X3][Y3] != EMP)) {
        my_putstr("Error: this line is already full\n");
        return (FAILURE);
    }
    return (SUCCESS);
}
