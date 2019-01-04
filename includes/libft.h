/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:21:53 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/04 15:24:02 by gpouyat          ###   ########.fr       */
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
# include "./intern/get_next_line.h"
# include "./intern/ft_printf.h"
# include "./intern/ft_btree.h"
# include "./intern/secure_memory.h"
# include "./intern/color.h"

extern int			g_log_fd;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef	enum		e_bool
{
	True = 1,
	False = 0,
}					t_bool;

typedef struct		s_array_byte
{
	char	*bytes;
	size_t	nb;
}					t_array_byte;

enum				e_logger_lvl
{
	LOG_LVL_OFF,
	LOG_LVL_FATAL,
	LOG_LVL_ERROR,
	LOG_LVL_WARN,
	LOG_LVL_INFO,
	LOG_LVL_DEBUG,
	LOG_LVL_MAX
};

/*
** ERROR FUNCTION
*/
int					over_p(char *str, char *ag, int nb);
void				basicerror_out(char *name, char *error, int nb);
int					over(char *str, int nb);
void				*over_str(char *str);
void				basicerror(char *name, char *error, int ex);
void				*over_p_str(char *str, char *ag);
void				exit_error(const char *progname, const char *error,
						pid_t pid, int sig);

/*
** LIST FUNCTION
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew_secu(void const *content, size_t content_size,
						size_t lvl);
t_list				*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem));
void				ft_lstsuppress(t_list *list);
void				ft_lstaddnew(t_list **list, void const *content,
						size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nw);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstpush(t_list **alst, t_list *new_elem);
void				ft_lstpush_new(t_list **alst, void const *content,
						size_t content_size);
void				ft_lstremove(t_list **lst, t_list *removed);
void				ft_lstsort(t_list **lst, t_bool (*sort)(t_list *a,
						t_list *b));
void				ft_lstsortrev(t_list **lst, t_bool (*sort)(t_list *a,
						t_list *b));
void				ft_lstrev(t_list **lst);
void				ft_lstpush_new_secu(t_list **alst, void const *content,
						size_t content_size, size_t lvl);

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
void				ft_putsize_t_base_fd(size_t number, unsigned int base,
						int fd);
void				ft_putnbr_base_fd(unsigned int number, unsigned int base,
						int fd);
void				ft_putnbr_base_fd_low(unsigned int number,
						unsigned int base, int fd);
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
void				*ft_memcpy_swap(void *dest, const void *src, size_t n);
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

/*
** BITS FUNCTION
*/
void				b_print(int size, void const *nb);
void				b_print_array(t_array_byte array, char *split);
void				b_print_fd(int size, void const *nb, int fd);
void				b_print_array_fd(t_array_byte array, char *split, int fd);
t_array_byte		b_new_secu(size_t nb, size_t lvl);
t_array_byte		b_new(size_t nb);
t_array_byte		b_dump_secu(const char *s, size_t len, size_t lvl);
t_array_byte		b_dump(const char *s, size_t len);
t_array_byte		b_clean_secu(t_array_byte arr);
t_array_byte		b_clean(t_array_byte arr);
t_array_byte		b_joinf_secu(t_array_byte dest, t_array_byte srcs,
														int free, size_t lvl);
t_array_byte		b_join_secu(t_array_byte dest, t_array_byte srcs,
																size_t lvl);
t_array_byte		b_joinf(t_array_byte dest, t_array_byte srcs, int free);
t_array_byte		b_join(t_array_byte dest, t_array_byte srcs);
uint32_t			left_rot32(uint32_t nb, unsigned int count);

/*
**	LOGGER
*/
int					log_log(enum e_logger_lvl lvl, const char *format,
																va_list list);
int					log_init(char *filename, int fd);
void				log_close(void);
void				log_func_start(const char function[24]);
void				log_func_end(const char function[24]);
void				log_fatal(const char *fmt, ...);
void				log_error(const char *fmt, ...);
void				log_warn(const char *fmt, ...);
void				log_info(const char *fmt, ...);
void				log_debug(const char *fmt, ...);

size_t				ft_align(size_t number, size_t divider);
size_t				ft_align4(size_t number);
ssize_t				ft_next_multiple(ssize_t	number, size_t divisor);
int					ft_getopt(int argc, char const *argv[],
						const char *optstring);
char				*ft_itochar(size_t size, const void *nb, t_bool is_little);
char				*ft_itochar_secu(size_t size, const void *nb,
												t_bool is_little, size_t lvl);
#endif
