/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:21:20 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/14 23:23:49 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*suc;
	unsigned char	cuc;

	suc = (unsigned char *)s;
	cuc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (suc[i] == cuc)
			return (&suc[i]);
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1uc;
	unsigned char	*s2uc;

	s1uc = (unsigned char *)s1;
	s2uc = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1uc[i] != s2uc[i])
			return (s1uc[i] - s2uc[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_uc;
	unsigned char	*src_uc;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_uc = (unsigned char *)dest;
	src_uc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_uc[i] = src_uc[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_uc;
	unsigned char	*src_uc;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_uc = (unsigned char *)dest;
	src_uc = (unsigned char *)src;
	i = -1;
	if (src_uc < dest_uc)
		while (++i < n)
			dest_uc[n - 1 - i] = src_uc[n - 1 - i];
	else
		while (++i < n)
			dest_uc[i] = src_uc[i];
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*suc;

	suc = (unsigned char *)s;
	i = -1;
	while (++i < n)
		suc[i] = c;
	return (suc);
}
