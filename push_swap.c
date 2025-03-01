/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:22:03 by raphael           #+#    #+#             */
/*   Updated: 2025/03/01 17:59:05 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
			if ((av[i][j] > 47 && av[i][j] < 58) || av[i][j] == '-')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

//----------------------------------------
// POUR TEST	
void	print_list(t_list_ps **lst)
{
	t_list_ps	*current;
	
	if (!lst || !*lst)
	{
		//printf("printf_list: lst ou *lst = NULL\n");
		return;
	}
	printf("\n\nprint list_a: ");
	current = *lst;
	while (current)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
}
//---------------------------------------


int	main(int ac, char **av)
{
	if (ac <= 1 || check_nbrs(av) == 0)
	{
		printf("Error\n");
		//ft_printf("Error\n");// ./libft/ft_printf.c
		return (0);
	}
	ft_sort(ac, av);// ft_sort.c
	return (0);
} 

/*
// POUR TEST LISTES -> OK
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