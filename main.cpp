#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class Point{
	private:
		float x, y;
	
	public:
		Point(float, float);
		void set_x(float);
		void set_y(float);
		float get_x();
		float get_y();
		virtual void print();
};
Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
	cout << "konstruktor klasy Point" << endl;
	cout << "x: " << x << ", y: " << y << endl;
}
//modyfikatory
void Point::set_x(float x) {
	this->x = x;
};
void Point::set_y(float y) {
	this->y = y;
};
//akcesory
float Point::get_x(){
	return x;
}
float Point::get_y() {
	return y;
}
void Point::print() {
	cout << "X: " << x << ", Y: " << y;
}

class Point3d : public Point {
	private:
		float z;
	
	public:
		Point3d(float, float, float);
		void set_z(float);
		float get_z();
		void print();
};

Point3d::Point3d(float x, float y, float z) : Point(x, y) {
	this->z = z;
	cout << "konstruktor klasy Point3d" << endl;
	cout << "z: " << z << endl;
}

void Point3d::set_z(float z) {
	this->z = z;
}

float Point3d::get_z(){
	return z;
}

void Point3d::print(){
	Point::print();
	cout << ", Z: " << z << endl;
}

//ostream& operator << (ostream& os, Point& p) {
//	os << p.get_x() << ", " << p.get_y() << endl;
//	return os;
//}
//
//ostream& operator << (ostream& os, Point3d& p3) {
//	os << p3.get_x() << ", " << p3.get_y() << ", " << p3.get_z() << endl;
//	return os;
//}

ostream& operator << (ostream& os, Point& p) {
	p.print();
	return os;
}

int main(int argc, char** argv) {
	
	Point point = Point(5, 5);
	point.print();
	point.set_x(10);
	point.print();
	point.set_y(10);
	point.print();

	cout << "Test akcesora X: " << point.get_x() << endl;
	cout << "Test akcesora Y: " << point.get_y() << endl;

	cout << "--------------------------------" << endl;
	
	Point3d point3d = Point3d(1, 2, 3);
	point3d.get_x();
	point3d.get_y();
	
	cout << "--------------------------------" << endl;

	cout << "Test akcesora pola Z: " << point3d.get_z() << endl;

	cout << "--------------------------------" << endl;

	point3d.print();

	cout << "--------------------------------" << endl;

	Point* p = new Point3d(1, 2, 3);
	cout << "Print Point3d na wskazniku Point" << endl;
	p->print();
	cout << "--------------------------------" << endl;
	cout << "Przeciazony operator cout: " << *p << endl;
	cout << "--------------------------------" << endl;
	Point3d* p3 = new Point3d(1, 2, 3);
	cout << "Przeciazony operator cout dla Point3d: " << *p3;
	delete p;

	return 0;
}
