/*
	author @MehmetErtekin
*/

#include<iostream>
#include<conio.h>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int size;
	cout<<"How many :";
	cin>>size;
	vector<int> tracks(size);
	for(int i=0;i<size;i++){
		cout<<i<<". track : ";
		cin>>tracks[i];
	}
	//First Come First Serve
	cout<<"----------------------------"<<endl;
	int fcfs = 0;
	for(int i=0;i<size-1;i++){
		fcfs+=abs(tracks[i]-tracks[i+1]);
		cout<<tracks[i]<<"-";
	}

	cout<<tracks[size-1];
	cout<<endl<<"First Come First Serve :"<<fcfs<<endl;

	//Shortest Seek Time First
	cout<<"----------------------------"<<endl;
	vector<int> stFirst = tracks;
	int *nearest;
	int tmp;
	for(int i=0;i<size-1;i++){
		nearest = &stFirst[i+1];
		for(int j=i+2;j<size;j++){
			if(abs(stFirst[i]-*nearest)>abs(stFirst[i]-stFirst[j])){
				nearest = &stFirst[j];
			}
		}
		tmp = stFirst[i+1];
		stFirst[i+1]=*nearest;
		*nearest = tmp;
	}
	int sstf=0 ; 
	for(int i=0;i<size-1;i++){
		sstf+=abs(stFirst[i]-stFirst[i+1]);
		cout<<stFirst[i]<<"-";
	}
	cout<<stFirst[size-1];
	cout<<endl<<"Shortest Seek Time First :"<<sstf<<endl;

	//SCAN (Elevator)
	cout<<"----------------------------"<<endl;
	vector<int> scanL = tracks;
	vector<int> scanR;
	for(int i=1;i<scanL.size();i++){
		if(scanL[i]>scanL[0]){
			scanR.push_back(scanL[i]);
			scanL.erase(scanL.begin()+i);
			i--;
		}
	}
	
	sort(scanL.begin()+1,scanL.end());
	reverse(scanL.begin()+1,scanL.end());
	sort(scanR.begin(),scanR.end());
	
	vector<int> scanD = scanL; //full Scan Data
	scanD.insert(scanD.end(),scanR.begin(),scanR.end());
	int scan = 0;
	for(int i=0;i<size-1;i++){
		scan+=abs(scanD[i]-scanD[i+1]);
		cout<<scanD[i]<<"-";
	}
	cout<<scanD[size-1]<<endl;
	cout<<"SCAN (elevator) Algorihm :"<<scan<<endl;
	cout<<"----------------------------"<<endl;
	_getch();
	return 0;
}
