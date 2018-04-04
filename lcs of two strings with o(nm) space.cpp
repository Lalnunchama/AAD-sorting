
#include<iostream>
using namespace std;
#include<string.h>
int max(int a,int b);
int lcs(char *,char *,int,int);

main(){
	
	char h[100],a[100];
	cout<<"Enter your two input:";
	cin>>h;
	cin>>a;
		int m,n;
		m=strlen(h);
	n=strlen(a);
	cout<<lcs(h,a,m,n);
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
int lcs(char *a,char *b,int m,int n){

	int c[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if (i == 0 || j == 0)
         c[i][j] = 0;		
			else if(a[i-1]==b[j-1])
			c[i][j] = c[i-1][j-1] + 1;
			else
			 c[i][j] = max(c[i-1][j], c[i][j-1]);
		}
	}
	int k=c[m][n];	
	int r = m;
	int	s = n;
	int i = c[r][s];
	char LCS[i+1];
	LCS[i] = '\0';
	while(r > 0 && s > 0) {
		if(a[r - 1] == b[s - 1]) {
			LCS[i - 1] = a[r - 1];
			i--;
			r--;
			s--;

		} else if(c[r - 1][s] > c[r][s - 1]) {
			r--;
		} else {
			s--;
		}

	}
	cout<<"("<<LCS<<")"<<endl;
			 
return k;		 
			
	
}

