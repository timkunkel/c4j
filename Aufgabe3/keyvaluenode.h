#ifndef KEYVALUENODE_H
#define KEYVALUENODE_H
namespace rn {
namespace internal {

template <class KeyT,class T>
class KeyValueNode{
   public:
    typedef KeyT key_type;
    typedef T mapped_type;
    mapped_type m_mapped;
private:

    
public:
    key_type m_key;

    KeyValueNode* rTree;
    KeyValueNode* lTree;





KeyValueNode(key_type k ,KeyValueNode* r = 0, KeyValueNode* l = 0 )
        :m_key(k),rTree(r),lTree(l){
        m_key = k;

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

key_type key()const{return m_key;}
mapped_type  mapped()const { return m_mapped; }
//KeyValueNode<KeyT,T>& find(const key_type& key);
//KeyValueNode<KeyT,T>* insert(const key_type&,const mapped_type&);
//KeyValueNode<KeyT,T>* clone();
#include "_keyvaluenode.h"


};

}

}

#endif // KEYVALUENODE_H
