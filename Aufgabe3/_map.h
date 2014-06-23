template <class key_type,class mapped_type>
bool contains(const key_type& rhs)const{
    if(m_root == 0)
        return false;
    if((m_root->find(rhs)) != NULL ){
        cout << "Found" << endl;
        return true;
    }
    return false;
}

template <class key_type,class mapped_type>
rn::Map<key_type,mapped_type>& operator=(const Map<key_type,mapped_type>& rhs){
    if(m_root)
    {
        delete m_root;
    }
    m_root = rhs.m_root->clone();
    return *this;
}

template <class key_type,class mapped_type>
mapped_type& operator[](const key_type& k){
    if(m_root == 0){
        m_root = new rn::internal::KeyValueNode<KeyT,T>(k);
    }
    if(m_root->find(k) == 0){
        return (m_root->insert(k,m_root->mapped())).m_mapped;
    }
    else{
        return (m_root->insert(k,m_root->find(k)->mapped())).m_mapped;
    }
}

template <class key_type,class mapped_type>
const mapped_type operator[](const key_type k)const{
    return  (m_root->find(k).mapped());
}




