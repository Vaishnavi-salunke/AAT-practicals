
//TOWER OF HANOI

#include<iostream>
using namespace std;
void towerOfHanoi(int n,char from,char To,char Aux){
	if(n==1){
		cout<<"move disk one from"<<from<<"To"<<To<<endl;
		return;
	}
	towerOfHanoi(n-1,from,Aux,To);
	cout<<"Move disk"<<n<<"from"<<from<<"TO"<<Aux<<endl;
	towerOfHanoi(n-1,Aux,To,from);	
	
}
int main()
{
	int n;
	cout<<"Enter number of Disks:";
	cin>>n;
	cout<<"steps to solve TowerOfHanoi:\n";
	towerOfHanoi(n,'A','C','B');
	return 0;
}

	
