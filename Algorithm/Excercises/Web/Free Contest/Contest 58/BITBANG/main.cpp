#include <bits/stdc++.h>

using namespace std;

bool die(string s)
{
	s += "0";
	int n = s.size();
	int l = ((n ^ (n-1)) + 1) / 2;
	int cnt = n / l;
	for (int i = 1; i < cnt; ++i) {
		for (int k = 0; k < l-1; ++k)
        {
			if (s[i*l+k] != s[i*l-2-k]) return false;
		}
		if (s[i*l-1] != '0') return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
    {
		string s;
		cin >> s;
		if (die(s)) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
