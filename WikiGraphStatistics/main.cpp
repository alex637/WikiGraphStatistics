#include <iostream>
#include <vector>
#include <string>
#include <fstream>


class WikiGraph
{
public:
	int v, e; //number of vertices (pages) and edges (links)
	std::vector<bool> redirect;
	std::vector<std::vector<int>> graph;
	std::vector<std::string> names_of_pages;
	std::vector<int> size;

	void read_graph(std::string filename)
	{
		std::ifstream f(filename);
		f >> v >> e;
		redirect.assign(v, false);
		redirect.shrink_to_fit();
		names_of_pages.reserve(v);
		graph.assign(v, std::vector<int>());
		
		std::string page_name;
		bool redir;
		int x, y;

		for (int i = 0; i < v; i++)
		{
			f >> page_name;
			page_name.shrink_to_fit();
			names_of_pages.push_back(page_name);
			f >> x >> redir >> y;
			size.push_back(x);
			if (redir)
				redirect[i] = true;
			for (int j = 0; j < y; j++)
			{
				f >> x;
				graph[i].push_back(x);
			}
			graph[i].shrink_to_fit();
		}
	}

};


int main()
{
	// ? setlocale(0, "");

	std::string file;
	std::cout << "Input the path to file with WikiGraph:\n";
	std::cin >> file;
	std::cout << "\nReading WikiGraph from file...\n";

	WikiGraph w;
	w.read_graph(file);

	std::cout << "\n";
	system("pause");
}