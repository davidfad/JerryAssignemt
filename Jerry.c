#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Jerry.h"

/*  Plant  */

Plant* createPlant(char* name, double x, double y, double z)
{
    if(name == NULL) 
    {
        return NULL;       
    }

    Plant* plant = (Plant*)malloc(sizeof(Plant));
    if(plant == NULL)
    {
        return NULL;
    }
    plant->name = (char*)malloc(strlen(name));

    if(plant->name == NULL)
    {   
        free(plant->name);
        free(plant);
        return NULL;
    }

    plant->name = name;
    plant->x = x;
    plant->y = y;
    plant->z = z;

    return plant;
}
void destroyPlant(Plant* plant)
{
    if(plant == NULL)
    {
        return NULL;
    }
    free(plant->name);
    free(plant);
}
status printPlant(Plant* plant)
{
    if(plant == NULL) 
    {
        return failure;
    }

    printf("Planet : %s (%.2d,%.2d,%.2d) \n",plant->name, plant->x, plant->y, plant->z);
    return success;
}

/* Origin */

Origin* createOrigin(char* dimansion, Plant* plant)
{
    if(dimansion == NULL)
    {
        return NULL;
    }
    Origin* origin = (Origin*)malloc(sizeof(origin));
    if(origin == NULL)
    {
        return NULL;
    }
    origin->dimansion = (char*)malloc(strlen(dimansion));
    if(origin->dimansion == NULL)
    {
        free(origin);
        return NULL;
    }
    
    origin->dimansion = dimansion;
    origin->plants = plant;

    return origin;
}
void destroyOrigin(Origin* origin)
{
    if(origin == NULL)
    {
        return NULL;
    }
    free(origin->dimansion);
    free(origin);
}

/* PhysicalCharacteristics */

PhysicalCharacteristics* createPhysicalCharacteristics(char* name, double value)
{
    if(name == NULL)
    {
        return NULL;
    }
    PhysicalCharacteristics* pc = (PhysicalCharacteristics*)malloc(sizeof(pc));
    if(pc == NULL)
    {
        return NULL;
    }
    pc->name = (char*)malloc(strlen(name));
    if(pc->name)
    {
        free(pc);
        return NULL;
    }

    pc->name = name;
    pc->value = value;

    return pc;
}
void destroyPhysicalCharacteristics(PhysicalCharacteristics* physicalCharacteristics)
{
    if(physicalCharacteristics == NULL) return NULL;
    free(physicalCharacteristics->name);
    free(physicalCharacteristics);
}

/* Jerry */

Jerry* createJerry(char* id, int happiness, Origin* origin)
{
    if(id || origin == NULL)
    {
        return NULL;
    }
    Jerry* jerry = (PhysicalCharacteristics*)malloc(sizeof(jerry));
    if(jerry == NULL)
    {
        return NULL;
    }
    jerry->id = (char*)malloc(strlen(id));
    if(jerry->id == NULL)
    {
        return NULL;
    }

    jerry->id = id;
    jerry->happiness = happiness;
    jerry->origin = origin;
    jerry->physicalCharacteristics = NULL;
    jerry->numberOfCharacteristics = NULL;

    return jerry;
}
void destroyJerry(Jerry* jerry)
{
    if(jerry == NULL) return NULL;
    free(jerry->id);
    destroyOrigin(jerry->origin);

    for(int i =0; i< jerry->numberOfCharacteristics; i++)
    {
        destroyPhysicalCharacteristics(&jerry->physicalCharacteristics[i]);
    }
    free(jerry->physicalCharacteristics);
    free(jerry);
}
bool ifHasPhysicalCharacteristics(Jerry* jerry, PhysicalCharacteristics* pc)
{
    if(jerry == NULL || pc == NULL)
    {
        return false;
    }
    for(int i = 0; i < jerry->numberOfCharacteristics; i++)
    {
        
    }

}