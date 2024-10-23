// my overtly verbose and incomprehensible implementation of strstr function
#include <stdio.h>
// function name
// substring(char *substring, char *mainstring);
int main(void)
{
	// check for a substring and return the posiiton
	char *name = "Zioninion";
	char *word = "ion";
	int firststrlength = 0;
	int secondstrlength = 0;
	// get length of first string
	while(name[firststrlength] != '\0')
	{
		firststrlength++;
	}
	// get the length of the second string
	while(word[secondstrlength] != '\0')
	{
		secondstrlength++;
	}

	for(int i = 0; i < firststrlength; i++)
	{
		if(name[i] == word[0])// if letter = first letter in substring
		{
			int count = 0;
			for(int k = 0, j = i; k < secondstrlength; k++, j++) // loop through substring
			{
				if(word[k] == name[j])
				{
					count++;

				}
			}
			if(count == secondstrlength)
				printf("The position of the substring starts at: %d\n", i);
		}
	}
	return 0;
}
