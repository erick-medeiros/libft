/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:42 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 12:06:53 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	i = 0;
	while (us1[i] == us2[i] && us1[i] != '\0' && us2[i] != '\0')
		++i;
	return (us1[i] - us2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (us1[i] != us2[i] || us1[i] == '\0' || us2[i] == '\0')
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
