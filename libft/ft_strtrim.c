/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:26:05 by rqouchic          #+#    #+#             */
/*   Updated: 2019/11/13 13:24:54 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charset(char str1, char const *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (str1 != charset[i])
			i++;
		else
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	j = 0;
	a = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[j])
		j++;
	j--;
	while (ft_charset(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	while (ft_charset(s1[j], set))
		j--;
	if (!(str = malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (i <= j)
		str[a++] = s1[i++];
	str[a] = '\0';
	return ((char *)str);
}
