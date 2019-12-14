#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point& operator-=(const Point& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}Point& operator*=(const Point& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}
	Point& operator/=(const Point& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}
	
	//			Methods:
	double distance_to(const Point& other)
	{
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	void print()
	{
		cout << this->get_x() << "\t" << this->get_y()<<endl;
	}

};
Point operator+(const Point& left, const Point& right)
{
	Point Temp;
	Temp.set_x(left.get_x() + right.get_x());
	Temp.set_y(left.get_y() + right.get_y());
	return Temp;
}
Point operator-(const Point& left, const Point& right)
{
	Point Temp;
	Temp.set_x(left.get_x() - right.get_x());
	Temp.set_y(left.get_y() - right.get_y());
	return Temp;
}
Point operator*(const Point& left, const Point& right)
{
	Point Temp;
	Temp.set_x(left.get_x() * right.get_x());
	Temp.set_y(left.get_y() * right.get_y());
	return Temp;
}
Point operator/(const Point& left, const Point& right)
{
	Point Temp;
	Temp.set_x(left.get_x() / right.get_x());
	Temp.set_y(left.get_y() / right.get_y());
	return Temp;
}

void main()
{
	setlocale(LC_ALL, "");
	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	cout << "/////////////////////" << endl;
	A += C;
	A.print();
}
