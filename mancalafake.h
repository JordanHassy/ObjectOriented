#include <iostream>
#include <sstream>

class Mancala {
    int m_board[14];
    int m_player = 0;
 
    
    public:
        Mancala();
        
        int getPlayer();

        int getScore(int player);

        std::string getBoard();

        bool move(int pitNum);

};

