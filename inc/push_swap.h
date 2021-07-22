#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_direction
{
	R,
	RR
}	t_direction;

typedef struct s_node
{
	int					number;
	int					index;
	t_bool				keep_in_stack;
	struct s_node		*previous;
	struct s_node		*next;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	int			size;
	int			pairs;
	t_node		*mkp_head;
}	t_stack;

typedef struct s_info
{
	t_node		*a_node;
	t_node		*b_node;
	int			a_dir;
	int			b_dir;
	int			size;
	t_bool		is_set;
}	t_info;

t_stack	*create_stack(char **av);
void	ft_error(void);
void	ft_putendl(const char *str);
int		ft_isdigits(const char *str);
void	check_duplicates(t_stack *stack);

void	ft_sx(t_stack *stack, const char *name);
void	ft_rx(t_stack *stack, const char *name);
void	ft_rrx(t_stack *stack, const char *name);
void	ft_rr(t_stack *a, t_stack *b, const char *name);
void	ft_rrr(t_stack *a, t_stack *b, const char *name);
void	ft_ss(t_stack *a, t_stack *b, const char *name);
void	ft_px(t_stack *to, t_stack *from, const char *name);
void	free_stack(t_stack *stack);

void	indexing(t_stack *stack);
void	markup_stack(t_stack *stack);
int		mode_greater(t_stack *stack, t_node *markup_head);
void	solve(t_stack *a_stack);
void	solve_a(t_stack *a_stack, t_stack *b_stack);
void	solve_b(t_stack *a_stack, t_stack *b_stack);
void	ft_opt_direction(t_stack *a_stack, t_stack *b_stack,
			t_info *shift_info);
int		ft_max(int i, int j);
long	ft_atol(char *str);
int		ft_isint(long nbr);

#endif
