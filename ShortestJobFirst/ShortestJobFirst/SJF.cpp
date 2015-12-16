/*
author @MehmetErtekin
*/
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool myComp(pair<int, int> A, pair<int, int> B) {
	if (A.second < B.second)
		return true;
	else
		return false;
}
int main() {
	int count;
	vector<pair<int, int>> processTable;
	cout << "How many process :";
	cin >> count;
	for (int i = 1; i <= count; i++) {
		pair<int, int> newProcess;
		cout << i << ". Burst length :";
		newProcess.first = i;
		cin >> newProcess.second;
		processTable.push_back(newProcess);
	}
	sort(processTable.begin(), processTable.end(), myComp);
	cout << "------------------" << endl;
	cout << "#process\t Burstlength\t waitingT. \t turn Around" << endl;
	int waiting = 0;
	int turn;
	int sumturn = 0;
	int sumWaiting = 0;
	for (int i = 0; i < processTable.size(); i++) {
		turn = waiting + processTable[i].second;
		sumturn += turn;
		sumWaiting += waiting;
		cout << processTable[i].first << "\t\t " << processTable[i].second << "\t\t " << waiting << "\t\t " << turn << endl;
		waiting += processTable[i].second;
	}
	cout << "-------------------------" << endl;
	cout << "avg \t\t\t\t " << std::fixed << std::setprecision(2) << sumWaiting*1.0 / count << "\t\t " << sumturn*1.0 / count;
	_getch();
	return 0;
}