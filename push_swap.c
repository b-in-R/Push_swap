/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:22:03 by raphael           #+#    #+#             */
/*   Updated: 2025/02/16 21:02:31 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// OK


int	check_nbrs(char **av)
{
	int	i;
	int	j;
	
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] > 47 && av[i][j] < 58)
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);		
}



int	main(int ac, char **av)
{
	t_list_ps	*list_a;
	t_list_ps	*list_b;
	
	if (ac <= 1 || check_nbrs(av) == 0) // + check si plusieurs fois le meme nbr
	{
		ft_printf("Error\n");
		return (0);
	}
	list_a = NULL;
	list_b = NULL;
	if (ac <= 5)
		return 0;// a supp

		//easy_sort(av);// voir pour renvoyer tous les chiffres
	else
	{
		ft_start_sort(**av);
	}
	return (0);
}

/*
// POUR TEST	
void    print_list(t_list *lst)
{
    while (lst)
    {
        ft_printf("%d -> ", lst->content);
        lst = lst->next;
    }
    ft_printf("NULL\n");
}

// POUR TEST
int main(void)
{
    t_list  *list_a = NULL;
    t_list  *list_b = NULL;

    // Ajout des valeurs dans list_a
    ft_add_back(&list_a, ft_create(34));
    ft_add_back(&list_b, ft_create(54));
    ft_add_back(&list_b, ft_create(12));
    ft_add_back(&list_a, ft_create(89));
    ft_add_back(&list_b, ft_create(654));
    ft_add_back(&list_a, ft_create(1));

    ft_printf("Liste A après insertion :\n");
    print_list(list_a);

    ft_printf("\nListe B après insertion :\n");
    print_list(list_b);

    // Suppression d'un élément
    ft_printf("\nSuppression de 89 de list_a...\n");
    ft_del_node(&list_a, 89);
    print_list(list_a);

    ft_printf("\nSuppression de 12 de list_b...\n");
    ft_del_node(&list_b, 12);
    print_list(list_b);

    return 0;
}
*/