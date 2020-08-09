#include <iostream>
using namespace std;

class Person
{
public:
	int age;
	Person(int age)
	{
		this->age = age;
	}

	Person& PersonAddAge(Person &p)
	{
		this->age += p.age;
		return *this;
	}
};

int main()
{
	Person p1(18);
	Person p2(18);

	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout <<"p1's age: "<< p1.age << endl;
	cout << "p2's age: " << p2.age << endl;

	system("pause");
	return 0;
}