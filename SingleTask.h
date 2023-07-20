#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#pragma warning(disable:4996)

enum class Progress { NEW = 1, IN_PROGRESS, COMPLETED };
enum class Priority {LOW = 1, MEDIUM, HIGH};

class SingleTask
{
private:
	std::string name;
	std::string description;
	std::string creation_date;
	std::string final_date;
	Progress status;
	Priority priority;

	void CurrentDate(std::string& s)
	{
		std::time_t current_time = std::time(nullptr);
		std::tm local_time = *std::localtime(&current_time);
		std::ostringstream oss;
		oss << std::put_time(&local_time, "%d.%m.%Y");
		s = oss.str();
	}

public:
	SingleTask(std::string name, std::string description,
		std::string final_date, unsigned int priority)
		:name(name), description(description), final_date(final_date)
	{
		CurrentDate(creation_date);
		status = Progress::NEW;
		this->SetPriority(priority);
	}

	void SetPriority(int priority)
	{
		switch (priority)
		{
		case 0:
		case 1:
			this->priority = Priority::LOW;
			break;
		case 2:
			this->priority = Priority::MEDIUM;
			break;
		default:
			this->priority = Priority::HIGH;
			break;
		}
	}

	void ShowTask()
	{
		std::cout << "---------------------\n";
		std::cout << "Name: " << this->name << std::endl;
		std::cout << "Creation date: " << this->creation_date << std::endl;
		std::cout << "Status: ";
		switch (status)
		{
		case Progress::NEW:
			std::cout << "NEW\n";
			break;
		case Progress::IN_PROGRESS:
			std::cout << "IN PROGRESS\n";
			break;
		case Progress::COMPLETED:
			std::cout << "COMPLETED\n";
			break;
		}
		std::cout << "Priority: ";
		switch (priority)
		{
		case Priority::LOW:
			std::cout << " LOW\n";
			break;
		case Priority::MEDIUM:
			std::cout << " MEDIUM\n";
			break;
		case Priority::HIGH:
			std::cout << " HIGH\n";
			break;
		}
		std::cout << "Description: " << this->description << std::endl;
		std::cout << "Final date: " << this->final_date << std::endl;
	}

	void ChangeName(const std::string& new_name)
	{
		this->name = new_name;
	}

	void ChangeDescription(const std::string& new_descr)
	{
		this->description = new_descr;
	}

	std::string GetName() const
	{
		return this->name;
	}

	bool operator==(const std::string& name)
	{
		return this->name == name;
	}

	bool operator<(const SingleTask& other)
	{
		return this->priority < other.priority;
	}
};

