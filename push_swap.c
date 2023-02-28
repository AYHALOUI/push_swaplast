/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:45:16 by ahaloui           #+#    #+#             */
/*   Updated: 2023/02/28 23:56:36 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

    void print_list(t_list *head)
    {
        t_list *temp;
        temp = head;
        while (temp != NULL)
        {
            printf("data => %d\t index=> %d\n", temp->data, temp->index);
            temp = temp->next;
        }
    }


// void    ff()
// {
//     system("leaks push_swap");
// }
int main(int ac, char **av)
{
    // atexit(ff);
    t_list *head_a, *head_b;
    // t_list *temp;
    add_element(&head_a ,ac, av);
    index_list(head_a);
    // (void)head_b;
    sort(&head_a, &head_b);
    // print_list(head_a);
    
    // printf("==>%d|\n", instriction(ft_lstsize(head_a), get_position(head_a, ft_lstsize(head_a) - 1)));
    // printf("==>%d|\n", instriction(ft_lstsize(head_a), get_position(head_a, ft_lstsize(head_a) - 2)));
    return (0);
}