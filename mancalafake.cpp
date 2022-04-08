#include <iostream>
#include <sstream>
#include "mancala.h"

//My board indices
// 13 | 12 11 10  9  8  7 |  *
//  - |  0  1  2  3  4  5 |  6 

//  0 |  1  2  3  4  5  6 |  -
//  - |  7  8  9 10 11 12 | 13

//initializes all board values
Mancala::Mancala() {
    for (int i = 0; i < 14; i++) {
        if (i == 6 || i == 13){ 
            m_board[i] = 0;
            continue;
        }
        m_board[i] = 4;
    }
}

//returns score of current player
int Mancala::getScore(int player) {
    if (player == 0) 
        return m_board[6];
    else if (player == 1)
        return m_board[13];
    return 0;
}

//returns string form of board
std::string Mancala::getBoard() { 
    //using stringstream to format my board into a string
    std::stringstream ss;
    
    //all of these if statements are checking number size and current
    //player in order to output the right data into the stringstream ss
    if (m_board[13] >= 10) 
        ss << m_board[13] << " |";
    else
        ss << " " << m_board[13] << " |";
    
    for (int i = 12; i >= 7; i--) {
        if (m_board[i] >= 10)
            ss << " " << m_board[i];
        else
            ss << "  " << m_board[i];
    }

    if (m_player == 0)
        ss << " |  *\n - |";
    else if (m_player == 1)
        ss << " |  -\n * |";
    else
        ss << " |  -\n - |";
    
    for (int i = 0; i <= 5; i++) {
        if (m_board[i] >=10)
            ss << " " << m_board[i];
        else
            ss << "  " << m_board[i];
    }

    if (m_board[6] >= 10)
        ss << " | " << m_board[6] << "\n";
    else
        ss << " |  " << m_board[6] << "\n";
    
    return ss.str();
}

//returns current player
int Mancala::getPlayer() {
    return m_player;
}

//makes the current move. If the move is not allowed, returns false
bool Mancala::move(int pitNum) {

    //uses pitNum to get the index on the board that we want to use
    int pitIndex;
    if (m_player == 0) {
        pitIndex = 6 - pitNum;
        if (m_board[pitIndex] == 0 || pitIndex > 6 || pitIndex < 0) {
        return false;
        }
    }else if (m_player == 1) {
        pitIndex = 13-pitNum;
        if (m_board[pitIndex] == 0 || pitIndex > 12 || pitIndex < 7) {
        return false;
        }
    }

    int pitValue = m_board[pitIndex];
    m_board[pitIndex] = 0;

    //moves all the beads from the selected pit counterclockwise until they run out
    for (int i = 1; i <= pitValue;i++) {
        //(pitIndex + i)%14 basically gives the index of the current pit we are on
        m_board[((pitIndex + i)%14)] += 1;

        //if we land on the opposing players store, subtract what we added, and loop one more time
        if ((m_player == 0 && ((pitIndex + i)%14) == 13) || (m_player == 1 && ((pitIndex + i)%14) == 6)) {
            m_board[(pitIndex + i)%14]--;
            pitValue++;
        }
        //if we are on our last time through the loop
        if (i == pitValue){
            //if we ended the turn in either players store, break the loop, and therefore do not switch players
            if ((pitIndex + i)%14 == 6 || (pitIndex + i)%14 == 13)
                break;
                 //if the last pit we land on was previously 0,
            else if(m_board[(pitIndex + i)%14] == 1) {
                    /*and if the current player is 0 and we are on their side of the board, move the rock we 
                    added into the current pit into their store, and also move the rocks across from that pit 
                    into their store*/
                    if (m_player == 0 && (0 <= (pitIndex + i)%14) && ((pitIndex + i)%14 <=5)) {
                        m_board[(pitIndex + i)%14]--;
                        m_board[6] += (1 + m_board[((pitIndex + i)%14) + 12 - 2*((pitIndex + i)%14)]);
                        m_board[((pitIndex + i)%14) + 12 - 2*((pitIndex + i)%14)] = 0;
                    } else 
                    /*else if the current player is 1 and we are on their side of the board, move the rock we 
                    added into the current pit into their store, and also move the rocks across from that pit 
                    into their store*/
                    if (m_player == 1 && (7 <= (pitIndex + i)%14) && ((pitIndex + i)%14 <=12)) {
                        m_board[(pitIndex + i)%14]--;
                        m_board[13] += (1 + m_board[12- (pitIndex + i)%14]);
                        m_board[12- (pitIndex + i)%14] = 0;
                    }
            }

            //switch whose turn it is
            if(m_player == 0) {
                m_player = 1;
            }else if (m_player==1){ 
                m_player = 0;
            }
        } 
    }

    /*this block checks whether either players side of the board is all 0. If either player's is, set m_player 
    equal to -1*/
    bool ableToPlay[] = {false, false};
    for (int i = 0; i < 6; i++) {
        if(m_board[i] != 0) {
            ableToPlay[0] = true;
            break;
        }
    }
    for (int i = 7; i < 13; i++) {
        if (m_board[i] != 0) {
            ableToPlay[1] = true;
            break;
        }
    }
    if (!ableToPlay[0] || !ableToPlay[1]) {
        m_player = -1;
    }

    //if game is over, add all rocks on both sides of the board to the respective players store
    if (m_player == -1) {
        for (int i = 0; i < 6; i++) {
            m_board[6] += m_board[i];
            m_board[i] = 0;
        }
        for (int i = 7; i < 13; i++) {
            m_board[13] += m_board[i];
            m_board[i] = 0;
        }
    }
    return true;
}
