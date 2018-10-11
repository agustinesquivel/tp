#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define STRUCTARRAY 2
#define CHARSIZE 51
#define INTSIZE 65535 ///limite del entero signado (2^16 - 1)

typedef struct{
    int id;
    char name[CHARSIZE];
    char lastName[CHARSIZE];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

int initEmployees(sEmployee *, int);

int freeSlot(sEmployee *, int);

int addEmployee(sEmployee *, int, int, char *, char *, float, int);

void getEmployees(sEmployee *, int, int, char *, char *, float, int);

int findEmployeeById(sEmployee *,int, int);

int editEmployee(sEmployee *, int, int, char *, char *, float, int);

void modifyEmployee(sEmployee *, int, char *, char *, float, int);

int removeEmployee(sEmployee *, int, int);

void deleteEmployee(sEmployee *, int);

int sortEmployees(sEmployee *, int, int);

void getString(char *, int);

void valString(char *, char *, int);

int twoWords(char *);

int searchSpace(char *);

float getFloat(float, int);

float valFloat(char *, float, char *, int);

int getInt(int, int);

int valInt(char *, int, char *, int);

int searchCharacterFloat(char *);

int searchCharacterInt(char *);

int searchNoAlpha(char *);

char getChar(char);

void valChar(char);

char valCharModEmployee(char);

int valChange(char, int);

void toUpperChars(char *);

void employeeDataName(sEmployee *, char *, int);

void employeeDataLastName(sEmployee *, char *, int);

void employeeDataSalary(sEmployee *, float, int);

void employeeDataSector(sEmployee *, int, int);

void employeeStructData(sEmployee *, int);

int verifyVoid(sEmployee *, int);

void showList(sEmployee *, int);

void showSalary();

void upOrder(sEmployee *, int);

void downOrder(sEmployee *, int);

int printEmployee(sEmployee *, int);

char valCharList(char);

char valOrder(char);

