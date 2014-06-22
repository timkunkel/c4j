#ifndef KEYVALUENODE_H
#define KEYVALUENODE_H
#include <iostream>
using namespace std;
namespace rn {
namespace internal {

template <class KeyT,class T>
class KeyValueNode{
public:
    typedef KeyT key_type;
    typedef T mapped_type;
    pair<key_type,mapped_type> value_t;
private:

    
public:

    KeyValueNode* rTree;
    KeyValueNode* lTree;
    KeyValueNode* parent;

    KeyValueNode(key_type k ,KeyValueNode* r = 0, KeyValueNode* l = 0,KeyValueNode* p = 0 )
        :rTree(r),lTree(l),parent(p){

        value_t.first = k;

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
        cout << "Operator =" << endl;
        value_t.first = rhs.key();
        value_t.second = rhs.mapped();

     return *this;

    }
    KeyValueNode& operator=(const mapped_type& rhs){
        cout << "Operator =" << endl;
       // value_t.first = rhs.key();
        value_t.second = rhs;

     return *this;

    }

    key_type key()const{return value_t.first;}
    mapped_type  mapped()const { return value_t.second; }
    //KeyValueNode<KeyT,T>* find(const key_type& key);
    //KeyValueNode<KeyT,T>& insert(const key_type&,const mapped_type&);
    //KeyValueNode<KeyT,T>* clone();
#include "_keyvaluenode.h"


};

}

}

#endif // KEYVALUENODE_H
