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
template <typename E>
struct Edge: public Object
{
    int b;
    int a;
    E data;

    Edge(int i=-1, int j=-1)
    {
        b = i;
        e = j;
    }

    Edge(int i, int j, const E& value)
    {
        b = i;
        e = j;
        data = value;
    }  

    bool operator == (const Edge<E>& obj)
    {
        return (b == obj.b) && (e == obj.e);
    } 

    bool operator !=(const Edge<E>& obj)
    {
        return !(*this == obj);
    }
};

template <typename V, typename E>
class Graph : public Object
{
protected:
    template<typename T>
    DynamicArray<T> *toArray(LinkQueue<T>& queue)  //将队列转化成数组
    {
        DynamicArray<T> *ret = new DynamicArray<T>(queue.lenght());
        if(ret != NULL)
        {
            for(int i=0; i<queue.length(); i++)
            {
                ret->set(i, queue.front());
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new DynamicArray...");
        }
    }
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
    virtual int TD(int i)
    {
        return OD(i) + ID(i);
    }
    /*
    *  以二叉树层序遍历的思想对图进行遍历
    * @i: 起始顶点编号
    */
    SharePointer< Array<int> > BFS(int i)
    {
        DynamicArray<int>* ret = NULL;

        if((i>=0) && (i<vCount()))
        {
            LinkQueue<int> q;
            LinkQueue<int> r;
            DynamicArray<bool> visited(vCount());
            for(int i=0; i<vCount(); i++)
            {
                visited[i] = false;
            }

            q.add(i); //先把第一个顶点放进队列
            while(q.length() > 0)
            {
                int v = q.front();
                q.remove();
                if(!visited[v])
                {
                    SharePointer<Array<int> >aj = getAdjacent(v);
                    for(int j=0; j<aj->length();j++)
                    {
                        q.add((*aj)[j]);
                    }

                    r.add(v);
                    visited[v] = true;
                }
            }

            ret = toArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }
    }
};

}

#endif //__GRAPH_H__