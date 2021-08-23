#include <iostream>
using namespace std;

class ICalculator {
public:
	virtual void Plus(int x1, int y1) = 0;
	virtual void Minus() = 0;
	virtual void Mult() = 0;
	virtual void Divid() = 0;
	virtual void ShowResult() = 0;
};
////////////////////////////////////////////////////////////
class Calculator : public ICalculator {
protected:
	int x,y,Result;
public:
	virtual void Plus(int x1, int y1)override {
		x = x1;
		y = y1;
		Result = x + y;
	};
	virtual void Minus()override {};
	virtual void Mult() override {};
	virtual void Divid() override {};
	virtual void ShowResult()override {
		cout << Result;
	};
};
////////////////////////////////////////////////////////////
class HCalculator : public Calculator {
public:
	virtual void ShowResult()override {
		cout << "0x  "<<hex << Result;
	};	
};
//////////////////////////////////////////////////////////////
class BCalculator :public Calculator {
public:
	virtual void ShowResult()override {
		char Res[255]{ 0 };
		_itoa_s(Result, Res, 2);
		cout << Res;
	};
};

class ICar {
public:
	virtual void Drive() = 0;
};
class IBoat {
public:
	virtual void Swim() = 0;
};
class Amfib:public ICar, public IBoat{
public:
	// Унаследовано через ICar
	virtual void Drive() override{
		cout << "DRIVE\n";
	}

	// Унаследовано через IBoat
	virtual void Swim() override{
		cout << "Swim\n";
	}
};
class Weapon :public Amfib {
	Weapon(){}//
public: 
	static//
	void Fire() {
		cout << "Fire!!!\n";
	}
};

int main(){
	Amfib amp;
	amp.Drive();
	amp.Swim();
	/*
	Weapon war;
	war.Drive();
	war.Fire();
	war.Swim();*/

	Weapon::Fire();//<- для того, чтоб не создавать Weapon war;


	Calculator calc;
	calc.Plus(45, 23);
	calc.ShowResult();
	cout << endl << endl;

	HCalculator hexCalc;
	hexCalc.Plus(12, 20);
	hexCalc.ShowResult();
	cout << endl << endl;

	BCalculator itoaCalc;
	itoaCalc.Plus(0b10100, 0b100001);
	itoaCalc.ShowResult();
}
