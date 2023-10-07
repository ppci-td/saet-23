#include <bits/stdc++.h>

using namespace std;

int main( )
{
    int n;
    double a, b, c, area, perim, raio;

    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        perim = (a+b+c)/2;
        area = sqrt(perim * (perim - a) * (perim - b) * (perim - c));
        raio = area/perim;
        cout << fixed << setprecision(2) << raio << endl;
        }

    return 0;
}
