/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:26 by bkaztaou          #+#    #+#             */
/*   Updated: 2022/11/15 21:21:14 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len(int nbr, int *len)
{
	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 11);
		*len += 11;
	}
	else if (nbr >= 0 && nbr <= 9)
		*len += ft_putchar_len(nbr + '0');
	else if (nbr < 0)
	{
		*len += ft_putchar_len('-');
		ft_putnbr_len(nbr * (-1), len);
	}
	else
	{
		ft_putnbr_len(nbr / 10, len);
		ft_putnbr_len(nbr % 10, len);
	}
}
