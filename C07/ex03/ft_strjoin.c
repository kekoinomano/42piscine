/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:00:01 by sealvare          #+#    #+#             */
/*   Updated: 2022/04/06 15:43:44 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char **str, int size)
{
	int	res;
	int	i;
	int	j;

	i = -1;
	res = 0;
	while (++i < size)
	{
		j = -1;
		while (str[i][++j] != '\0')
			res++;
	}
	return (res);
}

int	sep_len(char *sep)
{
	int	r;
	int	i;

	i = -1;
	r = 0;
	while (sep[++i])
		r++;
	return (r);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		len;

	if (size)
	{
		len = ft_strlen(strs, size) + (sep_len(sep) * (size - 1));
		join = (char *)malloc(sizeof(char) * (len + 1));
		if (!join)
			return (0);
	}
	else
	{
		join = (char *)malloc(sizeof(char));
		join[0] = '\0';
		return (join);
	}
	len = -1;
	*join = 0;
	while (++len < size)
	{
		join = ft_strcat(join, strs[len]);
		if (len + 1 != size)
			ft_strcat(join, sep);
	}
	return ((ft_strcat(join, "\0")));
}

// int	main(void)
// {
// 	char	*text[10];

// 	text[0] = "Testando";
// 	text[1] = "a";
// 	text[2] = "funcao";
// 	text[3] = "ft_strjoin";
// 	text[4] = "com";
// 	text[5] = "o";
// 	text[6] = "separador";
// 	text[7] = "\' - \'";
// 	text[8] = "e tamanho";
// 	text[9] = "101";
// 	printf("%s\n", ft_strjoin(10, text, " - "));
// }