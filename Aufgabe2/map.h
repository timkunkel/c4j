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

Map():m_root(0){}

~Map(){
    if(m_root)
     delete m_root;
}

Map(const Map& rhs):m_root(0){
    *this = rhs;

}



Map& operator=(const Map& rhs);

Map(const Map& rhs): m_root(0){
    *this = rhs;
}

mapped_type& operator[](const key_type k);
const mapped_type operator[](const key_type k) const;

bool contains(const key_type& rhs) const;
Map& clone(const Map& map);


};
}


#endif // MAP_H
