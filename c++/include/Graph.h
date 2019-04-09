/*               Object
*                   |
*                   |
*                 Graph
*
*/

#ifndef __GRAPH_H__
#define __GRAPH_H__

namespace YLinLib
{

template <typename V, typename E>
class Graph : public Object
{
public:
    virtual V getVertex(int i) = 0;
    virtual bool getVertex(int i, V& value) = 0;
    virtual bool setVertex(int i, const V& value) = 0;
    virtual SharePointer< Array<int> > getAdjacent(int i) = 0;
    virtual E getEdge(int i, int j) = 0;
    virtual bool getEdge(int i, int j, E& value) = 0;
    virtual bool setEdge(int i, int j, const E& value) = 0;
    virtual bool removeEdge(int i, int j) = 0;
    virtual int vCount() = 0;
    virtual int eCount() = 0;
    virtual int oD(int i) = 0;
    virtual int ID(int i) = 0;
    virtual int TD(int i);
};

}

#endif //__GRAPH_H__