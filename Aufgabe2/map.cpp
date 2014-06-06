#include "map.h";
#include<iostream>

namespace rn {
using namespace std;


bool Map::contains(const key_type& rhs)const{
   //  if(m_root->find(rhs) )
   //      return true;
   //  else
         return false;

}



Map::mapped_type& Map::operator[](const internal::KeyValueNode::key_type k){
    cout << "Trying to add "<< k.num() <<"/"<<k.denom()<<endl;
   if(m_root == 0){
       m_root = new rn::internal::KeyValueNode(k);
   }

        return (m_root->find(k)).m_mapped;

}
const Map::mapped_type rn::Map::operator[](const Map::key_type k)const{

         return (m_root->find(k).mapped());



}

}
