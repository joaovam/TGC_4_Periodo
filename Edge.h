
#ifndef EDGE
#define EDGE
class Edge
{
private:
    Vertix vSource;
    Vertix vDest;

    double weight;

    string label;

public:
    Edge();
    ~Edge();
    Vertix getVSource();
    Vertix getVDest();
    void setVSource(Vertix v);
    void setVDest(Vertix v);
};

#endif