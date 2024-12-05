#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    string line;
    fstream inputFile;

    // Open input.txt file in read mode to check if it is empty
    inputFile.open("input.txt", ios::in);
    
    // Check if the file is empty
    if (inputFile.peek() == ifstream::traits_type::eof()) {
        inputFile.close(); // Close the file after checking

        // Open input.txt file in append mode
        inputFile.open("input.txt", ios::app);
        if (inputFile.is_open()) {
            // Instructions to write in txt file
            inputFile << "<!-- Hello Developer, this project is created by Aman Sinha you can contact me on sinhaaman655@hotmail.com | follow and star the repo on www.github.com/tranquillite-007--> \n";
            inputFile << "<!-- About this project : This is a C++ project to convert or we can say that a project to create HTML, CSS website by just writing some lines in normal English--> \n";    
            inputFile << "<!-- Direction to use this project: --> \n";
            inputFile << "<!-- Write the statements for your website based on below rules --> \n";
            inputFile << "<!-- 1. Write the statement in as shown below: --> \n";
            inputFile << "        <!-- $heading = (Heading For The Section)  --> \n";
            inputFile << "        <!-- $paragraph = (Paragraph For The Section)  --> \n";
            inputFile << "        <!-- $image = (Image URL to add image)  --> \n";
            inputFile << "        <!-- $link =(Hypertext)(Link URL to add link)  --> \n";
            inputFile << "<!-- 2. After writing all required statement Save the file in project root folder --> \n";
            inputFile << "<!-- 3. Run the project by using the converter.exe file in the project folder --> \n";
            inputFile << "<!-- 4. Your website will be generated in the project folder with name as index.html--> \n";
            inputFile << "<!-- For more syntax statement Rule read the readme.md file of below mentioned github repo --> \n";
            inputFile << "<!-- https://github.com/tranquillite-007/txt-to-html-convertor-in-cpp/edit/main/README.md --> \n";
            inputFile << "<!-- Don't forget to star the repo for future reference.--> \n";
            inputFile << "\n";
            inputFile << "<!--####``````````````````````````````````````####-->\n<!--####``````````````````````````````````````####-->\n<!--####``````````````````````````````````````####-->\n";
            inputFile << "<!-- Write your statements below, --> \n";
            inputFile << "<!-- Good Luck (Happy Coading) --> \n";
            inputFile.close();
        }
    } else {
        inputFile.close(); // Close the file if it is not empty
    }

    // Code for output file or for converting txt to html     
    fstream outputFile;

    // Open input.txt file for read mode
    inputFile.open("input.txt", ios::in);
    
    // Open index.html file in write mode
    outputFile.open("index.html", ios::out);
    if (outputFile.is_open()) {
        // Initial or predefined lines before body tag in html file 
        outputFile << "<!DOCTYPE html> \n";
        outputFile << "<html lang=\"en\"> \n";
        outputFile << " <head> \n";
        outputFile << "    <meta charset=\"UTF-8\"> \n";
        outputFile << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> \n";
        
        // Later I'll add title program to add title in website 
        outputFile << "    <title></title> \n";
        outputFile << " </head> \n";
        outputFile << " <body> \n";
        
        // While loop to read all lines from inputFile.txt
        while (getline(inputFile, line)) {
            // Test statement to print h1 tags
            outputFile << "    <h1 style=\"width: max-content; margin: auto; background-color: aqua;\">" << line << "</h1> \n";
        }
        
        cout << "congo developer!! the file is created and working properly...  \n";

        // Initial or predefined lines after html body in html file
        outputFile << " </body> \n";
        outputFile << "</html> \n";
    }
    return 0;
}