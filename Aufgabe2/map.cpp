#include "map.h"
#include<iostream>
using namespace std;
namespace rn {

bool Map::contains(const internal::KeyValueNode::key_type& rhs)const{
     cout << "Trying to find " << rhs.num() <<"/"<< rhs.denom()<<endl;
     if((m_root->find(rhs).mapped()) != 0 ){
       return true;
}
    return false;

}

Map& Map::operator=(const Map& rhs){
    if(m_root)
    {
        delete m_root;
    }
    cout << "Cloning"<< endl;
    m_root = rhs.m_root->clone();
    return *this;
}



Map::mapped_type& Map::operator[](const internal::KeyValueNode::key_type k){
   if(m_root == 0){
       m_root = new rn::internal::KeyValueNode(k);
       m_root->lTree = 0;
       m_root->rTree = 0;
   }

        return (m_root->find(k)).m_mapped;

}


const Map::mapped_type rn::Map::operator[](const internal::KeyValueNode::key_type k)const{
        cout << "Trying to find " << k.num()<<endl;
         return (m_root->find(k).mapped());



}

}
