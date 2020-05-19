#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include "Validate.h"
void GetString(char message[],char input[],int len)
{
    printf("%s",message);
    fflush(stdin);
    gets(input);
    while(Validate_String(input)!=1 || input[0]=='\0' || input[0]==' ' || (strlen(input)<3))
    {
        printf("Ingresa un dato valido: ");
        fflush(stdin);
        gets(input);
    }
}

int GetOption(char message[])
{
    int num;
    char auxNum[11];
    printf("%s",message);
    fflush(stdin);
    gets(auxNum);
    while(Validate_Integer(auxNum)!=1 || auxNum[0]=='\0')
    {
        printf("Ingresa una opcion valida: ");
        fflush(stdin);
        gets(auxNum);
    }
    num=atoi(auxNum);
    return num;
}

int GetInt(char message[],int tam)
{
    int num;
    char auxNum[11];
    printf("%s",message);
    fflush(stdin);
    gets(auxNum);
    while(Validate_IntID(auxNum)!=1 || auxNum[0]=='\0')
    {
        printf("Ingresa un numero valido: ");
        fflush(stdin);
        gets(auxNum);
    }
    num=atoi(auxNum);
    return num;
}

float GetFloat(char message[])
{
    float salary;
    printf("%s",message);
    scanf("%f",&salary);
    return salary;
}

char GetChar(char message[])
{
    char letter;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&letter);
    while((letter<'a' || letter>'z') && (letter<'A' || letter>'Z'))
    {
        printf("Ingresa un caracter valido: ");
        fflush(stdin);
        scanf("%c",&letter);
    }
    return letter;
}

int GetUpDown(char message[])
{
    int num;
    char auxNum[11];
    printf("%s",message);
    fflush(stdin);
    gets(auxNum);
    while(Validate_Integer(auxNum)!=1 || auxNum[0]=='\0' || strlen(auxNum)>1 || (auxNum<'0' && auxNum>'1'))
    {
        printf("Ingrese 0 o 1: ");
        fflush(stdin);
        gets(auxNum);
    }
    num=atoi(auxNum);
    return num;
}

int GenerarId(int id,int cont)
{
    return id+cont;
}
