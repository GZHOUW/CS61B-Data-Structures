#include <iostream>
using namespace std;

template <typename T>
class Base {
public:
	virtual void print1(T x) = 0;

	void print2(T x) {
		cout << x << endl;
		cout << x << endl;
	}
};

template <typename T>
class Derived : public Base<T> {
public:
	void print1(T x) override {
		cout << x << endl;
	}
};
