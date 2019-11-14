/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** tic tac toe errors
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/tictactoe.h"

int err_out_of_range(int id)
{
    if (!id)
        my_putstr("Error: this line is invalid or out of range\n");
    else
        my_putstr("Error: this column is invalid or out of range\n");
    if (!id)
        my_putstr("Line: ");
    return (YES);
}

char *err_invalid_arg(void)
{
    my_putstr("Error: invalid character used to play.\n");
    return (NULL);
}
