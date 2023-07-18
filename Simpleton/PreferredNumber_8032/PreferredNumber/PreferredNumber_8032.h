#pragma once

#include <array>
#include <iostream>

using namespace std;
typedef array<float, 41> FloatArray;
typedef unsigned short int uint16;
constexpr int a = 40;
constexpr int b = 16;

enum class ERa : uint16
{
    Ra5, Ra10, Ra20, Ra40
};

class PreferredNumber_8032;

class PreferredNumber_8032Destroyer
{
public:
	~PreferredNumber_8032Destroyer();

	void initialize(PreferredNumber_8032* p);

private:
	PreferredNumber_8032* p_instance;
};

class PreferredNumber_8032
{
public:
	static PreferredNumber_8032& GetInstance();

	float GetNumber(ERa R = ERa::Ra5, int i = 0) const
	{
		auto p_current = p_begin;
		p_current += GetStep(R) * i;
		return *p_current;
	}

	void PrintArray(ERa R = ERa::Ra5) const
	{
		auto p_current = p_begin;

		cout << 0 << "\t|\t" << *p_begin << endl;
		for (int i = 1; i < a / GetStep(R); i++)
		{
			p_current += GetStep(R);
			cout << i << "\t|\t" << *p_current << endl;
		}
		p_current = p_begin;
	}

	PreferredNumber_8032() {}
	PreferredNumber_8032(const PreferredNumber_8032&) = delete;
	PreferredNumber_8032& operator = (PreferredNumber_8032&) = delete;
	~PreferredNumber_8032() {}

protected:
	friend class SingletonDestroyer;

private:
	int GetStep(ERa R) const
	{
		int Step = b;
		for (int i = 0; i <= static_cast<uint16>(R); i++)
		{
			Step /= 2;
		}
		return Step;
	}

	FloatArray PrefNumArray = { 1.0f, 1.06f, 1.12f, 1.18f, 1.25f, 1.32f, 1.4f, 1.5f, 1.6f, 1.70f, 1.80f, 1.90f, 2.00f, 2.12f, 2.24f, 2.36f, 2.50f, 2.65f, 2.80f, 3.00f, 3.15f, 3.35f, 3.55f, 3.75f, 4.00f, 4.25f, 4.50f, 4.75f, 5.0f, 5.30f, 5.60f, 6.00f, 6.30f, 6.70f, 7.10f, 7.50f, 8.00f, 8.50f, 9.00f, 9.50f, 10.00f };
	FloatArray::const_pointer p_begin = &*PrefNumArray.cbegin();
	static PreferredNumber_8032* p_instance;
	static PreferredNumber_8032Destroyer destroyer;
};