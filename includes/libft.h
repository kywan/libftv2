/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:50:07 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/24 11:28:17 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_strcleanc(char **str, char c);

int					ft_strsub_len(char const *str, char c);

t_list				*ft_lst_push_back(t_list **lst, t_list *item);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd(t_list **alst, t_list *n);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

t_list				*ft_lstnew(void const *content, size_t content_size);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

char				*ft_strnstr(const char *s1, const char *s2, size_t n);

void				ft_strclr(char *s);

void				ft_strdel(char **as);

char				*ft_strnew(size_t size);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

void				*ft_memset(void *b, int c, size_t len);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memmove(void *des, const void *src, size_t n);

void				*ft_memalloc(size_t size);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				ft_bzero(void *s, size_t n);

void				ft_memdel(void **ap);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr(long long n);

char				*ft_strrev(char *a);

void				ft_putnbr_fd(int n, int fd);

char				*ft_strtrim(char const *s);

char				*ft_strjoin(char const *s1, char const *s2);

char				**ft_strsplit(char const *s, char c);

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isspace(int c);

int					ft_isprint(int c);

int					ft_tolower(int c);

int					ft_toupper(int c);

size_t				ft_strlen(const char *c);

int					ft_nbrlen(int i);

int					ft_atoi(char *c);

char				*ft_itoa(int n);

char				*ft_ftoa(float n, int prec);

double				ft_pow(double x, int y);

char				*ft_strcat(char *dest, const char *src);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strdup(const char *c);

int					ft_strlcat(char *dest, char *src, size_t i);

char				*ft_strncat(char *dest, char *src, int i);

char				*ft_strncpy(char *dest, const char *src, size_t i);

char				*ft_strstr(const char *s1, const char *s2);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

void				ft_putchar(char c);

void				ft_putchar_fd(char c, int i);

void				ft_putstr(const char *c);

void				ft_putstrlen(const char *c, int len);

void				ft_putstr_fd(char const *c, int fd);

void				ft_putnstr(const char *c, int n);

void				ft_putendl(char const *c);

void				ft_swap(void *a, void *b);

void				ft_swap_ptr(void **p1, void **p2);

#endif
