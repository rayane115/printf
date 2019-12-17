/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:00:59 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/14 16:35:00 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

/*int		count_len_add(long long int nb)
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
}*/

void	ft_left_add(char *str, t_struct *Struct, int len)
{
	int i = 0;

	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
	write(1,"0x",2);
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	while (Struct->width-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_right_add(char *str, t_struct *Struct, int len, char c)
{
	int i = 0;

	while (Struct->width-- > 0)
		ft_putchar_fd(c, 1);
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);
		write(1,"0x",2);
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	ft_print_add(long long int nb, t_struct *Struct)
{
	char *str;
	int len;
	int len_width;
	char c;

	c = ' ';
	if (Struct->flag == '0')
		c = '0';
	str = ft_strdup(ft_itoa_base_add(nb, "0123456789abcdef"));
	len = ft_strlen(str) + 2;
	len_width = len;
	if (Struct->precision > len)
		len_width = Struct->precision;
	Struct->width = Struct->width - len_width;
	if (Struct->flag == '-')
		ft_left_add(str, Struct, len);
	else
		ft_right_add(str, Struct, len, c);
}
