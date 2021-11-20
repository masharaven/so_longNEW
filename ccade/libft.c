#include "so_long.h"

int	find_symb(char c, const char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (c == buff[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && i < ((unsigned int)n - 1) && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strrchr(const char *str, int ch)
{
	char	*last;

	last = (char *)str;
	while (*last)
		last++;
	if (ch == '\0')
		return ((char *)last);
	while (last >= str)
	{
		if (*last == (char )ch)
			return ((char *)last);
		last--;
	}
	return (NULL);
}

void	*ft_realloc(void **src, size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (!dst)
	{
		free((*src));
		return (NULL);
	}
	if (!(*src))
	{
		free(dst);
		return (NULL);
	}
	ft_memmove(dst, (*src), size);
	free((*src));
	(*src) = NULL;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}
