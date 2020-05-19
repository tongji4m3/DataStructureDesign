#ifndef _KRUSKAL_MST_H_
#define _KRUSKAL_MST_H_

#include "EdgeWeightedGraph.h"
#include "Queue.h"
#include "Edge.h"
#include "MinPQ.h"
#include "UF.h"

class KruskalMST
{
public:
	KruskalMST(EdgeWeightedGraph G)
	{
		MinPQ<Edge> pq(G.getE());
		Queue<Edge> edges = G.edges();
		while (!edges.empty())
		{
			pq.push(edges.dequeue());
		}
		UF uf(G.getV());

		while (!pq.isEmpty() && mst.size() < G.getV() - 1)
		{
			Edge e = pq.delMin();
			int v = e.either();
			int w = e.other(v);
			if (uf.connected(v, w))
				continue;
			uf.unionPQ(v, w);
			mst.enqueue(e);
		}
	}

	Queue<Edge> getMST()
	{
		return mst;
	}

private:
	Queue<Edge> mst;
};

#endif //_KRUSKAL_MST_H_
