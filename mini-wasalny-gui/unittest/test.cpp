#include "pch.h"


TEST(Delgraph, Tst1) {
	Graph g(false);
	g.DelGraph();
	EXPECT_TRUE(g.IsEmpty());
}

TEST(BFS, tst2) {
	Graph g(false);
	g.AddVertex("Cairo");
	g.AddVertex("Fayoum");
	g.AddVertex("SharmElSheikh");
	g.AddVertex("ElMenia");
	g.AddVertex("Alex");
	g.AddVertex("Banha");
	g.AddEdge("Cairo", "Fayoum", 100);
	g.AddEdge("Cairo", "Alex", 200);
	g.AddEdge("Fayoum", "ElMenia", 150);
	g.AddEdge("Alex", "Banha", 180);
	g.AddEdge("Alex", "SharmElSheikh", 130);
	
	vector<string> expected_output = { "Cairo", "Fayoum", "Alex", "ElMenia", "SharmElSheikh", "Banha" };
	EXPECT_EQ(g.BFS("Cairo"), expected_output);
}


TEST(DFS, tst3){
	
	Graph g(false);
	g.DelGraph();
	g.AddVertex("Cairo");
	g.AddVertex("Fayoum");
	g.AddVertex("SharmElSheikh");
	g.AddVertex("ElMenia");
	g.AddVertex("Alex");
	g.AddVertex("Banha");
	g.AddEdge("Cairo", "Fayoum", 100);
	g.AddEdge("Cairo", "Alex", 200);
	g.AddEdge("Fayoum", "ElMenia", 150);
	g.AddEdge("Alex", "Banha", 180);
	g.AddEdge("Alex", "SharmElSheikh", 130);
	vector<string> expected_output = {  "Cairo", "Alex", "Banha", "SharmElSheikh", "Fayoum", "ElMenia"  };
	EXPECT_EQ(g.DFS("Cairo"), expected_output);
}

TEST(Dijkstra, tst4) {
	Graph g(false);
	g.DelGraph();
	g.AddVertex("Cairo");
	g.AddVertex("Fayoum");
	g.AddVertex("SharmElSheikh");
	g.AddVertex("ElMenia");
	g.AddVertex("Alex");
	g.AddVertex("Banha");
	g.AddEdge("Cairo", "Fayoum", 100);
	g.AddEdge("Cairo", "Alex", 200);
	g.AddEdge("Fayoum", "ElMenia", 150);
	g.AddEdge("Alex", "Banha", 180);
	g.AddEdge("Alex", "SharmElSheikh", 130);
	g.AddEdge("Banha", "SharmElSheikh", 20);
	pair<vector<string>, double>a= g.Dijkstra("ElMenia", "Banha");
	EXPECT_EQ(a.second,600);
}

TEST(BellmanFord, tst5) {
	Graph g(false);
	g.DelGraph();
	g.AddVertex("Cairo");
	g.AddVertex("Fayoum");
	g.AddVertex("SharmElSheikh");
	g.AddVertex("ElMenia");
	g.AddVertex("Alex");
	g.AddVertex("Banha");
	g.AddEdge("Cairo", "Fayoum", 100);
	g.AddEdge("Cairo", "Alex", 200);
	g.AddEdge("Fayoum", "ElMenia", 150);
	g.AddEdge("Alex", "Banha", 180);
	g.AddEdge("Alex", "SharmElSheikh", 130);
	g.AddEdge("Banha", "SharmElSheikh", 20);
	pair<vector<string>, double>a = g.BellmanFord("ElMenia", "Banha");
	EXPECT_EQ(a.second, 600);
}


TEST(AddVertex, tst6) {
	Graph g(false);
	g.DelGraph();
	EXPECT_TRUE(g.AddVertex("cairo"));
	EXPECT_FALSE(g.IsEmpty());
}

TEST(DelVertex, tst7) {
	Graph g(false);
	g.DelGraph();
	g.AddVertex("Cairo");
	EXPECT_TRUE(g.DelVertex("Cairo"));
    EXPECT_TRUE(g.IsEmpty());
}

TEST(Addedge, tst8) {
	Graph g(false);
	g.DelGraph();
	g.AddVertex("Cairo");
	g.AddVertex("Fayoum");
	EXPECT_TRUE(g.AddEdge("Cairo", "Fayoum", 100));
	vector<string> expected_output = { "Cairo", "Fayoum"};
	EXPECT_EQ(g.DFS("Cairo"), expected_output);
}

TEST(deledge, tst9) {
	Graph g(false);
	g.DelGraph();
	g.AddVertex("Cairo");
	g.AddVertex("Fayoum");
	g.AddEdge("Cairo", "Fayoum", 100);
	EXPECT_TRUE(g.DelEdge("Cairo", "Fayoum", 100));
	vector<string> expected_output = { "Cairo" };
	EXPECT_EQ(g.DFS("Cairo"), expected_output);
}
