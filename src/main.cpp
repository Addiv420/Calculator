// Standard library headers
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <cmath>
#include <cstdlib>

// Namespace declaration
using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[38;5;196m"
#define GREEN   "\033[38;5;28m"
#define YELLOW  "\033[38;5;226m"
#define BLUE    "\033[38;5;21m"
#define MAGENTA "\033[38;5;165m"
#define PINK    "\033[38;5;204m"
#define CYAN    "\033[38;5;51m"
#define WHITE   "\033[38;5;255m"

// Input validation helper: Prevents infinite loops on invalid input
void input_fallback(short &attempt_count) {
    wcin.clear();
    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
    attempt_count++;
    
    if (attempt_count <= 5) {
        wcout << YELLOW << L"Hey! Don't break the program" << RESET << RED << " >:( \a" << RESET << endl << endl;
    } else if (attempt_count > 5 && attempt_count < 8) {
        wcout << BLUE << L"Are you trying to annoy me?" << RESET << PINK << " :3 \a" << RESET << endl << endl;
    } else if (attempt_count >= 8) {
        wcout << RED << L"Enough! Aborting... >:O\a" << RESET << endl << endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Initialize runtime environment
    system("clear");
    wcout << RESET;
    
    // UTF-8 locale configuration
    setlocale(LC_ALL, "en_US.UTF-8");
    locale::global(locale(""));

    // Measurement units configuration
    const wstring prefixes[] = { L"", L"mm", L"cm", L"dm", L"m" };
    short unit_prefix = 0;
    const double pi = M_PI;
    short error_count = 0;

    // Main application loop
    while (true) {
        short operation_choice;
        
        // Display main menu
        wcout << L"Select an operation:" << endl;
        wcout << L"-Calculate cuboid volume\t" << YELLOW << L"[1]" << RESET << endl;
        wcout << L"-Calculate circle circumference\t" << YELLOW << L"[2]" << RESET << endl;
        wcout << L"-Configure measurement units\t" << YELLOW << L"[3]" << RESET << endl;
        wcout << L"-Exit program\t\t\t" << YELLOW << L"[0]" << RESET << endl;
        wcout << CYAN << L"Selection: " << PINK;

        wcin >> operation_choice;
        wcout << RESET << endl;

        if (wcin.fail()) {
            input_fallback(error_count);
            continue;
        }

        // Operation handling
        switch(operation_choice) {
            case 1: { // Cuboid volume calculation
                double length, width, height;
                
                while (true) {
                    wcout << L"Enter cuboid length: ";
                    wcin >> length;
                    if (wcin.fail()) { input_fallback(error_count); continue; }
                    
                    wcout << L"Enter cuboid width: ";
                    wcin >> width;
                    if (wcin.fail()) { input_fallback(error_count); continue; }
                    
                    wcout << L"Enter cuboid height: ";
                    wcin >> height;
                    if (wcin.fail()) { input_fallback(error_count); continue; }

                    wcout << L"Result: " << GREEN 
                          << length * width * height 
                          << RESET << L" " << YELLOW 
                          << prefixes[unit_prefix] << RESET << endl << endl;
                    break;
                }
                break;
            }
            
            case 2: { // Circle circumference calculation
                double radius;
                
                while (true) {
                    wcout << L"Enter circle radius: ";
                    wcin >> radius;
                    if (wcin.fail()) { input_fallback(error_count); continue; }

                    wcout << L"Result: " << GREEN 
                          << 2 * pi * radius 
                          << RESET << L" " << YELLOW 
                          << prefixes[unit_prefix] << RESET << endl << endl;
                    break;
                }
                break;
            }
            
            case 3: { // Unit configuration
                while (true) {
                    short unit_choice;
                    
                    wcout << GREEN << L"Unit Configuration:" << RESET << endl;
                    wcout << L"-No unit\t\t" << YELLOW << L"[1]" << RESET << endl;
                    wcout << L"-Millimeters\t\t" << YELLOW << L"[2]" << RESET << endl;
                    wcout << L"-Centimeters\t\t" << YELLOW << L"[3]" << RESET << endl;
                    wcout << L"-Decimeters\t\t" << YELLOW << L"[4]" << RESET << endl;
                    wcout << L"-Meters\t\t\t" << YELLOW << L"[5]" << RESET << endl;
                    wcout << L"-Return to main menu\t" << YELLOW << L"[0]" << RESET << endl;
                    wcout << CYAN << L"Selection: " << PINK;

                    wcin >> unit_choice;
                    wcout << RESET << endl;

                    if (wcin.fail()) {
                        input_fallback(error_count);
                        continue;
                    }

                    // Handle unit selection
                    if (unit_choice >= 1 && unit_choice <= 5) {
                        unit_prefix = unit_choice - 1;
                        wcout << L"Selected unit: " << YELLOW 
                              << prefixes[unit_prefix] << RESET << endl << endl;
                    } else if (unit_choice == 0) {
                        break;
                    } else {
                        wcout << RED << L"Invalid unit selection!" << RESET << endl << endl;
                    }
                }
                break;
            }
            
            case 0: // Program exit
                return 0;
            
            default: // Error handling
                wcout << RED << L"Invalid selection!" << RESET << endl << endl;
        }
    }
    return EXIT_SUCCESS;
}