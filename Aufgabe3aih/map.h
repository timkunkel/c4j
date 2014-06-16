#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "rationalnumber.h"
#include "keyvaluenode.h"
using namespace std;
namespace rn{
template <class KeyT,class T>
class Map{



public:

    typename internal::KeyValueNode<KeyT,T>* m_root;

    KeyT key_type;
    T mapped_type;

Map():m_root(0){}

~Map(){
    if(m_root)
     delete m_root;
}

Map(const Map<KeyT,T>& rhs):m_root(0){
    *this = rhs;

}
template<class KeyT,class T>
typename Map<KeyT,T>& operator=(const Map<KeyT,T>& rhs){
    if(m_root)
    {
        delete m_root;
    }
    cout << "Cloning"<< endl;
    m_root = rhs.m_root->clone();
    return *this;
}


template<class KeyT,class T>
T& operator[](const typename KeyT k){
    if(m_root == 0){
        m_root = new rn::internal::KeyValueNode<KeyT,T>(k);
        m_root->lTree = 0;
        m_root->rTree = 0;
    }

         return (m_root->find(k)).m_mapped;

 }

template<class KeyT,class T>
const T operator[](const KeyT k) const{
    //cout << "Trying to find " << k.num()<<endl;
     return (m_root->find(k).mapped());



}




template<class KeyT,class T>
bool contains(const KeyT& rhs) const{
         cout << "Trying to find " << rhs.num() <<"/"<< rhs.denom()<<endl;
         if((m_root->find(rhs).mapped()) != 0 ){
           return true;
    }
        return false;
}


//template<class KeyT,class T>
//typename Map<KeyT,T>& clone(const Map& map);


};
}


#endif // MAP_H
