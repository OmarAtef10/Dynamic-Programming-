#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n,int k){///Space Optimized
    int C[k+1];
    memset(C,0,sizeof (C)); ///Initialize first elements with 0
    C[0]=1;
    for (int i = 1; i <=n ; i++) {

        for (int j = min(i,k); j >0 ; j--) {
            C[j]=C[j]+C[j-1];

        }
    }
    return C[k];

}

int main() {
    cout<<binomialCoeff(4,2);
    return 0;
}
