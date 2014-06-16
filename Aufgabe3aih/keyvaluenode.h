#ifndef KEYVALUENODE_H
#define KEYVALUENODE_H
#include "rationalnumber.h"
namespace rn {
namespace internal {

template <class KeyT,class T>
class KeyValueNode{
   public:
    KeyT m_key;
    T m_mapped;
private:

    
public:

    KeyValueNode* rTree;
    KeyValueNode* lTree;






    KeyValueNode(const KeyT& k,T m=0,KeyValueNode* r = 0, KeyValueNode* l = 0 )
        :m_key(k),m_mapped(m),rTree(r),lTree(l){
        m_key = k;
        m_mapped = m;
        rTree = r;
        lTree = l;
    }
    ~KeyValueNode(){
        if(rTree!=0){
            delete rTree;
        }
        if(lTree!=0){
            delete lTree;
        }
    }

    KeyValueNode& operator=(const KeyValueNode& rhs){

        m_key = rhs.m_key;
        m_mapped = rhs.m_mapped;


    }
    KeyT key()const{return m_key;}


    T  mapped()const { return m_mapped; }
    typename KeyValueNode<KeyT,T>& find(const KeyT& key);
    typename KeyValueNode<KeyT,T>* insert(const KeyT& key,const T& mapped);
    typename KeyValueNode<KeyT,T>* clone();



};

}

}

#endif // KEYVALUENODE_H
