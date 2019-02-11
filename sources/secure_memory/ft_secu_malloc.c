/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:57:29 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/09 12:56:22 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** @brief Adds `secu_malloc` in `mem`
**
** @param secu_malloc Item to add
** @param mem List in which to add
*/

static void		ft_s_malloc_mouv(t_secu_malloc *secu_malloc, t_mem *mem)
{
	if (!mem->first)
	{
		mem->first = secu_malloc;
		mem->last = secu_malloc;
		secu_malloc->prev = NULL;
		secu_malloc->next = NULL;
	}
	else
	{
		secu_malloc->prev = mem->last;
		mem->last->next = secu_malloc;
		mem->last = secu_malloc;
	}
}

/*
** @brief Securely mallocs with a category
**
** @param size Size to be malloced
** @param lvl Pointer category
**
** @return Returns a pointer to the malloced area in memory
*/

void			*ft_secu_malloc_lvl(size_t size, size_t lvl)
{
	void			*ptr;

	if (!(ptr = ft_memalloc(size)))
	{
		free(secu_malloc);
		over("Malloc secu: Malloc failed (return NULL)", 2);
		return (NULL);
	}
	return (ft_secu_add(ptr, lvl));
}

/*
** @brief Securely allocates memoy
** @param size Size of malloc
** @return Pointer to the area of memory which has been allocated
*/

void			*secu_malloc(size_t size)
{
	return (ft_secu_malloc_lvl(size, MALLOC_LVL_DEFAULT));
}

/*
** @brief Singleton to get the mem struct
**
** @return Return the `mem` struct
*/

t_mem			*get_mem(void)
{
	static t_mem *mem = NULL;

	if (mem == NULL)
	{
		if (!(mem = (t_mem *)ft_memalloc(sizeof(t_mem))))
		{
			over("Malloc secu: Malloc failed", 2);
			return (NULL);
		}
		mem->first = NULL;
		mem->last = NULL;
	}
	return (mem);
}

void			*ft_secu_add(void *secu_ptr, size_t lvl)
{
	t_mem			*mem;
	t_secu_malloc	*secu_malloc;

	mem = get_mem();
	if (!mem ||
		!(secu_malloc = (t_secu_malloc*)ft_memalloc(sizeof(t_secu_malloc))))
	{
		over("Malloc secu: Malloc failed (return NULL)", 2);
		return (NULL);
	}
	secu_malloc->lvl = lvl;
	secu_malloc->ptr = secu_ptr;
	secu_malloc->next = NULL;
	ft_s_malloc_mouv(secu_malloc, mem);
	return (secu_ptr);
}