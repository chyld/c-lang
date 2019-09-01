/*
 * File:   main.c
 * Author: <your name here>
 */

#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

#define MIN 0
#define MAX 1

typedef struct LinkedList LinkedList;
struct LinkedList
{
	int data;
	LinkedList *next;
};
LinkedList *head;
LinkedList *tail;

// prototypes for student-implemented functions
int getValidInteger(int lowerBound, int upperBound);
float averageIntegerArray(int values[], int count);
int findExtremeInIntegerArray(int ifMax, int values[], int count);

// prototypes for Dr. T functions
void buildLinkedListFromString(char string[]);
void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer,
	LinkedList *node);
LinkedList *getNode(char string[], int spaceIndex);
int getNumber();

/*
 * Height Statisticamator Programming Assignment
 */
int main(int argc, char** argv)
{
  char input[MAX_LENGTH];
  fgets(input, MAX_LENGTH, stdin);
  while (input[0] != 'q')
  {
    buildLinkedListFromString(input);

    int size = getValidInteger(1, 100);
    int heights[size];
    for(int i = 0; i < size; i++) heights[i] = getValidInteger(1, 96);
    float mean = averageIntegerArray(heights, size);
    int min = findExtremeInIntegerArray(0, heights, size);
    int max = findExtremeInIntegerArray(1, heights, size);
    printf("%.2f %d %d\n", mean, min, max);

    fgets(input, MAX_LENGTH, stdin);
  }

return 0;
}


int getValidInteger(int lowerBound, int upperBound){

  for(int i = 0; i < 1000; i++) {
    int x = getNumber();
    if(x >= lowerBound && x <= upperBound) return x;
  }

}


float averageIntegerArray(int values[], int count){

  int sum = 0;
  for(int i = 0; i < count; i++) sum += values[i];
  return (float)sum / count;

}


int findExtremeInIntegerArray(int ifMax, int values[], int count){

  int value = values[0];
  for(int i = 0; i < count; i++){
    int temp = values[i];
    if(ifMax && temp > value) value = temp;
    if(!ifMax && temp < value) value = temp;
  }
  return value;

}


/*
* Builds a linked list of input values from provided string
*/
void buildLinkedListFromString(char string[])
{
	// find first space in string
	int spaceIndex = -1;
	char *result = NULL;
	result = strchr(string, ' ');
	char *stringStart = &string[0];

	// loop while there are more spaces in string
	while (result != NULL)
	{
		spaceIndex = result - stringStart;

		// build new node and add to list
		LinkedList *node = getNode(stringStart, spaceIndex);
		addNodeToList(&head, &tail, node);

		// find next space in string
		string = &string[0] + spaceIndex + 1;
		result = strchr(string, ' ');
		stringStart = &string[0];
	}

	// add final node to list
	LinkedList *node = getNode(stringStart,
		strlen(stringStart));
	addNodeToList(&head, &tail, node);
}

/*
* Adds a node to the linked list
*/
void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer,
	LinkedList *node)
{
	// add node to linked list
	if (*headPointer == NULL)
	{
		// adding to empty list
		*headPointer = node;
	}
	else
	{
		// add to end of list
		(*tailPointer)->next = node;
	}
	*tailPointer = node;
}

/*
* Gets a node for the linked list
*/
LinkedList *getNode(char string[], int length)
{
	// extract int from string
	char* intString = malloc((length + 1) * sizeof(char));
	strncpy(intString, string, length);
	intString[length] = '\0';
	int value = atoi(intString);

	// free memory
	free(intString);
	intString = NULL;

	// build and return node
	LinkedList *node;
	node = malloc(sizeof(struct LinkedList));
	node->data = value;
	node->next = NULL;
	return node;
}

/*
* Get a number from the linked list. If the linked
* list is empty, returns -1
*/
int getNumber()
{
	// check for empty list
	int value;
	if (head != NULL)
	{
		// save value at front of list
		value = head->data;
		
		// move along list
		LinkedList *temp = head;
		head = head->next;
		free(temp);
	}
	else
	{
		// empty list
		value = -1;
	}
	return value;
}

