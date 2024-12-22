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
				
				istringstream iss(content);
				string firstWord;
				
				iss >> firstWord; 
				
				//check the first word and operate based on there syntax structure
				if (firstWord == "$word" || firstWord == "$div") {
                    
					size_t start = string::npos;
					size_t end = string::npos;
					size_t cStart = string::npos;
					size_t cEnd = string::npos;
					
					int openParentheses = 0;
					int openBrackets = 0;	
                    	
                    for (size_t i = 0; i < content.length(); ++i) {
                        if (content[i] == '~') {
                            // Skip the next character
                            ++i;
                            continue;
                        }
                        if (content[i] == '(') {
                            if (openParentheses == 0) {
                                start = i; 
                            }
                            openParentheses++;
                        } else if (content[i] == ')') {
                            openParentheses--;
                            if (openParentheses == 0 && start != string::npos) {
                                end = i; 
                            }
                        } else if (content[i] == '[') {
                            if (openBrackets == 0) {
                                cStart = i;
                            }
                            openBrackets++;
                        } else if (content[i] == ']') {
                            openBrackets--;
                            if (openBrackets == 0 && cStart != string::npos) {
                                cEnd = i; 
                            }
                        }
                    }
					
					if (start != string::npos && end != string::npos && end > start){
						string className;
						
						// Check if the class is there or not, if class info is available
                        if (cStart != string::npos && cEnd != string::npos && cEnd > cStart) {
                            className = content.substr(cStart + 1, cEnd - cStart - 1);
                        } else {
                            className = ""; // Default class name if not present
                        }
                        
                         
                        if (firstWord == "$word") {
                            string text = content.substr(start + 1, end - start - 1);
                            if (!className.empty()) {
                                outputFile << "    <h1 class=\"" << className << "\">" << text << "</h1> \n";
                                cout<< "working \n";
                            } else {
                                outputFile << "    <h1>" << text << "</h1> \n"; // No class attribute
                                cout<< "no class working \n";
                            }
                        }
					}	
				}
				
			}
		}
		// html snippet lines after html body in html file
        outputFile << " </body> \n";
        outputFile << "</html> \n";
	}	
}