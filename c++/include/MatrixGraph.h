#ifndef __MATRIXGRAPH_H__
#define __MATRIXGRAPH_H__
#include "Graph.h"
#include "Exception.h"
#include "DynamicArray_Old.h"
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
    SharePointer< Array<int> > getAdjacent(int i) //获取与i相临接的其他顶点
    {
        DynamicArray<int>* ret = NULL;

        if((i >= 0) && (i < vCount()))
        {
            int n = 0;
            for(int j=0 ;j<vCount(); j++)
            {
                if(m_edges[i][j] != NULL)
                {
                    n++;
                }
            }

            ret = new DynamicArray(n);
            if(ret != NULL)
            {
                for(int j=0, k = 0;j<vCount(); j++)
                {
                    if(m_edges[i][j] != NULL)
                    {
                        ret->set(k++, j);
                    }
                }
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
            }
        }
        else
        {
           THROW_EXCEPTION(InvalidParameterException,"Index i is invalid..."); 
        }
    }
    E getEdge(int i, int j)  //获取i到j顶点的权值
    {
        E ret;
        if(!getEdge(i, j, &ret))
        {
            THROW_EXCEPTION(InvalidParameterException,"Index i&j is invalid...");
        }
        return ret;
    }
    bool getEdge(int i, int j, E& value)
    {
        bool ret = ((i>=0) && (i<vCount())
                    (j>=0) && (j<vCount()));
        if(ret)
        {
            if(m_vertexes[i][j] ! = NULL)
            {
                value = *(m_vertexes[i][j]);
            }
            else
            {
                THROW_EXCEPTION(InvalidParameterException, "No value assigned to this vertex...");
            }
        }

        return ret;        
    }
    bool setEdge(int i, int j, const E& value)
    {
        bool ret = ((i>=0) && (i<vCount())
            (j>=0) && (j<vCount()));

        if(ret)
        {
            E *ne = m_edges[i][j];
            if(be == NULL)
            {
                ne = new E();
                if(ne != NULL)
                {
                    *ne = value;
                    m_edges[i][j] = ne;
                    m_eCount++;
                }
                else
                {
                    THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
                }
            }
            else
            {
                *ne = value;
            }
        }
    }
    bool removeEdge(int i, int j)
    {
        bool ret = ((i>=0) && (i<vCount())
            (j>=0) && (j<vCount()));
        if(ret)
        {
            E* toDel = m_edges[i][j];
            m_edges[i][j] = NULL;

            if(toDel != NULL)
            {
                m_eCount--;

                delete toDel;
            }
        }   

        return ret;     
    }
    int vCount()
    {
        return N;
    }
    int eCount()  //获取图中边的数量
    {
        return m_eCount;
    }
    int oD(int i)  //获取 "出度"
    {
        int ret = 0;
        if((i>=0) && (i<vCount()))
        {
            for(int i=0; i<vCount(); i++)
            {
                for(int j=0; j<vCount(); j++)
                {
                    if(m_edges[i][j] != NULL) //看i行中不为空的次数
                    {
                        ret++;
                    }
                }
            }
        }
        else
        {
           THROW_EXCEPTION(InvalidParameterException, "Index i is invalid..."); 
        }
    }

    int ID(int i)  //获取 "入度"
    {
         int ret = 0;
        if((i>=0) && (i<vCount()))
        {
            for(int i=0; i<vCount(); i++)
            {
                for(int j=0; j<vCount(); j++)
                {
                    if(m_edges[j][i] != NULL)  //看i列中不为空的次数
                    {
                        ret++;
                    }
                }
            }
        }
        else
        {
           THROW_EXCEPTION(InvalidParameterException, "Index i is invalid..."); 
        }       
    }  
};
}

#endif //__MATRIXGRAPH_H__