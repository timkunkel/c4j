#include "keyvaluenode.h"

using namespace rn::internal;


KeyValueNode* find(const KeyValueNode& node){
    if(node.m_key == m_key)
        return &this;
    else if(&node == 0){
        return 0;
    }
    else if(node.m_key < m_key){
        find(lTree);
    }else{
        find(lTree);
    }

}
void insert(const key_type& key,const mapped_type& mapped){
    if(key.m_key == m_key){
        m_mapped = mapped.m_mapped;
    }
    else if(key.m_key < m_key){
        if(lTree = 0)
            lTree = new KeyValueNode(key,mapped);
        else
            lTree.insert(key,mapped);
    }
    else{
        if(rTree = 0)
            rTree = new KeyValueNode(key,mapped);
        else
            rTree.insert(key,mapped);
    }
}
