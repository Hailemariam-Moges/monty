#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @str1: type str compared
 * @str2: type str compared
 * Return: 0 if str1 and str2 are equals.
 *         another value if they are different
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i]; i++)
		;
	if (str1[i] > str2[i])
		return (1);
	if (str1[i] < str2[i])
		return (-1);
	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @str: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int _sch(char *str, char c)
{
	int cont = 0;

	while (str[cont] != '\0')
	{
		if (str[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (str[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @str: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *_strtoky(char *str, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!str)
		str = ultimo;
	while (str[i] != '\0')
	{
		if (_sch(d, str[i]) == 0 && str[i + 1] == '\0')
		{
			ultimo = str + i + 1;
			*ultimo = '\0';
			str = str + j;
			return (str);
		}
		else if (_sch(d, str[i]) == 0 && _sch(d, str[i + 1]) == 0)
			i++;
		else if (_sch(d, str[i]) == 0 && _sch(d, str[i + 1]) == 1)
		{
			ultimo = str + i + 1;
			*ultimo = '\0';
			ultimo++;
			str = str + j;
			return (str);
		}
		else if (_sch(d, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
