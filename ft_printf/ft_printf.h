#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_convert_arg(char c, va_list arg_lst);
int	ft_putchar(char c);
int	ft_print_s(char *s);
int	ft_print_nb(long long nb, char *base, long long base_size);