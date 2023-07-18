#include "PreferredNumber_8032.h"

PreferredNumber_8032* PreferredNumber_8032::p_instance = nullptr;
PreferredNumber_8032Destroyer PreferredNumber_8032::destroyer;

PreferredNumber_8032Destroyer::~PreferredNumber_8032Destroyer()
{
    delete p_instance;
}

void PreferredNumber_8032Destroyer::initialize(PreferredNumber_8032* p)
{
    p_instance = p;
}

PreferredNumber_8032& PreferredNumber_8032::GetInstance()
{
    if (!p_instance) {
        p_instance = new PreferredNumber_8032();
        destroyer.initialize(p_instance);
    }
    return *p_instance;
}