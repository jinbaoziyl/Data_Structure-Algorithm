#ifndef __LISTGRAPH_H__
#define __LISTGRAPH_H__

namespace YLinLib
{

template<typename V, typename E>
class ListGraph : public Graph<V, E>
{
protected:
    struct Vertex : public Object
    {
        V* data;
        LinkList< Edge<E> > edge;

        Vertex()
        {
            data = NULL;
        }
    };
    LinkList< Vertex*> m_list;
public:
    ListGraph(unsigned int n = 0)
    {
        for(unsigned int i = 0; i < n ; i++)
        {
            addVertex();
        }
    }  

    int addVertex()
    {
        int ret = -1;
        Vertex* v = new Vertex();
        if(v != NULL)
        {
            m_list.insert(v);

            ret = m_list.length() - 1; //返回新增顶点的编号
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new Vertex...");
        }

        return ret;
    }  

    int addVertex(const V& value)
    {
        int ret = addVertex();
        if(ret >= 0)
        {
            setVertex(ret, value);
        }
    }  

    bool setVertex(int i, const V& value)
    {
        int ret = ((i>=0) && (i<vCount()));

        if(ret)
        {
            Vertex* vertex = m_list.get(i);
            V* data = vertex->data;

            if(data == NULL)
            {
                data = new V();
            }

            if(data != NULL)
            {
                *data = value;

                vertex->data = data;
            }
            else
            {
               THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new Vertex value..."); 
            }
        }

        return ret;
    }

    V getVertex(int i)
    {
        V ret;
        if(!getVertex(i, ret))
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid..."); 
        }
        return ret;
    }

    bool getVertex(int i, V& value)
    {
        int ret = ((i>=0) && (i<vCount()));
        if(ret)
        {
            Vertex* v = m_list.get(i);

            if(v->data != NULL)
            {
                value = *(v->data);
            } 
        }

        return ret;
    }

    void removeVertex()   //删除最近新增的顶点
    {
        if(m_list.length() > 0)
        {
            int index = m_list.length() - 1;
            Vertex* v = m_list.get(i);

            if(m_list.remove(index))
            {
                int i = 0;
                //删除临接链表中，与被删顶点相关的边
                for(m_list.move(0); !m_list.end(); m_list.next())
                {
                    int pos = m_list.current()->edge.find(Edge<E>(i,index));
                    if(pos > 0)
                    {
                        m_list.current()->edge.remove(pos);
                    }
                    i++;
                }
            }
        }
        else
        {
           THROW_EXCEPTION(InvalidParameterException, "No vertex to delete...");  
        }
    }
    SharedPointer< Array<int> >getAdjacent(int i)
    {
        DynamicArray<int> *ret = NULL;
        if((i>=0) && (i<vCount()))
        {
            Vertex* vertex = m_list.get(i);

            ret = new DynamicArray<int>(vertex->edge.length());
            if(ret != NULL)
            {
                int k = 0;
                for(vertex->edge.move(0); !vertex->edge.end(); vertex->edge.next(), k++)
                {
                    ret->set(k, vertex->edge.current().e); //遍历每条边，取出目的顶点
                }
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new Vertex value...");
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }
    }

    E getEdge(int i, int j)
    {
        E ret;
        if(!getEdge(i, j, ret))
        {
            THROW_EXCEPTION(InvalidParameterException, "No value assigned to this position....");
        }
        return ret;
    }

    bool getEdge(int i, int j, E& value)
    {
        int ret = ((i>=0) && (i<vCount()) && (j>=0) && (j<vCount()));

        if(ret)
        {
           Vertex* vertex = m_list.get(i);
           int pos = vertex->edge.find(Edge<E>(i,j));

           if(pos > 0)
           {
               value = vertex->edge.get(pos).date;
           } 
           else
           {
               THROW_EXCEPTION(InvalidParameterException, "No value assigned to this position....");
           }
        }

        return ret;
    }

    bool  setEdge(int i, int j, const E& value)
    {
        int ret = ((i>=0) && (i<vCount()) && (j>=0) && (j<vCount()));
        if(ret)
        {
            Vertex* vertex = m_list.get(i);
            int pos = vertex->edge.find(Edge<E>(i,j));
            if(pos >= 0)
            {
                ret = vertex->edge.set(pos, Edge<E>(i,j,value));
            }
            else
            {
                ret = vertex->edge.set(0, Edge<E>(i,j,value));
            }
        }
        
        return ret;
    }

    bool removeEdge(int i, int j)
    {
        int ret = ((i>=0) && (i<vCount()) && (j>=0) && (j<vCount()));
        if(ret)
        {
            Vertex* vertex = m_list.get(i);
            int pos = vertex->edge.find(Edge<E>(i,j));
            if(pos >= 0)
            {
                ret = vertex->edge.remove(pos);
            }
        }
        
        return ret;
    }   

    int vCount()
    {
        return m_list.length();
    } 

    int eCount()
    {
        int ret = 0;
        for((i>=0) && (i<vCount()))
        {
            for(m_list.move(0); !m_list.end();m_list.next())
            {
                LinkList< Edge<E> >&edge = m_list.current()->edge;
                for(edge.move(0); !edge.end(); edge.next())
                {
                    if(edeg.current().e == i)
                    {
                        ret++;
                        break;
                    }
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }

    int oD(int i)
    {
        int ret = 0;
        if((i>=0) && (i<vCount()))
        {
            ret = m_list.get(i)->edge.length();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }

    ~ListGraph()
    {
        while(m_list.length() > 0)
        {
            Vertex *toDel = m_list.get(0);
            m_list.remove(0);

            delete toDel->data;
            delete toDel;
        }
    }
};
}

#endif //__LISTGRAPH_H__