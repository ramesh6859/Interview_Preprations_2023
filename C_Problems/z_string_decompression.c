#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *expandString(char *input)
{
    int input_len = strlen(input);
    char *output = malloc(input_len * sizeof(char));
    int output_index = 0;
    char current_char;
    int repeat_count;
    for (int i = 0; i < input_len; i++)
    {
        printf("%c ------", input[i]);
        current_char = input[i];
        if (current_char == '[')
        {
            repeat_count = input[i - 1] - '0';
            for (int j = 0; j < repeat_count; j++)
            {
                output[output_index++] = input[i + 1];
            }
            while (input[i] != ']')
            {
                i++;
            }
        }
        else
        {
            output[output_index++] = current_char;
        }
    }
    output[output_index] = '\0';
    // for (int l = 0; l < sizeof(output); l++)
    // {
    //     printf("%c ", output[l]);
    // }
    return output;
}
int main()
{
    char *input1 = "a3[b]c";
    char *output1 = expandString(input1);
    printf("Input: %s\n", input1);
    printf("Output: %s\n", output1);
    free(output1);
    char *input2 = "abc2[pq]";
    char *output2 = expandString(input2);
    printf("Input: %s\n", input2);
    printf("Output: %s\n", output2);
    free(output2);
    return 0;
}
