#include <stdio.h>

int sportsQuestion(void);
int geographyQuestion(void);
void pause(int);

int giResponse = 0;

void main()
{
    do
    {
        system("cls");
        printf("\n\tTHE TRIVIA GAME\n\n");
        printf("1\tSports\n");
        printf("2\tGeography\n");
        printf("3\tQuit\n");
        printf("\n\nEnter your selection: ");
        scanf("%d", &giResponse);
        switch (giResponse)
        {
        case 1:
            if (sportsQuestion() == 4)
                printf("\nCorrect!\n");
            else
                printf("\nIncorrect\n");
            pause(2);
            break;
        case 2:
            if (geographyQuestion() == 2)
                printf("\nCorrect!\n");
            else
                printf("\nIncorrect\n");
            pause(2);
            break;
        }
    } while (giResponse != 3);
}

int sportsQuestion(void)
{
    int iAnswer = 0;
    system("cls");
    printf("\tSports Question\n");
    printf("\nWhat University did NFL star Deon Sanders attend? ");
    printf("\n\n1\tUniversity of Miami\n");
    printf("2\tCalifornia State University\n");
    printf("3\tIndiana University\n");
    printf("4\tFlorida State University\n");
    printf("\nEnter your selection: ");
    scanf("%d", &iAnswer);
    return iAnswer;
}

int geographyQuestion(void)
{
    int iAnswer = 0;
    system("cls");
    printf("\tGeography Question\n");
    printf("\nWhat is the state capitol of Florida? ");
    printf("\n\n1\tPensecola\n");
    printf("2\tTallahassee\n");
    printf("3\tJacksonville\n");
    printf("4\tMiami\n");
    printf("\nEnter your selection: ");
    scanf("%d", &iAnswer);
    return iAnswer;
}

void pause(int inNum)
{
    int iCurrentTime = 0;
    int iElapsedTime = 0;
    iCurrentTime = time(NULL);
    do
    {
        iElapsedTime = time(NULL);
    } while ((iElapsedTime - iCurrentTime) < inNum);
}
