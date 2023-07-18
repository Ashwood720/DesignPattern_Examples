#include "iostream"
#include "string"

using namespace std;

class Employee;

class Mediator
{
public:
	virtual void Notify(Employee* emp, string msg) = 0;
};

class Employee
{
public:
	Employee(Mediator* med = nullptr) : mediator(med){}
	void SetMediator(Mediator* med)
	{
		mediator = med;
	}
	virtual ~Employee(){}

protected:
	Mediator* mediator;
};

class Designer : public Employee
{
public:
	Designer(Mediator* med = nullptr) : Employee(med) {}
	void ExecuteWork()
	{
		cout << "<-Designer working" << endl;
		mediator->Notify(this, "Designer projecting...");
	}

	void SetWork(bool state)
	{
		isWorking = state;
		if (state == true) cout << "Designer free" << endl;
		if(state == false) cout << "Designer busy" << endl;
	}

private:
	bool isWorking;
};

class Director : public Employee
{
public:
	Director(Mediator* med = nullptr) : Employee(med) {}
	void GiveCommand(string txt)
	{
		text = txt;
		if (text.empty())
		{
			cout << "->Director known, that designer working" << endl;
		}
		else
		{
			cout << "->Director give the command" << text << endl;
		}
		mediator->Notify(this, text);
	}

private:
	string text;
};

class Controller : public Mediator
{
public:
	Controller(Designer* des, Director* dir)
	{
		designer = des;
		director = dir;
		designer->SetMediator(this);
		director->SetMediator(this);
	}

	void Notify(Employee* emp, string msg) override
	{
		if(auto dir = dynamic_cast<Director*>(emp))
		{
			if(msg.empty())
			{
				designer->SetWork(false);
			}
			else
			{
				designer->SetWork(true);
			}
		}
		if (auto des = dynamic_cast<Designer*>(emp))
		{
			if (msg == "Designer projecting...")
			{
				director->GiveCommand("");
			}
		}
	}

private:
	Designer* designer;
	Director* director;
};

int main()
{
	Designer* designer = new Designer();
	Director* director = new Director();

	Controller* Mediator = new Controller(designer, director);

	director->GiveCommand(" to project");

	cout << endl;
	designer->ExecuteWork();

	delete designer;
	delete director;
	delete Mediator;
}