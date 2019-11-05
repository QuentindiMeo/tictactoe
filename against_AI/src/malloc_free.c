/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** main tic tac toe memory allocation and free
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/tictactoe.h"

int quit(char *to_be_freed)
{
    free(to_be_freed);
    return (END_OF_FILE);
}

data *freer(data *game)
{
    if (game && game->board && game->board[0])
        for (uint i = 0; i < HEIGHT_BOARD + 1 && game->board[i]; i++)
            free(game->board[i]);
    if (game && game->board)
        free(game->board);
    if (game)
        free(game);
    return (NULL);
}

data *mallocator(void)
{
    data *game = malloc(sizeof(data));

    if (!game)
        return (NULL);
    game->board = malloc(sizeof(char *) * (HEIGHT_BOARD + 1));
    if (!game->board)
        return (freer(game));
    for (uint i = 0; i < HEIGHT_BOARD + 1; i++) {
        game->board[i] = malloc(sizeof(char) * (LENGTH_BOARD + 2));
        if (!game->board[i])
            return (freer(game));
    }
    return (game);
}
