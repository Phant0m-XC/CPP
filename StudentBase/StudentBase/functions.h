#pragma once

#include "student.h"

void getMemory(student**, int);
void freeMemory(student**);
void read(student**, int);
void print(student**, int);
void sort(student**, int);
void findGroup(student**, int);
void averageMarks(student**, int);
void bestMarks(student**, int);
void worstMarks(student**, int);
void result(student**, int, void(*ptralg)(student**, int));
void(*getFunction(void(*menu[])(student**, int)))(student**, int);