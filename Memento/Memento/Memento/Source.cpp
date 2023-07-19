#include "iostream"
#include "string"
#include "stack"

using namespace std;

class Memento 
{
public:
	virtual int GetDollars() = 0;
	virtual int GetEuro() = 0;
	virtual ~Memento(){}
};

class ExchangeMemento : public Memento
{
public:
	ExchangeMemento(int d, int e) : dollars(d), euro(e) {}
	int GetDollars() override
	{
		return dollars;
	}
	int GetEuro() override
	{
		return euro;
	}

private:
	int dollars;
	int euro;
};

class Exchange
{
public:
	Exchange(int d, int e) : dollars(d), euro(e) {}
	void GetDollars()
	{
		cout << "Dollar: " << dollars << endl;
	}
	void GetEuro()
	{
		cout << "Euro: " << euro << endl;
	}
	void Sell()
	{
		dollars ? --dollars : 0;
	}

	void Buy()
	{
		++euro;
	}

	ExchangeMemento* Save()
	{
		return new ExchangeMemento(dollars, euro);
	}

	void Restore(Memento* exchargeMemento)
	{
		dollars = exchargeMemento->GetDollars();
		euro = exchargeMemento->GetEuro();

		delete exchargeMemento;
	}

private:
	int dollars;
	int euro;
};

class Memory
{
public:
	Memory(Exchange* ex) : exchange(ex){}
	void BackUp()
	{
		history.push(exchange->Save());
	}

	void Undo()
	{
		if (history.empty()) return;

		exchange->Restore(history.top());
		history.pop();
	}

private:
	stack<Memento*> history;
	Exchange* exchange;
};

int main()
{
	Exchange* exchange = new Exchange(10, 10);

	Memory* memory = new Memory(exchange);

	exchange->GetDollars();
	exchange->GetEuro();

	cout << "... Sell dollar, buy euro ..." << endl;

	exchange->Sell();
	exchange->Buy();

	cout << "... Save state ..." << endl;

	memory->BackUp();

	cout << "... Sell dollar, buy euro ..." << endl;

	exchange->Sell();
	exchange->Buy();

	exchange->GetDollars();
	exchange->GetEuro();

	cout << "... Ressurect state ..." << endl;
	memory->Undo();

	exchange->GetDollars();
	exchange->GetEuro();
}