
#include <stdio.h>
#include <ctype.h>
#include <time.h>

int main()
{
    char questions[5][100] = {
        "Who developed the C language?",
        "Which symbol ends a statement in C?",
        "Which header is needed for printf()?",
        "Size of int on most systems (bytes)?",
        "Which loop runs at least once?"
    };

    char options[5][4][30] = {
        {"Dennis Ritchie", "James Gosling", "Guido van Rossum", "Bjarne Stroustrup"},
        {":", ";", ".", ","},
        {"conio.h", "string.h", "stdio.h", "math.h"},
        {"1", "2", "8", "4"},
        {"do-while", "for", "while", "none"}
    };

    char answers[5] = {'A', 'B', 'C', 'D', 'A'};

    int score = 0;
    int attempted = 0;
    int skipped = 0;
    int i, j;
    char ch;

    time_t start = time(NULL);

    printf("===== C LANGUAGE QUIZ =====\n");
    printf("Time limit: 60 seconds\n");

    for (i = 0; i < 5; i++)
    {
        while (1)
        {
            if (difftime(time(NULL), start) >= 60)
            {
                printf("\nTime is up!\n");
                goto result;
            }

            printf("\nQ%d. %s\n", i + 1, questions[i]);

            for (j = 0; j < 4; j++)
            {
                printf("%c. %s\n", 'A' + j, options[i][j]);
            }

            printf("Enter answer (A-D) or S to skip: ");

            if (scanf(" %c", &ch) != 1)
            {
                printf("Input error!\n");
                goto result;
            }

            ch = toupper((unsigned char)ch);

            if (difftime(time(NULL), start) >= 60)
            {
                printf("\nTime is up!\n");
                goto result;
            }

            if (ch == 'S')
            {
                skipped++;
                break;
            }

            if (ch < 'A' || ch > 'D')
            {
                printf("Invalid answer! Please enter A, B, C, D or S.\n");
                continue;
            }

            attempted++;

            if (ch == answers[i])
            {
                printf("Correct answer!\n");
                score++;
            }
            else
            {
                printf("Wrong answer!\n");
                printf("Correct option: %c\n", answers[i]);
            }

            break;
        }
    }

result:
    printf("\n QUIZ RESULT \n");
    printf("Total questions: 5\n");
    printf("Attempted: %d\n", attempted);
    printf("Correct answers: %d\n", score);
    printf("Wrong answers: %d\n", attempted - score);
    printf("Skipped: %d\n", skipped);
    printf("Unanswered: %d\n", 5 - attempted - skipped);
    printf("Percentage: %.1f%%\n", score * 100.0 / 5);

    if (score >= 4)
    {
        printf("Performance: Excellent\n");
    }
    else if (score >= 3)
    {
        printf("Performance: Good\n");
    }
    else
    {
        printf("Performance: Needs Improvement\n");
    }

    printf("Time taken: %.0f seconds\n",
           difftime(time(NULL), start));

    return 0;
}
