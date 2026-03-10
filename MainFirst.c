#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jerry.h"
#include "Defs.h"

int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        printf("Usage : ./JerryAssignemt <numberOfPlanets> <numberOfJerries> <configurationFile>");
        return 1;
    }
    else
    {
        printf("%s \n", argv[1]);
        printf("%s \n", argv[2]);
        printf("%s \n", argv[3]);
    }
    int numberOfPlanets = atoi(argv[1]);
    int numberOfJerries = atoi(argv[2]);
    char* file = argv[3];
    char input[64];
    Plant** plants = (Plant**)calloc(numberOfPlanets, sizeof(Plant*));
    Jerry** jerries = (Jerry**)calloc(numberOfJerries, sizeof(Jerry*));
    int pCount = 0, jCount = 0;
    if(plants == NULL || jerries == NULL)
    {
        printf("Problem Memory \n");
        return 1;
    }
    FILE* f = fopen(file, "r");
    if(file == NULL)
    {
        printf("File is empty! \n");
        return 1;
    }
    while(1)
    {
        printf("AW JEEZ RICK, what do you want to do now ? \n");
        printf("1 : Print all Jerries \n");
        printf("2 : Print all Planets \n");
        printf("3 : Add physical characteristic to Jerry \n");
        printf("4 : Remove physical characteristic from Jerry \n");
        printf("5 : Print Jerries by a planet \n");
        printf("6 : Print Jerries by a physical characteristic \n");
        printf("7 : Go Home \n");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) != 1 || input[0] < '1' || input[0] > '7')
        {
            printf("RICK WE DON'T HAVE TIME FOR YOUR GAMES ! \n");
        }
        if(input[0] == '1')
        {
            for(int i = 0; i < jCount; i++)
            {
                printJerry(jerries[i]);
            }
        }
    }
}