/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:24:19 by ahaloui           #+#    #+#             */
/*   Updated: 2023/02/23 13:21:22 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list)
{
    int temp;

    if ((*list)->next != NULL)
    {
        temp = (*list)->data;
       (*list)->data = (*list)->next->data;
       (*list)->next->data = temp;
       ft_printf("sa\n");
    }
}


void	sb(t_list **list)
{
    int temp;

    if ((*list)->next != NULL)
    {
        temp = (*list)->data;
       (*list)->data = (*list)->next->data;
       (*list)->next->data = temp;
       ft_printf("sb\n");
    }
}

void	ss(t_list **list_a, t_list **list_b)
{
    sa(list_a);
    sb(list_b);
    ft_printf("ss\n");
}