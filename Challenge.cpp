#include <iostream>
#include <sstream>
#include <vector>
#include "cMatrix3x3.h"

using namespace std;

vector<string> scanInput(string str) {
        vector<string> inputs;

        stringstream s(str);
        string input; 

        while (s >> input) {
            inputs.push_back(input);
        }

        return inputs;
    }

void promptUser(int N, cMatrix3x3* mtrx) {
    string input;
    bool validInput = false;

    while (!validInput) {
        cout << endl;
        cout << "> "; getline(cin, input);

        vector<string> inputs = scanInput(input);
        int size = inputs.size();

        if (size == 3) {
            if (inputs[1] == "+" || inputs[1] == "-" || inputs[1] == "*") {
                cMatrix3x3 m1, m2;
                for (int i=0; i<N; i++) {
                    if (inputs[0] == mtrx[i].getLabel()) {
                        m1.setLabel(mtrx[i].getLabel());
                        m1.assignMatrix(mtrx[i]);
                    } else if (inputs[2] == mtrx[i].getLabel()) {
                        m2.setLabel(mtrx[i].getLabel());
                        m2.assignMatrix(mtrx[i]);
                    } else {
                        cout << "There are no matches for the matrices you entered!";
                        continue;
                    }
                }
                // Perform the matrix operations
                if (inputs[1] == "+") {
                    (m1 + m2).printMatrix();
                } else if (inputs[1] == "-") {
                    (m1 - m2).printMatrix();
                } else {
                    (m1 * m2).printMatrix();
                }
            
                validInput = true;
            } else {
                cout << "There are no matches for the operation you entered!";
            }
        } else {
            cout << "Please enter a valid matrix label and operation in the format: label1 operator label2";
        }
    }
}

int main() {
    cout << "                      ==Matrix Calculator==                      " << endl;
    cout << "To stop entering matrices = Enter '#' as the label of the matrix." << endl;
    cout << "To quit                   = Enter 'quit' as the label of the matrix.\n" << endl;
    cout << "Press any key to continue..."; 
    cin.get();

    while (true) {
        cMatrix3x3 M; // M - Matrix
        string ML; // ML - Matrix Label
        cout << "\nMatrix Label: "; cin >> ML;
        cin.ignore();

        if (ML != "#" && ML != "quit") {
            M.setLabel(ML);
            M.setMatrix();
        } else if (ML == "quit"){
            cout << "\nTerminating...";
            cin.get();

            return 0;
        } else if (ML == "#") {
            if (N!=0) {
                cout << "\nPlease enter the operation you want to perform." << endl;
                promptUser(N, mtrx);

                cin.get();
                break;
            } else {
                cout << "No matrix has been provided" << endl;
            }
        }
    }

    return 0;
}