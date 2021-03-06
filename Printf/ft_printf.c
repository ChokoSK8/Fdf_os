/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:58:07 by abrun             #+#    #+#             */
/*   Updated: 2020/12/12 15:54:13 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"
#include <stdio.h>

int			ft_pow_int(int n, int p)
{
	int res;

	if (p == 0)
		return (1);
	res = n;
	p--;
	while (p > 0)
	{
		res *= n;
		p--;
	}
	return (res);
}

int			print_va_arg(char c, va_list lst, char *num)
{
	const char		*s;
	if (c == 's')
	{
		s = va_arg(lst, const char *);
		return (print_s(s, num));
	}
	if (c == 'd' || c == 'i')
		return (print_d(va_arg(lst, int), num));
	else if (c == 'c')
		return (print_c(va_arg(lst, int), num));
	else if (c == 'u')
		return (print_u(va_arg(lst, unsigned int), num));
	else if (c == 'x')
		return (print_x(va_arg(lst, long long int), num));
	else if (c == 'X')
		return (print_bigx(va_arg(lst, long long int), num));
	else if (c == 'p')
		return (print_p(va_arg(lst, long long int), num));
	else if (c == '%')
	{
		return (print_c('%', num));
	}
	return (0);
}

int			fill_num_last_step(int puissance, char *num, int n, int counter)
{
	while (puissance)
	{
		num[counter] = n / ft_pow(10, puissance - 1) + '0';
		puissance--;
		n -= ((n / ft_pow(10, puissance)) * ft_pow(10, puissance));
		counter++;
	}
	return (counter);
}

int			fill_num_star(char *num, int *c_num, int n)
{
	int		puissance;
	int		counter;

	counter = *c_num;
	puissance = ft_putpui(n, 10);
	num[*c_num] = 0;
	n < 0 && is_flag_minus(num) ? n *= -1 : n;
	n < 0 ? puissance-- : puissance;
	if (n < 0)
	{
		num[counter++] = '-';
		n *= -1;
		counter = fill_num_last_step(puissance, num, n, counter);
	}
	else
	{
		counter = *c_num;
		counter = fill_num_last_step(puissance, num, n, counter);
	}
	*c_num = counter;
	num[counter] = 0;
	return (1);
}

int			ft_printf(const char *s, ...)
{
	va_list		lst;
	char		*num;
	int			c_num;
	int			n_chr;

	n_chr = 0;
	va_start(lst, s);
	while (*s)
	{
		num = malloc(100);
		c_num = 0;
		s += browse_s(s, &n_chr);
		if (*s && *s == '%')
		{
			s++;
			while (!ft_isalpha(*s) && *s != '%'  && *s)
			{
				if (*s == '*')
				{
					if (!(fill_num_star(num, &c_num, va_arg(lst, int))))
						return (0);
					s++;
				}
				else
					num[c_num++] = *s++;
			}
			num[c_num] = 0;
			n_chr += print_va_arg(*s, lst, num);
			*s ? s++ : s;
			free(num);
		}
	}
	va_end(lst);
	return (n_chr);
}
