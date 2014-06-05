#include "map.h";

using namespace rn;

bool Map::contains(const key_type& rhs){
     if(m_root->find(rhs))
         return true;
     else
         return false;

}
