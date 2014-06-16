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

    internal::KeyValueNode<KeyT,T>* m_root;

    typedef KeyT key_type;
    typedef T mapped_type;

Map():m_root(0){}
~Map(){
    if(m_root)
     delete m_root;
}
template<class KeyT,class T>
Map(const Map<KeyT,T>& rhs):m_root(0){
    *this = rhs;

}
//template<class KeyT,class T>
//Map<KeyT,T>& operator=(const Map<KeyT,T>& rhs);
//template<class KeyT,class T>
//mapped_type& operator[](const key_type k);
//template<class KeyT,class T>
//const mapped_type operator[](const key_type k) const;
//template<class KeyT,class T>
//bool contains(const key_type& rhs) const;

#include "_map.h"

};
}


#endif // MAP_H
