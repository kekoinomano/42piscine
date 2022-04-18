/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:25:44 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/18 13:12:13 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	med;
	int	arr2;
	int	i;

	med = size / 2;
	i = 0;
	while (i < med)
	{
		arr2 = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = arr2;
		i++;
	}
}
