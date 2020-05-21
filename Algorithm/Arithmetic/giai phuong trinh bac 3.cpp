#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define float long double

float a, b, c, d;
vector<float> Result;

float h(float x)
    { return a*x*x*x + b*x*x + c*x + d; }
int sign(float x)
    { if (fabs(x)<=1e-9) return 0; return x>0 ? 1 : -1; }
void decide(float x)
    { Result.push_back(x); }

bool solve(float a, float b, float c, float &x1, float &x2) {
    if (sign(a)==0) {
        if (sign(b)==0) return false;
        x1=x2=-c/b; return true;
    }
    float d = b*b-4*a*c;
    if (sign(d)==0) {
        x1 = x2 = -b/(2*a);
        return true;
    } else if (sign(d)>0) {
        x1 = (-b-sqrt(d))/(2*a);
        x2 = (-b+sqrt(d))/(2*a);
        if (x1>x2) swap(x1, x2);
        return true;
    }
    return false;    
}

void search1(float ll, float rr) {
    if (::isinf(ll)) {
        ll=rr-100;
        while (sign(h(ll))>0) ll-=(rr-ll);
    }
    if (::isinf(rr)) {
        rr=ll+100;
        while (sign(h(rr))<0) rr+=(rr-ll);
    }
    //printf("search1(%Lg, %Lg)\n", ll, rr);
    if (sign(h(ll))==0) return decide(ll);
    if (sign(h(rr))==0) return decide(rr);
    if (sign(h(ll))>0 || sign(h(rr))<0) return;
    
    float mm=(ll+rr)/2;
    for (int i=1; i<=100; i++) {
        h(mm)>0 ? rr=mm : ll=mm;
        mm=(ll+rr)/2;
    }
    return decide(mm);
}

void search2(float ll, float rr) {
    //printf("search2(%g, %g)\n", ll, rr);
    if (sign(h(ll))==0) return decide(ll);
    if (sign(h(rr))==0) return decide(rr);
    if (sign(h(ll))<0 || sign(h(rr))>0) return;
    
    float mm=(ll+rr)/2;
    for (int i=1; i<=100; i++) {
        h(mm)<0 ? rr=mm : ll=mm;
        mm=(ll+rr)/2;
    }
    return decide(mm);
}

main () {
    while (cin >> a >> b >> c >> d) {
        if (sign(a)==0) {
            float x1, x2;
            if (solve(b, c, d, x1, x2))
            { decide(x1); decide(x2); }
        } else {
            if (a<0) { a=-a, b=-b, c=-c, d=-d; }
            float x1, x2;
            if (solve(3*a, 2*b, c, x1, x2)) {
                search1(-1.0/0.0, x1);
                search2(x1, x2);
                search1(x2, +1.0/0.0);
            } else {
                search1(-1.0/0.0, 0);
                search1(0, +1.0/0.0);
            }
        }
        sort(Result.begin(), Result.end());
        Result.erase(unique(Result.begin(), Result.end()), Result.end());
        cout.precision(6);
        for (float x: Result) 
        cout << (fabs(x)<=1e-15 ? 0.0 : x) << endl;
        Result.clear();
    }
}