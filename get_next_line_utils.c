#include "get_next_line.h"

int	check_line(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf && buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*join(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	if (n == 1 && !s1)
		return (ft_strdup(s2));
	d = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		d[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		d[i++] = s2[j++];
	d[i] = '\0';
	if (s1)
		free((char *)s1);
	return (d);
}

int	check_eof(int k, char **linebuf, char *buf, char **line)
{
	if (k == 0 && (ft_strlen(*linebuf) == 0 || !*linebuf))
	{
		free(*linebuf);
		*linebuf = NULL;
		free(buf);
		*line = ft_strdup("");
		return (0);
	}
	return (1);
}

int	make_line_and_linebuf(char **line, char **linebuf, char **buf, int k)
{
	// if (k < BUFFER_SIZE && check_line(*linebuf) == -1)
	// 	*linebuf[ft_strlen(*linebuf)] = '\n';
	free(*buf);
	*buf = NULL;
	*line = ft_substr(*linebuf, check_line(*linebuf));
	if (!*line)
	{
		free(*linebuf);
		*linebuf = NULL;
		return (-1);
	}
	if (k != 0)
		*linebuf = cut_linebuf(*linebuf);
	if (!*linebuf)
		return (-1);
	if (k == 0)
	{
		free(*linebuf);
		*linebuf = NULL;
		return (0);
	}
	return (1);
}
