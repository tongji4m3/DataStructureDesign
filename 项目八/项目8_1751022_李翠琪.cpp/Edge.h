#ifndef _EDGE_H_
#define _EDGE_H_

class Edge
{
public:
	Edge() {}
	Edge(int v, int w, double weight) : v(v), w(w), weight(weight) {}

	int either() const
	{
		return v;
	}

	int other(int vertex) const
	{
		if (vertex == v)
			return w;
		else if (vertex == w)
			return v;
	}

	double getWeight() const
	{
		return weight;
	}

	bool operator < (const Edge & that) const
	{
		if (weight < that.weight)
			return true;
		else
			return false;
	}

private:
	int v;
	int w;
	double weight;
};

#endif //_EDGE_H_
