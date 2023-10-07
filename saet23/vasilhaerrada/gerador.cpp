#include <bits/stdc++.h>

using namespace std;

bool existe(double a, double b, double c){
    if(a >= b + c)
        return false;
    if(b >= a + c)
        return false;
    if(c >= a + b)
        return false;
    return true;
}

int main( )
{
    srand(time(NULL) + clock());
    double L1, L2, L3;

    int n = 1000 - rand()%1000;

    cout << n <<endl;

    while(n--){
        do{
            L1 = (double)rand()/100.0;
            L2 = (double)rand()/100.0;
            L3 = (double)rand()/100.0;
        }
        while(!existe(L1, L2, L3));

        cout << L1 <<" "<< L2 <<" "<< L3 << endl;

        }

    return 0;
}

