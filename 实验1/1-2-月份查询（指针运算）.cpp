#include <iostream>
using namespace std;

int main()
{
	int t, n, a;
	cin >> t;
	int scores[100];
	int *poi;
	
	while(t--)
	{
		cin >> n;		
		for(int i=0; i<n; i++)
		{
			cin >> scores[i];
		}
		poi = scores+n/2;
		poi--;
		cout << *poi << ' ';
		poi++; poi++;
		cout << *poi << endl;
		poi--;
		cin >> a;
		cout << *(poi + a-1-n/2) << endl;
		
	}
	
	return 0;
}
