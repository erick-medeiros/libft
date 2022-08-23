/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:09:12 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 13:20:43 by eandre-f         ###   ########.fr       */
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

// ft_atoi_base

int	ft_validate_base(char *base)
{
	size_t	i;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (!ft_isprint(base[i]))
			return (0);
		if (ft_strchr(&base[i + 1], base[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	convert_from_base(char *str, char *base)
{
	size_t	i;
	size_t	c;
	int		val;
	int		base_len;

	i = 0;
	val = 0;
	base_len = ft_strlen(base);
	while (str[i] && ft_strchr(base, str[i]))
	{
		c = 0;
		while (base[c] != str[i] && base[c])
			c++;
		val = (val * base_len) + c;
		i++;
	}
	return (val);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		val;
	size_t	i;

	if (!ft_validate_base(base))
		return (0);
	sign = 1;
	val = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	if (str[i] == '0')
	{
		i++;
		if (str[i] == 'x' || str[i] == 'X')
			i++;
	}
	val = convert_from_base(&str[i], base);
	return (val * sign);
}
