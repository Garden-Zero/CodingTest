#include <bits/stdc++.h>
using namespace std;

char arr[2188][2188];

void recursive(int x, int y, int length, char c){
    int nl = length/3;
    if(length > 3){
        recursive(x, y, length/3, c);
        recursive(x+nl, y, length/3, c);
        recursive(x+nl*2, y, length/3, c);

        recursive(x, y+nl, length/3, c);
        recursive(x+nl, y+nl, length/3, ' ');
        recursive(x+nl*2, y+nl, length/3, c);

        recursive(x, y+nl*2, length/3, c);
        recursive(x+nl, y+nl*2, length/3, c);
        recursive(x+nl*2, y+nl*2, length/3, c);
    }else{
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                arr[x+i][y+j] = c;
            }
        }
        arr[x+1][y+1] = ' ';
    }
}


int main(){
    int n;
    cin >> n;
    recursive(1, 1, n, '*');

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}