#include <iostream>
#include <strings.h>

static char strings[10][100];
int k = 0;
int f, f2, ind = 999, numstr = -1, numsub = 0, numsubneeded, currnumber = 0, shouldwewritedownthenumber;

int main()
{
    int i, j;
    char string[100];
    //input
    printf("Hey, guys. Let's do some stuff!\n");
    printf("Enter a few lines of text here:\n* when you're fed up typing: just press enter on the empty line.\n");
    printf("* please, remember, that spaces are considered as symbols.\n\n");
    gets(string);
    j = strlen(string);
    for (i = 0; i < j; i++)
        strings[k][i] = string[i];
    while(strlen(string) != 0)
    {
        gets(string);
        k += 1;
        j = strlen(string);
        for (i = 0; i < j; i++)
            strings[k][i] = string[i];
    }
    printf("Good Job! Really. Okay, here we go.\nHere are some substrings I picked out for you:\n\n");
    shouldwewritedownthenumber = 1;
    for (i = 0; i < k; i++)
        for (j = 0; j < strlen(strings[i]); j++)
            if (isdigit(strings[i][j]) == 0)
            {
                if (shouldwewritedownthenumber == 1)
                {
                    currnumber += 1;
                    printf("%d. \"", currnumber);
                    shouldwewritedownthenumber = 0;
                }
                printf("%c", strings[i][j]);
                if (int(strings[i][j]) < ind)
                {
                    ind = int(strings[i][j]);
                    numstr = i;
                    numsubneeded = numsub;
                }
                f += 1;
                f2 = 1;
                if ((j == strlen(strings[i]) - 1))
                {
                    printf("\"\n");
                    numsub += 1;
                    f = 0;
                    shouldwewritedownthenumber = 1;
                }
            }
            else
                if (f != 0)
                {
                    printf("\"\n");
                    numsub += 1;
                    f = 0;
                    shouldwewritedownthenumber = 1;
                }
    if (f2 == 1)
        printf("\nSymbol \"%c\" in %d substring has the \"smallest code\".\n",char(ind),numsubneeded+1);
    else
    {
        printf("Oh, I was wrong. There're no substrings at all. Only the numbers present\nin parent strings. Try again.\nBest wishes.\n");
        return 0;
    }
    printf("\nLet's do some manipulations with the \"%s\" string.\n", strings[numstr]);
    printf("Here what we've finally got:\n\n\"");
    for (i = 0; i < strlen(strings[numstr]); i++)
        if (isdigit(strings[numstr][i]) == 0)
            printf("%c", strings[numstr][i]);
    printf("\"\n");
    return 0;
}
