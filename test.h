#define TEST
#include <iostream>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <fstream>
#include <vector>

class typing_test
{
public:
    void start();
    void results(int, int, int);
};


// results screen 
void typing_test::results(int cpm, int wpm, int wrong){
    std::cout << "----------\n"
		 << "Results\n"
		 << "----------\n"
		 << "Characters typed: " << cpm << "\n"
         << "Words typed: " << wpm <<"\n"
		 << "Incorrect words: " << wrong << "\n"
	     << "Press enter to return to the start.\n";
	std::cin.ignore();
}


void typing_test::start(){
    int char_typed = 0;
    int words_typed = 0;
    int wrong_words = 0;
    std::string word, answer, display;
    std::ifstream dict ("words.txt");
    std::vector<std::string> words;
    std::chrono::steady_clock::time_point tEnd = std::chrono::steady_clock::now() + std::chrono::seconds(60);

    std::cout << "Type as many words as possible in one minute. Press enter to start.\n";
    std::cin.ignore();

    // generates random words
    if (dict.is_open()){
        while(getline(dict, word) && (std::chrono::steady_clock::now() <= tEnd)){
            words.push_back(word);
            srand(time(NULL));
            display = words[rand() % words.size()];
            std::cout << display << std::endl;
            std::cin >> answer;
            char_typed = char_typed + (sizeof(word));
            words_typed = words_typed + 1;
            
            // alerts user when incorrect word is typed
            if(answer != display){
                wrong_words = wrong_words + 1;
				std::cout << "\aWrong\n" << std::endl;
				std::cout << display << std::endl;				
				std::cin  >> answer;	
			}	
        }
        dict.close();
        std::cout << "Time is up. These are your results.\n";
        std::cin.ignore();
		results(char_typed, words_typed, wrong_words);
    }
}