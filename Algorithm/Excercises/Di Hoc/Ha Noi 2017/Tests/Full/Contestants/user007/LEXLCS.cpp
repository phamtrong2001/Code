#include <bits/stdc++.h>
using namespace std;

// returns shortest supersequence of X and Y
string printShortestSuperSeq(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int index = dp[m][n];
    string str;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            str.push_back(X[i - 1]);
            i--, j--, index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            str.push_back(Y[j - 1]);
            j--, index--;
        }
        else
        {
            str.push_back(X[i - 1]);
            i--, index--;
        }
    }
    while (i > 0)
    {
        str.push_back(X[i - 1]);
        i--, index--;
    }
    while (j > 0)
    {
        str.push_back(Y[j - 1]);
        j--, index--;
    }

    reverse(str.begin(), str.end());
    return str;
}

string lcs( string X, string Y, int m, int n )
{
   int L[m+1][n+1];
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   int index = L[m][n];
   char lcs[index+1];
   lcs[index] = '\0';
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1];
          i--; j--; index--;
      }

      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }

   return lcs;
}

int main()
{
    freopen("LEXLCS.inp", "r", stdin);
    freopen("LEXLCS.out", "w", stdout);
    string X, Y;
    cin >> X >> Y;
    cout << max(lcs(X, Y, X.size(), Y.size()), lcs(Y, X, Y.size(), X.size())) << '\n';
    cout << min(printShortestSuperSeq(X, Y),printShortestSuperSeq(Y, X));

    return 0;
}
