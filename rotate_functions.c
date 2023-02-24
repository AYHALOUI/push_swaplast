/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:40 by ahaloui           #+#    #+#             */
/*   Updated: 2023/02/24 12:53:42 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


// ra function that shifts up all elements of stack a by 1. The first element becomes the last one.
void	ra(t_list **list)
{
    t_list *temp;
    t_list *temp2;

    temp = *list;
    temp2 = *list;
    if (temp->next != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = temp2;
        *list = temp2->next;
        temp2->next = NULL;
        ft_printf("ra\n");
    }
}


//rb : shift up all elements of stack b by 1. The first element becomes the last one.
void	rb(t_list **list)
{
    t_list *temp;
    t_list *temp2;

    temp = *list;
    temp2 = *list;
    if (temp->next != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = temp2;
        *list = temp2->next;
        temp2->next = NULL;
        ft_printf("rb\n");
    }
}

//rr : ra and rb at the same time.
void	rr(t_list **list_a, t_list **list_b)
{
    ra(list_a);
    rb(list_b);
    ft_printf("rr\n");
}