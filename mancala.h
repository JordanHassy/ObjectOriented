#include <iostream>
#include <sstream>

class Mancala {
    int m_board[14];
    int m_player = 0;

    
    public:
        Mancala() {
            for (int i = 0; i < 14; i++) {
                if (i == 6 || i == 13){ 
                    m_board[i] = 0; 
                    continue;
                }
                m_board[i] = 4;
            }
        }

        int getScore(int player) {
            if (player == 0) 
                return m_board[6];
            else if (player == 1)
                return m_board[13];
            return 0;
        }

        std::string getBoard() {
            std::stringstream ss;
            ss << '\n';
            
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
            else if (m_player == -1)
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

        int getPlayer() {
            return m_player;
        }

        bool move(int pitNum) {
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
            for (int i = 1; i <= pitValue; i++) {
                m_board[(pitIndex + i)%14]++;
                if ((m_player == 0 && ((pitIndex + i)%14) == 13) || (m_player == 1 && ((pitIndex + i)%14) == 6)) {
                    m_board[(pitIndex + i)%14]--;
                    pitValue++;
                }
                if (i == pitValue){
                    if ((pitIndex + i)%14 == 6 || (pitIndex + i)%14 == 13)
                        break;
                    else if(m_board[(pitIndex + i)%14] == 1) {
                        if (m_player == 0 && (0 <= (pitIndex + i)%14) && ((pitIndex + i)%14 <=5)) {
                            m_board[(pitIndex + i)%14]--;
                            m_board[6] += (1 + m_board[((pitIndex + i)%14) + 12 - 2*((pitIndex + i)%14)]);
                            m_board[((pitIndex + i)%14) + 12 - 2*((pitIndex + i)%14)] = 0;
                        } else  
                        if (m_player == 1 && (7 <= (pitIndex + i)%14) && ((pitIndex + i)%14 <=12)) {
                            m_board[(pitIndex + i)%14]--;
                            m_board[13] += (1 + m_board[12- (pitIndex + i)%14]);
                            m_board[12- (pitIndex + i)%14] = 0;
                        }
                    }
                    if(m_player == 0) {
                        m_player = 1;
                    }else if (m_player==1){ 
                        m_player = 0;
                    }
                } 
            }

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
            if (!ableToPlay[0] || !ableToPlay[1])
                m_player = -1;

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


};

// 13 | 12 11 10  9  8  7 |  *
//  - |  0  1  2  3  4  5 |  6 