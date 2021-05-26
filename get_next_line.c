#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, int len)
{
	char	*b;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((ft_strlen(s) == 0) || (len <= 0))
		return (ft_strdup(""));
	b = (char *)malloc((len + 1) * sizeof(char));
	if (!b)
		return (NULL);
	while (s[i] != '\0' && len > 0)
	{
		b[i] = s[i];
		i++;
		len--;
	}
	b[i] = '\0';
	return (b);
}

char	*ft_strdup(char *s)
{
	int			len;
	int			i;
	char		*d;

	i = 0;
	len = ft_strlen(s);
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*cut_linebuf(char *linebuf)
{
	int		i;
	int		j;
	char	*new_linebuf;

	i = 0;
	j = 0;
	while (linebuf[i] != '\n' && linebuf[i] != '\0')
		i++;
	if (linebuf[i] != '\n')
		return (ft_strdup(""));
	new_linebuf = malloc(sizeof(char) * (check_line(linebuf) + 1));
	if (!new_linebuf)
		return (NULL);
	i++;
	while (linebuf[i] != '\0')
		new_linebuf[j++] = linebuf[i++];
	new_linebuf[j] = '\0';
	free(linebuf);
	return (new_linebuf);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*linebuf;
	int			n;
	int			k;

	n = 0;
	k = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while (check_line(linebuf) == -1 && k != 0 && ++n)
	{
		k = read(fd, buf, BUFFER_SIZE);
		if (k == -1)
		{
			free(buf);
			return (-1);
		}
		buf[k] = '\0';
		linebuf = join(linebuf, buf, n);
		if (!linebuf)
		{
			free(buf);
			return (-1);
		}
		// if (k == 0 && ft_strlen(linebuf) == 0)
		// {
		// 	free(buf);
		// 	free(linebuf);
		// 	*line = ft_strdup("");
		// 	return (0);
		// }
		if (k < BUFFER_SIZE && check_line(linebuf) == -1)
			linebuf[ft_strlen(linebuf)] = '\n';
		if (k == 0 && ft_strlen(linebuf) == 0)
		{
			free(linebuf);
			*line = ft_strdup("");
			return (0);
		}
	}
	free(buf);
	buf = NULL;
	*line = ft_substr(linebuf, check_line(linebuf));
	if (!*line)
	{
		free(linebuf);
		return (-1);
	}
	linebuf = cut_linebuf(linebuf);
	if (!linebuf)
		return (-1);
	if (k == 0)
	{
		free(linebuf);
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("gnlTester/files/41_no_nl", O_RDONLY);
// 	while (get_next_line(fd, &line))
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", line);
// 	free(line);
// 	// get_next_line(fd, &line);
// 	// printf("%s\n", line);
// 	// free(line);
// 	// get_next_line(fd, &line);
// 	// printf("%s\n", line);
// 	// free(line);
// 	// get_next_line(fd, &line);
// 	// printf("%s", line);
// 	// free(line);
// 	// get_next_line(fd, &line);
// 	// printf("%s", line);
// 	close(fd);
// 	// while (1) {}
// }