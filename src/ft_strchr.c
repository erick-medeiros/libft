/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:25:50 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 12:22:37 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*us;
	unsigned char	uc;
	size_t			i;

	us = (unsigned char *) s;
	uc = (unsigned char) c;
	i = 0;
	while (us[i] != '\0')
	{
		if (us[i] == uc)
			return ((char *) &us[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *) &us[i]);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*us;
	unsigned char	uc;
	int				i;

	us = (unsigned char *) s;
	uc = (unsigned char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (us[i] == uc)
			return ((char *) &us[i]);
		i--;
	}
	if (uc == '\0')
		return ((char *) &us[i]);
	return (NULL);
}
