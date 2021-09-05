#include<iostream>
//#include<cmath>
#define _USE_MATH_DEFINES

//TASK 1
class Figure
{
	double a;
	double b;
public:
	Figure(double _a = 0., double _b = 0.) : a(_a), b(_b)
	{
	}

	virtual	void area() = 0;

	double get_a()
	{
		return a;
	}

	double get_b()
	{
		return b;
	}

	virtual ~Figure()
	{
	}
};

class Parallelogram : public Figure
{
	double h;

public:
	Parallelogram(double a, double b, double _h = 0.) : h(_h), Figure(a,b)
	{
	}

	void area() override
	{
		double a = get_a();
		std::cout<<"Parallelogram area: "<< a * h<<'\n';
	}

	double get_h()
	{
		return h;
	}
};

class Circle: public Figure
{
	double R;

public:
	Circle(double _R): R(_R)
	{
	}

	 void area() override
	{
		const double PI = std::atan(1.0) * 4;
		std::cout << "Circle area: " << PI * pow(R, 2)<<'\n';
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double a, double b): Parallelogram(a,b)
	{
	}

	void area() override
	{
		double a = get_a();
		double b = get_b();
		std::cout << "Rectangle area: " << a * b<<'\n';
	}
};

class Square : public Parallelogram
{
public:
	Square(double a):Parallelogram(a,a)
	{
	}

	void area() override
	{
		double a = get_a();
		std::cout << "Square area: " << a * a<<'\n';
	}
};
class Rhombus : public Parallelogram
{
public:
	Rhombus(double a,double b,double h):Parallelogram(a,b,h)
	{
	}

	void area() override
	{
		double a = get_a();
		double h = get_h();
		std::cout << "Rhombus area: " << a * h<<'\n';
	}
};

//TASK 2
class Car
{
public:
	std::string company;
	std::string model;

	Car(std::string com="",std::string mod=""): company(com),model(mod)
	{
		std::cout << "Class Car\n";
	}

};

class PassengerCar :virtual public Car
{
public:
	PassengerCar(std::string com,std::string mod): Car(com,mod)
	{
		std::cout << "Class PassengerCar: "<<company<<' '<<model<<'\n';
	}

};

class Bus :virtual public Car
{
public:
	Bus(std::string com,std::string mod): Car(com,mod)
	{
		std::cout << "Class Bus: " << company << ' ' << model << '\n';
	}

};

class Minivan : public PassengerCar, Bus
{
public:
	Minivan(std::string com, std::string mod) : PassengerCar(com, mod), Bus(com, mod), Car(com, mod)
	{
		std::cout << "Class Minivan: " << company << ' ' << model << '\n';
	}

};

//TASK 3
class Fraction
{
	int numerator;
	int denomenator;
};

int main()
{
	//Task 1
	{
		std::cout << "Task 1\n";
		Parallelogram p(3.,2.3,1.5);
		p.area();
		Circle c(3.5);
		c.area();
		Rectangle r(4.5, 3.);
		r.area();
		Square s(4.);
		s.area();
		Rhombus rhombus(4., 3., 2.);
		rhombus.area();
	}

	//Task 2
	{
		std::cout << "\n\nTask 2\n";
		Car c;
		std::cout << '\n';
		PassengerCar p("Ford", "Focus");
		std::cout << '\n';
		Bus b("Scania", "S500");
		std::cout << '\n';
		Minivan("Toyota", "Hiace");
	}
	
	//Task 3
	{
		std::cout << "\n\nTask 3\n";


	}

}

