/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:55:16 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/14 22:33:28 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

int	ft_sprintf(char *str, size_t size,	const char *format, ...)
{
	va_list		ap;
	t_format	*fmt;
	int			len;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	fmt = ft_initialize_format(format, ap);
	if (fmt == NULL)
		return (0);
	fmt->fill_str = 1;
	fmt->str = str;
	fmt->size_str = size;
	len = ft_while_placeholder(fmt);
	free(fmt);
	va_end(ap);
	return (len);
}

int	ft_vprintf(const char *format, va_list ap)
{
	t_format	*fmt;
	size_t		length;

	fmt = ft_initialize_format(format, ap);
	length = ft_while_placeholder(fmt);
	free(fmt);
	return (length);
}
