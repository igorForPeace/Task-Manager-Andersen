#include <iostream>
#include "TaskManager.h"

int main()
{
	/*TaskManager tm;
	int i = 0;
	while (i < 4)
	{
		tm.AddTask();
		i++;
	}
	std::cout << "My tasks: \n\n";
	tm.ShowTasks();
	tm.SortTasks();
	std::cout << "\n\nAfter sorting: \n\n";
	tm.ShowTasks();*/

	TaskManager tm;
	
	while (true)
	{
		std::cout << "\n OPTIONS:\n";
		std::cout << "1 - show all tasks\n";
		std::cout << "2 - add new task\n";
		std::cout << "3 - find task\n";
		std::cout << "4 - edit task\n";
		std::cout << "5 - delete task\n";
		std::cout << "6 - sort tasl\n"; 
		std::cout << "0 - exit\n";
		std::cout << "Chose option: \n";
		int num;
		std::string str;
		std::cin >> num;
		std::cin.get();
		switch (num)
		{
		case 1:
			tm.ShowTasks();
			break;
		case 2:
			tm.AddTask();
			break;
		case 3:
			std::cout << "\n find task option, please, enter the name of task: ";
			std::getline(std::cin, str);
			tm.FindTask(str);
			break;
		case 5:
			std::cout << "\ndelete task option, enter the name of task: ";
			std::getline(std::cin, str);
			tm.DeleteTask(str);
			break;
		case 6:
			tm.SortTasks();
			break;
		case 0:
			std::cout << "Good bye!\n";
			return 0;
		}
		std::cin.clear();
	}
	return 0;
}