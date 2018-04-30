/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <kshyshki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:22:17 by kshyshki          #+#    #+#             */
/*   Updated: 2017/10/31 18:42:49 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_countchars(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static size_t		ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	counter = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	wrd;

	i = 0;
	wrd = ft_countwords(s, c);
	if (!s)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (wrd + 1))))
		return (NULL);
	ft_bzero(str, sizeof(char*) * (wrd + 1));
	while (i < wrd)
	{
		j = 0;
		while (*s == c)
			s++;
		if (!(str[i] = ft_strnew(ft_countchars(s, c))))
			return (NULL);
		while (*s != c && *s != '\0')
			str[i][j++] = *s++;
		str[i++][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}
