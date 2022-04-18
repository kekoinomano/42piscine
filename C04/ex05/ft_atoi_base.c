/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:52:33 by sealvare          #+#    #+#             */
/*   Updated: 2022/04/07 13:31:30 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	index_of_base(unsigned char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	i;
	int	base_len;
	int	num;

	num = 0;
	base_len = check_base(base);
	sign = 0;
	if (!base_len)
		return (0);
	while ((*str == '\t' || *str == '\v' || *str == '\f' || *str == '\n' || \
			*str == '\r' || *str == ' ') && *str)
		str++;
	while ((*str == '+' || *str == '-') && *str)
	{
		if (*str++ == '-')
			sign++;
	}
	i = -1;
	while (index_of_base(str[++i], base) != -1 && str[i])
		num = (num * base_len) + (index_of_base(str[i], base));
	if (sign % 2 == 1)
		return (-num);
	return (num);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d", ft_atoi_base("010101", "01"));
// }