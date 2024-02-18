/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:45 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 17:23:38 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int				ft_atoi(const char *str);
int				ft_isalnum(int i);
int				ft_isalpha(int i);
int				ft_isascii(int i);
int				ft_isdigit(int i);
int				ft_isprint(int i);
char			*ft_strchr(const char *str, int p);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *str, int p);
int				ft_tolower(int i);
int				ft_toupper(int i);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memset(void *ptr, int v, size_t count);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_bzero(void *s, size_t count);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			*ft_calloc(size_t nmemb, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t destsize);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
long long int	ft_atoll(const char *str);
int				ft_is_space(char c);

#endif