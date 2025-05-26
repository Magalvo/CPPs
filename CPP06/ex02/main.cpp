#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	int i;

	std::srand(std::time(0));
	i = std::rand() % 3;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		putStr("A\n", CYAN);
	else if (dynamic_cast<B*>(p))
		putStr("B\n", CYAN);
	else if (dynamic_cast<C*>(p))
		putStr("C\n", CYAN);
}

void identify(Base& p)
{
	Base test;

	try {
		test = dynamic_cast<A&>(p);
		putStr("A\n", CYAN);
	} catch (std::exception &e) {}
	try {
		test = dynamic_cast<B&>(p);
		putStr("B\n", CYAN);
	} catch (std::exception &e) {}
	try {
		test = dynamic_cast<C&>(p);
		putStr("C\n", CYAN);
	} catch (std::exception &e) {}

}

int main() {
	Base *test;
	test = generate();
	identify(test);
	identify(*test);
	delete test;
}