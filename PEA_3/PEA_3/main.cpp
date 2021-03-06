#include <iostream>
#include <climits>
#include <windows.h>
#include "Reader.h"
#include "Genetic.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std::chrono;
using namespace std;

int main()
{
	srand(time(NULL));

	char choice;
	Reader * reader;
	Genetic * genetic;
	char name[] = "tsp_10c.txt";
	boolean isRead = false;					// czy graf jest wczytany

	cout << "Menu:" << endl;
	cout << "1. Wczytaj graf" << endl
		<< "2. Wyswietl graf" << endl
		<< "3. Algorytm genetyczny" << endl
		<< "0. Wyjscie" << endl;

	do {
		cout << "Twoj wybor: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			reader = new Reader(name);
			isRead = true;
			break;
		case '2':
			if (!isRead) {
				cout << "Graf nie zostal wczytany." << endl;
			}
			else {
				reader->printTab();
			}
			break;
		case '3':
			if (!isRead) {
				cout << "Graf nie zostal wczytany." << endl;
			}
			else {
				genetic = new Genetic(reader->elementsNumber, 50, 0.2, 0.9);
				genetic->algorithm(reader->tab);
				genetic->printPath(genetic->solution.population);
				cout << "cost: " << genetic->solution.cost << endl;

				delete genetic;
			}
			break;
		case '0':
			break;
		default:
			cout << "Bledny wybor." << endl;
		}
	} while (choice != '0');

	delete reader;
    return 0;
}