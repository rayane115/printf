/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:02:47 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/13 16:51:23 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int		count_len(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_left(int nb, t_struct *Struct, int len)
{
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(nb, 1);
	while (Struct->width-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_right(int nb, t_struct *Struct, int len, char c)
{
	while (Struct->width-- > 0)
		ft_putchar_fd(c, 1);
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(nb, 1);
}

void	ft_print_nb(int nb, t_struct *Struct)
{
	int len;
	int len_width;
	char c;

	c = ' ';
	if (Struct->flag == '0')
		c = '0';
	len = count_len(nb);
	len_width = len;
	if (Struct->precision > len)
		len_width = Struct->precision;
	Struct->width = Struct->width - len_width;
	if (Struct->flag == '-')
		ft_left(nb, Struct, len);
	else
		ft_right(nb, Struct, len, c);
}
