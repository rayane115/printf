/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:27:59 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/02 01:00:35 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int			count_len_u(unsigned int nb)
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

int			ft_left_u(unsigned int nb, t_struct *data, int len)
{
	int a;
	int p;

	a = 0;
	p = data->precision;
	if (data->prec_s == -1 && nb == 0)
	{
		data->precision = 2;
		data->width--;
	}

	while (data->precision-- - len > 0)
		a += ft_putchar_fd_return('0', 1);
	if (!(p == -1 && nb == 0))
		a += ft_putnbr_unsigned(nb);
	while (data->width-- > 0)
		a += ft_putchar_fd_return(' ', 1);
	return (a);
}

int			ft_right_u(unsigned int nb, t_struct *data, int len, char c)
{
	int a;
	int p;

	p = data->precision;
	a = 0;
	if (data->width == -1 && data->precision == -1 && nb == 0)
		return (a);
	if (data->flag == '0' && data->width > 0 && data->precision > 0)
		while (data->width-- > 0)
			a += ft_putchar_fd_return(' ', 1);
	while (data->width-- > 0)
		a += ft_putchar_fd_return(c, 1);
	while (data->precision-- - len > 0)
		a += ft_putchar_fd_return('0', 1);
	if (!(p == -1 && nb == 0))
		a += ft_putnbr_unsigned(nb);
	return (a);
}

void		ft_raccourci(t_struct *data, int nb, int *len)
{
	if (data->prec_s == -1 && nb == 0)
	{
		data->precision = 0;
		data->width--;
		*len = *len + 1;
	}
}

int			ft_print_u(unsigned int nb, t_struct *data)
{
	int		len;
	int		len_width;
	char	c;
	int		a;

	a = 0;
	c = ' ';
	if (data->precision == -1 && data->width > 0 && nb == 0)
		data->width = data->width + 1;
	if (data->flag == '0' && (data->precision == 0 || data->prec_s <= -1))
		c = '0';
	ft_raccourci(data, nb, &len);
	len = count_len_u(nb);
	if (nb == 0)
		len = 1;
	len_width = len;
	if (data->precision > len)
		len_width = data->precision;
	data->width = data->width - len_width;
	if (data->flag == '-')
		a = ft_left_u(nb, data, len);
	else
		a = ft_right_u(nb, data, len, c);
	return (a);
}
