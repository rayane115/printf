/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:13:06 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/01 22:56:55 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int			ft_len2(unsigned int n, char *base)
{
	int len;
	int res;

	res = 0;
	if (n < 0)
		res++;
	len = ft_strlen(base);
	while (n)
	{
		n = n / len;
		res++;
	}
	return (res);
}

char		*ft_itoa_base(unsigned int n, char *base)
{
	char	*str;
	int		i;
	int len_base;
	int len;

	i = 0;
	len_base = ft_strlen(base);
	len = ft_len2(n, base);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	str[len + 1] = 0;
	while (len >= 0)
	{
		str[--len] = base[n % len_base];
		n = n / len_base;
	}
	return (str);
}
