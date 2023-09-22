#include <bits/stdc++.h>

using namespace std;

int n, na, nb;
int tema[1024], temb[1024];

int main() {

    scanf("%d", &n);
    scanf("%d", &na);
    memset(tema,0,sizeof(tema));
    while (na--) {
        int t;
        scanf("%d", &t);
        tema[t]++;
    }
    scanf("%d", &nb);
    memset(temb,0,sizeof(temb));
    while (nb--) {
        int t;
        scanf("%d", &t);
        temb[t]++;
    }

    bool ok= true;
    int deia=0, deib=0;
    for (int i=1;i<=n;i++)
        if (tema[i]==0 and temb[i]>1) {
            tema[i]++;
            temb[i]--;
            deib++;
        } else if (tema[i]==0) ok = false;
    for (int i=1;i<=n;i++)
        if (temb[i]==0 and tema[i]>1) {
            temb[i]++;
            tema[i]--;
            deia++;
        } else if (temb[i]==0) ok = false;


    if (deia > deib) {
        // A deu mais q B.
        int faltadar = deia-deib;
        // B tem q ter faltadar figurinhas redundantes
        int red=0;
        for (int i=1;i<=n;i++)
            if (temb[i]>1)
                red += (temb[i]-1);
        if (red < faltadar) ok=false;
    }
    if (deib > deia) {
        // B deu mais q A.
        int faltadar = deib-deia;
        // A tem q ter faltadar figurinhas redundantes
        int red=0;
        for (int i=1;i<=n;i++)
            if (tema[i]>1)
                red += (tema[i]-1);
        if (red < faltadar) ok=false;
    }

    if (!ok)
        printf("impossivel\n");
    else {
        printf("%d\n", max(deia,deib));
    }

    return 0;
}
