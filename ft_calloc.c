char	*ft_calloc(size_t size, size_t type)
{
	char	*buffer;
	int		i;

	buffer = malloc(size + 1 * type);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < size)
	{
		buffer[i] = 0;
		i++;
	}
	buffer[size] = '\0';
	return (buffer);
}
