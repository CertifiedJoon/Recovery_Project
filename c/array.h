#ifndef PROJECT_RECOVERY_H
#define PROJECT_RECOVERY_H

const int MinCapacity = 16;
const int GrowthFactor = 2;
const int ShrinkFactor = 4;

typedef struct CJarray {
  int size;
  int capacity;
  int *data;
} array;

int adjust_capacity(int capacity);
