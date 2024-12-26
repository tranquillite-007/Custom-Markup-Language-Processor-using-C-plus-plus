				#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;





string processTilde(const string& input) {
    string result;
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == '~') {
            if (i + 1 < input.length() && (input[i + 1] == '(' || input[i + 1] == ')' || input[i + 1] == '[' || input[i + 1] == ']')) {
                continue;
            } else {
                result += input[i];
            }
        } else {
            result += input[i];
        }
    }
    return result;
}

int main() {
    string line;
    fstream inputFile, outputFile;

    inputFile.open("userInput.txt", ios::in);
    if (inputFile.peek() == ifstream::traits_type::eof()) {
        inputFile.close();

        inputFile.open("userInput.txt", ios::app);
        if (inputFile.is_open()) {
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
    } else {
        inputFile.close(); //close if the file is not empty
    }

    inputFile.open("userInput.txt", ios::in);
    outputFile.open("output.html", ios::out);

    if (outputFile.is_open()) {
        // First add HTML snippet to our .html file outputFile << "<!DOCTYPE html> \n";
        outputFile << "<html lang=\"en\"> \n";
        outputFile << "<head> \n";
        outputFile << "    <meta charset=\"UTF-8\"> \n";
        outputFile << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> \n";
        
        // Later I'll add title program to add title in website 
        outputFile << "    <title></title> \n";
        outputFile << "    <link href=\"https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css\" rel=\"stylesheet\"> \n";
        outputFile << "</head> \n";
        outputFile << "<body> \n";

        while (getline(inputFile, line)) {
            if (line.empty() || line[0] != '$') {
                continue;
            } else {
                string content = line;

                istringstream iss(content);
                string tagName;
                iss >> tagName;
                
                size_t cStart = content.find('[');
        		size_t cEnd = content.find(']');

        		string className;
        		if (cStart != string::npos && cEnd != string::npos && cEnd > cStart) {
        		    className = processTilde(content.substr(cStart + 1, cEnd - cStart - 1));
        		}   
				
				//document structural tags first 
				//paragraph
				if (tagName == "$paragraph") {
            		size_t start = content.find('(');
            		size_t end = content.find(')');
            		if (start != string::npos && end != string::npos && end > start) {
            		    string text = processTilde(content.substr(start + 1, end - start - 1));
            		    if (!className.empty()) {
            		        outputFile << "    <p class=\"" << className << "\">" << text << "</p> \n";
            		    } else {
            		        outputFile << "    <p>" << text << "</p> \n"; // No class attribute
            		    }
            		}
        		}
        		
        		//headings from h1-h6
        		//h1
        		else if (tagName == "$heading1") {
            		size_t start = content.find('(');
            		size_t end = content.find(')');
            		if (start != string::npos && end != string::npos && end > start) {
            		    string text = processTilde(content.substr(start + 1, end - start - 1));
            		    if (!className.empty()) {
            		        outputFile << "    <h1 class=\"" << className << "\">" << text << "</h1> \n";
            		    } else {
            		        outputFile << "    <h1>" << text << "</h1> \n"; 
            		    }
            		}
        		}
        		
        		//h2
        		else if (tagName == "$heading2") {
            		size_t start = content.find('(');
            		size_t end = content.find(')');
            		if (start != string::npos && end != string::npos && end > start) {
            		    string text = processTilde(content.substr(start + 1, end - start - 1));
            		    if (!className.empty()) {
            		        outputFile << "    <h2 class=\"" << className << "\">" << text << "</h2> \n";
            		    } else {
            		        outputFile << "    <h2>" << text << "</h2> \n"; 
            		    }
            		}
        		}
        		
        		//h3
        		else if (tagName == "$heading3") {
            		size_t start = content.find('(');
            		size_t end = content.find(')');
            		if (start != string::npos && end != string::npos && end > start) {
            		    string text = processTilde(content.substr(start + 1, end - start - 1));
            		    if (!className.empty()) {
            		        outputFile << "    <h3 class=\"" << className << "\">" << text << "</h3> \n";
            		    } else {
            		        outputFile << "    <h3>" << text << "</h3> \n"; 
            		    }
            		}
        		}
        		
        		//h4
        		else if (tagName == "$heading4") {
            		size_t start = content.find('(');
            		size_t end = content.find(')');
            		if (start != string::npos && end != string::npos && end > start) {
            		    string text = processTilde(content.substr(start + 1, end - start - 1));
            		    if (!className.empty()) {
            		        outputFile << "    <h4 class=\"" << className << "\">" << text << "</h4> \n";
            		    } else {
            		        outputFile << "    <h4>" << text << "</h4> \n"; 
            		    }
            		}
        		}
        		
        		//h5
        		else if (tagName == "$heading5") {
            		size_t start = content.find('(');
            		size_t end = content.find(')');
            		if (start != string::npos && end != string::npos && end > start) {
            		    string text = processTilde(content.substr(start + 1, end - start - 1));
            		    if (!className.empty()) {
            		        outputFile << "    <h5 class=\"" << className << "\">" << text << "</h5> \n";
            		    } else {
            		        outputFile << "    <h5>" << text << "</h5> \n"; 
            		    }
            		}
        		}
        		
        		//h6
        		else if (tagName == "$heading6") {
            		size_t start = content.find('(');
            		size_t end = content.find(')');
            		if (start != string::npos && end != string::npos && end > start) {
            		    string text = processTilde(content.substr(start + 1, end - start - 1));
            		    if (!className.empty()) {
            		        outputFile << "    <h6 class=\"" << className << "\">" << text << "</h6> \n";
            		    } else {
            		        outputFile << "    <h6>" << text << "</h6> \n"; 
            		    }
            		}
        		}
        		
        		//header
				else if (tagName == "$header_start") {
        		    if (!className.empty()) {
        		        outputFile << "<header class=\"" << className << "\">\n";
        		    } else {
        		        outputFile << "<header>\n";
        		    }
        		}
				else if (tagName == "$header_end") {
        		    outputFile << "</header>\n";
        		}
        		
        		//nav
        		else if (tagName == "$nav_start") {
        		    if (!className.empty()) {
        		        outputFile << "<nav class=\"" << className << "\">\n";
        		    } else {
        		        outputFile << "<nav>\n";
        		    }
        		}
				else if (tagName == "$nav_end") {
        		    outputFile << "</nav>\n";
        		}
        		
        		//main
        		else if (tagName == "$main_start") {
        		    if (!className.empty()) {
        		        outputFile << "<main class=\"" << className << "\">\n";
        		    } else {
        		        outputFile << "<main>\n";
        		    }
        		}
				else if (tagName == "$main_end") {
        		    outputFile << "</main>\n";
        		}
        		
        		//article
        		else if (tagName == "$article_start") {
        		    if (!className.empty()) {
        		        outputFile << "<article class=\"" << className << "\">\n";
        		    } else {
        		        outputFile << "<article>\n";
        		    }
        		}
				else if (tagName == "$article_end") {
        		    outputFile << "</article>\n";
        		}
        		
        		//aside
        		else if (tagName == "$aside_start") {
        		    if (!className.empty()) {
        		        outputFile << "<aside class=\"" << className << "\">\n";
        		    } else {
        		        outputFile << "<aside>\n";
        		    }
        		}
				else if (tagName == "$aside_end") {
        		    outputFile << "</aside>\n";
        		}
        		
        		//div
        		else if (tagName == "$div_start") {
        		    if (!className.empty()) {
        		        outputFile << "    <div class=\"" << className << "\">\n";
        		    } else {
        		        outputFile << "    <div>\n";
        		    }
        		}
				else if (tagName == "$div_end") {
        		    outputFile << "    </div>\n";
        		}
        		
        		//section
        		else if (tagName == "$section_start") {
        		    if (!className.empty()) {
        		        outputFile << "<section class=\"" << className << "\">\n";
        		    } else {
        		        outputFile << "<section>\n";
        		    }
        		}
				else if (tagName == "$section_end") {
        		    outputFile << "</section>\n";
        		} 
				
				//footer
				else if (tagName == "$footer_start") {
        		    if (!className.empty()) {
        		        outputFile << "<footer class=\"" << className << "\">\n";
        		    } else {
        		        outputFile << "<footer>\n";
        		    }
        		}
				else if (tagName == "$footer_end") {
        		    outputFile << "</footer>\n";
        		}        
            
            	
            	//image and media tags start from here

				//image
            	else if (tagName == "$image") {				
    				size_t start = content.find('(');
    				size_t end = content.find(')');
    				if (start != string::npos && end != string::npos && end > start) {
    				    string imageDetails = content.substr(start + 1, end - start - 1);
    				    size_t commaPos = imageDetails.find(',');
    				    if (commaPos != string::npos) {
    				        string imageUrl = imageDetails.substr(0, commaPos);
    				        string altText = imageDetails.substr(commaPos + 1);
    				        if (!className.empty()) {
    				            outputFile << "    <img class=\"" << className << "\" src=\"" << imageUrl << "\" alt=\"" << altText << "\"> \n";
    				        } else {
    				            outputFile << "    <img src=\"" << imageUrl << "\" alt=\"" << altText << "\"> \n";
    				        }
    				    }
    				}
				}

				//link <a></a>
				else if (tagName == "$link") {
				    size_t start = content.find('(');
				    size_t end = content.find(')');
				    if (start != string::npos && end != string::npos && end > start) {
				        string linkDetails = content.substr(start + 1, end - start - 1);
				        size_t commaPos = linkDetails.find(',');
				        if (commaPos != string::npos) {
				            string linkUrl = linkDetails.substr(0, commaPos);
				            string linkText = linkDetails.substr(commaPos + 1);
				            if (!className.empty()) {				
                				outputFile << "    <a class=\"" << className << "\" href=\"" << linkUrl << "\">" << linkText << "</a> \n";
				            } else {				
				                outputFile << "    <a href=\"" << linkUrl << "\">" << linkText << "</a> \n";
				            }
				        }
				    }
				}

				// Audio tag
                else if (tagName == "$audio") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string audioDetails = content.substr(start + 1, end - start - 1);
                        if (!className.empty()) {
                            outputFile << "    <audio class=\"" << className << "\" controls><source src=\"" << audioDetails << "\" type=\"audio/mpeg\"></audio>\n";
                        } else {
                            outputFile << "    <audio controls><source src=\"" << audioDetails << "\" type=\"audio/mpeg\"></audio>\n";
                        }
                    }
                }

				// Video tag
                else if (tagName == "$video") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string videoDetails = content.substr(start + 1, end - start - 1);
                        if (!className.empty()) {
                            outputFile << "    <video class=\"" << className << "\" controls><source src=\"" << videoDetails << "\" type=\"video/mp4\"></video>\n";
                        } else {
                            outputFile << "    <video controls><source src=\"" << videoDetails << "\" type=\"video/mp4\"></video>\n";
                        }
                    }
                }
                
                // Picture tag (for responsive images)
                else if (tagName == "$picture") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string imageDetails = content.substr(start + 1, end - start - 1);
                        if (!className.empty()) {
                            outputFile << "    <picture class=\"" << className << "\"><source srcset=\"" << imageDetails << "\" type=\"image/webp\"><img src=\"" << imageDetails << "\" alt=\"Responsive image\"></picture>\n";
                        } else {
                            outputFile << "    <picture><source srcset=\"" << imageDetails << "\" type=\"image/webp\"><img src=\"" << imageDetails << "\" alt=\"Responsive image\"></picture>\n";
                        }
                    }
                }
                
                // Embed tag
                else if (tagName == "$embed") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string embedDetails = content.substr(start + 1, end - start - 1);
                        if (!className.empty()) {
                            outputFile << "    <embed class=\"" << className << "\" src=\"" << embedDetails << "\" type=\"application/pdf\">\n";
                        } else {
                            outputFile << "    <embed src=\"" << embedDetails << "\" type=\"application/pdf\">\n";
                        }
                    }
                }
                
                // Object tag
                else if (tagName == "$object") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string objectDetails = content.substr(start + 1, end - start - 1);
                        if (!className.empty()) {
                            outputFile << "    <object class=\"" << className << "\" data=\"" << objectDetails << "\" type=\"application/pdf\"></object>\n";
                        } else {
                            outputFile << "    <object data=\"" << objectDetails << "\" type=\"application/pdf\"></object>\n";
                        }
                    }
                }
                
                // Iframe tag
                else if (tagName == "$iframe") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string iframeDetails = content.substr(start + 1, end - start - 1);
                        if (!className.empty()) {
                            outputFile << "    <iframe class=\"" << className << "\" src=\"" << iframeDetails << "\" frameborder=\"0\" allowfullscreen></iframe>\n";
                        } else {
                            outputFile << "    <iframe src=\"" << iframeDetails << "\" frameborder=\"0\" allowfullscreen></iframe>\n";
                        }
                    }
                }
                
                // Canvas tag
                else if (tagName == "$canvas") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string canvasDetails = content.substr(start + 1, end - start - 1);
                        if (!className.empty()) {
                            outputFile << "    <canvas class=\"" << className << "\" width=\"" << canvasDetails << "\"></canvas>\n";
                        } else {
                            outputFile << "    <canvas width=\"" << canvasDetails << "\"></canvas>\n";
                        }
                    }
                }
                
                // SVG tag
                else if (tagName == "$svg") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string svgDetails = content.substr(start + 1, end - start - 1);
                        if (!className.empty()) {
                            outputFile << "    <svg class=\"" << className << "\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"" << svgDetails << "\"></svg>\n";
                        } else {
                            outputFile << "    <svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"" << svgDetails << "\"></svg>\n";
                        }
                    }
                }
                
                // Map tag
                else if (tagName == "$map") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string mapDetails = content.substr(start + 1, end - start - 1);
                        if (!className.empty()) {
                            outputFile << "    <map class=\"" << className << "\" name=\"" << mapDetails << "\"></map>\n";
                        } else {
                            outputFile << "    <map name=\"" << mapDetails << "\"></map>\n";
                        }
                    }
                }
                
                // Area tag inside map
                else if (tagName == "$area") {
                    size_t start = content.find('(');
                    size_t end = content.find(')');
                    if (start != string::npos && end != string::npos && end > start) {
                        string areaDetails = content.substr(start + 1, end - start - 1);
                        size_t commaPos = areaDetails.find(',');
                        if (commaPos != string::npos) {
                            string coords = areaDetails.substr(0, commaPos);
                            string href = areaDetails.substr(commaPos + 1);
                            if (!className.empty()) {
                                outputFile << "    <area class=\"" << className << "\" coords=\"" << coords << "\" href=\"" << href << "\" alt=\"Area\" shape=\"rect\">\n";
                            } else {
                                outputFile << "    <area coords=\"" << coords << "\" href=\"" << href << "\" alt=\"Area\" shape=\"rect\">\n";
                            }
                        }
                    }
				}
			}
        }
        // HTML snippet lines after HTML body in HTML file
        outputFile << "</body> \n";
        outputFile << "</html> \n";
    }
}