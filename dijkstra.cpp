#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<list>
#include<map>
#include<set>
#include<vector>

using namespace std;




class Vertex{

public:
	Vertex(string name_ = ""){ name = name_; }
	void add_neighbour(Vertex* v, int dist){
		if (find(Neighbours.begin(), Neighbours.end(), v) != Neighbours.end()) return;
		else Neighbours.push_back(v);
		distances[v] = dist;
		
	}
	void print(){}
	int d;
	map<Vertex*, int> distances;
	string name;
	list<Vertex*> Neighbours;


};

struct comp{
	bool operator()(Vertex* a, Vertex* b){
		return a->d < b->d;
	}

} Comp;

class Graph{
public:
	set<Vertex*> all_vertices;
	map<string, Vertex*> name_to_vertex;

	void add_edge(string V1, string V2, int dist){
		if (name_to_vertex.find(V1) == name_to_vertex.end())	name_to_vertex[V1] = new Vertex(V1);
		if (name_to_vertex.find(V2) == name_to_vertex.end())	name_to_vertex[V2] = new Vertex(V2);
		all_vertices.insert(name_to_vertex[V1]);
		all_vertices.insert(name_to_vertex[V2]);
		name_to_vertex[V1]->add_neighbour(name_to_vertex[V2], dist);
		name_to_vertex[V2]->add_neighbour(name_to_vertex[V1], dist);
		
	}

	void BFS(string S){

	}

	void dijkstra(string S, string C)
	{
		Vertex *tmp;
		list<Vertex*>unmarkt;
		for(set<Vertex*>::iterator it=all_vertices.begin();it!=all_vertices.end();it++)
		{
			unmarkt.push_back(*it);
			(*it)->d=1000;
		}

		
		Vertex *v1=name_to_vertex.find(S)->second;
		v1->d=0;
		while(!unmarkt.empty())
		{
			
			unmarkt.sort(Comp);
			tmp=unmarkt.front();
			unmarkt.pop_front();

			for(map<Vertex*, int>::iterator is=tmp->distances.begin();is!=tmp->distances.end();is++)
			{
				if(is->first->d > tmp->d + is->second)
				{
					is->first->d=tmp->d + is->second;
				}



			}

		}
	

		//map<string, Vertex*>::iterator ip=name_to_vertex.find(C);
		//Vertex *v2=ip->second;
		Vertex *v2=name_to_vertex[C];
		cout<<v2->d;

	}


};


void main(){

	Graph G;

	G.add_edge("A", "B", 3);
	G.add_edge("A", "E", 1);
	G.add_edge("B", "C", 2);
	G.add_edge("B", "D", 2);
	G.add_edge("C", "D", 4);
	G.add_edge("D", "E", 1);

	G.dijkstra("A", "D");
	system("pause");
}