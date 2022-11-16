#pragma once

//  прототипы для функций Int
void FillArrayInt(int* arr1, size_t length);
void ShowArrayInt(int* arr, size_t length);
void MinMaxArrayInt(int* arr, size_t length);
void SortArrayInt(int* arr, size_t length);
void EditArrayInt(int* arr, size_t length);

//  прототипы для функций Float
void FillArrayFloat(float* arr1, size_t length);
void ShowArrayFloat(float* arr, size_t length);
void MinMaxArrayFloat(float* arr, size_t length);
void SortArrayFloat(float* arr, size_t length);
void EditArrayFloat(float* arr, size_t length);

//  прототипы для функций Char
void FillArrayChar(char* arr1, size_t length);
void ShowArrayChar(char* arr, size_t length);
void MinMaxArrayChar(char* arr, size_t length);
void SortArrayChar(char* arr, size_t length);
void EditArrayChar(char* arr, size_t length);

//  прототипы для функций, все функции для типов
void Integer(int* arr, size_t length);
void Float(float* arr, size_t length);
void Char(char* arr, size_t length);

//  условная компиляция для каждого типа данных
#ifdef INTEGER

void Integer(int* arr, size_t length)

#endif

#ifdef FLOAT

void Float(float* arr, size_t length)

#endif

#ifdef CHAR

void Char(char* arr, size_t length)

#endif
