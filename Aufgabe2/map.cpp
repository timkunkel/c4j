#include "map.h";

namespace rn {



bool Map::contains(const key_type& rhs)const{
     if(m_root->find(rhs))
         return true;
     else
         return false;

}

}
