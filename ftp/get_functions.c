#include "ft_printf.h"
#include "./libft/libft.h"


t_ft_flags ft_get_flag_func(char c)
{
    int i;
    t_flags_table   func_flags[7];

    i = 0;
    ft_flag_func_initializer(func_flags);
    if (c > '0' && c <= '9')
        c = 'w';
    while (c && (i < 7))
    {
        if (c == func_flags[i].c)
            return (func_flags[i].ft_flag);
        i++;
    }
    return (NULL);
}

t_ft_specifiers ft_get_specifier_func(char c)
{
    int i;
    t_specifiers_table  func_specifiers[9];

    i = 0;
    ft_specifier_func_initializer(func_specifiers);
    while (c && (i < 8))
    {
        if (c == func_specifiers[i].c)
            return (func_specifiers[i].ft_specifier);
        i++;
    }
    return (NULL);
}