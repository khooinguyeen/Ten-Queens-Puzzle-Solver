/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:07:57 by kmai              #+#    #+#             */
/*   Updated: 2023/11/29 16:30:16 by kmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_putnbr(int nb)
{
	long	num;

	num = nb;
	if (num < 0)
	{
		num = -num;
		ft_putchar('-');
	}
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + 48);
	return (num);
}

void	ft_print_board(int *board)
{
	int	row;
	int	col;

	col = 0;
	while (col < 10)
	{
		ft_putnbr(board[col]);
		ft_putchar(' ');
		col++;
	}
	ft_putstr("\n=-=-=-=-=-=-=-=-=-=\n");
	row = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			if (row == board[col])
				ft_putstr("x ");
			else
				ft_putstr("o ");
			col++;
		}
		row++;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	ft_print_solution(int *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putnbr(board[i]);
		i++;
	}
	ft_putchar('\n');
}

int	ft_check(int *board, int current)
{
	int	i;

	i = 0;
	while (i < current)
	{
		if (board[i] == board[current])
			return (0);
		if (board[i] == board[current] + (current - i) || board[i] == board[current] - (current - i))
			return (0);
		i++;
	}
	return (1);
}

void	ft_try_queens(int *board, int current, int *count)
{
	int	i;

	if (current == 10)
	{
		ft_print_board(board);
		(*count)++;
		return ;
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			board[current] = i;
			if (ft_check(board, current))
				ft_try_queens(board, current + 1, count);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int count;
	int	*ptr = &count;

	count = 0;
	ft_try_queens(board, 0, ptr);
	return (count);
}

#include <stdio.h>
int	main(void)
{
	printf("Number of solution: %d\n", ft_ten_queens_puzzle());
	return (0);
}
