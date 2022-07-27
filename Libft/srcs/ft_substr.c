/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:43:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/13 13:00:45 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*null_return(void)
{
	char	*ret;

	ret = malloc(sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

int	lencheck(char const *s, unsigned int start, size_t len)
{
	if ((ft_strlen(s) - start) < len)
		return ((ft_strlen(s) - start));
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (null_return());
	sub = (char *)malloc(sizeof(char) * (lencheck(s, start, len) + 1));
	if (!sub)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
