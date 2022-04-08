#include <iostream>

class GuessingGame {

    public:
        //initializes "m_answer"
        GuessingGame(std::string answer) : m_answer{answer} {}

        //returns true if all of the letters in "m_answer" are in "m_lettersGuessed"
        bool isComplete() {
            if (getRevealed() == m_answer)
                return true;
            else
                return false;
        }

        //returns a string "revealed" which has all unguessed letters as "_" and all guessed letters filled in
        std::string getRevealed() {
            std::string revealed{};

            //assembles the "revealed" string by checking which value to add, letter by letter.
            for (int i = 0; i < (int)m_answer.length(); i++) {
                /*This if-else chooses whether we should add a space or an underscore to "revealed", by checking 
                whether m_answer[i] is a space or not(which would make it a letter) */
                if(m_answer[i] == ' ')
                    revealed += ' ';
                else 
                    revealed += '_';
                /*if any of our guessed letters are equal to m_answer[i], this loop replaces the value just
                added to "revealed" with the letter we correctly guessed*/
                for (int j = 0; j < (int)m_lettersGuessed.length(); j++) {
                    if (tolower(m_answer[i]) == tolower(m_lettersGuessed[j])) {
                        revealed[i] = m_answer[i];
                    }
                }
            }
            return revealed;
        }

        //adds the new guess to "m_lettersGuessed" and outputs the getRevealed() string
        void makeGuess(char letter) {
            m_lettersGuessed += letter;
        }

        //returns the ammount of guesses in "m_lettersGuessed" that do not match "m_answer"
        int getMistakes() {
            int mistakeCount {0};
            bool correct;

            /*checks every letter guessed to see if it is in answer. For every guessed letter
            that is not in "m_answer", "mistakeCount" gets incremented.
            */
            for (int i = 0; i < (int)m_lettersGuessed.length(); i++){
                correct = false; 
                for (int j = 0; j < (int)m_answer.length(); j++){
                    if (tolower(m_lettersGuessed[i]) == tolower(m_answer[j])) {
                        correct = true;
                    }
                }

                //if m_lettersGuessed[i] is not in m_answer, increment "mistakeCount"
                if (!correct) {
                    mistakeCount++;
                }
            }
            return mistakeCount;
        }

        //returns "m_answer"
        std::string getAnswer() {
            return m_answer;
        }

        void printLettersGuessed() {
            bool isCorrect;
            for (int i = 0; i < (int)m_lettersGuessed.length(); i++) {
                isCorrect = false;
                for (int j = 0; j < (int)m_answer.length(); j++) {  
                    if (m_lettersGuessed[i] == m_answer[j]) { 
                        isCorrect = true;
                    }
                }
                if(!isCorrect)
                    std::cout << m_lettersGuessed[i] << ", ";
            }
        }




        std::string m_lettersGuessed{};
        std::string m_answer;
};