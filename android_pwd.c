//open.cpp

#include<iostream>
#define M 3

int num=0;

struct Board{
	int board[M][M];
};

int isGood(int x,int y,int i,int j,Board B){
	int k,t;
	if(i==x){
		if(y<j){
			for(k=y+1;k<=j-1;k++){
				if(!B.board[i][k])
					return 0;
			}
		}
		else{
			for(k=j+1;k<=y-1;k++){
				if(!B.board[i][k])
					return 0;
			}
		}
		return 1;
	}
	else if(y==j){
		if(x<i){
			for(k=x+1;k<=i-1;k++){
				if(!B.board[k][j])
					return 0;
			}
		}
		else{
			for(k=i+1;k<=x-1;k++){
				if(!B.board[k][j])
					return 0;
			}
		}
		return 1;
	}
	else if(x<i && y<j){
		if(i-x==j-y){
			t=i-x;
			for(k=1;k<t;k++){
				x+=1;
				y+=1;
				if(!B.board[x][y])
					return 0;
			}
			return 1;
		}
	}
	else if(x<i && y>j){
		if(i-x==y-j){
			t=i-x;
			for(k=1;k<t;k++){
				x+=1;
				j+=1;
				if(!B.board[x][j])
					return 0;
			}
			return 1;
		}
	}
	else if(x>i && y<j){
		if(x-i==j-y){
			t=x-i;
			for(k=1;k<t;k++){
				i+=1;
				y+=1;
				if(!B.board[i][y])
					return 0;
			}
			return 1;
		}
	}
	else{
		if(x-i==y-j){
			t=x-i;
			for(k=1;k<t;k++){
				i+=1;
				j+=1;
				if(!B.board[i][j])
					return 0;
			}
			return 1;
		}
	}
	return 1;
}

void walk(int x,int y,int depth,Board B){
	int i,j;
	if(depth==0)
		num++;
	else{
		for(i=0;i<M;i++){
			for(j=0;j<M;j++){
				if(!B.board[i][j]){
					if(isGood(x,y,i,j,B)){
						B.board[i][j]=1;
						walk(i,j,depth-1,B);
						B.board[i][j]=0;
					}
				}
			}
		}
	}
}

int main(){
	int i,j,depth;
	Board B;
	for(depth=4;depth<=M*M;depth++){
		for(i=0;i<M;i++){
			for(j=0;j<M;j++){
				memset(B.board,0,M*M*sizeof(int));
				B.board[i][j]=1;
				walk(i,j,depth-1,B);
			}
		}
	}
	std::cout<<"num = "<<num<<std::endl;
}
