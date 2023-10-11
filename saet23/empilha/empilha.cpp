#include <bits/stdc++.h>
using namespace std;

int analize(int copos)
{
    long int aux = ((copos+1)*2)*4;
    double result = (sqrt(aux)-1)/2;
    return (int)result;    
}

int main()
{
    int numT =0;
    int copomax =0;
//    cin>>numT;
//    for(int i=0; i<numT;i++)
//    {
        cin>>copomax;
        cout<<analize(copomax)<<endl;
//    }
    return 0;

}
