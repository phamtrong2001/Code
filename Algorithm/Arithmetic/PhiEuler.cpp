#include <stdio.h>

#define long long long

long Power[230997][15]; // positive

long power(int a, int k){
    if (k==0) return 1;
    if (Power[a][k] > 0) return Power[a][k];
    long p=power(a, k/2);
    if (k&1) return Power[a][k] = p*p*a;
    else return Power[a][k] = p*p;
}

long phi(int p, int k){
    // phi of p^k with p is a prime
    if (k==0) return 1;
    return (p-1)*power(p, k-1);
}

long Phi[230997]; // positive

long phi(int m){
    int i, k, om=m;
    long r=1;

    if (Phi[om] > 0) return Phi[om];
    for (i=2; i*i<=m; i++){
        k=0;
        while (m%i==0) { k++; m/=i; }
        r *= phi(i, k);
    }
    if (m>1) r *= phi(m, 1);
    return Phi[om] = r;
}

int n;

main(){
    int i;
    long r=0;
for (;;){
    scanf("%d", &n);
    if (n==0) return 0;
    r = phi(n);
    printf("%lld\n", r);
}
}