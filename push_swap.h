#ifndef PUSH_SWAP_h
#define PUSH_SWAP_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
# include <limits.h>
#include "printf/ft_printf.h"
#include "libft/libft.h"



// parsing functions
void    quit();
int     check_is_empty(char *str);
int     is_contain_allspace(char *str);
int     check_is_digit(char *str);
void    check_string(int ac, char *str);

// utils functions
int     check_if_duplicate(t_list **head);
char    **check_and_join(int ac,char **av);
int     is_sorted(t_list **head);
void    add_element(t_list **head, int ac, char **av);

// swap functions
void    sa(t_list **head);
void	sa(t_list **head);
void	ss(t_list **list_a, t_list **list_b);

// rotate functions
void    ra(t_list **head);
void    rb(t_list **head);
void    rr(t_list **list_a, t_list **list_b);

// reverse rotate functions
void    rra(t_list **head);
void    rrb(t_list **head);
void    rrr(t_list **list_a, t_list **list_b);

// push functions
void    pa(t_list **list_a, t_list **list_b);
void    pb(t_list **list_a, t_list **list_b);
void    pp(t_list **list_a, t_list **list_b);

#endif