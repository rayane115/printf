/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:54:45 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/13 17:23:27 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int		count_len_x(unsigned long long int nb)
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
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	ft_left_x(unsigned long long int nb, t_struct *Struct, int len)
{
	char *str;
	int i = 0;
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
	if (Struct->type == 'x')
		str = ft_strdup(ft_itoa_base(nb, "0123456789abcdef"));
	else
		str = ft_strdup(ft_itoa_base(nb, "0123456789ABCDEF"));
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	while (Struct->width-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_right_x(unsigned long long int nb, t_struct *Struct, int len, char c)
{
	char *str;
	int i = 0;
	while (Struct->width-- > 0)
		ft_putchar_fd(c, 1);
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
	if (Struct->type == 'x')
		str = ft_strdup(ft_itoa_base(nb, "0123456789abcdef"));
	else
		str = ft_strdup(ft_itoa_base(nb, "0123456789ABCDEF"));
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	ft_print_x(unsigned long long int nb, t_struct *Struct)
{
	int len;
	int len_width;
	char c;

	c = ' ';
	if (Struct->flag == '0')
		c = '0';
	len = count_len_x(nb);
	len_width = len;
	if (Struct->precision > len)
		len_width = Struct->precision;
	Struct->width = Struct->width - len_width;
	if (Struct->flag == '-')
		ft_left_x(nb, Struct, len);
	else
		ft_right_x(nb, Struct, len, c);
}
