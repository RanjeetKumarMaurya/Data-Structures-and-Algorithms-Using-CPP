#include <iostream>
using namespace std;


/*
Print filled square
.................................
.           ****                .
.           ****                .
.           ****                .
.           ****                .
.................................
*/
void printSquare(int n){
    cout << "Printing filled square" <<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout <<"*";
        }
        cout <<endl;
    }
}



/*
Print Right Triangle
.................................
.           *                   .
.           **                  .
.           ***                 .
.           ****                .
.................................
*/
void printRightTriangle(int n){
    cout << "Printing right triangle" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout <<"*";
        }
        cout << endl;
    }
}


/*
Print Number Right Triangle
.................................
.           1                   .
.           12                  .
.           123                 .
.           1234                .
.................................
*/
void printNumberTriangle(int n){
    cout << "Printing number triangle" << endl;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= i; j ++){
            cout <<j+1;
        }
        cout << endl;
    }
}



/*
Print same Number Right Triangle
.................................
.           1                   .
.           22                  .
.           333                 .
.           4444                .
.................................
*/
void printSameNumberTriangle(int n){
    cout << "Printing same number triangle" << endl;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= i; j ++){
            cout <<i+1;
        }
        cout << endl;
    }
}



/*
Print reverse Right Triangle
.................................
.           ****                .
.           ***                 .
.           **                  .
.           *                   .
.................................
*/
void printReverseRightTriangle(int n){
    cout << "Printing reverse right triangle" << endl;
    for(int i = 0; i < n; i++){
        for(int j = n; j > i; j--){
            cout <<"*";
        }
        cout << endl;
    }
}




/*
Print reverse Number Right Triangle
.................................
.           1234                .
.           123                 .
.           12                  .
.           1                   .
.................................
*/
void printReverseNumberTriangle(int n){
    cout << "Printing reverse number triangle" << endl;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n - i; j ++){
            cout <<j+1;
        }
        cout << endl;
    }
}


/*
Print Triangle
.................................
.            *                  .
.           ***                 .
.          *****                .
.         ********              .
.................................
*/
void printTriangle(int n){
    cout << "Printing triangle" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            cout << " ";
        }
        for(int k = 0; k < (2 * i - 1); k++){
            cout << "*";
        }
        for(int l = 0; l < n-i; l++){
            cout << " ";
        }
        cout << endl;
    }
}


/*
Print Diamond
.................................
.            *                  .
.           ***                 .
.          *****                .
.         ********              .
.          *****                .
.           ***                 .
.            *                  .
.................................
*/
void printDiamond(int n){
    cout << "Printing Diamond" << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            cout << " ";
        }
        for(int k = 0; k < (2 * i - 1); k++){
            cout << "*";
        }
        for(int l = 0; l < n-i; l++){
            cout << " ";
        }
        cout << endl;
    }

    for(int i = 2 * n - n - 1; i > 2 * 0; i--){
        for(int j = 0; j < n-i; j++){
            cout << " ";
        }
        for(int k = 0; k < (2 * i - 1); k++){
            cout << "*";
        }
        for(int l = 0; l < n-i; l++){
            cout << " ";
        }
        cout << endl;
    }    
}



/*
Print Reverse Triangle
.................................
.         ********              .
.          *****                .
.           ***                 .
.            *                  .
.................................
*/
void printReverseTriangle(int n){
    cout << "Printing reverse triangle" << endl;
    for(int i = n; i > 0; i--){
        for(int j = 0; j < n-i; j++){
            cout << " ";
        }
        for(int k = 0; k < (2 * i - 1); k++){
            cout << "*";
        }
        for(int l = 0; l < n-i; l++){
            cout << " ";
        }
        cout << endl;
    }
}



/*
Print half diamond
.................................
.         *                     .
.         **                    .
.         ***                   .
.         **                    .
.         *                     .
.................................
*/
void printHalfDiamond(int n){
    cout << "Printing half diamond" << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout <<"*";
        }
        cout << endl;
    }

    for(int i = 2 * n - n - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            cout <<"*";
        }
        cout << endl;
    }
}



/*
Print binary Right Triangle
.................................
.           1                   .
.           01                  .
.           101                 .
.           0101                .
.................................
*/
void printBinaryRightTriangle(int n){
    cout << "Printing binary right triangle" << endl;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < i; j ++){
            cout << ((i % 2) ^ (j % 2)) % 2;
        }
        cout << endl;
    }
}


