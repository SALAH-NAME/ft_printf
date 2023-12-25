#include "ft_printf.h"
#include "./libft/libft.h"

void ft_flag_func_initializer(t_flags_table *func_flags)
{
    func_flags[0].c = '-';
    func_flags[0].ft_flag = handle_minus;

    func_flags[1].c = '0';
    func_flags[1].ft_flag = handle_zero;

    func_flags[2].c = '.';
    func_flags[2].ft_flag = handle_point;

    func_flags[3].c = '#';
    func_flags[3].ft_flag = handle_hash;

    func_flags[4].c = ' ';
    func_flags[4].ft_flag = handle_space;

    func_flags[5].c = '+';
    func_flags[5].ft_flag = handle_plus;

    func_flags[6].c = 'w';
    func_flags[6].ft_flag = handle_width;
}


void ft_specifier_func_initializer(t_specifiers_table *func_specifiers)
{
    func_specifiers[0].c = 'c';
    func_specifiers[0].ft_specifier = handle_char;

    func_specifiers[1].c = 's';
    func_specifiers[1].ft_specifier = handle_str;

    func_specifiers[2].c = 'd';
    func_specifiers[2].ft_specifier = handle_nbr;

    func_specifiers[3].c = 'i';
    func_specifiers[3].ft_specifier = handle_nbr;

    func_specifiers[4].c = 'u';
    func_specifiers[4].ft_specifier = handle_unbr;

    func_specifiers[5].c = 'x';
    func_specifiers[5].ft_specifier = handle_lhex;

    func_specifiers[6].c = 'X';
    func_specifiers[6].ft_specifier = handle_uhex;

    func_specifiers[7].c = 'p';
    func_specifiers[7].ft_specifier = handle_add;

    func_specifiers[8].c = '%';
    func_specifiers[8].ft_specifier = handle_ptc;
}
