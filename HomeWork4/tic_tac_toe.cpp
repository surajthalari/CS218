#include <bits/stdc++.h>

using namespace std;

int checkW(vector<string> &matrix){
    for(int i=0;i<3;i++){
        if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][2] == 'X'){
            return 1;
        }
        else if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][2] == 'O'){
            return -1;
        }
    }

    for(int i=0;i<3;i++){
        if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[2][i] == 'X'){
            return 1;
        }
        else if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[2][i] == 'O'){
            return -1;
        }
    }

    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){
        if(matrix[0][0] == 'X'){
            return 1;
        }
        else if(matrix[0][0] == 'O'){
            return -1;
        }
    }

    if(matrix[0][2] == matrix[1][1] == matrix[2][0]){
        if(matrix[1][1] == 'X'){
            return 1;
        }
        else if(matrix[1][1] == 'O'){
            return -1;
        }
    }

    return 0;
}

bool isFilled(vector<string> &matrix){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrix[i][j] == '#'){
                return false;
            }
        }
    }
    return true;
}


int compute(vector<string> &matrix, bool X){
    int w = checkW(matrix);

    if (w == 1 or w == -1){
        return w;
    }

    if (isFilled(matrix)){
        return 0;
    }

    if(X){
        int b = -9999;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (matrix[i][j] == '#'){
                    matrix[i][j] = 'X';
                    b = max(b, compute(matrix, false));
                    matrix[i][j] = '#';
                }
            }
        }      
        return b;
    }
    else{
        int b = 9999;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (matrix[i][j] == '#'){
                    matrix[i][j] = 'O';
                    b = min(b, compute(matrix, true));
                    matrix[i][j] = '#';
                }
            }
        }
        return b;
    }
}


void solve(vector<string> &matrix, int x_count, int o_count){
    int x = 0;
    if(x_count == o_count){
        x = INT_MIN;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(matrix[i][j] == '#'){
                    matrix[i][j] = 'X';
                    x = max(x, compute(matrix, false));
                    matrix[i][j] = '#';
                }
            }
        }
    }
    else if(x_count > o_count){
        x = INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(matrix[i][j] == '#'){
                    matrix[i][j] = 'O';
                    x = min(x, compute(matrix, true));
                    matrix[i][j] = '#';
                }
            }
        }
    }

    if(x == 1){
        cout << "Crosses win" << endl;
    }
    else if(x == -1){
        cout << "Noughts win" << endl;
    }
    else if(x == 0){
        cout << "Draw" << endl;
    }
    else if(isFilled(matrix)){
        int w = checkW(matrix);
        if(w == 1){
            cout << "Crosses win" << endl;
        }
        else if(w == -1){
            cout << "Noughts win" << endl;
        }
        else{
            cout << "Draw" << endl;
        }
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<string> matrix;

    int x_count = 0, o_count = 0;

    for(int i=0;i<3;i++){
        string temp;
        cin >> temp;
        matrix.push_back(temp);
        if(temp [0] == 'X') x_count++;
        else if(temp [0] == 'O') o_count++;
        if(temp [1] == 'X') x_count++;
        else if (temp [1] == 'O') o_count++;
        if(temp [2] == 'X') x_count++;
        else if(temp [2] == 'O') o_count++;

    }

    solve(matrix, x_count, o_count);
    return 0;
}