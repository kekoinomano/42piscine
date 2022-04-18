/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:43:11 by sealvare          #+#    #+#             */
/*   Updated: 2022/04/06 12:39:14 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	itoa(int nb, int pos, char *base, char *out);
int		ft_atoi_base(char *str, char *base);
int		check_base(char *base);
int		count_final_length(int nb, int len_base);

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\n'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*sol;
	int		char_len;
	int		num_int;
	int		len_base;

	if (check_base(base_from) && check_base(base_to))
	{
		len_base = ft_strlen(base_to);
		num_int = ft_atoi_base(nbr, base_from);
		char_len = count_final_length(num_int, check_base(base_to)) + 1;
		if (num_int <= 0)
			char_len = count_final_length(-num_int, check_base(base_to)) + 2;
		sol = (char *)malloc(sizeof(char) * char_len);
		if (!sol)
			return (0);
		itoa(num_int, --char_len, base_to, sol);
		sol[char_len] = '\0';
		return (sol);
	}
	else
		return (0);
}

// int	main(void)
// {
// 	ft_convert_base("	-01aj", "0123456789abcdef", "10");
// }
