//
//  Created by Jonas Anseeuw
//  Copyright (c) 2014 Jonas Anseeuw. All rights reserved.
//

#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

/*
template<EdgeType RT>
class Toplogic: public virtual Graph<RT>{
public:
	Toplogic(int n=0):Graph<RT>(n){};
	std::vector<int> topologicalSort(){
		std::vector<int> ts(this->numberOfVertices());
		// CALCULATE THE INDEGREES OF EACH NODE
		std::vector<int> indegrees(this->numberOfVertices());
		for(int i=0; i<this->numberOfVertices(); i++){
			std::map<int, int>::iterator it = this->vertices[i].begin();
			while(it != this->vertices[i].end()){
				indegrees[it->first]++;
				it++;
			}
		}
		// PUSH VERTICES WITH INDEGREE ZERO ON QUEUE
		std::queue<int> nextIndegree;
		for(int i=0; i<indegrees.size(); i++){
			if(indegrees[i] == 0){
				nextIndegree.push(i);
			}
		}
		// PROCESS VERTICES
		int order=0;
		while(!nextIndegree.empty()){
			int v=nextIndegree.front();
			ts[order]=v;
			std::map<int ,int>::iterator it = this->vertices[v].begin();
			while(it != this->vertices[v].end()){
				indegrees[it->first]--;
				if(indegrees[it->first]==0){
					nextIndegree.push(it->first);
				}
				it++;
			}
			nextIndegree.pop();
			order++;
		}
		return ts;
	}
};
*/

template<EdgeType RT>
class Toplogic: public virtual Graph<RT>{
public:
	Toplogic(int n=0):Graph<RT>(n){};
	std::vector<int> reverseTopologicalSort(){
		// INITIALIZING VECTORS AND POST ORDER COUNTER
		std::vector<bool> visited(this->numberOfVertices(), false);
		std::vector<int> post(this->numberOfVertices(), -1);
		int cnt = 0;
		// DFS
		for(int i=0; i<this->numberOfVertices(); i++)
		{
			if(!visited[i])
				tsR(i, visited, post, cnt);
		}
		return post;
	}
private:
	void tsR(int i, std::vector<bool> &visited, std::vector<int> &post, int &cnt){
		visited[i] = true;
		std::map<int,int>::iterator it = this->vertices[i].begin();
		while(it != this->vertices[i].end()){
			if(!visited[it->first]){
				tsR(it->first, visited, post, cnt);
			}
			it++;
		}
		post[i] = cnt++;
	}
};

int main(int argc, char *argv[]){
	Toplogic<DIRECTED> g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	
	std::vector<int> reverseToplogicOrder = g.reverseTopologicalSort();
	for (int i=reverseToplogicOrder.size()-1; i>=0; i--) {
		std::cout<<reverseToplogicOrder[i]<<" ";
	}
	
    return 0;
}

