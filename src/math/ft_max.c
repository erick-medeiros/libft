/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:03:49 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/08 14:07:14 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int number1, int number2)
{
	if (number1 > number2)
		return (number1);
	else
		return (number2);
}

float	ft_maxf(float number1, float number2)
{
	if (number1 > number2)
		return (number1);
	else
		return (number2);
}

double	ft_maxd(double number1, double number2)
{
	if (number1 > number2)
		return (number1);
	else
		return (number2);
}
