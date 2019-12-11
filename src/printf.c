/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:57:58 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/11 15:33:11 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void		ft_verif_type(const char *str,t_struct *Struct,  int *i )
{
	while (str[*i])
	{
		if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X')
		{
			Struct->type = str[*i];
			return ;
		}
		*i = *i + 1;
	}
}

void	ft_verif_precision(const char *str, t_struct *Struct, int *i)
{
	if (str[*i] == '.')
	{
		*i += 1;
		Struct->precision = ft_atoi(&str[*i]);
	}
	while (str[*i] && str[*i] >= '0' &&  str[*i] <= '9')
		*i += 1;
}

void	ft_verif_width(const char *str, t_struct *Struct, int *i)
{
	if (str[*i] >= '0' &&  str[*i] <= '9')
		Struct->width = ft_atoi(&str[*i]);
	while (str[*i] && str[*i] >= '0' &&  str[*i] <= '9')
		*i += 1;
}

void	ft_verif_flags(const char *str, t_struct *Struct, int *i)
{

		if (str[*i] == '-')
		{
			Struct->flag = '-';
			while (str[*i] == '-' || str[*i] == '0')
				*i += 1;
			return ;
		}
		if (str[*i] == '0')
		{
			Struct->flag = '0';
			while (str[*i] == '0' || str[*i] == '-')
			{
				if (str[*i] == '-')
					Struct->flag = '-';
				*i += 1;
			}
			return ;
		}
}


void	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
}

void	ft_print_nb(int nb)
{
	ft_putnbr_fd(nb, 1);
}

void	ft_print_string(char *str)
{
	int i;

	i = 0;
	if (!str)
		str = NULL;

	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	ft_print_U(unsigned int n)
{
	ft_putnbr_unsigned(n);
}

void ft_print_x(unsigned long long int x)
{
	char *str;

	int i;

	i = 0;
	str = ft_strdup(ft_itoa_base(x, "0123456789abcdef"));
		while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}

}

void ft_print_X(unsigned long long int X)
{
		char *str;

	int i;

	i = 0;
	str = ft_strdup(ft_itoa_base(X, "0123456789ABCDEF"));
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	ft_print_add(long long int p)
{
	char *str;
	int i;

	i = 0;

	str = ft_strdup(ft_itoa_base_add(p, "0123456789abcdef"));
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	select_type(t_struct Struct, va_list arg)
{
	if (Struct.type == 'c')
		ft_print_char(va_arg(arg, int));
	if (Struct.type == 'd' || Struct.type == 'i')
		ft_print_nb(va_arg(arg, int));

	if (Struct.type == 's')
		ft_print_string(va_arg(arg, char *));

	 if (Struct.type == 'p')
	 	ft_print_add(va_arg(arg, long long int));

	if (Struct.type == 'u')
		ft_print_U(va_arg(arg, unsigned int));


	if (Struct.type == 'x')
		ft_print_x(va_arg(arg,unsigned long long int));

	if (Struct.type == 'X')
		ft_print_X(va_arg(arg,unsigned long long int));
}

void	ft_initial_struct(t_struct *Struct)
{
	Struct->flag = 0;
	Struct->width = 0;
	Struct->precision = 0;
	Struct->flag = 0;
}

int		count_len(int nb)
{
	int i;

	i = 0;

	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_parsing_all(t_struct Struct, va_list arg)
{
	if (Struct.flag == '-' && Struct.width > 0 && Struct.precision == 0)
	{
		//char *str;
		int i;

		i = 0;
		select_type(Struct, arg);
		while (i < Struct.width)
		{
			ft_putchar_fd(' ',1);
			i++;
		}
	}
}

int ft_printf(const char *str, ...)
{
	int i;
	t_struct Struct;
	va_list		arg;
	i = 0;

	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_initial_struct(&Struct);
			ft_verif_flags(str, &Struct, &i);
			printf("flag = %c\n", Struct.flag);
			ft_verif_width(str, &Struct, &i);
			printf("width = %d\n", Struct.width);
			ft_verif_precision(str, &Struct, &i);
			printf("precision = %d\n", Struct.precision);
			ft_verif_type(str, &Struct, &i);
			printf("type = %c\n", Struct.type);
		//	select_type(Struct, arg);
			ft_parsing_all(Struct, arg);
		}


		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(arg);
	return (0);
}
