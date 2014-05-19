#ifndef MAP_H
#define MAP_H
#include "rationalnumber.h"

namespace map{
class Map{
public:
    typedef rn::RationalNumber key_type;
    typedef int mapped_type;

private:
    class KeyValueNode{


        KeyValueNode():
            key_type(new rn::RationalNumber(),0){

        }

        KeyValueNode(key_type k,mapped_type m){
            key_type = k;
            mapped_type = m;
        }

    };

    KeyValueNode* root;


public:

Map():
    key_type(new rn::RationalNumber(0,0)),mapped_type(0){}

~Map(){
    delete
}

}


}

#endif // MAP_H
