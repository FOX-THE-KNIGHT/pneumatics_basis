#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "utils.h"
#include "etypes.h"
#include "basis.h"
void printSectors(E_FLOW_SECTOR_ARRAY least);
void printSector(E_FLOW_SECTOR sector);

void printSectors(E_FLOW_SECTOR_ARRAY least)
{
    for (int i = 0; i < least.length; i++){
      printf("SECTOR %d:\n", i);
      printSector(*(least.sectors + i));
    }
}

void printSector(E_FLOW_SECTOR sector)
{
  printf("\t AREA - %f \t RESISTENCE - %f\n", sector.area, sector.resistence);
}
 
int main()
{
  //Test to calculate effective area
  unsigned int length = 4;
  float resistencies[4] = {1, 2, 3, 4};
  float areas[4] = {1, 2, 3, 4};
  
  E_FLOW_SECTOR basic = {areas[0], resistencies[0]};
  E_FLOW_SECTOR *leastArray = (E_FLOW_SECTOR*) calloc((length - 1), sizeof(E_FLOW_SECTOR));
  
  E_FLOW_SECTOR_ARRAY least;
  
  for(int i = 1; i < length; i++){
    (leastArray + (i - 1)) -> area = areas[i];
    (leastArray + (i - 1)) -> resistence = resistencies[i];
  }
  
  least.length = length - 1;
  least.sectors = leastArray;
  
  printSectors(least);
  printf("\n\nEffective area \t %f\n", getEffectiveArea(basic, least));
  
  return 0;
}
