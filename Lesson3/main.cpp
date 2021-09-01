#include<iostream>

class Figure
{
public:
	Figure()
	{

	}

};

class Parallelogram : public Figure
{
public:
	Parallelogram()
	{

	}

	virtual	int area() = 0;

};

class Rectangle : public Parallelogram
{
public:
	Rectangle()
	{

	}
};

class Square : public Parallelogram
{
public:
	Square()
	{

	}
};
class Rhombus : public Parallelogram
{
public:
	Rhombus()
	{

	}
};

