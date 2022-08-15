/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:46:35 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/15 11:03:22 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	int		nsave;
	char	s[12];

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	nsave = n;
	if (n < 0)
		n = n * -1;
	s[11] = '\0';
	i = 11;
	while (n != 0)
	{
		i--;
		s[i] = (n % 10) + '0';
		n = n / 10;
	}
	if (nsave < 0)
	{
		i--;
		s[i] = '-';
	}
	return (ft_strdup(&s[i]));
}

char	*ft_uitoa_base(unsigned int nbr, char *base)
{
	size_t	index;
	size_t	len_base;
	char	s[11];

	if (base == NULL)
		return (NULL);
	len_base = ft_strlen(base);
	index = 10;
	s[index] = '\0';
	while (nbr != 0 || index == 10)
	{
		index--;
		s[index] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (ft_strdup(&s[index]));
}

char	*ft_ulltoa_base(unsigned long long nbr, char *base)
{
	size_t	index;
	size_t	len_base;
	char	s[21];

	if (base == NULL)
		return (NULL);
	len_base = ft_strlen(base);
	index = 20;
	s[index] = '\0';
	while (nbr != 0 || index == 20)
	{
		index--;
		s[index] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (ft_strdup(&s[index]));
}
