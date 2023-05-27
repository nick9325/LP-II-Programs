#include<bits/stdc++.h>

using namespace std;


int g=0;


void Print(int start[]){
	
	for(int i=0;i<9;i++){	
		if(i%3==0) cout<<endl;
		cout<<start[i]<<" ";
	}
	cout<<endl;
}



int heuristic(int start[],int goal[]){
	
	int h=0;

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(start[i]==goal[j] and start[i]!=-1){
				h+=abs((j-i)/3)+abs((j-i)%3);
			}
		}
	}	
	
	return h+g;
}



void Copy(int start[],int t[]){
	
	for(int i=0;i<9;i++){
		t[i]=start[i];
	}
	
}

void moveR(int start[],int idx){
	
	swap(start[idx],start[idx+1]);
}

void moveL(int start[],int idx){
	
	swap(start[idx],start[idx-1]);
}

void moveD(int start[],int idx){
	
	swap(start[idx],start[idx+3]);
}

void moveU(int start[],int idx){
	
	swap(start[idx],start[idx-3]);
}


void moveTile(int start[],int goal[]){
	
	int emptyI;
	
	for(int i=0;i<9;i++){
		if(start[i]==-1){
			emptyI=i;
			break;
		}
	}

	int col=emptyI%3;
	int row=emptyI/3;

	
	int f1=INT_MAX,f2=INT_MAX,f3=INT_MAX,f4=INT_MAX,t1[9],t2[9],t3[9],t4[9];

	Copy(start,t1);
	Copy(start,t2);
	Copy(start,t3);
	Copy(start,t4);

	if(col<3){
		moveR(t1,emptyI);
		f1=heuristic(t1,goal);
	}
	if(col>=0){
		moveL(t2,emptyI);
		f2=heuristic(t2,goal);
	}
	if(row<3){
		moveD(t3,emptyI);
		f3=heuristic(t3,goal);
	}
	if(row>=0){
		moveU(t4,emptyI);
		f4=heuristic(t4,goal);
	}


	if(f1<=f2 and f1<=f3 and f1<=f4){
		moveR(start,emptyI);
	}
	else if(f2<=f1 and f2<=f3 and f2<=f4){
		moveL(start,emptyI);
	}
	else if(f3<=f1 and f3<=f1 and f3<=f4){
		moveD(start,emptyI);
	}	
	else{
		moveU(start,emptyI);
	}


	
	

}


void solveEight(int start[],int goal[]){
	
	g++;
	
	moveTile(start,goal);

	int f=heuristic(start,goal);

	if(f==g) {
		Print(start);
		return;
	}
	Print(start);

	solveEight(start,goal);
	
}


bool isSolvable(int start[]){
	int inv=0;
	
	for(int i=0;i<9;i++){
		if(start[i]<=1) continue;
		for(int j=i+1;j<9;j++){
			if(start[i]>start[j]) inv++;
		}
		
	}

	return (inv&1) ? false: true;
}




int main(){

	
	cout<<"Enter start state: ";
	int start[9],goal[9];

	for(int i=0;i<9;i++){
		cin>>start[i];
	}
	

	cout<<"Enter goal state: ";

	for(int i=0;i<9;i++){
		cin>>goal[i];
	}

	if(isSolvable(start)) solveEight(start,goal);
	else cout<<"Impossible to solve: ";

	


return 0;
}

