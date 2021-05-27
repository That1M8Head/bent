/*

bent - the Basic Easy Note Taker
Created by Arsalan Kazmi <That1M8Head>

*/

/* Header declarations */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    /* Variable initialisation */
    int w, x;
    char filename[20];
    char content[100];

    /* Filename input */
    printf("Enter filename: ");
    fgets(filename, 20, stdin);
    for(w=0;w<=20;w++)
    {
        if(filename[x] == '\n')
        {
            filename[x] = '\0';
            break;
        }
    }

    /* Note content input */
    printf("Enter content: ");
    fgets(content, 100, stdin);
    for(x=0;x<=100;x++)
    {
        if(content[x] == '\n')
        {
            content[x] = '\0';
            break;
        }
    }

    /* Trimming inputted string for filename */
    filename[strlen(filename) - 1] = '\0';

    /* Create file */
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) 
    { 
        perror("Oh, I'm die, thank you forever");
        exit(EXIT_FAILURE);
    }

    /* Write to file and close it */
    fprintf(fp, content);
    fflush(fp);
    fclose(fp);

    /* Inform user and quit */
    printf("Saved.");
    exit(EXIT_SUCCESS);
}