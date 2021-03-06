// CPP_XMLFinder.cpp : Defines the entry point for the console application.
//******************************************************************************//
//   This application opens an XML file and searches for a specific XML tag (attribute) 
//   The reason for this is I had some XML files I was trying to troubleshoot, and part of that troubleshooting involved seeing if a specific tag existed in the file.                                                                 //
//                                                                         
//*****************************************************************************//
#include "stdafx.h"
#include <iostream>
#include<fstream>
#include<string>
#include <time.h>
#include<chrono>
#include<ctime>

using namespace std;

int main()
{
	
	int row_count = 0;
	int letter_index = 0;
	int next_index = 0;
	
	std::string target; //insert your own string or XML attribute to be found
	std::string lines;
	std::string found_string = "";
	std::ifstream myFile("C:\\Users\\zrebstock\\Documents\\python4inf.txt");
	std::string input;
	cout << "Enter string you want to find" << endl; //get user input for string they want to locate
	cin >> target;

	cout << endl;
	time_t  start = time(0);
	if (myFile.is_open()) {
		cout << "Searching..." << endl;
		while (! myFile.eof() ) { //while not EOF

			std::getline(myFile, lines);// read each line per loop iterration 
			
				for (int i = 0; i <= lines.length(); i++) { //search through each char in the line
					if (lines[i] == target[letter_index]) { //compare current char to target[x]
					
						found_string = found_string + lines[i]; //add matching char to string
						letter_index++; //move index to next char in target (i.e. "<" would be 0, "m" would be 1)
						
						if (found_string == target) { //break out of loop if target string is found (in the event it's not at the end of the file like in my testing (for performance comparision between Python, C++ and C#
							cout << "Found string..." << target << endl;
							cout << "Searching...." << "Rows: " << row_count << endl;
							time_t end = time(0);
							double diff = difftime(end, start);
							cout << "Elapsed time in seconds: " << diff << endl;
							break;
						}
					}
					else { //reset indexes and found_string placeholder (have to find entire string to pass the checks listed above)
						

						letter_index = 0;
						found_string = "";
						
						
					}
					

				}
				
				

			row_count++; //add row count for each line the search has to go through

				
		
			
			
			if (found_string != target && myFile.eof() == true) { //print if string could not be located
				cout << "Could not locate string" << endl;
		}
			
		}
		myFile.close();
		system("pause");
	}
	
	









	
}
