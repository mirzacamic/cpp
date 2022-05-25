#include <iostream>
#include <fstream>
#include <string.h>

int start();
std::string single();
std::string multy();

int play(std::string word);

int main() {
    int mode = start();
    std::string word;

    if(mode == 1)
        word = single();
    else if (mode == 2)
        word = multy();

    int eso = play(word);
}

int start(){
    int players = 0;

    std::cout << "##### WELCOME TO HANGMAN #####" << std::endl;
    do
    {
        std::cout << "1 or 2 players? ";
        std::cin >> players;
    } while (players > 2);
    
    system("clear");

    if (players == 0)
    {
        exit(1);
    }
    return players;
}

std::string single(){

    std::string word;

    std::ifstream fin("word.txt");
    int words = 1;
    char ch;

    fin.seekg(0, std::ios::beg);

    while (fin)
    {
        fin.get(ch);
        if(ch==' '||ch=='\n')
            words++;
    }
    fin.close();


    std::fstream myFile;
    myFile.open("word.txt", std::ios::in);

    srand(time(0));
    int randy = (rand() % words) +1;
    if(myFile.is_open()){
        for (int i = 0; i < randy; i++)
        {
            std::getline(myFile, word);
        }
        
    }
    std::cout << std::endl << word;
    return word;

}

std::string multy(){
    system("clear");
    std::string word;

    do
    {
        std::cout << "Enter the word: ";
        std::cin >> word;
    } while ((word.length() > 15) && (word.length() < 3));
    
    return word;
}

int play(std::string word){
    system("clear");

    char s[word.length()];

    for (size_t i = 0; i < word.length(); i++)
    {
        s[i] = word[i];
    }
    

    char guess[word.length()];

    for (size_t i = 0; i < word.length(); i++)
    {
        guess[i] = '_';
    }
     
    int lives = word.length();
    char letter;

    do
    {
        system("clear");
        std::cout << "Lives left: " << lives << "/" << word.length() << std::endl;
        std::cout << "The word is: ";

        for (size_t i = 0; i < word.length(); i++)
        {
            std::cout << guess[i];
        }
        

        if(strcmp(s, guess) == 0){
            std::cout << "\nWON!\n";
            break;
        }

        std::cout << "\nYour letter: ";
        std::cin >> letter;

        char last[word.length()];
        for (size_t i = 0; i < word.length(); i++)
        {
            last[i] = guess[i];
        }

        for (size_t i = 0; i < word.length(); i++)
        {
            if (letter == word[i])
            {
                guess[i] = letter;
            }
        }
        if(strcmp(last, guess) == 0)
            lives--;
        
        if(lives == 0)
            break;
        


    } while (1);
    
    if (lives == 0)
    {
        std::cout << "YOU LOST!\nThe word was: " << word << std::endl;
    }
    

    return 1;
}