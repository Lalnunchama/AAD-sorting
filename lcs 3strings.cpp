// C++ program to find LCS of three strings
#include<bits/stdc++.h>
using namespace std;
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1]
   and Z[0..o-1] */
int lcsOf3( string X, string Y, string Z, int m,
                               int n, int o)
{
    int L[m+1][n+1][o+1];
 
    /* Following steps build L[m+1][n+1][o+1] in
       bottom up fashion. Note that L[i][j][k]
       contains length of LCS of X[0..i-1] and
       Y[0..j-1]  and Z[0.....k-1]*/
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            for (int k=0; k<=o; k++)
            {
                if (i == 0 || j == 0||k==0)
                    L[i][j][k] = 0;
 
                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
 
                else
                    L[i][j][k] = max(max(L[i-1][j][k],
                                         L[i][j-1][k]),
                                     L[i][j][k-1]);
            }
        }
    }
 
    /* L[m][n][o] contains length of LCS for
      X[0..n-1] and Y[0..m-1] and Z[0..o-1]*/
    int k= L[m][n][o];
	
	int r = m;
	int	s = n;
	int t= o;
	int i = L[r][s][o];

	char LCS[i+1];

	LCS[i] = '\0';

	while(r > 0 && s > 0&& t> 0) {

		if(X[r - 1] == Y[s - 1]&&Y[s - 1]==Z[t-1]) {

			LCS[i - 1] = X[r - 1];

			i--;
			r--;
			s--;
			t--;

		} else if(L[r - 1][s][t] > L[r][s - 1][t]|| L[r - 1][s][t] > L[r][s][t-1]) {

			r--;

		} else if(L[r ][s-1][t] > L[r-1][s ][t]|| L[r ][s-1][t] > L[r][s][t-1]) {

			s--;

		}
		else 
		t--;

	}
	cout<<"("<<LCS<<")"<<endl;
			 
return k;		 
		
}
 
/* Driver program to test above function */
int main()
{
    string X = "666222054263314443712";
    string Y = "5432127413542377777";
    string Z = "6664664565464057425";
 
    int m = X.length();
    int n = Y.length();
    int o = Z.length();
 
    cout << "Length of LCS is " << lcsOf3(X, Y,
                                    Z, m, n, o);
 
    return 0;
}
