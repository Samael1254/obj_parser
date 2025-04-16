#include "ft_chars.h"
#include "ft_strings.h"
#include <stdbool.h>

bool	is_element(char *line, const char *elem)
{
	int	keyword_len;

	keyword_len = ft_strcspn(line, " ");
	if (keyword_len == 0)
		return (false);
	return (ft_strncmp(line, elem, keyword_len) == 0);
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
