#ifndef __MATRIXGRAPH_H__
#define __MATRIXGRAPH_H__
#include "Graph.h"
#include "Exception.h"

namespace YLinLib
{
/*
* @N: 图中顶点的个数
* @V: 与顶点相关的数据结构
* @E: 与边的权相关的数据结构
*/
template <int N, typename V, typename E>
class MatrixGraph : public Graph<V, E>
{
protected:
    V* m_vertexes[N];
    E* m_edges[N][N];
    int m_eCount;   //边的个数
public:
    MatrixGraph()
    {
        for(int i=0; i<vCount();i++)
        {
            m_vertexes[i] = NULL;
            for(int j=0; j<vCount(); j++)
            {
                m_edges[i][j] = NULL;
            }
        }
        m_eCount = 0;
    }

    ~MatrixGraph()
    {
        for(int i=0; i<vCount();i++)
        {
            for(int j=0; j<vCount(); j++)
            {
                delete m_edges[i][j];
            }
            delete m_vertexes[i];
        }
    }

    V getVertex(int i)
    {
        V ret;
        if(!getVertex(i, ret))
        {
           THROW_EXCEPTION(InvalidParameterException,"Index i is NULL..."); 
        }
        return ret;
    }
    bool getVertex(int i, V& value)
    {
        bool ret = ((i>=0) && (i<vCount()));
        if(ret)
        {
            if(m_vertexes[i] ! = NULL)
            {
                value = *(m_vertexes[i]);
            }
            else
            {
                THROW_EXCEPTION(InvalidParameterException, "No value assigned to this vertex...");
            }
        }

        return ret;
    }
    bool setVertex(int i, const V& value)
    {
        bool ret = ((i>=0) && (i<vCount()));
        if(ret)
        {
            V* data = m_vertexes[i]; //为了异常安全，用临时变量
            if(data == NULL)
            {
                data = new V();
            }
            if(data != NULL)
            {
                *data = value;
                m_vertexes[i] = data;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
            }
        }

        return ret;       
    }
    virtual SharePointer< Array<int> > getAdjacent(int i) = 0;
    virtual E getEdge(int i, int j) = 0;
    virtual bool getEdge(int i, int j, E& value) = 0;
    virtual bool setEdge(int i, int j, const E& value) = 0;
    virtual bool removeEdge(int i, int j) = 0;
    virtual int vCount() = 0;
    virtual int eCount() = 0;
    virtual int oD(int i) = 0;
    virtual int ID(int i) = 0;   
};
}

#endif //__MATRIXGRAPH_H__