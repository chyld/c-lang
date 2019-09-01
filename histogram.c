/*
 * File:   main.c
 * Author: <your name here>
 */

#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

/*
 * Junior Codebreaker Programming Assignment
 */
int main(int argc, char** argv)
{
	char input[MAX_LENGTH];
	fgets(input, MAX_LENGTH, stdin);
	while (input[0] != 'q')
	{

    int histogram[26];
    for(int i = 0; i < 26; i++) histogram[i] = 0;

    char* pointer = input;
    while(*pointer){
      char c = *pointer;

      if(isalpha(c)){
        c = toupper(c);
        int pos = c - 65;
        histogram[pos] += 1;
      }

      pointer += 1;
    }

    for(int i = 0; i < 26; i++){
      if(histogram[i]) printf("%c%d ", i + 65, histogram[i]);
    }
    printf("\n");


		fgets(input, MAX_LENGTH, stdin);
	}

	return 0;
}

