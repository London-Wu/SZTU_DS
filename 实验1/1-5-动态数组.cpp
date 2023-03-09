#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int *ipoi;
	char *cpoi;
	float *fpoi;
	char type;
	int n;
	while(t--)
	{
		cin >> type >> n;
		if(type == 'I')
		{
			ipoi = new int(n);
			int sum = 0;
			for(int i=0;i<n;i++)
			{
				cin >> *(ipoi+i);
				sum += *(ipoi+i);
			}
			cout << sum/n << endl;
			delete[] ipoi;
		}
		else if(type == 'C')
		{
			cpoi = new char(n);
			char maxc = 0;
			for(int i=0;i<n;i++)
			{
				cin >> *(cpoi+i);
				if(*(cpoi+i)>maxc)
				{
					maxc = *(cpoi+i);
				}
			}
			cout << maxc << endl;
			delete[] cpoi;
		}
		else if(type == 'F')
		{
			fpoi = new float(n);
			for(int i=0;i<n;i++)
			{
				cin >> *(fpoi+i);
			}
			float minn = *fpoi;
			for(int i=0;i<n;i++)
			{
				if(*(fpoi+i)<minn)
				{
					minn = *(fpoi+i);
				}
			}
			cout << minn << endl;
			delete[] fpoi;
		}
	}
	
	return 0;
}
