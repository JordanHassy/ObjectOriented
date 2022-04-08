#include <iostream> 

class Matrix {
    int m_rows;
    int m_cols;
    double * m_newMatrix;
    public:
        Matrix(int rows, int cols) : m_rows{rows}, m_cols{cols} {
            m_newMatrix = new double[rows * cols];
            for (int i = 0; i < (rows*cols); i++) {
                m_newMatrix[i] = 0;
            }
        }

        ~Matrix() {
            delete [] m_newMatrix;
        }

        void setValue(int row, int col, double value) {
            m_newMatrix[col + (row * m_cols)] = value;
        }

        double getValue(int row, int col) {
            double value = m_newMatrix[col + (row * m_cols)];
            return value;
        }

        int getRows() {
            return m_rows;
        }

        int getCols() {
            return m_cols;
        }

        void print() {
            for (int r = 0; r < m_rows; r++) {
                for (int c = 0; c < m_cols; c++) {
                    std::cout << m_newMatrix[c + (r * m_cols)] << " ";
                }
                std::cout << '\n';
            }
        }
};
