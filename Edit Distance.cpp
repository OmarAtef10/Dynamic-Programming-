#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int editDistance(char *x, char *y, int m, int n ){ ///Edit Distance Problem
    int ed[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <=n ; j++) {

            if (i==0)
                ed[i][j]=j;

            else if (j==0)
                ed[i][j]=i;

            else if (x[i-1]==y[j-1])
                ed[i][j]=ed[i-1][j-1];

            else
                ed[i][j]= 1 + min(min(ed[i][j-1],ed[i-1][j]),ed[i-1][j-1]);///Insert, Remove , Delete

        }
    }
    return ed[m][n];
}

int main() {
    char omar[]="CART";
    char lol[] = "MARCH";

    cout<<editDistance(omar,lol,strlen(omar), strlen(lol));
    return 0;
}
