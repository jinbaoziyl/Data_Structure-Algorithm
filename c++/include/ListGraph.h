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
};
}

#endif //__LISTGRAPH_H__