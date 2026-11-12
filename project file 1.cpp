#include<iostream>
#include<string>
using namespace std;
struct Task {
	string name;
	double deadline;
	double time;
	int quadrant;
	bool completed;
};
void addtask(Task task[], int& taskcount)
{
	
	char choice;
	do
	{
		if (taskcount > 50)
		{
			cout << "Limit has exceeded";
			return;
		}
		cout << "Enter name of subject or task name:"<<endl;
		cin >> task[taskcount].name;
		cout << "Enter deadline for task 0 to 23 formatin:"<<endl;
		cin >> task[taskcount].deadline;
		cout << "Enter duration for task"<<endl;
		cin >> task[taskcount].time;
		int isimportant, isurgent;
		cout << "Is this task important ?is it important enter 1 otherwise 0 "<<endl;
		cin >> isimportant;
		cout << "Is this task urgent? is it urgent enter 1 otherwise 0"<<endl;
		cin >> isurgent;
		
		if (isimportant==1 && isurgent==1) {
			task[taskcount].quadrant = 1;
		}
		else if (isimportant==0 && isurgent==1) {
			task[taskcount].quadrant = 2;
		}
		else if (isimportant==1 && isurgent==0) {
			task[taskcount].quadrant = 3;
		}
		
		else
		{
			task[taskcount].quadrant = 4;
		}
		task[taskcount].completed = false;
		taskcount++;

		cout << "Task has completed successfully!!"<<endl;
		
		cout << "Enter c if you want to enter another task!"<<endl;
		cin >> choice;
	}
	while (choice == 'c' || choice == 'C');
}

void runschedual(Task task[], int taskcount)
{

	if (taskcount == 0) {
		cout << "!!!Schedual cannot run as there is no task !!!" << endl;
		return;

	}
	for (int i = 0; i < taskcount; i++) {
		task[i].completed = false;
	}
	for (int i = 0;i < taskcount - 1;i++) {
		for (int j = 0;j < taskcount - i - 1;j++) {
			if (task[i].deadline < task[i].time) {
				task[i].time = task[i].deadline;

			}

			if ((task[i].quadrant > task[i + 1].quadrant) || (task[j].quadrant == task[j + 1].quadrant && task[j].deadline > task[j + 1].deadline)) {
				Task temp = task[j];
				task[j] = task[j + 1];
				task[j + 1] = temp;
			}
		}
	}
	double timetake = 0;
	int completed = 0;
	int incomplete= 0;
	for (int i = 0;i < taskcount;i++) {
		task[taskcount].completed = false;
		cout << "Task " << i+1 << endl;
		cout << "Current task is " << task[i].name << "\nand Time for current task is " << task[i].time << "\nQuadrant of task is " << task[i].quadrant << endl;
		timetake = timetake + task[i].time;
		if (timetake <= task[i].deadline) {
			cout << "Completed by hour " << timetake << "hours" << endl;
			task[taskcount].completed = true;
			completed++;
		}
		else {
			timetake=task[i].deadline;
			cout << " Finished at hour " << timetake << "hours" << endl;
			task[taskcount].completed = false;
			incomplete++;
		}
	}
	cout << "Total time in which all  tasks are complete " << timetake << endl;
	cout << "Number of tasks that are  successfully completed " << completed << endl;
	cout << "Number of tasks that are incomplete or cutoff due to strict deadline " << incomplete << endl;
}

int main()
{
	cout << "*****Welcome to Eisenhower smart task schedular*****"<<endl;
	Task task[50];
	int taskcount = 0;
	int choice;
	do 
	{
		cout << "Enter your choice:" << endl;
		cout << "Enter 1 if you want to add task and run the smart schedualar" << endl;
		cout << "Enter 2 if you want to exit  " << endl;
		cin >> choice;
		switch (choice) 
		{
		 case 1:
			addtask(task, taskcount);

			if (taskcount > 0) {
				runschedual(task, taskcount);
			}
			break;
		 case 2:
			cout << "Exiting form smart schedualar good luck for your tasks:)))!" << endl;
		break;
	 default:
			cout << "Invalid choice" << endl;

		}
	} while (choice != 2);
	
		return 0;
}

		










