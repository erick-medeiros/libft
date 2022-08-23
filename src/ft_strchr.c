/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:25:50 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 12:56:08 by eandre-f         ###   ########.fr       */
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	o;
	size_t	len_l;
	char	*bigc;

	bigc = (char *) big;
	len_l = ft_strlen(little);
	if (len_l == 0)
		return (bigc);
	i = 0;
	while (i < len && bigc[i] != '\0')
	{
		o = 0;
		while (bigc[i + o] == little[o] && (i + o) < len)
		{
			if (little[o + 1] == '\0')
				return (&bigc[i]);
			o++;
		}
		i++;
	}
	return (NULL);
}
