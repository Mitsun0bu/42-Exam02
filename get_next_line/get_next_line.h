#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*get_line(char *line, char *buff, int fd);
int		ft_strlen(char *s);
int		ft_position_nl(char *s);
char	*ft_strjoin(char *line, char *buff);