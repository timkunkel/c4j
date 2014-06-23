KeyValueNode<key_type, mapped_type>* find(const key_type& key){

    if(key == value_t.first){
        return this;
    }
    else if(key < value_t.first){
        if(lTree == 0)
            return 0;
        return  lTree->find(key);
    }
    else {
        if(rTree == 0){
            return 0;
        }
        return rTree->find(key);
    }
    return 0;
}

KeyValueNode<key_type, mapped_type>* clone(){
    KeyValueNode<key_type, mapped_type>* clonedNode = new KeyValueNode(value_t.first);
    clonedNode->value_t.second = value_t.second;
    clonedNode->parent = parent;
    if(rTree != 0){
        clonedNode->rTree = rTree->clone();
    }
    if(lTree != 0){
        clonedNode->lTree = lTree->clone();
    }
    return clonedNode;
}

KeyValueNode<key_type, mapped_type>& insert(const key_type& newKey,const mapped_type& newMapped){
    if(newKey == value_t.first){
        value_t.second = newMapped;
        return *this;
    }
    else if(newKey < value_t.first){
        if(lTree == 0){
            lTree = new KeyValueNode(newKey);
            lTree->parent = this;
            lTree->value_t.second = newMapped;
            return *lTree;
        }
        else
            return lTree->insert(newKey,newMapped);
    }
    else {
        if(rTree == 0){
            rTree = new KeyValueNode(newKey);
            rTree->parent = this;
            rTree->value_t.second = newMapped;
            return *rTree;
        }
        else
            return  rTree->insert(newKey,newMapped);
    }
    return *this;
}

KeyValueNode<key_type,mapped_type>* findNext(){
    if(rTree != 0)
        return rTree->findSmallest();

    KeyValueNode<key_type,mapped_type>* parentNode = parent;
    while(key() > parentNode->key() && parentNode != 0)
        parentNode = parentNode->parent;

    return parentNode;

}

KeyValueNode<key_type,mapped_type>* findSmallest(){
    if(lTree == 0){
        return this;
    }
    return  lTree->findSmallest();
}

KeyValueNode<key_type,mapped_type>* findBiggest(){
    if(rTree == 0){
        return this;
        return rTree;
    }
    return  rTree->findBiggest();
}

