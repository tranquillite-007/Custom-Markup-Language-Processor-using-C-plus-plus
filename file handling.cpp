#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string line;
	fstream myFile;
	myFile.open("file.txt", ios::out);
	if(myFile.is_open()){
		myFile <<" first line \n";
		myFile.close();
	}
	myFile.open("file.txt", ios::app);
	if(myFile.is_open()){
		myFile << " second appended line  ! \n";
		myFile.close();
	}
	fstream newFile;
	myFile.open("file.txt", ios::in);
	newFile.open("file.html", ios::out);
	if(newFile.is_open()){
		while(getline(myFile, line)){
			newFile << line << "<br> \n";
			cout<<"the file is created \n";
		}
		
	}
	return 0;
}