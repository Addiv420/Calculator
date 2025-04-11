//header - imports important function
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <cmath>
#include <cstdlib>

//Auto std
using namespace std;

//Colors
#define RESET   "\033[0m"
#define RED     "\033[38;5;196m"
#define GREEN   "\033[38;5;28m"
#define YELLOW  "\033[38;5;226m"
#define BLUE    "\033[38;5;21m"
#define MAGENTA "\033[38;5;165m"
#define PINK    "\033[38;5;204m"
#define CYAN    "\033[38;5;51m"
#define WHITE   "\033[38;5;255m"

//fallback function: Prevents infinite loop if user tries to put in a char into a int and gives out a funny message after 5 failed attempts.
void fallback(short &failCount) {
	wcin.clear();
	wcin.ignore(numeric_limits<streamsize>::max(), '\n');
	failCount++;
	if (failCount <= 5) {
		wcout << YELLOW << L"Hey! Nicht das Programm kaputt machen" << RESET << RED << "	>:( \a" << RESET << endl << endl;
	} else if (failCount > 5 && failCount < 8) {
		wcout << BLUE << L"Willst du mich etwa ärgern?" << RESET << PINK << "	:3 \a" << RESET << endl << endl;
	} else if (failCount >= 8) {
		wcout << RED << L"Jetzt Reichts! >:O\a" << RESET << endl << endl;
		exit(50);
	}
}

//main function
int main()
{
//initialization, put in before the loop so it don't reset:

	//Clearing messages in terminal
	system("clear");

	//Default color
	wcout << RESET;

	//8-Bit encoder
	setlocale(LC_ALL, "en_US.UTF-8");
	locale::global(locale(""));

	//array with prefixes
	wstring prefixes[] = { L"", L"mm", L"cm", L"dm", L"M" };

	//prefix number which is then put into the [] of the prefixes array
	short prefix = 0;

	//pi definition
	double pi = M_PI;

	//misc
	short failCount = 0;

	//Infite loop, till user exits
	while (true) {

		//number to select where to enter, put into the loop so it don't infinite loop
		short operationNumber;
		
		//Start TUI
		wcout << L"Was möchtest du berechnen?" << endl;
		wcout << L"Volumen eines " << YELLOW << L"Quaders" << RESET << L"		[1]" << endl;
		wcout << L"Umfang eines " << YELLOW << L"Kreises" << RESET << L"		[2]" << endl;
		wcout << L"Einstellungen: " << YELLOW << L"Präfix" << RESET << L"		[3]" << endl;
		wcout << L"Programm " << YELLOW << L"Schließen" << RESET << L"		[0]" << endl;
		wcout << CYAN << L"Eingabe: " << PINK;

		//selection input
		wcin >> operationNumber;
		wcout << RESET << endl;

		if (wcin.fail()) {
			fallback(failCount);
			continue;
		}

		//if number 1, then enter cuboid calculator
		else if (operationNumber == 1) {
			//initialization of the values of the cuboid
			double cuboidLength = 0;
			double cuboidWidth = 0;
			double cuboidHight = 0;

			//loop for cuboid calculator
			while (true) {
				//Asking for input (cuboid length), then validating it
				wcout << L"Geben Sie die Länge des Quaders ein: ";
				wcin >> cuboidLength;
				if (wcin.fail()) {
					fallback(failCount);
					continue;
				}
				
				//Same thing just with the width
				wcout << L"Geben Sie die Breite des Quaders ein: ";
				wcin >> cuboidWidth;
				if (wcin.fail()) {
					fallback(failCount);
					continue;
				}

				//This time with the hight
				wcout << L"Geben Sie die Höhe des Quaders ein: ";
				wcin >> cuboidHight;
				if (wcin.fail()) {
					fallback(failCount);
					continue;
				}
				
				//initializing result
				double cuboidResult = 0;

				//Calculating result
				cuboidResult = cuboidLength * cuboidWidth * cuboidHight;

				//Outputting the result
				wcout << L"Das Ergebniss ist: " << GREEN << cuboidResult << RESET; wcout << " "; wcout << YELLOW << prefixes[prefix] << RESET << endl << endl;
				break;
			}
		}

		//circumference of a circle
		else if (operationNumber == 2) {
			double circleRadius = 0;

			//Loop for if users input fails
			while (true) {
				wcout << L"Geben Sie den Radius des Kreises ein: ";
				wcin >> circleRadius;
				if (wcin.fail()) {
					fallback(failCount);
					continue;
				}

				//Initializing result
				double circleResult = 0;

				//Calculating result
				circleResult = 2 * pi * circleRadius;

				//Outputting result
				wcout << L"Das Ergebniss ist: " << GREEN << circleResult << RESET; wcout << L" "; wcout << YELLOW << prefixes[prefix] << RESET << endl << endl;
				break;
			}
		}

		else if (operationNumber == 3) {
			while (true) {
				short settingsNumber = 0;

				//Prefix settings TUI
				wcout << GREEN << L"Präfix Einstellungen:" << RESET << endl;
				wcout << L"Setze präfix auf " << YELLOW << L"Leer" << RESET << L"		[1]" << endl;
				wcout << L"Setze präfix auf " << YELLOW << L"Millimeter" << RESET << L"	[2]" << endl;
				wcout << L"Setze präfix auf " << YELLOW << L"Zentimeter" << RESET << L"	[3]" << endl;
				wcout << L"Setze präfix auf " << YELLOW << L"Dezimeter" << RESET << L"	[4]" << endl;
				wcout << L"Setze präfix auf " << YELLOW << L"Meter" << RESET << L"		[5]" << endl;
				wcout << L"Einstellungen " << YELLOW << L"schließen" << RESET << L"		[0]" << endl;
				wcout << CYAN << L"Eingabe: " << PINK;

				wcin >> settingsNumber;
				wcout << endl;
				wcout << RESET;

				//Fallback
				if (wcin.fail()) {
					fallback(failCount);
					continue;
				}

				//Prefix 1 - Empty
				else if (settingsNumber == 1) {
					prefix = 0;
					wcout << L"Das Prefix ist jetzt auf: "; wcout << YELLOW << L"Leer" << RESET << endl << endl;
				}

				//Prefix 2 - Millimeter
				else if (settingsNumber == 2) {
					prefix = 1;
					wcout << L"Das Prefix ist jetzt auf: "; wcout << YELLOW << L"Millimeter" << RESET << endl << endl;
				}

				//Prefix 3 - Centimeter
				else if (settingsNumber == 3) {
					prefix = 2;
					wcout << L"Das Prefix ist jetzt auf: "; wcout << YELLOW << L"Zentimeter" << RESET << endl << endl;
				}

				//Prefix 4 - Dezimeter
				else if (settingsNumber == 4) {
					prefix = 3;
					wcout << L"Das Prefix ist jetzt auf: "; wcout << YELLOW << L"Dezimeter" << RESET << endl << endl;
				}

				//Prefix 5 - Meter
				else if (settingsNumber == 5) {
					prefix = 4;
					wcout << L"Das Prefix ist jetzt auf: "; wcout << YELLOW << L"Meter" << RESET << endl << endl;
				}

				//Exit
				else if (settingsNumber == 0) {
					break;
				}
			}
		}

		//Exit
		else if (operationNumber == 0) {
			return 0;
		}

		//Error
		else {
			wcout << L"Ungültige eingabe." << endl << endl;
		}
	}
	return 1;
}