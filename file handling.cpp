#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string line;
	fstream inputFile;
	
	
	// Open input.txt file in append mode
	inputFile.open("input.txt", ios::app);
	if(inputFile.is_open()){				
		inputFile.close();
	}
	
	
	
	
    //code for output file or for converting txt to html 	
	fstream outputFile;
	
	//open input.txt file for read mode
	inputFile.open("input.txt", ios::in);
	
	//open index.html file in read mode
	outputFile.open("index.html", ios::out);
	if(outputFile.is_open()){
		
		//initial or predefined lines before body tag in html file 
		outputFile << "<!DOCTYPE html> \n";
		outputFile << "<html lang=\"en\"> \n";
		outputFile << " <head> \n";
		outputFile << "    <meta charset=\"UTF-8\"> \n";
		outputFile << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> \n";
		
		// later i'll add title programme to add title in website 
		outputFile << "    <title></title> \n";
		outputFile << " </head> \n";
		outputFile << " <body> \n";
		
		//while loop to read all lines from inputFile.txt
		while(getline(inputFile, line)){
			
			// test statement to print h1 tag 
//			outputFile <<" " << line << " \n";
			outputFile <<"    <h1 style=\"width: max-content; margin: auto; background-color: aqua;\">" << line << "</h1> \n";

			cout<<"congo developer!! the file is created and working properly...  \n";
		}
		
		//initial or predefined lines after html body in html file
		outputFile <<" </body> \n";
		outputFile <<"</html> \n";
	}
	return 0;
}