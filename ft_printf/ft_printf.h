/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:21:48 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/04/05 19:15:26 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# define FT_PRINTF_H

size_t	ft_strlen(char *str);
int		print_char(char a);
int		print_int(int number);
int		print_string(char *str);
int		print_hexadecimal(unsigned int number, char symbol);
int		print_unsigned_d(unsigned int number);
int		print_pointer(void *ptr);
int		ft_printf(const char *format, ...);

#endif
