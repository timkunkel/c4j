#ifndef KEYVALUENODE_H
#define KEYVALUENODE_H
#include "rationalnumber.h"
namespace rn {
namespace internal {


class KeyValueNode{
   public:
    typedef RationalNumber key_type;
    typedef int mapped_type;
    mapped_type m_mapped;
private:

    
public:
    key_type m_key;

    KeyValueNode* rTree;
    KeyValueNode* lTree;






    KeyValueNode(const key_type& k,mapped_type m=0,KeyValueNode* r = 0, KeyValueNode* l = 0 )
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

    key_type key()const{return m_key;}
    mapped_type  mapped()const { return m_mapped; }
    KeyValueNode& find(const key_type& key);
    KeyValueNode* insert(const key_type&,const mapped_type&);
    KeyValueNode* clone();



};

}

}

#endif // KEYVALUENODE_H
