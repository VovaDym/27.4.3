#pragma once

#include <iostream>
#include <vector>




enum Task
{
    A,
    B,
    C,
    AMOUNT_TASK,
    NONE
};



class Employee
{
public:

    void addSubordinate()
    {
        Employee* newWorker = new Employee;
        newWorker->boss = this;
        subordinate.push_back(newWorker);
    }

    int getAmountSubordinate()
    {
        return subordinate.size();
    }

    Employee* goSubordinateAt(const int index)
    {
        return subordinate[index];
    }

    void setTask()
    {
        if (this->task == NONE)
        {
            int task = rand() % AMOUNT_TASK;
            this->task = static_cast<Task>(task);
        }
    }

    Task getTask()
    {
        return task;
    }

private:

    Employee* boss = nullptr;
    std::vector <Employee*> subordinate;
    Task task = NONE;
};
