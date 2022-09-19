/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:20:58 by dnguyen           #+#    #+#             */
/*   Updated: 2021/10/24 10:22:42 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "unistd.h"
# include "stdlib.h"

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int value, size_t n);
int		ft_memcmp(const void *ptr, const void *ptr2, size_t num);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *string, int ch);
char	*ft_strdup(const char *src);
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *st1, const char *st2, size_t num);
char	*ft_strnstr(const char *big, const char *s, size_t len);
char	*ft_strrchr(const char *s, int a);
char	*ft_strjoin(char const *s, char const *s2);
char	*ft_strtrim(char const *s1, const char *set);
int		ft_tolower(int ch);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int ch);
char	**ft_split(char const *s, char c);

#endif
