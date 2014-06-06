#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "rationalnumber.h"
#include "keyvaluenode.h"
using namespace std;
namespace rn{

class Map{



public:
    internal::KeyValueNode* m_root;
    typedef rn::RationalNumber key_type;
    typedef int mapped_type;

Map():m_root(0){
    m_root;
    cout << "created:"<< (m_root) << endl;}

~Map(){
    if(m_root)
     delete m_root;
}



Map& operator=(const Map& rhs){
    if(m_root)
    {
        delete m_root;
    }
    m_root = rhs.m_root;
    rn::Map returnMap();
  //  returnMap.m_root = m_root;
    return *this;
}

Map(const Map& rhs): m_root(0){
    *this = rhs;
}

mapped_type& operator[](const key_type k);
const mapped_type operator[](const key_type k) const;

bool contains(const key_type& rhs) const;


};
}


#endif // MAP_H
