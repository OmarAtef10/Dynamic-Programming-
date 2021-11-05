#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BinomialCoeff(int m, int n ){ ///Recursive Binomial Coefficient.cpp
    if (n==0 or n==m)
        return 1;
    return BinomialCoeff(m-1,n-1)+ BinomialCoeff(m-1,n);
}
int binomialCoeff(int m,int n ){///Memorized Binomial Coefficient.cpp   BUGGY
    int arr[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= min(i,n) ; j++) {
            if (j==0 || j==1)
                arr[i][j]=1;
            else
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];

        }
    }
    return arr[m][n];
}


int main() {
    cout<<BinomialCoeff(4,2)<<endl;
    cout<<binomialCoeff(4,2)<<endl;
    return 0;
}
