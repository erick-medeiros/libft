/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:59:29 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/12 18:36:06 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int			ft_printf(const char *format, ...);
int			ft_sprintf(char *str, size_t size,	const char *format, ...);

char		*get_next_line(int fd);

// #include <ctype.h>
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

// #include <string.h>
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char	*big, const char *little, size_t len);
char		*ft_strdup(const char *s);

// #include <bsd/string.h>
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

// #include <stdlib.h>
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nelem, size_t elsize);

// Part 2
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);

// Extras
char		*ft_ulltoa_base(unsigned long long nbr, char *base);
char		*ft_uitoa_base(unsigned int nbr, char *base);
void		ft_strupd(char **str, char *newstr);
size_t		ft_split_count(char const *s, char c);
int			ft_isspace(int c);
int			ft_validate_base(char *base);
int			ft_atoi_base(char *str, char *base);
void		ft_toupper_str(char **str);
void		ft_tolower_str(char **str);

// math
int			ft_abs(int number);
float		ft_absf(float number);
double		ft_absd(double number);
int			ft_max(int number1, int number2);
float		ft_maxf(float number1, float number2);
double		ft_maxd(double number1, double number2);
int			ft_min(int number1, int number2);
float		ft_minf(float number1, float number2);
double		ft_mind(double number1, double number2);

size_t		ft_split_cmd_count(char const *s, char c);
char		**ft_split_cmd(char const *s, char c);

#endif