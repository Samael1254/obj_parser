#include "ft_chars.h"
#include "ft_strings.h"
#include <stdbool.h>

bool	is_element(char *str, const char *elem)
{
	if (!str)
		return (false);
	return (ft_strcmp(str, elem) == 0);
}

bool	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_float(char *str)
{
	int		i;
	bool	period;

	period = false;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
		{
			if (period)
				return (false);
			period = true;
		}
		i++;
	}
	return (true);
}

bool	is_vertex(char *str)
{
	int	i;
	int	n;

	n = 0;
	while (n < 3)
	{
		i = 0;
		if (str[0] == '-' || str[0] == '+')
			i++;
		if (!str[i])
			return (false);
		while (str[i] && str[i] != '/')
		{
			if (!ft_isdigit(str[i]))
				return (false);
		}
		if (!str[i])
			return (true);
		if (n == 2)
			return (false);
		str += i + 1;
		n++;
	}
	return (true);
}
