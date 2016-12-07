#include <iostream>
#include <list>
#include <map>

using namespace std;

class Graf{
private:
	int vertexcount;
	list <int> *adj;
public:
	Graf(int V){
		this->vertexcount = V;
		adj = new list<int>[V];
	}

	void add(int v, int h){
		adj[v].push_back(h);
		adj[h].push_back(v);
	}

	list<int> sort(list<int>unmarkt, map<const int, int> hodnota){
		map <const int, int> sort;
		while (!unmarkt.empty()){
			sort[unmarkt.back()] = hodnota.find(unmarkt.back())->second;
			unmarkt.pop_back();
		}
		int a = sort.size();
		map<const int, int>::iterator it = sort.begin();
		while (a!=0)
		{
			it = sort.begin();
			for (map<const int, int>::iterator ix = sort.begin(); ix != sort.end();ix++){
				if (it->second < 0){
					if (ix->second > 0)
						it = ix;
				}
				else if (it->second > ix->second && ix->second > 0){
					it = ix;
				}
			}
			unmarkt.push_back(it->first);
			sort.erase(it);
			a--;
		}
		return unmarkt;
	}

	int dijkstra(const int v)
	{
		int tmp;
		list<int>unmarkt;
		map<const int, int> hodnota;
		for (int i = 0; i < vertexcount;i++)
		{
			unmarkt.push_back(i);
			hodnota[i] = -1;

		}
		map<const int, int>::iterator it = hodnota.find(v);
		map<const int, int>::iterator is;
		it->second = 0;

		while (!unmarkt.empty())
		{

			unmarkt = sort(unmarkt,hodnota);
			tmp = unmarkt.front();
			unmarkt.pop_front();
			it = hodnota.find(tmp);
			for (list<int>::iterator ix = adj[tmp].begin(); ix != adj[tmp].end(); ix++){
				is = hodnota.find(*ix);
				if (is->second == -1) is->second = it->second + 1;
				else if (is->second > it->second + 1){
					is->second = it->second + 1;
				}
			}
		}
		int najdlhsia = 0;
		for (map<const int, int>::iterator ik = hodnota.begin(); ik != hodnota.end();ik++){
			if (ik->second > najdlhsia)
				najdlhsia = ik->second;
		}
		return najdlhsia;
	}

	int priemer(){
		int priemer = 0, cp = 0;
		for (int i = 0; i < vertexcount; i++){
			priemer = dijkstra(i);
			if (priemer>cp) cp = priemer;
		}
		return cp;
	}

};


int main()
{
	Graf g(5);
	g.add(0, 2);
	g.add(0, 3);
	g.add(2, 1);
	g.add(3, 4);
	g.add(1, 4);

	int a = g.priemer();

	return 0;
}