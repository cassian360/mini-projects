// a simple calculator in c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int counter = 0;
	int size = 4;
	int c; //  get char
	// get initial set of calc.
	char *calculation = malloc(size * sizeof(char));	
	while(c = fgetc(stdin), c != '\n' && c != EOF)
	{
		if(counter == size - 1)
		{
			size *= 2;
			// realloc new buff
			char *newcalculation = realloc(calculation, size);
			
			calculation = newcalculation;
		}
		calculation[counter++] = c;
	}

	// parse the calculation
	int count = 0;
	int firstvarpos;// position of the first variable
	int secondvarpos;// position of the second variable
	char *firstVar = malloc(sizeof(char) * 10);
	char *secondVar = malloc(sizeof(char) * 10);
	// get length of calculation
	for(int i = 0; calculation[i] != '\0'; i++)
	{
		count++;
	}
	char operator; // hold the operator
	for(int i = 0; calculation[i] != '\0'; i++ )
	{
		if(calculation[i] == '+' || calculation[i] == '-' || calculation[i] == '*' || calculation[i] == '/')
		{
			operator = calculation[i];
			firstvarpos = i;
			for(int i = 0; i < firstvarpos; i++)
			{
				firstVar[i] = calculation[i];
			}
			for(int i = firstvarpos + 1, k = 0; i < count; i++, k++)
			{
				secondVar[k] = calculation[i];
			}
		}
	}	
	// convert to first variable to double
	long double var1 = strtold(firstVar, NULL);
	long double var2 = strtold(secondVar, NULL);
	long double answer; // answer for the variables
	switch(operator)
	{
		case '+':
			answer = var1 + var2;
			printf("%.3Lf + %.3Lf = %.3Lf", var1, var2, answer);
			break;
		case '-':
			answer = var1 - var2;
			printf("%.3Lf - %.3Lf = %.3Lf", var1, var2, answer);
			break;
		case '/':
			answer = var1 / var2;
			printf("%.3Lf / %.3Lf = %.3Lf", var1, var2, answer);
			break;
		case '*':
			answer = var1 * var2;
			printf("%.3Lf * %.3Lf = %.3Lf", var1, var2, answer);
			break;
		case '^': 
			answer = powl(var1, var2);
			printf("%.3Lf ^ %.3Lf = %.3Lf", var1, var2, answer);
			break;
	}

	return 0; 
}
