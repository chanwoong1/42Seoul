/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:14:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/14 12:28:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == NULL && new != NULL)
	{
		*lst = new;
		return ;
	}
	else if (lst == NULL || new == NULL)
		return ;
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
	*lst = tmp;
}
