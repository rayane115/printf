/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_U.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:27:59 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/13 13:47:24 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"


int		count_len_U(unsigned int nb)
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

void	ft_left_U(unsigned int nb, t_struct *Struct, int len)
{
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_unsigned(nb);
	while (Struct->width-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_right_U(unsigned int nb, t_struct *Struct, int len, char c)
{
	while (Struct->width-- > 0)
		ft_putchar_fd(c, 1);
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_unsigned(nb);
}

void	ft_print_U(unsigned int n, t_struct *Struct)
{
	int len;
	int len_width;
	char c;

	c = ' ';
	if (Struct->flag == '0')
		c = '0';
	len = count_len(n);
	len_width = len;
	if (Struct->precision > len)
		len_width = Struct->precision;
	Struct->width = Struct->width - len_width;
	if (Struct->flag == '-')
		ft_left_U(n, Struct, len);
	else
		ft_right_U(n, Struct, len, c);
}
