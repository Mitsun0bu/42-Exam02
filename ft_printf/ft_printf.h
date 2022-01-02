# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
			/* ft_printf utils */
			void	ft_putchar(char c);
			void	ft_convert_arg(char c, va_list arg_ptr);
						/* ft_convert_arg utils */
						void	ft_print_s(char *s);
						void	ft_print_d(long long nb, char *base, long long base_size);
						void	ft_print_x(unsigned long long nb, char *base, unsigned long long base_size);
			int		ft_arg_len(char c, va_list copy);
						/* ft_arg_len utils */
						int		ft_strlen(char *s);
						int		ft_len_signed(long long nb);
						int		ft_len_unsigned(unsigned long long nb);