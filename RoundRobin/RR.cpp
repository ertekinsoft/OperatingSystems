/*
	Round Robin Scheduling Algorithm
	autor @mehmet
*/
#include <iostream>
#include <vector>
#include <utility>
#include <conio.h>
#include <ostream>
#include <cmath>
using namespace std;
int  mod(int A, int B);
bool isFinished(vector<int> table);
int main() {
	int count,quantumSize;
	cout << "How many processes :";
	cin >> count;
	cout << "Enter quantum size :";
	cin >> quantumSize;
	cout << "---------------------------------" << endl;
	vector<int> processTable(count);
	for (int i = 0; i < count; i++) {
		cout << i << ". Process' burst time :";
		cin >> processTable[i];
	}
	cout << "---------------------------------" <<endl ;
	for (int i = 0; i < count; i++) {
		cout << "P" << i<<"\t";
	}
	cout << "time";
	cout << endl;
	int currIndx = 0;
	int currTime = 0;
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << processTable[i] << "\t";
	}
	cout << currTime;
	vector<int> waitingTime(count, 0);
	vector<int> responseTime(count, 0);
	vector<int> burstTime;
	burstTime = processTable;
	while (!isFinished(processTable))
	{
		while (processTable[currIndx]==0)
		{
			currIndx++;
			currIndx = currIndx % count;
		}
		if (processTable[currIndx] == burstTime[currIndx])
			responseTime[currIndx] = currTime;
		if (processTable[currIndx] <= quantumSize) {
			currTime += processTable[currIndx];
			processTable[currIndx] = 0;
		}
		else {
			currTime += quantumSize;
			processTable[currIndx] -= quantumSize;
		}
		if(processTable[currIndx]==0)
			waitingTime[currIndx] = currTime-burstTime[currIndx];
		
		currIndx++;
		currIndx = currIndx % count;
		cout << endl;
		for (int i = 0; i < count; i++) {
			cout << processTable[i] << "\t";
		}
		cout << currTime;
	}
	cout <<endl<< "---------------------------------" << endl;
	cout << endl << "Process\t" << "WaitingTime\t" <<"ResponseTime"<< endl;
	for (int i = 0; i < count; i++)
	{
		cout << i << "\t" << waitingTime[i] <<"\t\t"<<responseTime[i]<< endl;
	}
	_getch();
	return 0;
}
bool isFinished(vector<int> table) {
	for (int i = 0; i < table.size(); i++) {
		if (table[i] != 0) {
			return false;
		}
	}
	return true;
}
int mod(int A, int B) {
	int C = floor(A*1.0 / B);
	return A - C*B;
}