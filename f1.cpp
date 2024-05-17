/*
* FILE : f3.cpp
* PROJECT : Focused assignment 3
* PROGRAMMER : Rachit jagdishbhai patel
* FIRST VERSION : 2024-05-17
* DESCRIPTION : Program to store the data in malloc memory allocation
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996) 
void fillflightInfo(struct FlightInfo* flight, char* destination, char* date);
void printFlightInfo(struct FlightInfo flight[]);
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
	struct FlightInfo flight[2];
	char destination[30];
	char date[30];
	int i = 0;
	printf("Enter the destination and date of the flights\n");
	for (i = 0; i < 10; i++)
	{
		printf("FLight no %d:\n", i + 1);
		printf("Destination :");
		fgets(destination, sizeof(destination), stdin);
		destination[strcspn(destination, "\n")] = '\0';
		printf("Date :");
		fgets(date, sizeof(date), stdin);
		date[strcspn(date, "\n")] = '\0';
		fillflightInfo(&flight[i], destination, date);
	}
	printFlightInfo(flight);
	return 0;
}