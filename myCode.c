#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Gemini 2.5 Pro With Reasoning
//This will get the file contents as a string
char* readFromFile(const char* fileName) {
	FILE* fileToRead = NULL;
	char* textToReturn = NULL;
	long fileSize = 0;

	//Open the file
	fopen_s(&fileToRead, fileName, "rb");

	//Get the file length
	fseek(fileToRead, 0, SEEK_END);
	fileSize = ftell(fileToRead);
	rewind(fileToRead);

	//Read the file (ah so here this is actually a casting statement to cast it to char pointers
	//instead of null pointers
	textToReturn = (char*)malloc(fileSize + 1);
	fread(textToReturn, 1, fileSize, fileToRead);
	textToReturn[fileSize] = '\0';
	fclose(fileToRead);

	return textToReturn;

}

//https://www.educative.io/answers/splitting-a-string-using-strtok-in-c
//This will extract the numbers into an array
void getNumbers(int arrayToBuild[], char* sourceData) {
	char* currentNumber = strtok(sourceData, " ");

	int i = 0;
	while (currentNumber != NULL) {
		printf(currentNumber);
		arrayToBuild[i] = atoi(currentNumber);
		currentNumber = strtok(NULL, " ");
		i++;
	}
}

int main() {
	printf(readFromFile("my_document.txt"));
	int numbers[154];
	getNumbers(numbers, readFromFile("my_document.txt"));

	int sum = 0;
	for (int i = 0; i < 152; i++) {
		sum += numbers[i];
	}

	//Loop over each number to find its distances
	for (int mainNumber = 19; mainNumber < 26; mainNumber++) {

		//Loop over each number you want to match against
		for (int matchNumber = 19; matchNumber < 26; matchNumber++) {

			//Loop over the dataset
			for (int i = 0; i < 152; i++) {
				if (numbers[i] == mainNumber) {
					int j = 0;
					for (j = i; j < 152; j++) {
						if (numbers[j] == matchNumber) {
							break;
						}
					}
					printf("Current distance from main number %d to matchNumber %d is %d\n", mainNumber, matchNumber, j - i);
				}
			}
		}
	}


	printf("\nThe total is: %d\n", sum);
}