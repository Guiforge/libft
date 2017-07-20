/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:21:53 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/20 20:00:35 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

# define C_NONE     "\033[0m"
# define C_BOLD     "\033[1m"
# define C_UNDER	"\033[4m"
# define C_FLASH	"\033[5m"
# define C_REVERS	"\033[7m"
# define C_BLACK    "\033[30m"
# define C_RED      "\033[31m"
# define C_GREEN    "\033[32m"
# define C_BROWN    "\033[33m"
# define C_BLUE     "\033[34m"
# define C_MAGENTA  "\033[35m"
# define C_CYAN     "\033[36m"
# define C_GREY		"\033[37m"
# define B_BLACK	"\033[40m"
# define B_RED		"\033[41m"
# define B_GREEN	"\033[42m"
# define B_ORANGE	"\033[43m"
# define B_BLUE		"\033[44m"
# define B_CYAN		"\033[46m"
# define B_GREY		"\033[47m"
# define CD_GREY	"\033[90m"
# define CL_RED		"\033[91m"
# define CL_GREEN	"\033[92m"
# define C_YELLOW	"\033[93m"
# define CL_BLUE	"\033[94m"
# define CL_TURQ	"\033[96m"
# define BD_GREY	"\033[100m"
# define BL_RED		"\033[101m"
# define BL_GREEN	"\033[102m"
# define B_YELLOW	"\033[103m"
# define BL_BLUE	"\033[104m"
# define BL_PURPLE	"\033[105m"
# define B_TURQ		"\033[106m"

/*
** ERROR FUNCTION
*/
int					over_p(char *str, char *ag, int nb);
void				basicerror_out(char *name, char *error, int nb);
int					over(char *str, int nb);
void				*over_str(char *str);
void				basicerror(char *name, char *error, int ex);
void				*over_p_str(char *str, char *ag);

/*
** LIST FUNCTION
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem));
void				ft_lstsuppress(t_list *list);
void				ft_lstaddnew(t_list **list, void const *content,
						size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nw);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

/*
** TAB FUNCTION
*/
char				**ft_strdbldup(char **str);
void				ft_strdblfree(char **tab);
char				**tri_strdbl_r(char **str);
char				**tri_strdbl(char **str);
char				**ft_strdblnew(int	size);
void				ft_strdblprint(char **tab);

/*
** STRING\IS FUNCTION
*/
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_str_isvalue(char *s);
int					ft_str_isdigit(char *s);
int					ft_str_isprint(char *s);

/*
** STRING\FREE FUNCTION
*/
void				ft_fri(char **adrr);
void				ft_strclr(char *s);
void				ft_strdel(char **as);

/*
** STRING\PUT FUNCTION
*/
void				ft_putendl(char const *str);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);

/*
** STRING\USEMALLOC
*/
char				*pf_itoa_base(intmax_t nb, uintmax_t base);
char				*pf_uitoa_base(uintmax_t nb, uintmax_t base);
char				*pf_itoa_plusbase(intmax_t nb, uintmax_t base);
char				*ft_uitoa(unsigned int n);
char				*ft_itoa_base(int nb, unsigned int base);
char				*ft_itoa_plusbase(int nb, unsigned int base);
char				*ft_strdup(const char *str);
char				*ft_strjoincl(char *s1, char const *s2, int free);
char				*ft_replace(char *src1, char *src2, int index, int size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strnew(size_t size);

int					ft_indexchr(const char *s, int c);
char				*rev(char *str);
uintmax_t			nb_of_figure(uintmax_t nb, uintmax_t base);
char				*ft_getchar(wchar_t c);
char				*ft_getwstr(wchar_t *s);
int					ft_strwlen(wchar_t *s);
void				ft_putwstr(wchar_t *s);
void				ft_putwchar(wchar_t c);
void				ft_putwstr_fd(wchar_t *s, int fd);
void				ft_putwchar_fd(wchar_t c, int fd);
int					ft_atoi_base(char *str, int base);
char				*ft_strtolower(char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_itoa(int n);
char				*win_linesitoa(uintmax_t num, unsigned int base, int *i);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_strsplit(char const *s, char c);

#endif
