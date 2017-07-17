/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:49:00 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/17 17:28:59 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_btree.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*btree;

	btree = NULL;
	if (!(btree = (t_btree*)malloc(sizeof(t_btree))))
		return (NULL);
	btree->parent = NULL;
	btree->left = NULL;
	btree->right = NULL;
	btree->item = item;
	return (btree);
}
