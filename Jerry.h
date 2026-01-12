#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Defs.h"

/* Struct Definitions */

typedef struct Plant // כוכב
{
    char* name;
    double x;
    double y;
    double z;
} Plant;

typedef struct Origin // מוצא
{
    char* dimansion;
    Plant* plants;
} Origin;

typedef struct PhysicalCharacteristics // תכונות פיזיות
{
    char* name;
    double value;
} PhysicalCharacteristics;

typedef struct Jerry // גרי
{
    char* id;
    int happiness;
    Origin* origin;
    PhysicalCharacteristics* physicalCharacteristics;
    int numberOfCharacteristics;
} Jerry;

/* Functions of Plant*/ // כוכב 

Plant* createPlant(char* name, double x, double y, double z);
void destroyPlant(Plant* plant);
status printPlant(Plant* plant);

/* Functions of Origin */ // מוצא

Origin* createOrigin(char* dimansion, Plant* plant);
void destroyOrigin(Origin* origin);

/* Functions of PhysicalCharacteristics */ // תכונות פיזיות

PhysicalCharacteristics* createPhysicalCharacteristics(char* name, double value);
void destroyPhysicalCharacteristics(PhysicalCharacteristics* pc);

/* Functions of Jerry */ // גרי

Jerry* createJerry(char* id, int happiness, Origin* origin);
void destroyJerry(Jerry* jerry);

bool ifHasPhysicalCharacteristics(Jerry* jerry, PhysicalCharacteristics* pc);
status addPhysicalCharacteristics(Jerry* jerry, PhysicalCharacteristics* pc);
status removePhysicalCharacteristics(Jerry* jerry, char* name);
status printJerry(Jerry* jerry);