#include "stdafx.h"
#include "convertstring.h"

int nlen(const char* str)
{
	int len = 0;

	while (str[len * 2])
		len++;

	return len;
}

//
// FUNCTION delete_zero_symbols (char* str)
//
// PURPOSE: each second symbol of source string is '\0' symbol. We delete it
//
void delete_zero_symbols(char* str)
{
	int len = nlen(str);

	for (int i = 1; i < len + 1; i++)
		str[i] = str[i * 2];
}