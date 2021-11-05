///Longest Increasing Sequence Dynamic programming
#include <iostream>
using namespace std;
int lis(int arr[] , int n ){
    int *lis,i,max=0;
    ///Initialize LIS with value of 1
    lis = (int*) malloc(sizeof (int)*n);
    for ( i = 0; i < n; i++) {
        lis[i]=1;
    }
    ///Updating LIS table with respect for the given array
    for (i = 1; i <n ; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i]>arr[j] && lis[i]< lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    ///Returning max number in LIS table
    for (i = 0;  i<n ; i++) {
        if (max< lis[i])
            max=lis[i];
    }
    ///Freeing LIS
    free(lis);
    return max;
}

int main() {
    int arr[5]={10,60,20,40,50};
    cout<<lis(arr,5)<<endl;
    return 0;
}
