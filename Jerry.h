#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Defs.h"
#ifndef JERRY_H
#define JERRY_H

/* Struct Definitions */

typedef struct Plant // כוכב
{
    char* name;
    double x;
    double y;
    double z;
} Plant;

typedef struct Origin // מוצא מימד
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

PhysicalCharacteristics* createPhysicalCharacteristics(char* name, double value); // להוסיף תכונה פיזית בכללי
void destroyPhysicalCharacteristics(PhysicalCharacteristics* pc); // למחוק תכונה פיזית
 
/* Functions of Jerry */ // גרי

Jerry* createJerry(char* id, int happiness, Origin* origin); // ליצור גרי
void destroyJerry(Jerry* jerry); // למחוק לגמריי גרי

bool ifHasPhysicalCharacteristics(Jerry* jerry, PhysicalCharacteristics* pc); // לבדוק אם יש לגרי תכונה פיזית
status addPhysicalCharacteristics(Jerry* jerry, PhysicalCharacteristics* pc); // להוסיף תכונה פיזית לגרי
status removePhysicalCharacteristics(Jerry* jerry, char* name); //  למחוק תכונה פיזית לגרי
status printJerry(Jerry* jerry); // להדפיס את גרי
#endif