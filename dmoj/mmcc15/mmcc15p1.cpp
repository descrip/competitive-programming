#include <iostream>
#include <utility>
#include <stack>
using namespace std;

#include "inaho.h" 
//Why can't he get the bionic eye to fix the game for him its literally magic

const int MAX = 500001;
int pset[MAX], setsize[MAX], setrank[MAX];
stack<pair<bool,pair<int,int>>> prevadd;

void Init(int N){
	fill(setsize,setsize+MAX,1);
	fill(setrank,setrank+MAX,0);
	for (int i = 1; i <= N; ++i) pset[i] = i;
}

int findset(int a){return (pset[a] == a) ? a : findset(pset[a]);}

void AddEdge(int U, int V){
	if (findset(U) == findset(V)){
		prevadd.push({false,{-1,-1}});
		return;
	}
	int x = findset(U), y = findset(V);

	if (setrank[x] > setrank[y]){
		setsize[x] += setsize[y];
		pset[y] = x;
		prevadd.push({false,{x,y}});
	}
	else{
		setsize[y] += setsize[x];
		pset[x] = y;
		if (setrank[x] == setrank[y]){
			++setrank[y];
			prevadd.push({true,{y,x}});
		}
		else prevadd.push({false,{y,x}});
	}
}

void RemoveLastEdge(){
	bool derank = prevadd.top().first;
	int x = prevadd.top().second.first, y = prevadd.top().second.second;
	prevadd.pop();
	if (x == -1 && y == -1) return;
	setsize[x] -= setsize[y];
	pset[y] = y;
	if (derank) --setrank[x];
}

int GetSize(int U){return setsize[findset(U)];}
