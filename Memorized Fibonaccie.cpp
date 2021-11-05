#include <iostream>
using namespace std;
#define MAX 100
#define NIL (-1)
long long lookup [MAX];
///Normal fibonacci
long long fibo(int n){
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else{
        return fibo(n-1)+ fibo(n-2);
    }

}

///Memorization stores already calculated results to avoid re-calculation
void initialize(){  ///Initializes an array full of NIL value (-1) MUST be called at the beginning of the program
    for (int i = 0; i < MAX; i++) {
        lookup[i]=NIL;
    }
}

long long fib(int n){
    if (lookup[n]==NIL){
        if (n<=1)
            lookup[n]=n;
        else
            lookup[n]= fib(n-1)+ fib(n-2);
    }
    return lookup[n];
}

long long tabulizedFib(int n) { ///Fibonacci but with tabulated solution
    long long fibo[n + 1];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    return fibo[n];
}

int main() {
    initialize();
    cout<<fib(69)<<endl;
    cout<<tabulizedFib(69)<<endl;
    //cout<<fibo(69);
    return 0;
}
