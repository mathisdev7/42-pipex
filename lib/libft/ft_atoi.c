/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:09:12 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 22:33:32 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (2147483648);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
		if ((result > INT_MAX && sign == 1) || (result > (2147483648)
				&& sign == -1))
			return (2147483648);
	}
	if (str[i])
		return (2147483648);
	return (result * sign);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "-123456";
// 	printf("%d", ft_atoi(str));
// }
