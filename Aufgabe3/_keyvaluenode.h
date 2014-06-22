KeyValueNode<key_type, mapped_type>* find(const key_type& key){
    if(this == 0){
        return 0;
    }
    if(key == value_t.first){
        return this;
    }
    else if(key < value_t.first){
        if(lTree == 0)
            return 0;
        lTree->find(key);
    }
    else if(key > value_t.first){
        if(rTree == 0){
            return 0;
        }
        rTree->find(key);
    }
    return 0;
}

template <class key_type,class mapped_type>
KeyValueNode<key_type, mapped_type>* clone(){    
    KeyValueNode* clonedNode = new KeyValueNode(value_t.first, value_t.second);
    if(rTree != 0){
        clonedNode->rTree = rTree->clone();
    }
    if(lTree != 0){
        clonedNode->lTree = lTree->clone();
    }
    return clonedNode;
}

template <class key_type,class mapped_type>
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
            cout << "Creating new lTree with " << newKey << " " << newMapped << endl;
        }
        else
            lTree->insert(newKey,newMapped);
    }
    else if(newKey > value_t.first){
        if(rTree == 0){
            rTree = new KeyValueNode(newKey);
            rTree->parent = this;
            rTree->value_t.second = newMapped;
        }
        else
            rTree->insert(newKey,newMapped);
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

