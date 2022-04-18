/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:51:45 by sealvare          #+#    #+#             */
/*   Updated: 2022/04/06 12:36:51 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_in_base(char c, char *base);
int		is_space(char c);

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
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
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	base_len;
	int	num;
	int	i;

	num = 0;
	base_len = check_base(base);
	sign = 0;
	if (!base_len)
		return (0);
	while ((*str == '\t' || *str == '\v' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == ' ') && *str)
		str++;
	while ((*str == '+' || *str == '-') && *str)
		if (*str++ == '-')
			sign++;
	i = -1;
	while (is_in_base(str[++i], base) && str[i])
		num = (num * base_len) + (index_of_base(str[i], base));
	if (sign % 2 == 1)
		return (-num);
	else
		return (num);
}

int	count_final_length(int nb, int len_base)
{
	int	i;

	i = 0;
	while (nb >= 1)
	{
		nb /= len_base;
		i++;
	}
	return (i);
}

void	itoa(int nb, int pos, char *base, char *out)
{
	int	len_base;

	if (nb < 0)
	{
		out[0] = '-';
		itoa(-nb, pos, base, out);
	}
	else
	{
		pos--;
		len_base = check_base(base);
		if (nb >= 1)
		{
			out[pos] = base[nb % len_base];
			if (nb / len_base > 0)
				itoa(nb / len_base, pos, base, out);
		}
	}
	if (nb == 0)
		out[0] = base[nb];
}
