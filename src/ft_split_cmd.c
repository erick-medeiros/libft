/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:03:36 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/23 13:12:28 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SINGLE_QUOTE 39
#define DOUBLE_QUOTE 34

static int	count_word(char const *s, int delimiter)
{
	int	index;

	index = 0;
	while (s[index] != '\0' && s[index] != delimiter)
		index++;
	return (index);
}

static int	cmdlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (*s == SINGLE_QUOTE)
		len = count_word(++s, SINGLE_QUOTE);
	else if (*s == DOUBLE_QUOTE)
		len = count_word(++s, DOUBLE_QUOTE);
	else if (*s != c)
		len = count_word(s, c);
	return (len);
}

size_t	ft_split_cmd_count(char const *s, char c)
{
	size_t	count;
	size_t	len;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c || ft_isquote(*s))
		{
			count++;
			len = cmdlen(s, c);
			s += ft_isquote(*s);
			s += len;
			s += ft_isquote(*s);
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split_cmd(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**splited;

	if (s == NULL)
		return (NULL);
	splited = malloc(sizeof(char *) * (ft_split_cmd_count(s, c) + 1));
	if (splited == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s != c || ft_isquote(*s))
		{
			len = cmdlen(s, c);
			s += ft_isquote(*s);
			splited[i++] = ft_substr(s, 0, len);
			s += len;
			s += ft_isquote(*s);
		}
		else
			s++;
	}
	splited[i] = NULL;
	return (splited);
}
