#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	string line;
	fstream inputFile, outputFile;
	
	inputFile.open("userInput.txt", ios::in);
	if(inputFile.peek() == ifstream::traits_type::eof()){
		inputFile.close();
		
		inputFile.open("userInput.txt", ios::app);
		if(inputFile.is_open()){
			// Instructions to write in txt file
            inputFile << "<!-- Hello Developer, this project is created by Aman Sinha you can contact me on sinhaaman655@hotmail.com | follow and star the repo on www.github.com/tranquillite-007--> \n";
            inputFile << "<!-- About this project : This is a C++ project to convert or we can say that a project to create HTML, CSS website by just writing some lines in normal English--> \n";    
            inputFile << "<!-- Direction to use this project: --> \n";
            inputFile << "<!-- Write the statements for your website based on below rules --> \n";
            inputFile << "<!-- 1. Write the statement in as shown below: --> \n";
            inputFile << "        <!-- $heading = (Heading For The Section)  --> \n";
            inputFile << "        <!-- $paragraph = (Paragraph For The Section)  --> \n";
            inputFile << "        <!-- $image = (Image URL to add image,alt value)  --> \n";
            inputFile << "        <!-- $link =(Hypertext,Link URL to add link)  --> \n";
            inputFile << "<!-- 2. After writing all required statement Save the file in project root folder --> \n";
            inputFile << "<!-- 3. Run the project by using the converter.exe file in the project folder --> \n";
            inputFile << "<!-- 4. Your website will be generated in the project folder with name as index.html--> \n";
            inputFile << "<!-- For more syntax statement Rule read the readme.md file of below mentioned github repo --> \n";
            inputFile << "<!-- https://github.com/tranquillite-007/txt-to-html-convertor-in-cpp/edit/main/README.md --> \n";
            inputFile << "<!-- Don't forget to star the repo for future reference.--> \n";
            inputFile << "\n";
            inputFile << "<!--####``````````````````````````````````````####-->\n<!--####``````````````````````````````````````####-->\n<!--####``````````````````````````````````````####-->\n";
            inputFile << "<!-- Write your statements below, --> \n";
            inputFile << "<!-- you can remove above lines or comments from txt file, these are non-functional lines -->";
            inputFile << "<!-- Good Luck (Happy Coding) --> \n";
            inputFile.close();
		}
	}else{
		inputFile.close(); //close if the file is not empty
	}

	inputFile.open("userInput.txt", ios::in);
	outputFile.open("output.html", ios::out);
	
	if(outputFile.is_open()){
		// First add HTML snippet to our .html file
        outputFile << "<!DOCTYPE html> \n";
        outputFile << "<html lang=\"en\"> \n";
        outputFile << " <head> \n";
        outputFile << "    <meta charset=\"UTF-8\"> \n";
        outputFile << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> \n";
        
        // Later I'll add title program to add title in website 
        outputFile << "    <title></title> \n";
        outputFile << "    <link href=\"https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css\" rel=\"stylesheet\"> \n";
        outputFile << " </head> \n";
        outputFile << " <body> \n";
        
        
        
        while(getline(inputFile, line)){
        	if(line.empty() || line[0] != '$'){
        		continue;
			}else{
				string content = line;
				
			}
		}
		// html snippet lines after html body in html file
        outputFile << " </body> \n";
        outputFile << "</html> \n";
	}	
}