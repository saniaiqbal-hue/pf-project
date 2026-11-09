#include<iostream>
#include<string>
using namespace std;
struct task {
	string name;
	int deadline;
	int duration;
	int quadrant;
	bool completed;
};
void addtask(task task[], int& taskcount)
{
	
	char choice;
	do
	{
		if (taskcount > 50)
		{
			cout << "Limit has exceeded";
			return;
		}
		cout << "Enter name of subject or task name:";
		cin >> task[taskcount].name;
		cout << "Enter deadline for task:";
		cin >> task[taskcount].deadline;
		cout << "Enter duration for task";
		cin >> task[taskcount].duration;
		cout << "Enter eisenhower quadrant ";
		cin >> task[taskcount].quadrant;
		task[taskcount].completed = false;
		taskcount++;

		cout << "Task has completed successfully";
		cout << "Enter c if you want to enter another task!";
		cin >> choice;
	}
	while (choice == 'c' || choice == 'C');
}
int main()
{
	task array[50];
	int taskcount = 0;
	addtask(array, taskcount);
	return 0;
}









