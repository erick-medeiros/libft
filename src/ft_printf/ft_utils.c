/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:26:51 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/14 22:36:11 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./ft_printf.h"

t_format	*ft_initialize_format(const char *format, va_list ap)
{
	t_format	*fmt;

	fmt = malloc(sizeof(t_format));
	if (fmt == NULL)
		return (NULL);
	fmt->format = format;
	va_copy(fmt->ap, ap);
	fmt->i = 0;
	fmt->length = 0;
	fmt->fill_str = 0;
	fmt->str_i = 0;
	fmt->size_str = 0;
	fmt->str = NULL;
	return (fmt);
}

t_holder	*ft_initialize_holder(void)
{
	t_holder	*hdr;

	hdr = (t_holder *)malloc(sizeof(t_holder));
	if (hdr == NULL)
		return (NULL);
	hdr->flag_minus = 0;
	hdr->flag_plus = 0;
	hdr->flag_space = 0;
	hdr->flag_numbersign = 0;
	hdr->flag_zero = 0;
	hdr->subspec_width = 0;
	hdr->width = 0;
	hdr->subspec_precision = 0;
	hdr->precision = 0;
	hdr->length = 0;
	return (hdr);
}

void	ft_specifier_pct(t_format *fmt)
{
	char	c;

	c = '%';
	fmt->length += ft_writestr(fmt, 1, &c, 1);
	fmt->i++;
}

int	ft_writestr(t_format *fmt, int fd, const void *buf, size_t count)
{
	size_t	length;
	size_t	i;

	if (fmt->fill_str == 1)
	{
		i = 0;
		while (i < count && fmt->str_i < fmt->size_str)
		{
			fmt->str[fmt->str_i] = ((char *)buf)[i];
			++i;
			++fmt->str_i;
		}
		fmt->str[fmt->str_i] = '\0';
		length = i;
	}
	else
		length = write(fd, buf, count);
	return (length);
}
