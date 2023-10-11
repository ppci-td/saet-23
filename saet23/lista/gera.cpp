#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s;
    srand(time(NULL)+clock());
    int y = 1 + (rand() % 10000);
    cout<< y<<endl;
    for (int j = 0; j < y; j++)
    {
        int x = 1 + (rand() % 20);
        for (int i = 0; i < x; i++)
        {
            s = rand() % 26 + 65 + rand() % 2 * 32;
            cout << s;
        }
        cout<<endl;
    }
}
