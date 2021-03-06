/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 20:09:31 by gpouyat           #+#    #+#             */
/*   Updated: 2018/12/25 23:19:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** @brief Searches into memory for a pointer
**
** @param ptr Pointer to search
** @param mem Where to seach
**
** @return Returns the corresponding malloc struct
*/

static t_secu_malloc	*ft_malloc_search(void *ptr, t_mem *mem)
{
	t_secu_malloc *tmp;

	tmp = mem->first;
	while (tmp && (tmp->ptr != ptr))
		tmp = tmp->next;
	return (tmp);
}

/*
** @brief Frees securely the variable passed
**
** @param ptr The pointer to the variable you want to free
*/

void					ft_secu_free(void *ptr)
{
	t_mem			*mem;
	t_secu_malloc	*secu_malloc;

	if (!(mem = get_mem()))
		return ;
	if (!(secu_malloc = ft_malloc_search(ptr, mem)))
		return ;
	if (!secu_malloc->prev)
		mem->first = secu_malloc->next;
	else
		secu_malloc->prev->next = secu_malloc->next;
	if (!secu_malloc->next)
		mem->last = secu_malloc->prev;
	else
		secu_malloc->next->prev = secu_malloc->prev;
	ft_memdel(&secu_malloc->ptr);
	ft_memdel((void **)&secu_malloc);
}

/*
** @brief Frees all it can find in memory
*/

void					ft_secu_free_all(void)
{
	t_mem			*mem;
	t_secu_malloc	*secu_malloc;
	t_secu_malloc	*tmp;

	if (!(mem = get_mem()))
		return ;
	secu_malloc = mem->first;
	while (secu_malloc)
	{
		tmp = secu_malloc;
		secu_malloc = secu_malloc->next;
		free(tmp->ptr);
		free(tmp);
	}
	free(mem);
}

/*
** @brief Frees a whole `lvl`
**
** @param lvl level to free
*/

void					ft_secu_free_lvl(size_t lvl)
{
	t_mem			*mem;
	t_secu_malloc	*secu_malloc;
	t_secu_malloc	*tmp;

	if (!(mem = get_mem()))
		return ;
	secu_malloc = mem->first;
	while (secu_malloc)
	{
		if (secu_malloc->lvl == lvl)
		{
			tmp = secu_malloc;
			ft_secu_free(tmp->ptr);
			if (!(mem = get_mem()))
				return ;
			secu_malloc = mem->first;
		}
		else
			secu_malloc = secu_malloc->next;
	}
}
