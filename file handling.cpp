#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string line;
	fstream inputFile;
	
	
	// Open input.txt file
	inputFile.open("input.txt", ios::out);
	if(inputFile.is_open()){
		
		//add initial data in text file 
		
		inputFile <<"Add your commands here....  \n";
		
		
				
		inputFile.close();
	}
	
	
	
	
	
//	fstream outputFile;
//	inputFile.open("input.txt", ios::in);
//	outputFile.open("index.html", ios::out);
//	if(outputFile.is_open()){
//		while(getline(inputFile, line)){
//			outputFile << line << "<br> \n";
//			cout<<"the file is created \n";
//		}
//	}
	return 0;
}