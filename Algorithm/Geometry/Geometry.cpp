struct toado
{
    int x, y, id;
};
pii Vect(toado p, toado q)
{
    return mp(q.x - p.x, q.y - p.y);
}

long long CCW(toado p, toado q, toado r)
{
    pii u = Vect(p,q);
    pii v = Vect(q,r);
    return (1ll * u.F * v.S - 1ll * u.S * v.F);
}

void Make_convex(toado a[], int n, toado b[], int &m)
{
    sort (a+1, a+n+1, comp);
    b[m=1] = a[1];
    for (int i = 2; i <= n; i++){
        while (m > 1 && CCW(b[m-1], b[m], a[i]) <= 0) m--;
        b[++m] = a[i];
    }
    int chot = m;
    for (int i = n-1; i >= 1; i--){
        while (m > chot && CCW(b[m-1], b[m], a[i]) <= 0) m--;
        b[++m] = a[i];
    }
    m--;
}
double KC( toado p, toado q)
{
    long long hx = p.x - q.x;
    long long hy = p.y - q.y;
    return sqrt(hx*hx + hy*hy);
}
double Area()
{
	p[n+1] = p[1];
	double S = 0;
	for (int i = 1; i <= n; i++)
		S += (p[i].x - p[i+1].x)*(p[i].y + p[i+1].y);
	return abs(S)/2;
}