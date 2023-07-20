#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <algorithm>
#include "SingleTask.h"


class TaskManager
{
private:
	std::vector<SingleTask> tasks;

	void ValidDate(std::string& input_date)
	{
		std::time_t current_time = std::time(nullptr);
		std::tm local_time = *std::localtime(&current_time);
		while (true)
		{
			std::cout << "Enter final date (dd.mm.yyyy): ";
			std::getline(std::cin, input_date);
			std::tm input_time = {};
			std::istringstream iss(input_date);
			iss >> std::get_time(&input_time, "%d.%m.%Y");
			if (std::mktime(&input_time) > std::mktime(&local_time))
			{
				break;
			}
			std::cout << "invalid date\n";
		}
	}

public:
	TaskManager(){}

	void AddTask()
	{
		std::cout << "\n-----adding new task-----\n";
		std::cout << "enter name of task: ";
		std::string temp_name;
		std::getline(std::cin, temp_name);
		std::cout << "enter description: ";
		std::string temp_descr;
		std::getline(std::cin, temp_descr);
		std::string temp_fdate;
		this->ValidDate(temp_fdate);
		int temp_priority;
		std::cout << "Enter priority (1 - 3): ";
		std::cin >> temp_priority;
		std::cin.get();
		tasks.emplace_back(temp_name, temp_descr, temp_fdate, temp_priority);
	}

	void ShowTasks()
	{
		if (tasks.size() == 0)
		{
			std::cout << "Empty list of tasks\n";
			return;
		}
		for (int i = 0; i < tasks.size(); i++)
		{
			tasks[i].ShowTask();
		}
	}

	void FindTask(const std::string& name)
	{
		for (int i = 0; i < tasks.size(); i++)
		{
			if (tasks[i].GetName() == name)
			{
				tasks[i].ShowTask();
				return;
			}
		}
		std::cout << "No task with " << name << " name\n";
	}

	void EditTask()
	{
		/*
			some code...
		*/
	}

	void DeleteTask(std::string& name)
	{
		std::vector<SingleTask>::iterator it = std::find(tasks.begin(), tasks.end(), name);
		if (it != tasks.end())
		{
			tasks.erase(it);
		}
		else
		{
			std::cout<< "No task with " << name << " name\n";
		}
	}

	void SortTasks()
	{
		std::sort(tasks.begin(), tasks.end());
	}
};

