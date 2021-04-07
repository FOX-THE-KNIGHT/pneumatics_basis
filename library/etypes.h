#ifndef ETYPES_H_
#define ETYPES_H_
typedef struct
{
  int *array;
  int length;
} E_ARR_INT;

typedef struct
{
  float *array;
  int length;
} E_ARR_FLOAT;
typedef struct E_FLOW_SECTOR{
  float area;
  float resistence;
} E_FLOW_SECTOR;
typedef struct E_FLOW_SECTOR_ARRAY{
  E_FLOW_SECTOR *sectors;
  unsigned int length;
} E_FLOW_SECTOR_ARRAY;
#endif //ETYPES_H_
