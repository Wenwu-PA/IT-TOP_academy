#ifndef FUNCTION_H
#define FUNCTION_H

// Прототипы функций для целых чисел
void FillArrayInt(int arr[], int size);
void ShowArrayInt(int arr[], int size);
int FindMinInt(int arr[], int size);
int FindMaxInt(int arr[], int size);
void SortArrayInt(int arr[], int size);
void EditElementInt(int arr[], int size);

// Прототипы функций для действительных чисел
void FillArrayDouble(double arr[], int size);
void ShowArrayDouble(double arr[], int size);
double FindMinDouble(double arr[], int size);
double FindMaxDouble(double arr[], int size);
void SortArrayDouble(double arr[], int size);
void EditElementDouble(double arr[], int size);

// Прототипы функций для символов
void FillArrayChar(char arr[], int size);
void ShowArrayChar(char arr[], int size);
char FindMinChar(char arr[], int size);
char FindMaxChar(char arr[], int size);
void SortArrayChar(char arr[], int size);
void EditElementChar(char arr[], int size);

// Обобщающие имена в зависимости от типа данных
#ifdef INTEGER
    #define FillArray FillArrayInt
    #define ShowArray ShowArrayInt
    #define FindMin FindMinInt
    #define FindMax FindMaxInt
    #define SortArray SortArrayInt
    #define EditElement EditElementInt
#endif

#ifdef DOUBLE
    #define FillArray FillArrayDouble
    #define ShowArray ShowArrayDouble
    #define FindMin FindMinDouble
    #define FindMax FindMaxDouble
    #define SortArray SortArrayDouble
    #define EditElement EditElementDouble
#endif

#ifdef CHAR
    #define FillArray FillArrayChar
    #define ShowArray ShowArrayChar
    #define FindMin FindMinChar
    #define FindMax FindMaxChar
    #define SortArray SortArrayChar
    #define EditElement EditElementChar
#endif

#endif