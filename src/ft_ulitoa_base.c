/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:07:47 by eandre-f          #+#    #+#             */
/*   Updated: 2022/05/11 02:11:52 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulitoa_base(unsigned long int nbr, char *base)
{
	size_t	index;
	size_t	len_base;
	char	s[11];

	if (base == NULL)
		return (NULL);
	len_base = ft_strlen(base);
	s[10] = '\0';
	index = 10;
	while (nbr != 0 || index == 10)
	{
		index--;
		s[index] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (ft_strdup(&s[index]));
}
