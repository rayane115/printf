/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:45:32 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/06 20:00:01 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libc.h>
# include <stdarg.h>

typedef struct s_struct
{
	char flag;
	int width;
	int precision;
	char type;
}				t_struct;

int ft_printf(const char *string, ...);
int ft_recup(int n, ...);
void	ft_putchar(char c);
void	ft_verif_flags(const char *str, t_struct *Struct, int *i);

#endif
