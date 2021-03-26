#include <stdio.h>
//#include <stdbool.h>
int main()
{
	char str[10000];
	char temp ;
	int i = 0, j, inc = 0, s, e, c, flag ;
	scanf("%s", str);
	while(str[i] != '\0')
	{
		if(str[i] == '[')
			inc++ ;
		if(str[i] == ']')
			inc-- ;
		if((str[i] >= 'a') && (str[i] <= 'z'))
			str[i] = (char)(((int)(str[i])-97+inc)%26+97);	// increment the character (rotation rather) based on count of square brackets
		i++ ;
	}
	do
	{
		flag = 0 ;
		i = 0 ;
		c = 0 ;	// keeps count of number of nested parentheses
		while(str[i] != '\0')
		{
			if(str[i] == '(')
			{
				flag = 1 ;	// there is a string in parentheses
				if(c == 0)
					s = i ;	// starting index of outermost opening parentheses
				c++ ;
			}
			if(str[i] == ')')
			{
				c-- ;
				if(c == 0)	// encountered the outermost closing parentheses
				{
					e = i ;	// ending index of outermost parentheses
					str[s++] = '0' ;
					str[e--] = '0' ;	// remove parentheses after detecting a bracketed string
					for(j = s; j <= (s+e)/2; j++)	// reverse the outermost string in parentheses
					{
						temp = str[j];
						str[j] = str[s+e-j];
						str[s+e-j] = temp ;
					}
					for(j = s; j <= e; j++)	// swap the parentheses
					{
						if(str[j] == '(')
							str[j] = ')' ;
						else if(str[j] == ')')
							str[j] = '(' ;
					}
				}
			}
			i++ ;
		}
	} while(flag == 1);	// repeat the process as long as paratheses exist
	i = 0 ;
	while(str[i] != '\0')
	{
		if((str[i] >= 'a') && (str[i] <= 'z'))	// print only the letters
			printf("%c", str[i]);
		i++ ;
	}
}
