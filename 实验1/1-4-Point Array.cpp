#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point
{
private:
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	~Point();
	Point(const Point& p);
	double getX();
	double getY();
	void setXY(double x1, double y1){x=x1; y=y1;}
	void setX(double x_value);
	void setY(double y_value);
	double getDisTo(Point &p);
};

Point::Point():x(0), y(0){ cout << "Constructor." << endl; }
Point::Point(double x_value, double y_value):x(x_value), y(y_value)
{ cout << "Constructor." << endl; }
Point::Point(const Point &p){x=p.x; y=p.y; cout << "Constructor." << endl;}
Point::~Point(){ cout << "Distructor." << endl;}
double Point::getX(){ return x;}
double Point::getY(){ return y;}
void Point::setX(double x_value) { x=x_value;}
void Point::setY(double y_value) { y=y_value;}
double Point::getDisTo(Point &p)
{
	return sqrt(pow(x-p.x, 2)+pow(y-p.y, 2));
}

int main()
{
	int t;
	cin >> t;
	int n;
	Point *ps;
	int x, y;
	double maxDis;
	int maxIndex1, maxIndex2;
	double dis;
	while(t--)
	{
		cin >> n;
		ps = new Point[n];
		for(int i=0;i<n;i++)
		{
			cin >> x;
			cin >> y;
			ps[i].setXY(x, y);
		}
		
		maxDis = 0;
		maxIndex1 = 0;
		maxIndex2 = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				dis = ps[i].getDisTo(ps[j]);
				if(dis > maxDis)
				{
					maxDis = dis;
					maxIndex1 = i;
					maxIndex2 = j;
				}
			}
		}
		
		cout << "The longeset distance is " << fixed << setprecision(2) << maxDis<<\
		",between p[" << maxIndex1 << "] and p[" << maxIndex2 << "]." << endl;
		
		delete[] ps;
	}
}
