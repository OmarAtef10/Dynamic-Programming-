#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSequence(char *string1){ ///Dynamic Programing
    int n = strlen(string1);
    int arr[n][n];
    int x=0;
    for (int i = 0; i < n; i++) { ///Initializing an array
        arr[i][i]=1;
    }
    for (int d = 2; d <= n; d++) {
        for ( int i = 0; i < n - d + 1 ; i++) {
            x=i+d-1;
            if (string1[i]==string1[x] and x==2)
                arr[i][x]=2;
            else if (string1[i]==string1[x])
                arr[i][x]=arr[i+1][x-1]+2;
            else
                arr[i][x]= max(arr[i][x-1],arr[i+1][x]);
        }
    }

    return arr[0][n-1];
}

int main() {
    char *omar="BABCBAB";
    cout<<longestPalindromicSequence(omar);


    return 0;
}
