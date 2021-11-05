#include <iostream>
#include <bits/stdc++.h>
using namespace std;

///Longest Common Sequence
int lcs( char *x,char *y, int m , int n ){ ///Two char arrays and their lengths as parameters
    int l[m+1][n+1];
    ///filling the array with the conditions
    for (int i = 0; i <=m; i++) {
        for (int j = 0; j <=n; j++) {
            if (i==0 || j==0)
                l[i][j]=0;

            else if(x[i-1]==y[j-1])
                l[i][j]=l[i-1][j-1]+1;

            else
                l[i][j]= max(l[i-1][j],l[i][j-1]);

        }
    }
    ///L[m][n] is the length of the LCS
    return l[m][n];
}

int main() {
    char omar[]="AGGTAB";
    char lol[] = "GXTXAYB";

    int m = strlen(omar);
    int n = strlen(lol);

    cout<<"Length of the Longest Common Sequence is: "<<lcs(omar,lol,m,n)<<endl;

    return 0;
}
