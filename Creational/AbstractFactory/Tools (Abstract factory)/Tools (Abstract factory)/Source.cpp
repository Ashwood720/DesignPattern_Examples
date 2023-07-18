#include <iostream>
#include <vector>
#include <memory>

using namespace std;



class ToolComponent
{
public:
	virtual void GetInfo() = 0;
	ToolComponent()
	{
		cout << "Call ToolComponent Constructor" << endl;
	}
	virtual ~ToolComponent()
	{
		cout << "Call ToolComponent Destructor" << endl;
	}
};

class CutToolComponent : public ToolComponent
{
public:
	void GetInfo() override
	{
		cout << "CutToolComponent" << endl;
	}
	CutToolComponent()
	{
		cout << "Call CutToolComponent Constructor" << endl;
	}
	~CutToolComponent() override
	{
		cout << "Call CutToolComponent Destructor" << endl;
	}
};

class WeldToolComponent : public ToolComponent
{
public:
	WeldToolComponent()
	{
		cout << "Call WeldToolComponent Constructor" << endl;
	}
	void GetInfo() override
	{
		cout << "WeldToolComponent" << endl;
	}
	~WeldToolComponent() override
	{
		cout << "Call WeldToolComponent Destructor" << endl;
	}
};

class Tool
{
public:
	Tool()
	{
		cout << "Call Tool Constructor" << endl;
	}

	virtual ToolComponent* AddCutToolComponent() = 0;
	virtual ToolComponent* AddWeldToolComponent() = 0;

	virtual ~Tool()
	{
		cout << "Call Tool Destructor" << endl;
	}
	ToolComponent* toolComponent;
};

class HandTool : public Tool
{
public:
	HandTool()
	{
		cout << "Call HandTool Constructor" << endl;
	}
	ToolComponent* AddCutToolComponent() override
	{
		cout << "This must be a Drill or AngleGrinder" << endl;
		toolComponent = new CutToolComponent();
		return toolComponent;
	}
	ToolComponent* AddWeldToolComponent() override
	{
		cout << "This must be a MMA-Welder" << endl;
		toolComponent = new WeldToolComponent();
		return toolComponent;
	}
	~HandTool() override
	{
		cout << "Call HandTool Destructor" << endl;
	}

};

class MachineTool : public Tool
{
public:
	MachineTool()
	{
		cout << "Call MachineTool Constructor" << endl;
	}
	ToolComponent* AddCutToolComponent() override
	{
		cout << "This must be a lathe" << endl;
		toolComponent = new CutToolComponent();
		return toolComponent;
	}
	ToolComponent* AddWeldToolComponent() override
	{
		cout << "This must be a MIG-Welder" << endl;
		toolComponent = new WeldToolComponent();
		return toolComponent;
	}
	~MachineTool() override
	{
		cout << "Call MachineTool Destructor" << endl;
	}
};

int main(int argv, char* argc[])
{
	Tool* tool = new MachineTool();
	tool->AddCutToolComponent();
	delete tool->toolComponent;
	tool->toolComponent = nullptr;
	delete tool;
	tool = nullptr;

	tool = new MachineTool();
	tool->AddWeldToolComponent();
	delete tool->toolComponent;
	tool->toolComponent = nullptr;
	delete tool;
	tool = nullptr;

	tool = new HandTool();
	tool->AddWeldToolComponent();
	delete tool->toolComponent;
	tool->toolComponent = nullptr;
	delete tool;
	tool = nullptr;

	tool = new HandTool();
	tool->AddCutToolComponent();
	delete tool->toolComponent;
	tool->toolComponent = nullptr;
	delete tool;
	tool = nullptr;

	return 0;
}