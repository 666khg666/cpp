#include <iostream>

class base
{
	public:
		virtual void print() const { std::cout << "base" << std::endl; }
};

class derived : public base
{
	public:
		virtual void print() const { base::print(); std::cout << "+Derived!" << std::endl; }
};

void func1(base obj)
{
	obj.print();
}

void func2(const base& obj)
{
	obj.print();
}


int main()
{
	derived d;
	
	func1(d); // calls print() function of base class
	func2(d); // calls print() function of derived class

	return 0;
}
