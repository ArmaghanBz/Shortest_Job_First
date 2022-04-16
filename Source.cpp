#include <iostream>
#include <string>
#include <vector>
using namespace std;

class process {
public:
	string ProcessNumber;
	float burstTime;
	float completionTime;
	float turnAroundTime;
	float waitingTime;
	float arrivalTime;
	float responseTime;
	process() : ProcessNumber(""), burstTime(0), completionTime(0), turnAroundTime(0), waitingTime(0), arrivalTime(0), responseTime(0) {};
	void takingInput();
	void display();
};
void process::takingInput() {
	cout << "\n\n\t\tPlease enter process number: ";
	cin.ignore();
	getline(cin, ProcessNumber);
	cout << "\t\tPlease enter the Burst time: ";
	cin >> burstTime;
	cout << "\t\t______________________\n\n";
}
void SelectionSort(process* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (p[j].burstTime < p[min].burstTime)
			{
				min = j;
			}
		}
		process temp = p[min];
		p[min] = p[i];
		p[i] = temp;
	}
}
void process::display() {
	cout << "\n\t\tProcess: " << ProcessNumber << endl;
	cout << "\t\tBurst time: " << burstTime << endl;
	cout << "\t\tCompletion time: " << completionTime << endl;
	cout << "\t\tTurn Around Time: " << turnAroundTime << endl;
	cout << "\t\tArrival Time: " << arrivalTime<< endl;
	cout << "\t\tWaiting Time: " << waitingTime << endl;
	cout << "\t\tResponse Time: " << responseTime << endl;
	cout << "\t\t_____________________________\n";
}

void main() {
	process obj[3];
	for (int i = 0; i < 3; i++) {
		obj[i].takingInput();
	}
	SelectionSort(obj, 3);
	//for Completion time
	obj[0].completionTime = obj[0].burstTime;
	for (int i = 1; i < 3; i++)
	{
		obj[i].completionTime = obj[i].completionTime + obj[i - 1].completionTime + obj[i].burstTime;
	}
	//Turn Around Time
	for (int i = 0; i < 3; i++)
	{
		obj[i].turnAroundTime = obj[i].completionTime - 0;
	}
	//Waiting Time
	for (int i = 0; i < 3; i++)
	{
		obj[i].waitingTime = obj[i].turnAroundTime - obj[i].burstTime;
	}
	//Response Time
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			obj[i].responseTime = 0;
		}
		else {
			obj[i].responseTime = obj[i - 1].completionTime;
		}
	}


	cout << "\t\t----------------------\n";
	cout << "\t\t     The Table\n";
	cout << "\t\t----------------------\n";
	for (int i = 0; i < 3; i++) {
		obj[i].display();
	}
	float totalProcesses = 3;
	float throuhput = 3/ obj[3 - 1].completionTime;
	cout << "\n\n\t\t  ThroughPut  =  " << throuhput;
	float avgWTime = 0;
	for (int i = 0; i < 3; i++)
	{
		avgWTime += obj[i].waitingTime;
	}
	avgWTime = avgWTime / totalProcesses;
	cout << "\n\n\t\t Average Waiting Time  =  " << avgWTime;
	float avgTAT = 0;
	for (int i = 0; i < 3; i++)
	{
		avgTAT += obj[i].turnAroundTime;
	}
	avgTAT= avgTAT / totalProcesses;
	cout << "\n\n\t\t  Average Waiting Time  =  " << avgTAT;
	cout << "\n\n\n";


}