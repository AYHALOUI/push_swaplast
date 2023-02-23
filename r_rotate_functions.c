#include "push_swap.h"


// reverse rotate functions
// rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
void	rra(t_list **list)
{
    t_list *temp;
    t_list *temp2;

    temp = *list;
    temp2 = *list;
    if (temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next->next = temp2;
        *list = temp->next;
        temp->next = NULL;
        ft_printf("rra\n");
    }
}

// rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
void	rrb(t_list **list)
{
    t_list *temp;
    t_list *temp2;

    temp = *list;
    temp2 = *list;
    if (temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next->next = temp2;
        *list = temp->next;
        temp->next = NULL;
        ft_printf("rrb\n");
    }
}

// rrr : rra and rrb at the same time.
void	rrr(t_list **list_a, t_list **list_b)
{
    rra(list_a);
    rrb(list_b);
    ft_printf("rrr\n");
}