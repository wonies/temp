/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:53:21 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/17 07:48:54 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_list(t_node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void leaks(){
	system("leaks push_swap");
}
int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_info	info;
	char	**get;
	
	atexit(leaks);
	a = NULL;
	b = NULL;
	get = NULL;
	ft_memset(&info, 0, sizeof(t_info));
	if (ac < 2)
		return (0);
	get = parsing(&a, ac, av);
	if (!get)
		return (0);
	pushswap_start(a, b, &info);
	print_list(a);
	
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
