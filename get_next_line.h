#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		check_line(char *linebuf);
char	*join(char *s1, char *s2, int n);
char	*ft_strdup(char *s);
int		ft_strlen(const char *s);
char	*ft_substr(char *s, int len);
char	*cut_linebuf(char *linebuf);

#endif