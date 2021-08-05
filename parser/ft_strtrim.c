/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:03:11 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/05 03:03:19 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_strtrim(char const *s, const char *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	int		i;

	if (!s || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s);
	while (s[start] != '\0' && ft_check(s[start], set))
		start++;
	while (end > start && ft_check(s[end - 1], set))
		end--;
	if (start == 0 && end == ft_strlen(s))
		return (ft_strdup(s));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (NULL);
	while (end > start)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}