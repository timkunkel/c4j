#ifndef KEYVALUENODE_H
#define KEYVALUENODE_H
#include "rationalnumber.h"
namespace rn {
namespace internal {


class KeyValueNode{
   public:
    typedef RationalNumber key_type;
    typedef int mapped_type;
private:
    key_type m_key;
    mapped_type m_mapped;
    KeyValueNode* rTree;
    KeyValueNode* lTree;
    
public:



    KeyValueNode(const key_type& k,const mapped_type& m):m_key(0),m_mapped(0),rTree(0),lTree(0){
        m_key = k;
        m_mapped = m;
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
    mapped_type mapped() const { return m_mapped;}
    KeyValueNode* find(const key_type& key);
    void insert(const key_type&,const mapped_type&);
    KeyValueNode* clone();



};

}

}

#endif // KEYVALUENODE_H
