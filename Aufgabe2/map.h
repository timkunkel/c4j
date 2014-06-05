#ifndef MAP_H
#define MAP_H
#include "rationalnumber.h"
#include "keyvaluenode.h"

namespace rn{
class Map{
public:
    typedef RationalNumber key_type;
    typedef int mapped_type;

private:
    internal::KeyValueNode* m_root;
public:

Map():m_root(0){}

~Map(){
    if(m_root)
     delete m_root;
}
Map& operator=(const Map& rhs){
    if(m_root)
        delete m_root;

    m_root = rhs.m_root;


}

Map(const Map& rhs): m_root(0){
    *this = rhs;
}




key_type operator[](const key_type& k);
bool contains(const key_type& rhs);


};
}




#endif // MAP_H
