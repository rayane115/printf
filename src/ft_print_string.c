/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:44 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/13 18:39:55 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	ft_left_string(char *str, t_struct *Struct, int len)
{
	int i = 0;
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);

	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	while (Struct->width-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_right_string(char *str, t_struct *Struct, int len, char c)
{
	int i = 0;
	while (Struct->width-- > 0)
		ft_putchar_fd(c, 1);
	while (Struct->precision-- - len > 0)
		ft_putchar_fd('0', 1);

	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	ft_print_string(char *str, t_struct *Struct)
{
	int len;
	int len_width;
	char c;

	c = ' ';
	if (Struct->flag == '0')
		c = '0';
	//len = count_len(nb);
	len = ft_strlen(str);
	len_width = len;
	if (Struct->precision > len)
		len_width = Struct->precision;
	Struct->width = Struct->width - len_width;
	if (Struct->flag == '-')
		ft_left_string(str, Struct, len);
	else
		ft_right_string(str, Struct, len, c);
}
