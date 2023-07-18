#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class ICommand
{
public:
	virtual void Positive() = 0;
	virtual void Negative() = 0;
};

class Conveyor
{
public:
	void On()
	{
		cout << "Conveyor activited" << endl;
	}
	void Off()
	{
		cout << "Conveyor deactivited" << endl;
	}
	void SpeedIncrease()
	{
		cout << "Conveyor speedup" << endl;
	}
	void SpeedDecrease()
	{
		cout << "Conveyor speeddown" << endl;
	}
};

class ConveyorWorkCommand : public ICommand
{
public:
	ConveyorWorkCommand(Conveyor* _conveyor) : conveyor(_conveyor) {}
	void Positive() override
	{
		conveyor->On();
	}
	void Negative() override
	{
		conveyor->Off();
	}

private:
	Conveyor* conveyor;
};

class ConveyorAdjustCommand : public ICommand
{
public:
	ConveyorAdjustCommand(Conveyor* _conveyor) : conveyor(_conveyor) {}
	void Positive() override
	{
		conveyor->SpeedIncrease();
	}
	void Negative() override
	{
		conveyor->SpeedDecrease();
	}

private:
	Conveyor* conveyor;
};

class Multipult
{
public:
	Multipult()
	{
		commands.resize(2);
	}
	void SetCommand(int Button, ICommand* Command)
	{
		commands[Button] = Command;
	}
	void PressOn(int Button)
	{
		commands[Button]->Positive();
		history.push(commands[Button]);
	}
	void PressCancel()
	{
		if (!history.empty())
		{
			history.top()->Negative();
			history.pop();
		}
	}

private:
	vector<ICommand*> commands;
	stack<ICommand*> history;
};

int main()
{
	Conveyor* conveyor = new Conveyor();

	Multipult* multipult = new Multipult();
	multipult->SetCommand(0, new ConveyorWorkCommand(conveyor));
	multipult->SetCommand(1, new ConveyorAdjustCommand(conveyor));

	multipult->PressOn(0);
	multipult->PressOn(1);
	multipult->PressOn(1);
	multipult->PressCancel();
	multipult->PressCancel();
	multipult->PressCancel();
}