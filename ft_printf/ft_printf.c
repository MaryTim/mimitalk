/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:17:21 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/04/05 19:56:34 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_print(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	if (c == 's')
		return (print_string(va_arg(args, char *)));
	if (c == 'i' || c == 'd')
		return (print_int(va_arg(args, int)));
	if (c == 'u')
		return (print_unsigned_d(va_arg(args, unsigned int)));
	if (c == 'p')
		return (print_pointer(va_arg(args, void *)));
	if (c == 'x' || c == 'X')
		return (print_hexadecimal(va_arg(args, unsigned int), c));
	if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			counter += my_print(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}

/*
int	main(void)
{
	int a = 12;
	ft_printf("test char %c and %s\n", 'm', "my string");
	ft_printf("test string %s\n", "hello world");
	ft_printf("test int %i\n", -1234524656);
	ft_printf("test decimal %d\n", -1234524656);
	ft_printf("test hex uppercase %X\n", 586);
	ft_printf("test hex lowercase %x\n", 586);
	ft_printf("test percent %%%c\n", 'h');
	ft_printf("test unsigned d %u\n", -1234524656);
	ft_printf("test pointer %p\n", &a);
	
	printf("original printf decimal %d\n", -1234524656);
	printf("original printf unsigned decimal %u\n", -1234524656);
	printf("original printf hex %X\n", 586);
	printf("original printf percent %% %c\n", 'h');
	printf("original printf pointer %p\n", &a);

	printf("\n%i", ft_printf("%%%c\n", 'h'));
	return (0);
}
*/
