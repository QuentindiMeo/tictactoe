/*
** PERSONAL PROJECT, 2019
** tictactoe
** File description:
** main tic tac toe
*/

#include "../include/my.h"
#include "../include/tictactoe.h"

static int help(void)
{
    my_putstr("\n\tWelcome to Tic-Tac-Toe\n\n \033[1mUSAGE\033[0m\n\t./tictac"
        "toe [\033[4mOPTION\033[0m]\n\n \033[1mDESCRIPTION\033[0m\n\tThis game"
        " is made of a 3x3 grid where you play against an AI. The goal\n\tis "
        "to make a line of three while getting your opponent away from doing\n"
        "\tit themself. By default, your pieces will be Xs, the AI's will be O"
        "s.\n\n\t\033[1m-1\033[0m \033[4mPIECE\033[0m, \033[1m--player\033[0m="
        "\033[4mPIECE\033[0m\n\t\033[1m-2\033[0m \033[4mPIECE\033[0m, \033[1m"
        "--ai\033[0m=\033[4mPIECE\033[0m\n\t\tChange respectively the player's"
        " or the AI's piece. \033[4mPIECE\033[0m has\n\t\tto be a printable "
        "character and can't be a space (' ').\n\n\t\033[1m-h\033[0m, \033[1m"
        "--help\033[0m\n\t\tDisplay this help.\n\n   \033[1mExit status:"
        "\033[0m\n\t0\tif the game ended with a draw or the game was quit ("
        "CTRL+D),\n\t1\tif the game ended and the player won,\n\t2\tif the "
        "game ended and the AI won,\n\t84\tif the program ended with an error."
        "\n\n \033[1mAUTHOR\033[0m\n\tWritten by Quentin di Meo.\n\n");
    return (SUCCESS);
}

static int print_winner(int id)
{
    if (!id) {
        my_putstr("\nIt's a draw!!\n");
        return (W_DRAW);
    }
    if (id == USER) {
        my_putstr("\nPlayer wins!!\n");
        return (W_USER);
    }
    if (id == AI) {
        my_putstr("\nAI wins!!\n");
        return (W_AI);
    }
    if (id == END_OF_FILE) {
        my_putstr("\nYou quit the game.\n");
        return (SUCCESS);
    }
    return (FAILURE);
}

static int main_tictactoe(int ac, char **av)
{
    data *game = mallocator();
    int winner;

    setup(&game);
    if (get_parameters(ac, av, game) == FAILURE)
        return ((freer(game)) ? FAILURE : FAILURE);
    my_putstr("Player: ");
    my_putchar(game->p1);
    my_putstr("\nAI:     ");
    my_putchar(game->p2);
    my_putstr("\n\n");
    for (int i = 0; i < HEIGHT_BOARD; i++)
        my_putstr(game->board[i]);
    winner = game_loop(game);
    freer(game);
    if (winner == END_OF_FILE || winner == DRAW)
        return ((winner == END_OF_FILE) ? END_OF_FILE : W_DRAW);
    return (winner == USER ? W_USER : W_AI);
}

int main(int ac, char **av)
{
    int ret_v;

    if (ac == 2 &&
        (my_str_isequal(av[1], "-h") || my_str_isequal(av[1], "--help")))
        return (help());
    ret_v = main_tictactoe(ac, av);
    ret_v = print_winner(ret_v);
    return (ret_v);
}
