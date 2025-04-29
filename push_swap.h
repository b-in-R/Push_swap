
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_list_ps
{
	int					value;
	int					index;
	struct s_list_ps	*next;
}						t_list_ps;

typedef struct s_logic
{
	int					pos;
	int					i;
	int					j;
	int					len;
}						t_logic;

//push_swap.c
int			ft_exit_error(char **str, t_list_ps *lst, int free_s, int free_l);

//ft_free.c
void		ft_free_list(t_list_ps *lst);
void		ft_free_str(char **str);

//ft_sort.c
int			ft_sort(char **str);
int			ft_check_sort(t_list_ps *list_a);

//ft_node.c
void		ft_start_list(char **str, t_list_ps **list_a);
t_list_ps	*ft_create(int value);
void		ft_add_front(t_list_ps **lst, t_list_ps *new);
void		ft_add_back(t_list_ps **lst, t_list_ps *new);

//ft_copy_list.c
void		ft_preprint(char *str, char *to_add, int *i);
int			ft_check_copy(t_list_ps *list_a, t_list_ps *list_copy);
void		ft_copy_list(t_list_ps *list_a, t_list_ps **list_copy);

//ft_logic.c
t_list_ps	*ft_logic(t_list_ps **list_a, t_logic *val);
int			ft_lst_len(t_list_ps *lst);

//ft_logic_less_6.c
t_list_ps	*ft_logic_less_6(t_list_ps **list_a, t_logic *val);

#endif