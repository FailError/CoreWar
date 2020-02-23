/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:16:42 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/14 21:28:29 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <wchar.h>
# include "ft_printf.h"
# include "get_next_line.h"

/*
	** typedefs
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
	** Char functions
*/

char			*ft_chtostr(char c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_putchar(char c);
int				ft_putchar_fd(char c, int fd);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
	** Double functions
*/

char			*ft_ldtoa(long double num, int precision);
char			*ft_lda_round_check(char *str, int remaind);

/*
	** lst functions
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
	** Math functions
*/

int				ft_isnan(double num);
int				ft_isinf(double num);
double			ft_pow(double x, int y);
long long		ft_llabs(long long i);
int				ft_abs(int i);

/*
	** Mem funtions
*/

void			*ft_memset(void *destination, int c, size_t n);
void			ft_bzero(void *destination, size_t n);
void			*ft_memcpy(void *restrict dst, const void *restrict src,
				size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memccpy(void *restrict dst, const void *restrict src, int c,
				size_t n);

/*
	** Number Functions
*/
int				ft_atoi(const char *str);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa(int n);
int				ft_ulllen(unsigned long long num, int base);
char			*ft_ulltoa(unsigned long long num, int base);
int				ft_lllen(long long num, int base);
char			*ft_lltoa(long long num, int base);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);

/*
	** Str functions
*/

size_t			ft_strlen(const char *s1);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *restrict s1, const char*restrict s2);
char			*ft_strncat(char *restrict s1, const char *restrict s2,
				size_t n);
size_t			ft_strlcat(char *restrict dst, const char *restrict src,
				size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_strclr(char *s);
void			ft_putendl_fd(char const *s, int fd);
int				ft_isnumeric(char *str);
int				ft_isnumber(char *str);
/*
	** WideChar Functions
*/

int				ft_putwchar(wchar_t c);
int				ft_putwchar_fd(wchar_t c, int fd);
int				ft_putwstr(const wchar_t *wstr);
int				ft_putwstr_fd(const wchar_t *wstr, int fd);
int				ft_putwnchar(wchar_t wc, int n);
int				ft_putwnchar_fd(wchar_t wc, int n, int fd);
int				ft_wclen(const wchar_t w);
int				ft_wstrlen(const wchar_t *wstr);
wchar_t			*ft_wstrdup(const wchar_t *wstr);
wchar_t			*ft_wcsncpy(wchar_t *dst, const wchar_t *src, ssize_t n);

#endif
