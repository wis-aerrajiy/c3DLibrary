/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:49:50 by mabahani          #+#    #+#             */
/*   Updated: 2023/04/17 23:59:39 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

static int	is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	first_index(char const *s1, char const *set)
{
	int	s_len;

	s_len = 0;
	while (s1[s_len] != '\0')
	{
		if (!is_set(set, s1[s_len]))
			break ;
		s_len++;
	}
	return (s_len);
}

static int	last_index(char const *s1, char const *set, int where_first)
{
	int	l_len;

	l_len = ft_strlen(s1) - 1;
	while (l_len >= where_first)
	{
		if (!is_set(set, s1[l_len]))
			break ;
		l_len--;
	}
	return (l_len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		last;
	int		i;
	int		first;
	char	*new;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	first = first_index(s1, set);
	last = last_index(s1, set, first);
	new = malloc(((last - first) + 1) * sizeof(char));
	if (new != NULL)
	{
		while (first < last)
			new[i++] = s1[first++];
		new[i] = '\0';
	}
	return (new);
}
