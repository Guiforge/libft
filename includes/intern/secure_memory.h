/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_memory.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:56:25 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/09 12:56:15 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECURE_MEMORY_H
# define SECURE_MEMORY_H

# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

# define MALLOC_LVL_DEFAULT 0
# define M_LVL_FUNCT 1

/*
** @file   secure_memory.h
**
** @brief  Function prototypes for the lexer module
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @struct s_secu_malloc
**
** @brief Contains all the info for the secu_malloc functions
**
** @param ptr Pointer to the malloc memory area
** @param lvl Categorize the pointer
** @param prev Previous struct
** @param next Next struct
*/

struct							s_secu_malloc
{
	void						*ptr;
	size_t						lvl;
	struct s_secu_malloc		*prev;
	struct s_secu_malloc		*next;
};

typedef struct s_secu_malloc	t_secu_malloc;

/*
** @struct s_mem
**
** @brief Main struct to hold the malloc securely
**
** @param first First node
** @param last last node
*/

typedef struct					s_mem
{
	t_secu_malloc				*first;
	t_secu_malloc				*last;
}								t_mem;

/*
** @file ft_secu_free.c
**
** @brief Functions used to securely free
*/

void							ft_secu_free(void *ptr);
void							ft_secu_free_all(void);
void							ft_secu_free_lvl(size_t lvl);

/*
** @file ft_secu_malloc.c
**
** @brief Functions to malloc securely
*/

void							*secu_malloc(size_t size);
void							*ft_secu_malloc_lvl(size_t size, size_t lvl);
t_mem							*get_mem(void);

char							*ft_strdup_secu(const char *str, size_t lvl);
char							*ft_strnew_secu(size_t size, size_t lvl);

void							*ft_secu_add(void *secu_ptr, size_t lvl);

void							ft_secu_malloc_debug(void);
#endif
