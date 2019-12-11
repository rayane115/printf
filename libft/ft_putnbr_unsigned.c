/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:09:21 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/08 18:01:32 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	long nb;

	nb = n;
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10);
	ft_putchar_fd((nb % 10) + '0', 1);
}
