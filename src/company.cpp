#include <iostream>
#include "employee.h"

int main()
{
    Employee* company = new Employee;
    std::cout << "Enter amount of teams: ";
    int amountTeams;
    std::cin >> amountTeams;
    for (int i = 0; i < amountTeams; ++i)
    {
        company->addSubordinate();
        std::cout << "Enter amount of workers on " << i + 1 << " team: ";
        int amountWorkers;
        std::cin >> amountWorkers;
        Employee* manager = company->goSubordinateAt(i);
        for (int j = 0; j < amountWorkers; ++j)
        {
            manager->addSubordinate();
        }   
    }
    system("cls");

    amountTeams = company->getAmountSubordinate();
    for (int i = 0; i < amountTeams; ++i)
    {
        std::cout << "Enter assignment for " << i + 1 << " team: ";
        int assignment;
        std::cin >> assignment;

        std::srand(assignment + i);
        Employee* manager = company->goSubordinateAt(i);
        int amountTask = manager->getAmountSubordinate();
        std::cout << "the manager of team " << i + 1 << " received task " << assignment << " from the boss" << std::endl;
        for (int i = 0; i < amountTask; ++i)
        {
            manager->setTask();
            if (manager->getTask() == 0)
            {
                std::cout << "employee " << assignment << "." << i << " received a type A task" << std::endl;
            }
            if (manager->getTask() == 1)
            {
                std::cout << "employee " << assignment << "." << i << " received a type B task" << std::endl;
            }
            if (manager->getTask() == 2)
            {
                std::cout << "employee " << assignment << "." << i << " received a type C task" << std::endl;
            }    
        }
        std::cout << std::endl;
    }      
}