#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void createNumber(char *number)
{
    int num1 = 0 ,num2 = 0,num3 = 0,num4 = 0;

    srand(time(NULL));

    num1 = rand() % 9 + 1; // first number should be more than 0 and less than 10

    // all the rest numbers could be in range from 0 to 9
    // but they can not repeat

    do
    {
        num2 = rand() % 10;
    }
    while (num1 == num2);

    do
    {
         num3 = rand() % 10;
    }
    while (num1 == num3 || num2 == num3);

    do
    {
         num4 = rand() % 10;
    }
    while (num1 == num4 || num2 == num4 || num3 == num4);

    sprintf(number,"%d%d%d%d", num1, num2, num3, num4);
}

void readInput(char *userInput)
{
	char _input[255] = "";
	int n = 4; // there should be four numbers
	int correctInput;
	int c;
	
	do
	{
		printf("Your number should consist 4 digits and it can not be started from 0)\n");
		printf("Enter number: ");
		scanf("%s",_input);
		
		correctInput = 1;
		
		for (int i = 0; i < n ; i++)
		{
			if( !isdigit(_input[i]) )
			{
				correctInput = 0;
				printf("You should enter only digits\n");
			}
		}
		
		if(correctInput)
		{
			if(_input[0] == '0')
			{
				correctInput = 0;
				printf("0 can not be in the beginning\n");
			}
		}
		
		if(correctInput)
		{
			for (int i = 0 ; i < n ; i++)
			{
				for (int j = 0 ; j < i ; j++)
				{
					if (_input[i] == _input[j])
					{
						correctInput = 0;
						printf("Numers can not repeat\n");
					}
				}
			}
		}
		
	}
	while(!correctInput);
	
	_input[4] = '\0';
	sprintf(userInput,"%s", _input);
}

int checkInput(char *userInput, char *number)
{
	int bulls = 0, cows = 0; // bulls - correct number and place, cows - only correct number
	int n = 4;
	
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			if (number[i] == userInput[j])
			{
				if (i == j)
				{
					bulls++;
				}
				else
				{
					cows++;
				}
			}
		}
	}
	printf("bulls: %d; cows: %d\n", bulls, cows);
	
	if (bulls == 4)
	{
		return 0;
	}
	return 1;
}

int main(void)
{
    char number[5];
	char userInput[5];
	int game = 1;
	int attempts = 0;
	
    createNumber(number);
	
	do
	{
		attempts++;
		readInput(userInput);
		game = checkInput(userInput, number);
	}
	while (game);
	
    printf("You win with %d attempts\n", attempts);
    return 0;
}
