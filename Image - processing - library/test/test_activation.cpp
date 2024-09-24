#include <iostream>
#include <fstream>
#include <vector>
#include <activation.h>

using namespace std;

vector<vector<float>> readMatrix(const string& filename){
    ifstream file(filename);

    if (!file.is_open()){
        cerr << "Error: Could not open the file" << filename << endl;
        exit(1);        
    }

    
}

void print_matrix(vector<vector<float>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

}