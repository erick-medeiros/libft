/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 00:32:55 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 13:57:48 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(void ***listptr)
{
	void	**list;
	size_t	i;

	if (*listptr != NULL)
	{
		list = *listptr;
		i = 0;
		while (list[i] != NULL)
		{
			free(list[i]);
			++i;
		}
		free(list);
		*listptr = NULL;
	}
}

// string allocation update

void	ft_strupd(char **str, char *newstr)
{
	char	*temp;

	temp = *str;
	*str = newstr;
	free(temp);
}
