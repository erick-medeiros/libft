/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:42 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/16 11:42:53 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1uc;
	unsigned char	*s2uc;

	s1uc = (unsigned char *) s1;
	s2uc = (unsigned char *) s2;
	i = 0;
	while (s1uc[i] == s2uc[i] && s1uc[i] != '\0' && s2uc[i] != '\0')
		++i;
	return (s1uc[i] - s2uc[i]);
}
