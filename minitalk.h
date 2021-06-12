#ifndef MINITALK_H

# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <stdio.h> // To delete afterwards.
# include <sys/wait.h> // To delete afterwards.

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_atoi(const char *c);
#endif