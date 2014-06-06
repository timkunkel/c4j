#ifndef MAP_H
#define MAP_H
#include "rationalnumber.h"
#include "keyvaluenode.h"

namespace rn{

class Map{



public:
    internal::KeyValueNode* m_root;
    typedef RationalNumber key_type;
    typedef int mapped_type;

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

mapped_type operator[](const key_type& k){
        return m_root->find(k)->mapped();

}
const mapped_type& operator[](const key_type& k)const{

         return m_root->find(k)->mapped();



}

bool contains(const key_type& rhs) const;


};
}


#endif // MAP_H
