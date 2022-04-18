/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:16:54 by sealvare          #+#    #+#             */
/*   Updated: 2022/04/02 11:16:54 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	i = -1;
	res = malloc(sizeof(*src));
	if (res == 0)
		return (0);
	while (src[++i] != '\0')
		res[i] = src[i];
	res[i] = '\0';
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					i;
	int					len;

	res = (struct s_stock_str *)malloc(sizeof(*res) * (ac + 1));
	if (!res)
		return (0);
	i = -1;
	while (++i < ac)
	{
		len = ft_strlen(av[i]);
		res[i].size = len;
		res[i].str = (char *)malloc(sizeof(char) * len + 1);
		if (!res[i].str)
			return (0);
		res[i].str = av[i];
		res[i].copy = (char *)malloc(sizeof(char) * len + 1);
		if (!res[i].copy)
			return (0);
		res[i].copy = ft_strdup(av[i]);
	}
	res[i].str = NULL;
	return (res);
}
