// CPP_XMLFinder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<fstream>
#include<string>
#include <time.h>

using namespace std;

int main()
{
	
	int row_count = 0;
	int letter_index = 0;
	int next_index = 0;
	std::string target = "<meterNo>";
	std::string lines;
	std::string found_string = "";
	std::ifstream myFile("C:\\Users\\zrebstock\\Documents\\python4inf.txt");

	if (myFile.is_open()) {

		while (row_count <=90000) {
			std::getline(myFile, lines);
				for (int i = 0; i <= lines.length(); i++) {
					if (lines[i] == target[letter_index]) {
					
						found_string = found_string + lines[i];
						letter_index++;
						
						if (found_string == target) {
							
							break;
						}
					}
					else {
						

						letter_index = 0;
						found_string = "";
						
						
					}
					

				}

				row_count++;
			
			next_index++;
		
			if (found_string == target) {
				cout << "Found string..." << target << endl;
				cout << "Searching...." << "Rows: " << row_count << endl;
				break;
			}

			
		}
		myFile.close();
		system("pause");
	}
	int num;
	









	
}