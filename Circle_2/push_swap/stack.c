/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:12:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/11 17:14:43 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

// 초기화 함수
void init(t_linked_stack *s)
{
	s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(t_linked_stack *s)
{
	return (s->top == NULL);
}

// 삽입 함수
void push(t_linked_stack *s, int item)
{
	t_stack	*temp;
	
	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
	{
		free_node(s);
		return;
	}
	temp->item = item;
	temp->link = s->top;
	s->top = temp;
}

// 삭제 함수
int	pop(t_linked_stack *s)
{
	t_stack	*temp;
	int		item;

	temp = 0;
	item = 0;
	if (is_empty(s))
	{
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else
	{
		temp = s->top;
		item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}

// 피크 함수
int	peek(t_linked_stack *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else
		return s->top->item;
}
