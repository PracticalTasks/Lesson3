#include<iostream>

enum CardSuit
{
	clubs,
	spades,
	heart,
	diamonds
};

enum CardValue
{
	six = 6, seven, eight,
	nine, ten, jack = 2,
	lady, king, ace = 1
};

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
	int whole;
	int numerator;
	int denomenator;

	int commonDen(int denL, int denB)
	{
		int volL{ 1 }, volB{ 1 };
		int tDenL{ denL }, tDenB{ denB };
		while (true)
		{
			volL++;
			tDenL = denL * volL;
			if (tDenL < tDenB)
				continue;
			else if (tDenL > tDenB)
			{
				volB++;
				tDenB = denB * volB;
				if (tDenL == tDenB)
					return tDenL;
			}
			else
				return tDenL;
		}
	}

	int greatestCommonDivisor(int a, int b) {
		if (a % b == 0)
			return b;
		if (b % a == 0)
			return a;
		if (a > b)
			return greatestCommonDivisor(a % b, b);
		return greatestCommonDivisor(a, b % a);
	}

public:
	Fraction(int _whole, int num, int den) :whole(_whole), numerator(num), denomenator(den)
	{
	} 

	void get()
	{
		std::cout<<"Whole: "<<whole<< " Numerator: " << numerator << " Denomenator: " << denomenator << '\n';
	}

	Fraction* operator+(Fraction& obj)
	{
		int commDen{};
		int tNum{ obj.whole * obj.denomenator + obj.numerator };
		numerator = whole * denomenator + numerator;
		whole = 0;
		if (denomenator < obj.denomenator)
		{
			commDen = commonDen(denomenator, obj.denomenator);
			numerator *= (commDen / denomenator);
			denomenator = commDen;

			tNum *= (commDen / obj.denomenator);
		}
		else if (denomenator > obj.denomenator)
		{
			commDen = commonDen(obj.denomenator, denomenator);
			tNum *= (commDen / obj.denomenator);
			
			numerator *= (commDen / denomenator);
			denomenator = commDen;
		}
	
		numerator += tNum;
		while (denomenator <= numerator)
		{
			numerator -= denomenator;
			whole++;
		}

		int CommDiv{ greatestCommonDivisor(numerator,denomenator)};
		numerator /= CommDiv;
		denomenator /= CommDiv;

		if (numerator == 0)
			denomenator = 0;

		return this;
	}

	Fraction* operator-(Fraction& obj)
	{
		int commDen{};
		int tNum{ obj.whole* obj.denomenator + obj.numerator };
		numerator = whole * denomenator + numerator;
		whole = 0;
		if (denomenator < obj.denomenator)
		{
			commDen = commonDen(denomenator, obj.denomenator);
			numerator *= (commDen / denomenator);
			denomenator = commDen;

			tNum *= (commDen / obj.denomenator);
		}
		else if (denomenator > obj.denomenator)
		{
			commDen = commonDen(obj.denomenator, denomenator);
			tNum *= (commDen / obj.denomenator);

			numerator *= (commDen / denomenator);
			denomenator = commDen;
		}

		numerator -= tNum;
		while (denomenator <= numerator)
		{
			numerator -= denomenator;
			whole++;
		}

		int CommDiv{ greatestCommonDivisor(numerator,denomenator) };
		numerator /= CommDiv;
		denomenator /= CommDiv;

		if (numerator == 0)
			denomenator = 0;

		return this;
	}

	Fraction* operator*(Fraction& obj)
	{
		int commDen{};
		int tNum{ obj.whole * obj.denomenator + obj.numerator }, tDen{ obj.denomenator };
		numerator = whole * denomenator + numerator;
		whole = 0;

		numerator *= tNum;
		denomenator *= tDen;
		while (denomenator <= numerator)
		{
			numerator -= denomenator;
			whole++;
		}

		int CommDiv{ greatestCommonDivisor(numerator,denomenator) };
		numerator /= CommDiv;
		denomenator /= CommDiv;

		if (numerator == 0)
			denomenator = 0;

		return this;
	}

	Fraction* operator/(Fraction& obj)
	{
		int commDen{};
		int tNum{ obj.whole * obj.denomenator + obj.numerator }, tDen{ obj.denomenator };
		numerator = whole * denomenator + numerator;
		whole = 0;

		numerator *= tDen;
		denomenator *= tNum;
		while (denomenator <= numerator)
		{
			numerator -= denomenator;
			whole++;
		}

		int CommDiv{ greatestCommonDivisor(numerator,denomenator) };
		numerator /= CommDiv;
		denomenator /= CommDiv;

		if (numerator == 0)
			denomenator = 0;

		return this;
	}
 
	Fraction* operator-()
	{
		whole = -whole;
		return this;
	}

	bool operator==(Fraction& obj)
	{
		if (denomenator == obj.denomenator)
		{
			if (numerator == obj.numerator)
				return true;
			else
				return false;
		}

		int commDen{};
		int tNum{ obj.whole * obj.denomenator + obj.numerator };
		numerator = whole * denomenator + numerator;
		whole = 0;
		if (denomenator < obj.denomenator)
		{
			commDen = commonDen(denomenator, obj.denomenator);
			numerator *= (commDen / denomenator);
			denomenator = commDen;

			tNum *= (commDen / obj.denomenator);
		}
		else if (denomenator > obj.denomenator)
		{
			commDen = commonDen(obj.denomenator, denomenator);
			tNum *= (commDen / obj.denomenator);

			numerator *= (commDen / denomenator);
			denomenator = commDen;
		}

		if (numerator == obj.numerator)
			return true;
		else
			return false;

	}

	bool operator!=(Fraction& obj)
	{
		if (*this == obj)
			return false;
		else
			return true;
	}

	bool operator<(Fraction& obj)
	{
		{
			if (numerator < obj.numerator)
				return true;
			else
				return false;
		}

		int commDen{};
		int tNum{ obj.whole * obj.denomenator + obj.numerator };
		numerator = whole * denomenator + numerator;
		whole = 0;
		if (denomenator < obj.denomenator)
		{
			commDen = commonDen(denomenator, obj.denomenator);
			numerator *= (commDen / denomenator);
			denomenator = commDen;

			tNum *= (commDen / obj.denomenator);
		}
		else if (denomenator > obj.denomenator)
		{
			commDen = commonDen(obj.denomenator, denomenator);
			tNum *= (commDen / obj.denomenator);

			numerator *= (commDen / denomenator);
			denomenator = commDen;
		}

		if (numerator < obj.numerator)
			return true;
		else
			return false;
	}

	bool operator>(Fraction& obj)
	{
		if (denomenator == obj.denomenator)
		{
			if (numerator > obj.numerator)
				return true;
			else
				return false;
		}

		int commDen{};
		int tNum{ obj.whole * obj.denomenator + obj.numerator };
		numerator = whole * denomenator + numerator;
		whole = 0;
		if (denomenator < obj.denomenator)
		{
			commDen = commonDen(denomenator, obj.denomenator);
			numerator *= (commDen / denomenator);
			denomenator = commDen;

			tNum *= (commDen / obj.denomenator);
		}
		else if (denomenator > obj.denomenator)
		{
			commDen = commonDen(obj.denomenator, denomenator);
			tNum *= (commDen / obj.denomenator);

			numerator *= (commDen / denomenator);
			denomenator = commDen;
		}

		if (numerator > obj.numerator)
			return true;
		else
			return false;
	}

	bool operator<=(Fraction& obj)
	{
		if (*this > obj)
			return false;
		else
			return true;
	}

	bool operator>=(Fraction& obj)
	{
		if (*this < obj)
			return false;
		else
			return true;
	}
};

//TASK 4
class Card
{
	CardSuit suit;
	CardValue value;
	bool position;
public:
	void Flip()
	{
		if (position)
			position = false;
		else
			position = true;
	}

	int GetValue()
	{
		return value;
	}

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
		Fraction a(1, 9, 12);
		Fraction b(1, 4, 7);

		if (a != b)
			std::cout << "true\n";
		else
			std::cout << "false\n";

		if (a <= b)
			std::cout << "true\n";
		else
			std::cout << "false\n";

		a+b;
		a.get();
		a/b;
		a.get();
		-a;
		a.get();

	}

	//Task 4
	{
		std::cout << "\n\nTask 4\n";
	}
}

