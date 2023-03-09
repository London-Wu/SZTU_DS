#include <iostream>
using namespace std;

// 月份表
const char* months[12] = {
	"January", "February", "March", "April", "May", "June",
	"July", "Aguest", "September", "October", "November", "December"
};

int main()
{
	int t;
	cin >> t;
	int inp;
	while(t--)
	{
		cin >> inp;
		if(inp>12) cout << "error" << endl;
		else cout << months[inp-1] << endl;
	}
	return 0;
}
