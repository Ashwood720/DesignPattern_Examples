#include <iostream>
#include <vector>

using namespace std;

class ToolComponent
{
public:
	virtual void GetInfo() = 0;
};

class CutToolComponent : public ToolComponent
{
public:
	void GetInfo() override
	{
		cout << "CutToolComponent" << endl;
	}
};

class WeldToolComponent : public ToolComponent
{
public:
	void GetInfo() override
	{
		cout << "WeldToolComponent" << endl;
	}
};

class Tool
{
public:
	virtual ToolComponent* AddToolComponent() = 0;
};

class CutTool : public Tool
{
public:
	ToolComponent* AddToolComponent() override
	{
		cout << "AngleGrinder" << endl;
		return new CutToolComponent();
	}
};

class WeldTool : public Tool
{
public:
	ToolComponent* AddToolComponent() override
	{
		cout << "MMA-Weld" << endl;
		return new WeldToolComponent();
	}
};

int main(int argv, char* argc[])
{
	Tool* tool = new CutTool();
	tool->AddToolComponent();

	tool = new WeldTool();
	tool->AddToolComponent();

	delete tool;
	tool = nullptr;

	return 0;
}