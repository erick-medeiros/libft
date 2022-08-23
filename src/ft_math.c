/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:51:29 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 11:55:46 by eandre-f         ###   ########.fr       */
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

int	ft_max(int number1, int number2)
{
	if (number1 > number2)
		return (number1);
	else
		return (number2);
}

int	ft_min(int number1, int number2)
{
	if (number1 < number2)
		return (number1);
	else
		return (number2);
}
