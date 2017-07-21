/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 20:03:46 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/21 12:54:54 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_secu_malloc.h>

int main(void)
{
  char *toto;

  toto = NULL;
  toto = ft_secu_malloc(sizeof(char) * 5);
  if (!toto)
    ft_printf("c'est de la merde");
  ft_strncpy(toto, "la\n\0", 4);
  ft_putstr(toto);
  toto = ft_secu_malloc(600);
  ft_strncpy(toto, "lo\n\0", 4);
  toto = ft_secu_malloc(600);
  ft_strncpy(toto, "lo\n\0", 4);
  toto = ft_secu_malloc(600);
  ft_strncpy(toto, "lo\n\0", 4);
  ft_secu_free(toto);
  toto = ft_secu_malloc(600);
  ft_strncpy(toto, "lo\n\0", 4);
  toto = ft_secu_malloc(600);
  ft_strncpy(toto, "lo\n\0", 4);
  toto = ft_secu_malloc(600);
  ft_strncpy(toto, "lo\n\0", 4);

  ft_putstr(toto);
  toto = ft_secu_malloc_lvl(12, 1);
  char *tata = ft_secu_malloc_lvl(12, 2);
  char *tutu = ft_secu_malloc_lvl(12, 3);

ft_strncpy(tutu, "lu\n\0", 4);
ft_strncpy(tata, "la\n\0", 4);

ft_secu_free_lvl(3);

ft_putstr(tutu);
ft_putstr(tata);

toto = ft_secu_malloc_lvl(12, 1);
tata = ft_secu_malloc_lvl(12, 2);
tutu = ft_secu_malloc_lvl(12, 3);

ft_secu_free_all();

  return (0);
}
