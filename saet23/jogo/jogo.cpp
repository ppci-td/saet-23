#include <bits/stdc++.h>

using namespace std;

int main(){

    int numj = 0, patq = 0, pdef = 0;
    int def[100000], atq[100000];
    int d = 0,a = 0;
    int soma[2];
    int atqdef[2];

    cin >> numj;

    for(int i = 0; i < numj; i++){
        cin >> patq;
        cin >> pdef;

        if(pdef > patq)
            def[d++] = (patq + pdef);
        else
            atq[a++] = (patq + pdef);
    }

    sort(def, def + d);
    sort(atq, atq + a);
    d--;
    a--;

    for(int i = 0; i < (numj/2); i++){

            if(d == -1){
                soma[i%2 == 0] += atq[a--];
                soma[i%2 != 0] += atq[a--];
            }else if(a == -1){
                soma[i%2 == 0] += def[d--];
                soma[i%2 != 0] += def[d--];
            }else{

                if(atqdef[i%2 == 0] == 0){
                    if(def[d] > atq[a]){
                        soma[i%2 == 0] += def[d--];
                        atqdef[i%2 == 0]--;
                    }
                    else{
                        soma[i%2 == 0] += atq[a--];
                        atqdef[i%2 == 0]++;
                    }
                }else if(atqdef[i%2 == 0] == 1){
                    soma[i%2 == 0] += def[d--];
                    atqdef[i%2 == 0]--;
                }else{
                    soma[i%2 == 0] += atq[a--];
                    atqdef[i%2 == 0]++;
                }

                if(d == -1){
                    soma[i%2 != 0] += atq[a--];
                }else if(a == -1){
                    soma[i%2 != 0] += def[d--];
                }else if(atqdef[i%2 != 0] == 0){
                    if(def[d] > atq[a]){
                        soma[i%2 != 0] += def[d--];
                        atqdef[i%2 != 0]--;
                    }
                    else{
                        soma[i%2 != 0] += atq[a--];
                        atqdef[i%2 != 0]++;
                    }
                }else if(atqdef[i%2 != 0] == 1){
                    soma[i%2 != 0] += def[d--];
                    atqdef[i%2 != 0]--;
                }else{
                    soma[i%2 != 0] += atq[a--];
                    atqdef[i%2 != 0]++;
                }

            }


    }

    cout << fixed << setprecision(2);

    if(soma[0] > soma[1]) cout << (double(soma[0])/(numj/2)) << endl;
    else cout << (double(soma[1])/(numj/2)) << endl;

    return 0;
}
