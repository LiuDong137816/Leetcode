#include <iostream>
#include <string>

class Example
{
private:
	std::string m_Name = "Unknow";

public:
	Example()
	{
		std::cout << "Create Example Default" << std::endl;
	}

	Example(std::string name)
	{
		std::cout << "Create Example Member Instantiate" << std::endl;
	}
};

class Entity
{
public:
	Entity() = default;
	Entity(Example example)
		:e(example)
	{
		
	}
	const std::string& GetName() const { return m_Name; }

	void PrintType()const 
	{
		std::cout << "Entity" << std::endl;
	}

private:
	Example e;
	Entity* m_Parent;
	std::string m_Name = "123";
};

void Print(const Entity& e)
{
	e.PrintType();
}



struct Conversion
{
	operator float() { return 0.33; }
};

void main()
{
	Example e("uu");
	Entity entity(e);
	//std::string str = e.GetName();
	//std::cout << str << std::endl;
	/*const char* val = "123";
	std::cout << &val << std::endl;*/
	/*const int* p = new int;
	int a = 21;
	p = &a;
	std::cout << *p << std::endl;*/

	/*int x = 4;
	auto f = [=]() mutable
		{
			x++;
			std::cout << x << std::endl;
		};
	f();

	std::cout << x << std::endl;*/
	/*Entity *e = nullptr;
	e->PrintType();*/
	//std::cout << e->GetName();
	Conversion con;
	std::cout << float(con) << std::endl;
	std::cin.get();
}