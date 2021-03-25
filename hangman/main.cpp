#include<iostream>
#include<fstream>
#include<vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>

using namespace  std;

const char myfile[] = "example.txt";
string chooseWord( const char* fileName)
    {
        vector<string> wordList;
        ifstream file(fileName);
        if (file.is_open())
            {
                string word;
                while (file >> word) {
                wordList.push_back(word);
                }
                file.close();
            }
        if (wordList.size() > 0) {
            int randomIndex = rand() % wordList.size();
            return wordList[randomIndex];
            }
        else return "";
    }

const string FIGURE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };
void renderGame(string guessedWord, int badGuessCount)
{
    system ("cls");
    cout << guessedWord << endl;
    cout << "Number of wrong guesses: " <<badGuessCount << endl;
    cout << FIGURE[badGuessCount] << endl;
}
char readGuess()
{
    char input;
    cout << "input"<< endl;
    cin >> input;
    return input;
}
string update(string guessedWord, string word, char guess)
{
    for (int i=0; i<word.size(); i++)
    {
        if (word[i]== guess)
        {
            guessedWord[i]=guess;
        }
    }
    return guessedWord;
}
bool contains(string word, char guess)
{
    return (word.find_first_of(guess) != string::npos);
}








int main()
{
    srand(time(0));
    string word = chooseWord(myfile);
    if (word.length() < 1) {
		cout << "Error reading vocabulary file " << myfile;
		return -1;
	}
    string guessedWord = string(word.size(), '-');
    int badGuessCount = 0;


    do{
        renderGame(guessedWord, badGuessCount);
        char guess = readGuess();
        if (contains(word, guess))
        {
            guessedWord = update(guessedWord, word, guess);

        }
        else badGuessCount++;


    }while(badGuessCount<7 && word !=guessedWord);
        system("cls");
        renderGame(guessedWord, badGuessCount);
    if (badGuessCount !=7)
		cout << "Congratulations! You win!";
	else
		cout << "You lost. The correct word is " << word;


    return 0;
}
