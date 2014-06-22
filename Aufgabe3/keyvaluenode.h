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
    pair<const key_type,mapped_type> value_t;

private:    
    
public:    
    KeyValueNode* rTree;
    KeyValueNode* lTree;
    KeyValueNode* parent;

    KeyValueNode(key_type k ,KeyValueNode* r = 0, KeyValueNode* l = 0,KeyValueNode* p = 0 )
        :rTree(r),lTree(l),parent(p),value_t(k,*(new mapped_type())){

    }

    ~KeyValueNode(){
        if(rTree!=0){
            delete rTree;
        }
        if(lTree!=0){
            delete lTree;
        }
    }





    key_type key()const{return value_t.first;}
    mapped_type  mapped()const { return value_t.second; }
#include "_keyvaluenode.h"
};
}
}
#endif // KEYVALUENODE_H
