/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:28:58 by sealvare          #+#    #+#             */
/*   Updated: 2022/04/05 18:28:58 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int lenght, int (*f)(int, int))
{
	int	i;
	int	sort;
	int	sort_rev;

	i = 0;
	sort = 0;
	sort_rev = 0;
	while (i < lenght - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			sort++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			sort_rev++;
		i++;
	}
	if (sort == i || sort_rev == i)
		return (1);
	return (0);
}
