#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 16384
#define MAX_TOKEN_LENGTH 32

typedef struct
{
    char token[MAX_TOKEN_LENGTH];
    int count;
} TokenCount;

int main()
{
    char* input[256];
    printf("Enter CSV Victim: ");
    scanf("%s", &input);

    char input2;
    printf("Enter Seperation Type (t for token, c for column): ");
    scanf(" %c", &input2);

    FILE *fp;
    char row[255];
    fp = fopen(input, "r");

    FILE *fp2;
    fp2 = fopen("csvskimlog.csv", "w");

    if (fp == NULL)
    {
        printf("Error Reading File\n");
        return -1;
    }
    TokenCount tokens[MAX_TOKENS];
    int tokenIndex = 0;

    if (input2 != 'c' && input2 != 't') 
    {
        printf("Seperation Type '%s' Not Valid\n", &input2);
        return 0;
    }

    while (feof(fp) != 1)
    {

        fgets(row, 255, fp);
        
        row[strcspn(row, "\n")] = '\0';
        
        char *token;
        if (input2 == 'c') 
        {
            token = strtok(row, ",");
        } else if (input2 == 't') 
        {
            token = strtok(row, " ,");
        }
        while (token != NULL)
        {
            int found = 0;
            for (int i = 0; i < tokenIndex; i++)
            {
                if (strcmp(tokens[i].token, token) == 0)
                {
                    tokens[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found && tokenIndex < MAX_TOKENS)
            {
                strncpy(tokens[tokenIndex].token, token, MAX_TOKEN_LENGTH - 1);
                tokens[tokenIndex].token[MAX_TOKEN_LENGTH - 1] = '\0';
                tokens[tokenIndex].count = 1;
                tokenIndex++;
            }
            if (input2 == 'c') 
            {
                token = strtok(NULL, ",");
            } else if (input2 == 't') 
            {
                token = strtok(NULL, " ,");
            }
        }
    }
    fprintf(fp2, "Token,Count\n");
    for (int i = 0; i < tokenIndex; i++)
    {
        fprintf(fp2, "%s,%d\n", tokens[i].token, tokens[i].count);
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
