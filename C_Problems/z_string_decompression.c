#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void expandString(char *inputString, char *outputString);

int main()
{
    char inputString[MAX_LEN] = "abc2[pq]";
    char outputString[MAX_LEN];

    expandString(inputString, outputString);

    printf("Input String: %s\n", inputString);
    printf("Output String: %s\n", outputString);

    return 0;
}

void expandString(char *inputString, char *outputString)
{
    int inputLength = strlen(inputString);
    int outputLength = 0;

    for (int i = 0; i < inputLength; i++)
    {
        if (inputString[i] >= '0' && inputString[i] <= '9')
        {
            int num = inputString[i] - '0';
            for (int j = 0; j < num; j++)
            {
                for (int k = i + 1; k < inputLength; k++)
                {
                    if (inputString[k] == ']')
                    {
                        break;
                    }
                    outputString[outputLength++] = inputString[k];
                }
            }
            i++; // skip the closing bracket
        }
        else
        {
            outputString[outputLength++] = inputString[i];
        }
    }

    outputString[outputLength] = '\0';
}
