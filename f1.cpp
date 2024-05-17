/*
* FILE : f1.cpp
* PROJECT : Focused assignment 1
* PROGRAMMER : Rachit jagdishbhai patel
* FIRST VERSION : 2024-05-17
* DESCRIPTION : Program to store the data in malloc memory allocation
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996) 
//Declaring fillflightInfo function
void fillflightInfo(struct FlightInfo* flight, char* destination, char* date);
//Declaring printFlightInfo
void printFlightInfo(struct FlightInfo flight[]);
//Declaring an structure name flightInfo
struct FlightInfo {
	char* destination;
	char* date;
};
//
// FUNCTION: fillflightInfo
//DESCRIPTION:
//The function will  store the value of the data
//PARAMETERS: 
// //struct FlightInfo flight: This the variable for structure.
//char destination: The parameter will store the value of destination of flights
//char date: The parameter will store the value of date of flights
//
void fillflightInfo(struct FlightInfo *flight, char* destination, char* date)
{
	flight->destination = (char*)malloc(strlen(destination) + 1);
	strcpy(flight->destination, destination);

	flight->date = (char*)malloc(strlen(date) + 1);
	strcpy(flight->date, date);
}
//
// FUNCTION: printflightInfo
//DESCRIPTION:
//The function will print the data.
//PARAMETERS: 
// struct FlightInfo flight[]: This the variable for structure and it will provide the data
//
void printFlightInfo(struct FlightInfo flight[])
{
	printf("%-20s %s\n", "destination", "date");
	for (int i = 0; i < 10; i++)
	{
		printf("%-20s %s\n", flight[i].destination, flight[i].date);
	}
}
int main()
{
	struct FlightInfo flight[10];
	//Declaring variable do basic tasks.
	char destination[30];
	char date[30];
	int i = 0;
	printf("Enter destination and date of 10 flights\n");
	//For loop is inizalized to get 10 user input of flights
	for (i = 0; i < 10 ; i++)
	{
		printf("FLight no %d:\n", i + 1);
		printf("Destination :");
		//This will store the destination 
		fgets(destination, sizeof(destination), stdin);
		//The statement will remove the newline character
		destination[strcspn(destination, "\n")] = '\0';
		printf("Date :");
		//This will store the date
		fgets(date, sizeof(date), stdin);
		//The statement will remove the newline character
		date[strcspn(date, "\n")] = '\0';
		//fillflightInfo function is called to store the data
		fillflightInfo(&flight[i], destination, date);
	}
	//printflightInfo function is called to print the data of the file.
	printFlightInfo(flight);
	return 0;
}