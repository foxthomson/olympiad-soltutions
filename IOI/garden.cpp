#include <iostream>

using namespace std;

int powers[1000000];
int sign[1000000];

int main(int argc, char **argv)
{
	int n, m;
	cin >> n >> m;
	
	powers[0] = 1;
	for (int i = 1; i < n; i++)
	{
		powers[i] = (2*powers[i-1]) % m;
	}
	
	int height = 0;
	bool up = false;
	bool down = false;
	for (int i = 0; i < n; i++)
	{
		char inp;
		cin >> inp;
		if (inp == 'P')
		{
			height--;
			if (height == -2) up = true;
		}
		else
		{
			height++;
			if (height == +2) down = true;
		}
		sign[i] = height;
	}
	
	
	
	if (up)
		for (int i = 0; i < n; i++) sign[i]++; 

	if (down)
		for (int i = 0; i < n; i++) sign[i]--;
		
	
	int ans = 0;
	if (down)
	{
		 for (int i = 1; i < n; i+=2)
		 {
			 ans <<= 1;
			 ans += (sign[i]==-1 ? 1 :0);
			 ans %= m;
		 }
		 ans++;
		 ans %= m;
	}
	if (!up && !down)
	{
		 for (int i = 0; i < n; i+=2)
		 {
			 ans <<= 1;
			 ans += (sign[i]==-1 ? 1 :0);
			 ans %= m;
		 }
		 ans += powers[n/2];
		 ans %= m;
	}
	if (up)
	{
		 for (int i = 1; i < n; i+=2)
		 {
			 ans <<= 1;
			 ans += (sign[i]==-1 ? 1 :0);
			 ans %= m;
		 }
		 ans += powers[n/2]-1;
		 ans %= m;
		 ans += powers[(n+1)/2];
		 ans %= m;
	}
	cout << ans << endl;

	return 0;
}

