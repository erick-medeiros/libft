/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:03:47 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/08 14:10:12 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

float	ft_absf(float number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

double	ft_absd(double number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}