/*
Print increasing Right Triangle
.................................
.           1                   .
.           12                  .
.           123                 .
.           1234                .
.................................
*/
void printIncreasingTriangle(int n){
    cout << "Printing increasing numeric triangle" << endl;
    int k = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << k;
            k++;
        }
        cout << endl;
    }
}


/*
Print letter Right Triangle
.................................
.           A                   .
.           AB                  .
.           ABC                 .
.           ABCD                .
.................................
*/
void printLetterRightTriangle(int n){
    cout <<"Printing letter right triangle" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << char(65 + j);
        }
        cout << endl;
    }
}




/*
Print same letter Right Triangle
.................................
.           A                   .
.           BB                  .
.           CCC                 .
.           DDDD                .
.................................
*/
void printSameLetterRightTriangle(int n){
    cout <<"Printing same letter right triangle" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << char(65 + i);
        }
        cout << endl;
    }
}




/*
Print reverse letter Right Triangle
.................................
.           ABCD                .
.           ABC                 .
.           AB                  .
.           A                   .
.................................
*/
void printReverseLetterRightTriangle(int n){
    cout <<"Printing reverse letter right triangle" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            cout << char(65 + j);
        }
        cout << endl;
    }
}



/*
Print letter Triangle
.................................
.           A                   .
.          ABA                  .
.         ABCBA                 .
.................................
*/
void printLetterTriangle(int n){
    cout <<"Printing letter triangle" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            cout << " ";
        }
        char ch = 'A';
        for(int k = 0; k <= i; k++){
            cout << ch;
            ch++;
        }
        
        ch -= 2;
        for(int k = 0; k < i; k++){
            cout << ch;
            ch--;
        }
        cout << endl;
    }
}



/* Print hollow diamond
.................................
.           ********            .
.           ***  ***            .
.           **    **            .
.           *      *            .
.           **    **            .
.           ***  ***            .
.           ********            .
.................................
*/
void printHollowDiamond(int n){
    cout <<"Printing hollow diamond" << endl;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n - i; j++){
            cout << "*";
        }
        for(int  k = 0; k < 2 * i; k++){
            cout <<" ";
        }
        for(int j = 0; j < n - i; j++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i = 1; i < n; i ++){
        for(int j = 0; j < i + 1; j++){
            cout << "*";
        }
        for(int  k = 0; k < 2 * (n- i -1); k++){
            cout <<" ";
        }
        for(int j = 0; j < i + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
}




/* Print mirror half diamond
.................................
.           *    *              .
.           **  **              .
.           ******              .
.           **  **              .
.           *    *              .
.................................
*/
void printMirrorHalfDiamond(int n){
    cout << "Printing mirror half diamond" << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << "*";
        }
        for(int k = 0; k < 2 * (n - i - 1); k++){
            cout << " ";
        }
        for(int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i = 1; i < n; i++){
        for(int j = n; j > i; j--){
            cout << "*";
        }
        for(int k = 0; k < 2 * i; k++){
            cout << " ";
        }
        for(int j = n; j > i; j--){
            cout << "*";
        }
        cout << endl;
    }
}



/* Print hollow sqare
.................................
.           ****                .
.           *  *                .
.           *  *                .
.           ****                .
.................................
*/
void printHollowSquare(int n){

}




void printPalindromicNumberPyramid(int n){

}




int main(){
    int t;
    cout <<"Enter no of test cases: " << endl;
    cin >> t;

    while(t){
        int n;
        cout << "Enter size of n: " << endl;
        cin >> n;
        printSquare(n);
        printRightTriangle(n);
        printNumberTriangle(n);
        printSameNumberTriangle(n);
        printReverseRightTriangle(n);
        printReverseNumberTriangle(n);
        printTriangle(n);
        printDiamond(n);
        printReverseTriangle(n);
        printHalfDiamond(n);
        printBinaryRightTriangle(n);
        printPalindromicNumberPyramid(n);
        printIncreasingTriangle(n);
        printLetterRightTriangle(n);
        printSameLetterRightTriangle(n);
        printReverseLetterRightTriangle(n);
        printLetterTriangle(n);
        printHollowDiamond(n);
        printMirrorHalfDiamond(n);
        printHollowSquare(n);
        t--;
    }
}