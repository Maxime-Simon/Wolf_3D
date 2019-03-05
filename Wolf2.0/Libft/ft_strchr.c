/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:11:23 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/01 19:30:10 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	t;

	t = 0;
	while (s[t] != c && s[t])
		t++;
	if (s[t] == c)
		return ((char *)&s[t]);
	return (NULL);
}