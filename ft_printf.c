/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:00:10 by codecham          #+#    #+#             */
/*   Updated: 2021/01/30 20:57:14 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags		    ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.width = 0;
	flags.zero = 0;
    flags.type = 0;
    flags.stardot = 0;
	return (flags);
}

static int     ft_treat_save(const char *save, va_list args)
{
    int     i;
    int     char_count;
    t_flags flags;

    i = 0;
    char_count = 0;
    while(1)
    {
        flags = ft_init_flags();
        if(!save[i])
            break;
        else if(save[i] == '%' && save[i + 1])
        {
            i = ft_flag(save, ++i, &flags, args);
            if (ft_type_list(save[i]))
                char_count += ft_print_var(flags.type, flags, args);
            else if(save[i])
                char_count += ft_putchar(save[i]);           
        }
        else if (save[i] != '%')
            char_count += ft_putchar(save[i]);
        i++;
    }
    return(char_count);

}

int         ft_printf(const char *input, ...)
{
    const char      *save;
    va_list         args;
    int             char_count;

    save = strdup(input);
    char_count = 0;
    va_start(args, input);
    char_count = char_count + ft_treat_save(save, args);
    va_end(args);
    free((char *)save);
    return (char_count);
}

// int main(void)
// {
// 	// printf("(-) -> |%0.*d|", -20, -2147483647);
//     // printf("\n-----------------------------\n");
// 	// ft_printf("(-) -> |%0.*d|", -20, -2147483647);
//     // printf("\n-----------------------------\n");
//     // printf("\n-----------------------------\n");
//     // // printf("(+) -> |%0.*d|", 20, -2147483647);
//     // // printf("\n-----------------------------\n");
// 	// // ft_printf("(+) -> |%0.*d|", 20, -2147483647);
// }

// int main(void)
// {
//     printf("-------SERIE DE TEST--------\n");
//     //printf("* (+) -> |%*d|\n", 7, -1);
//     printf(". + * (+) -> |%.*d|\n", 4, -1);
//     ft_printf(". + * (+) -> |%.*d|\n", 4, -1);
//     // printf("0 + * (+) -> |%0*d|\n", 4, -1);
//     printf("\n-----------------------------\n");
//     //printf("* (-) -> |%*d|\n", -7, -1);
//     printf(". + * (-) -> |%.*d|\n", -7, -1);
//     ft_printf(". + * (-) -> |%.*d|\n", -7, -1);
//     // printf("0 + * (-) -> |%0*d|\n", -7, -1);
//     printf("\n-----------------------------\n");
    
    

//     // printf("0 + 19 (-)|%019d|\n", -1 );
//     // printf("|%0*d|\n", -4, -1);
//     // ft_printf("|%0*d|\n", -4, -1);
// }