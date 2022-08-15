/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:09:56 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/14 22:23:58 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./ft_printf.h"

void	ft_specifier_c(t_format *fmt, t_holder *hdr)
{
	char	c;
	char	*s;

	c = (char)va_arg(fmt->ap, int);
	if (hdr->subspec_width && hdr->width > 1)
	{
		s = ft_strdup("");
		ft_subspec_justify(&s, hdr);
		if (hdr->flag_minus)
			s[0] = c;
		else
			s[hdr->width - 1] = c;
		fmt->length += ft_writestr(fmt, 1, s, hdr->width);
		free(s);
	}
	else
		fmt->length += ft_writestr(fmt, 1, &c, 1);
	fmt->i++;
}

void	ft_specifier_d_i(t_format *fmt, t_holder *hdr)
{
	char	*s;
	int		d;

	d = (int)va_arg(fmt->ap, int);
	s = ft_itoa(d);
	if (hdr->flag_minus)
			hdr->flag_zero = 0;
	if (hdr->subspec_precision)
	{
		if (hdr->precision == 0 && d == 0)
			ft_strupd(&s, ft_strdup(""));
		else
			ft_subspec_minimum_number(&s, hdr->precision);
	}
	if (hdr->flag_plus && ft_isdigit(s[0]))
		ft_strupd(&s, ft_strjoin("+", s));
	if (hdr->flag_space && !ft_strchr(s, '-') && !ft_strchr(s, '+'))
		ft_strupd(&s, ft_strjoin(" ", s));
	hdr->length = ft_strlen(s);
	if (hdr->subspec_width && hdr->width > hdr->length)
		ft_subspec_justify(&s, hdr);
	fmt->length += ft_writestr(fmt, 1, s, hdr->length);
	fmt->i++;
	free(s);
}

void	ft_specifier_p(t_format *fmt, t_holder *hdr)
{
	unsigned long long	ull;
	char				*s;

	ull = (unsigned long long)va_arg(fmt->ap, void *);
	if (ull == 0)
		s = ft_strdup("(nil)");
	else
	{
		s = ft_ulltoa_base(ull, "0123456789abcdef");
		ft_strupd(&s, ft_strjoin("0x", s));
	}
	hdr->length = ft_strlen(s);
	if (hdr->subspec_width && hdr->width > hdr->length)
	{
		if (hdr->flag_zero && ull > 0)
			s[1] = '0';
		ft_subspec_justify(&s, hdr);
		if (hdr->flag_zero && ull > 0)
			s[1] = 'x';
	}
	fmt->length += ft_writestr(fmt, 1, s, hdr->length);
	fmt->i++;
	free(s);
}

void	ft_specifier_s(t_format *fmt, t_holder *hdr)
{
	char		*s;
	char		*sn;

	sn = (char *)va_arg(fmt->ap, char *);
	hdr->flag_zero = 0;
	if (sn == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(sn);
	if (hdr->subspec_precision)
	{
		if (sn || hdr->precision >= 6)
			ft_strupd(&s, ft_substr(s, 0, hdr->precision));
		else
			ft_strupd(&s, ft_strdup(""));
	}
	hdr->length = ft_strlen(s);
	if (hdr->subspec_width && hdr->width > hdr->length)
		ft_subspec_justify(&s, hdr);
	fmt->length += ft_writestr(fmt, 1, s, hdr->length);
	fmt->i++;
	free(s);
}

void	ft_specifier_ui(t_format *fmt, t_holder *hdr, char *prefix, char *base)
{
	unsigned int	ui;
	char			*s;

	ui = (unsigned int)va_arg(fmt->ap, unsigned int);
	s = ft_uitoa_base(ui, base);
	if (hdr->flag_minus)
		hdr->flag_zero = 0;
	if (hdr->subspec_precision)
	{
		if (hdr->precision == 0 && ui == 0)
			ft_strupd(&s, ft_strdup(""));
		else
			ft_subspec_minimum_number(&s, hdr->precision);
	}
	if (hdr->flag_numbersign && ui > 0)
		ft_strupd(&s, ft_strjoin(prefix, s));
	hdr->length = ft_strlen(s);
	if (hdr->subspec_width && hdr->width > hdr->length)
		ft_subspec_justify(&s, hdr);
	fmt->length += ft_writestr(fmt, 1, s, hdr->length);
	fmt->i++;
	free(s);
}
