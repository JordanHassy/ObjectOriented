class LightsOut {
    bool lightMatrix[25];

    public:
        LightsOut() {
            for (int i = 0; i < 25; i++) {
                lightMatrix[i] = false;
            }
        }
        
        //toggle a light on
        void on(int row, int col) {
            //this math uses row and collumn to get the index from lightMatrix(see indices at bottom)
            lightMatrix[(col-1) + ((row-1)*5)] = true;
        }

        //get the value of a light
        bool get(int row, int col) {
            return lightMatrix[(col-1) + ((row-1)*5)];
        }

        //toggle the value of a light and it adjacent lights
        void toggle(int row, int col) {
            int index = (col-1) + ((row-1)*5);
            lightMatrix[index] = !lightMatrix[index];

            //all of these if statemets test whether or not the light we are 
            //accessing is on either of the 4 walls of the box
            if (index%5 > 0)
                lightMatrix[index-1] = !lightMatrix[index-1];
            if (index%5 < 4)
                lightMatrix[index+1] = !lightMatrix[index+1];
            if (row > 1)
                lightMatrix[index-5] = !lightMatrix[index-5];
            if (row < 5)
                lightMatrix[index+5] = !lightMatrix[index+5];
        }

        //returns true if the game was succesful
        bool success() {
            //loops throughr the whole matrix, if any value is true(a light is on), it 
            //returns false. If all lights are on, loop finishes and the function returns true
            for (int i = 0; i < 25; i++) {
                if (lightMatrix[i] == true)
                    return false;
            }
            return true;
        }
};


/*
0  1  2  3  4
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24
*/