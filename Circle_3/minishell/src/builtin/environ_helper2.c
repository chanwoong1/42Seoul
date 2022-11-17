/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:47:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 19:41:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "../main/helper.h"

/** while copying, add declare -x and quote " "  */
void	copy_strs_for_export(char **dst, char **src, size_t strs_count)
{
	size_t		i;
	t_string	*str;

	i = 0;
	str = new_string(64);
	while (i < strs_count)
	{
		str->f_clear(str);
		str->f_append(str, "declare -x ");
		str->f_append(str, src[i]);
		str->f_replace(str, ft_strchr(str->text, '=') - str->text, 1, "=\"");
		str->f_push_back(str, '\"');
		dst[i] = ft_strdup(str->text);
		i++;
	}
	delete_string(&str);
	dst[strs_count] = NULL;
}
