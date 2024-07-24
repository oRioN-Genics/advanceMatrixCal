#include <cmath>
#include "cMatrix3x3.h"

int N = 0;
cMatrix3x3* mtrx = NULL;

cMatrix3x3::cMatrix3x3()
{
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            matrix[i][j] = 0;
        }
    }
}

cMatrix3x3::~cMatrix3x3()
{
    
}

void cMatrix3x3::setLabel(string argLabel) {
    label = argLabel;
}

void cMatrix3x3::assignMatrix(cMatrix3x3& other) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

void cMatrix3x3::setMatrix() {
    cout << "[0     0     0]" << endl;
    cout << "[0     0     0]" << endl;
    cout << "[0     0     0]" << endl;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << "Enter value for row " << i+1 << " column " << j+1 << ":"; cin >> matrix[i][j];
        }
    }

    printMatrix();
    insertMatrix(*this);
}

void cMatrix3x3::insertMatrix(cMatrix3x3 newMatrix) {
    if (N==0) {
        N = 1;
        mtrx = new cMatrix3x3[N];
        mtrx[0] = newMatrix;
    } else {
        cMatrix3x3 *tmp = NULL;
        tmp = new cMatrix3x3 [N+1];

        for (int i=0; i<N; i++) {
            *(tmp+i) = *(mtrx+i);
        }
        mtrx = tmp;
        mtrx[N] = newMatrix;
        N++;
    }
}

string cMatrix3x3::getLabel() {
    return label;
}

void cMatrix3x3::printMatrix() {
    int maxWidth = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int width = to_string(matrix[i][j]).length();
            if (maxWidth < width) {
                maxWidth = width;
            }
        }
    }
    for (int i=0; i<3; i++) {
        cout << "[" ;
        for (int j=0; j<3; j++) {
            cout << setw(maxWidth) << matrix[i][j];
            if (j < 2) {
                cout << "       ";
            }
        }
        cout << "]" << endl;
    }
}

cMatrix3x3 cMatrix3x3::operator+(cMatrix3x3& other) {
    cMatrix3x3 result;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

cMatrix3x3 cMatrix3x3::operator-(cMatrix3x3& other) {
    cMatrix3x3 result;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

cMatrix3x3 cMatrix3x3::operator*(cMatrix3x3& other) {
    cMatrix3x3 result;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                result.matrix[i][j] += (matrix[i][k] * other.matrix[k][j]);
            }
        }
    }
    return result;
}

cMatrix3x3 cMatrix3x3::transpose() {
    cMatrix3x3 result;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}