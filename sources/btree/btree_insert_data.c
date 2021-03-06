/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:49:00 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/11 12:11:59 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree.h>

void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	if (!root)
		return ;
	if (!(*root))
		*root = btree_create_node(item);
	if (!(*root))
		return ;
	else if ((*cmpf)(item, (*root)->item) < 0)
	{
		btree_insert_data(&(*root)->left, item, cmpf);
		(*root)->left->parent = (*root);
	}
	else
	{
		btree_insert_data(&(*root)->right, item, cmpf);
		(*root)->right->parent = (*root);
	}
}
