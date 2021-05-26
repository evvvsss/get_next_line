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
	free((char *)s1);
	return (d);
}
