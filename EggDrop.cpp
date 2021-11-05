#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int eggDrop(int n , int k){ /// Recursive
    if (k==1 or k==0){ ///Best Case
        return k;
    }
    if (n==1) ///Worst Case
        return k;
    int min= INT_MAX,x,res;

    for (x = 1; x <=k ; x++) {
        res= max(eggDrop(n-1,x-1), eggDrop(n,k-x));
        if (res<min)
            min=res;
    }
    return min+1;

}

int EggDrop(int n , int k){ ///Dynamic programing
    int floor [n+1][k+1];
    int res;
    for (int i = 1; i <= n; i++) { ///One trial for each floor
        floor[i][1]=1;
        floor[i][0]=0;
    }
    for (int j = 0; j <= k; j++) { ///J trails for each egg
        floor[1][j]=j;
    }
    for (int i = 2; i <= n ; i++) {
        for (int j = 2; j <=k ; j++) {
            floor[i][j]=INT_MAX;
            for (int x = 1; x <= j; x++) {
                res=1+ max(floor[i-1][x-1],floor[i][j-x]);
                if (res<floor[i][j])
                    floor[i][j]=res;
            }
        }
    }
    ///[n][k] holds the result
    return floor[n][k];
}

int main() {
    cout<<eggDrop(2,4)<<endl;
    cout<<EggDrop(2,4);

    return 0;
}
