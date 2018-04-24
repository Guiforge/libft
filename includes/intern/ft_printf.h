/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:33:06 by gpouyat           #+#    #+#             */
/*   Updated: 2018/04/24 09:31:49 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	struct			s_flags
{
	unsigned char		hash;
	unsigned char		space;
	unsigned char		plus;
	char				convers;
	char				type[3];
	int					minus;
	int					preci;
	int					width;
	int					zero;
	int					size;
}						t_flags;

uintmax_t				ft_utnum(t_flags flags, va_list ap);
intmax_t				ft_tnum(t_flags flags, va_list ap);
char					*minus(t_flags flags, char *str);
char					*width(t_flags flags, char *str);
char					*preci(t_flags flags, char *str);
void					check(t_flags flags, char *format);
char					*ft_x(t_flags flags, char *format, va_list ap, int **i);
char					*ft_o(t_flags flags, char *format, va_list ap, int **i);
char					*ft_s(t_flags flags, char *format, va_list ap, int **i);
char					*ft_c(t_flags **flags, char *format, va_list ap,
																	int **i);
char					*ft_ups(t_flags flags, char *format, va_list ap,
																	int **i);
char					*ft_upc(t_flags **flags, char *format, va_list ap,
																	int **i);
char					*ft_convers(t_flags *flags, char *format, va_list ap,
																		int *i);
int						ft_printf(char *format, ...);
t_flags					get_struct(t_flags flags, char *format);
int						print(int fd, char *frmt, va_list ap);
char					*pf_couleur(char *format);
int						ft_dprintf(int fd, char *frmt, ...);

#endif
