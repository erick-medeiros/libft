/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:09:12 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 13:04:15 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_error(int sin)
{
	if (sin == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sin;
	long	val;
	long	pre;

	i = 0;
	sin = 1;
	val = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sin = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		pre = val;
		val = (val * 10) + (nptr[i] - '0');
		if (val < pre)
			return (ft_atoi_error(sin));
		i++;
	}
	return (val * sin);
}
