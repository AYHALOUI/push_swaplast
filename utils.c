#include "push_swap.h"

int check_if_duplicate(t_list **head)
{
    t_list *temp, *temp1;

    temp = *head;
    temp1 = temp->next;
	while (temp != NULL) 
	{    
        temp1 = temp->next;
        while (temp1 != NULL) 
		{    
            if(temp->data == temp1->data)
                return (1);
			temp1 = temp1->next;		    
        }
        temp = temp->next;
    }
	return (0);
}

char **check_and_join(int ac,char **av)
{
    char *str;
    int i;

    i = 1;
    str = ""; 
    while (av[i])
    {
        check_string(ac , av[i]);
        str = ft_strjoin(str,av[i]);
        str = ft_strjoin(str, " ");
        i++;
    }
    return (ft_split(str, ' '));
}

// function to check if linked list is sorted
int is_sorted(t_list **head)
{
    t_list *temp;

    temp = *head;
    while (temp->next != NULL)
    {
        if (temp->data > temp->next->data)
            return (0);
        temp = temp->next;
    }
    return (1);
}

void add_element(t_list **head, int ac, char **av)
{
    //t_list *head;
    t_list *temp;
    char **split;
    int i;
    
    i = 0;
    split = check_and_join(ac, av);
    *head = ft_lstnew(ft_atoi(split[i]));
    temp = *head;
    
    i = 1;
    while (split[i])
    {
        ft_lstadd_back(&temp, ft_lstnew(ft_atoi(split[i])));
        i++;
    }
    if (check_if_duplicate(&temp))
        quit();
    else if (is_sorted(&temp))
        return ;
}


//function to sort three elements
void sort_three(t_list **head)
{
    t_list *temp;

    temp = *head;
    if (temp->data > temp->next->data)
        sa(head);
    if (temp->data > temp->next->next->data)
        ra(head);
    if (temp->next->data > temp->next->next->data)
        rra(head);   
}

// function to sort five elements
void sort_five(t_list **head_a, t_list **head_b)
{
    t_list *temp;
    int i;

    i = 0;
    temp = *head_a;
    while (i < 2)
    {
        pb(head_a, head_b);
        i++;
    }
    sort_three(head_a);
    pa(head_a, head_b);
    pa(head_a, head_b);
}

// function to sort more than five elements
void sort_more_than_five(t_list **head_a, t_list **head_b)
{
    t_list *temp;
    int i;

    i = 0;
    temp = *head_a;
    while (i < 3)
    {
        pb(head_a, head_b);
        i++;
    }
    sort_three(head_a);
    pa(head_a, head_b);
    pa(head_a, head_b);
    pa(head_a, head_b);
}

// function to sort the stack
void sort(t_list **head_a, t_list **head_b)
{
    t_list *temp;
    int size;

    temp = *head_a;
    size = ft_lstsize(temp);
    if (size == 2)
    {
        sa(head_a);
        return ;
    }
    else if (size == 3)
        sort_three(head_a);
    else if (size == 4)
    {
        pb(head_a, head_b);
        sort_three(head_a);
        pa(head_a, head_b);
    }
    else if (size == 5)
        sort_five(head_a, head_b);
    else if (size > 5)
        sort_more_than_five(head_a, head_b);
}

// int main(int ac, char **av)
// {
//     t_list *head_a;
//     t_list *head_b;

//     head_a = NULL;
//     head_b = NULL;
//     if (ac == 1)
//         return (0);
//     add_element(&head_a, ac, av);
//     sort(&head_a, &head_b);
//     return (0);
// }