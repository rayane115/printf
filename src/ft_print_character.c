/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:29:21 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/14 16:06:14 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	ft_left_char(char a, t_struct *Struct, int len)
{
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
	ft_putchar_fd(a, 1);


	while (Struct->width-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_right_char(char a, t_struct *Struct, int len, char c)
{
	while (Struct->width-- > 0)
		ft_putchar_fd(c, 1);
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
	ft_putchar_fd(a, 1);
}

void	ft_print_char(char a, t_struct *Struct)
{
	int len;
	int len_width;
	char c;

	c = ' ';
	if (Struct->flag == '0')
		c = '0';
	len = 1;
	len_width = len;
	if (Struct->precision > len)
		len_width = Struct->precision;
	Struct->width = Struct->width - len_width;
	if (Struct->flag == '-')
		ft_left_char(a, Struct, len);
	else
		ft_right_char(a, Struct, len, c);
}

