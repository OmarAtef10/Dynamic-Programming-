#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapSack(int w,int wT[],int val[],int n){ ///Recursive KnapSack
    if (n==0 or w==0) ///Best Case
        return 0;
    if (wT[n-1]>w)
        return knapSack(w,wT,val,n-1);
    else
        return max(val[n-1]+ knapSack(w-wT[n-1],wT,val,n-1), knapSack(w,wT,val,n-1));

}

int KnapSack(int w,int wT[],int val[],int n) { ///Dynamic KnapSack
    int k[n+1][w+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i==0||j==0)
                k[i][j]=0;
            else if (wT[i-1]<=j)
                k[i][j]= max(val[i-1]+k[i-1][j-wT[i-1]],k[i-1][j]);
            else
                k[i][j]=k[i-1][j];
        }
    }
    return k[n][w];
}

int main() {
    int val[]={60,100,120};
    int weight[]={10,20,30};
    int w=50;
    cout<<knapSack(w,weight,val,3)<<endl;
    cout<<KnapSack(w,weight,val,3);



    return 0;
}
