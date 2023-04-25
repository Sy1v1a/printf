#include "main.h"
/**
 * getflag - calculate active flag
 * @format: formatted string to print argument
 * @i: take parameter
 * return: flag
 */
{
	int j, k;
	int flag = 0;
	const char FLAGSCH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGSARR[] = {T_MINUS, T_PLUS, T_ZERO, T_HASH, T_SPACE, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; FLAGSCH[j] != '\0'; j++)
			if (format[k] == FLAGSCH[j])
			{
				flag |= FLAGSARR[j];
				break;
			}

		if (FLAGSCH[j] == 0)
			break;
	}

	*i = k - 1;

	return (flag);
}
