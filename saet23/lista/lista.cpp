#include <bits/stdc++.h>
using namespace std;
// a b c d// e f g h //i j k l //m n o p// q r s t// u v w// x y z 

void ordena( vector<string> d,int max)
{
    vector<string> domingo;
    vector<string> segunda;
    vector<string> terca;
    vector<string> quarta;
    vector<string> quinta;
    vector<string> sexta;
    vector<string> sabado;

    for(int i =0; i<max;i++)
    {
        char ch=d[i][0];
        if((ch>=65&&ch<=68)||(ch>=97&&ch<=100))
        {
            domingo.push_back(d[i]);
        }
        if((ch>=69&&ch<=72)||(ch>=101&&ch<=104))
        {
            segunda.push_back(d[i]);
        }
        if((ch>=73&&ch<=76)||(ch>=105&&ch<=108))
        {
            terca.push_back(d[i]);

        }
        if((ch>=77&&ch<=80)||(ch>=109&&ch<=112))
        {
            quarta.push_back(d[i]);
        }
        if((ch>=81&&ch<=84)||(ch>=113&&ch<=116))
        {
            quinta.push_back(d[i]);
        }
        if((ch>=85&&ch<=87)||(ch>=117&&ch<=119))
        {
            sexta.push_back(d[i]);
        }
        if((ch>=88&&ch<=90)||(ch>=120&&ch<=122))
        {
            sabado.push_back(d[i]);
        }
    }
    for(int i =0 ; i<domingo.size();i++)
    {
        cout<<domingo[i]<<endl;
    }
    for(int i =0 ; i<segunda.size();i++)
    {
        cout<<segunda[i]<<endl;
    }
    for(int i =0 ; i<terca.size();i++)
    {
        cout<<terca[i]<<endl;
    }
    for(int i =0 ; i<quarta.size();i++)
    {
        cout<<quarta[i]<<endl;
    }
    for(int i =0 ; i<quinta.size();i++)
    {
        cout<<quinta[i]<<endl;
    }
    for(int i =0 ; i<sexta.size();i++)
    {
        cout<<sexta[i]<<endl;
    }
    for(int i =0 ; i<sabado.size();i++)
    {
        cout<<sabado[i]<<endl;
    }
}
int main()
{
    int quant;
    vector<string> vet;
    string temp;
    cin>>quant;
    for(int i =0 ;i<quant ;i++)
    {
        cin>>temp;
        vet.push_back(temp);
    }
   ordena(vet,quant);
}
