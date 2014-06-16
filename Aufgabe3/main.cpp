/*
 *
 * C / C++ für Java-Programmierer
 * Einfacher Test-Treiber für class RationalNumber
 * Autor: Hartmut Schirmacher
 *
 */

#include "assert.h"
#include "map.h"
#include <string>
#include "rationalnumber.h"

using namespace std;
using namespace rn;

void outPut(rn::internal::KeyValueNode<float,string>* node){
    if(node != 0){
        cout << "Node:" <<node->key()<< " = "<< node->mapped()  << endl;
        if(node->lTree != 0){
        cout << "Left:" <<node->lTree->key()<< " = "<< node->lTree ->mapped()  << endl;
        if(node->rTree == 0)
            cout<<""<< endl;
        }
        if(node->rTree != 0){
        cout << "Right:" <<node->rTree->key()<< " = "<< node->rTree ->mapped() <<"\n\n" << endl;
      }
        if(node->lTree != 0)
            outPut(node->lTree);
        if(node->rTree != 0){
            outPut(node->rTree);
    }
}
}

void doMapTests(){

    rn::RationalNumber a(1,1);
    RationalNumber b(2,3);
    RationalNumber c(1,4);
    RationalNumber d(5,1);
    string s = "eins";

    cout << "Starting tests" << endl;
    Map<float,std::string> map;
    cout<< map.m_root << endl;
    assert(!map.contains(2));
    cout << "Passed 1" << endl;
    map[2.0] = s;
    assert(map.contains(2.0));

    cout << map[2.0] << endl;
     map[2.0f] = "Zwei";
     map[2.1f] = "Zwei komma Eins";
     map[0.1f] = "Null komma eins";
     map[0.01f] = "Sehr Klein";

     cout << map[2.0] << endl;
     //cout << "Root:" <<map.m_root->key()<< " = "<< map.m_root->mapped()  << endl;
    // cout << "Left:" <<map.m_root->lTree->key()<< " = "<< map.m_root->lTree ->mapped()  << endl;
    // cout << "Right:" <<map.m_root->rTree->key()<< " = "<< map.m_root->rTree ->mapped()  << endl;
    outPut(map.m_root);
    cout << "PAssed" << endl;

  //  cout << "Map contains" << map.contains(RationalNumber(2,3)) << endl;

   // map[3] = 4;
    cout << "PAssed" << endl;

   // map[d] = 1;
   // map[2] =5;
    cout << "PAssed" << endl;

   // map[c] = 2;
   // int i;
   // i = map[a];


    //cout << "Map contains" << map.contains(RationalNumber(2,3)) << endl;

  //  cout << "Map root: "<<map.m_root->key().num() << "/" << map.m_root->key().denom() <<
  //          "Left Tree: "<<map.m_root->lTree->key().num() << "/" << map.m_root->lTree->key().denom() <<
   //         "Left Tree: "<<map.m_root->rTree->key().num() << "/" << map.m_root->rTree->key().denom() <<
    //        endl;
   //Map<RationalNumber,int> newMap = map;
   // cout << outputString(newMap.m_root, 3)<< endl;
    //cout << "Now its:" << map[a] <<endl;
   // cout << map.contains(a)<< endl;

}

void doUnitTests_RationalNumber() {

    cout << "Starting unit tests for class RationalNumber..." << endl;

    {
        // test default constructor, isValid(), and accessor num()
        cout << "- default constructor..." << flush;
        RationalNumber a;
        assert(a.isValid());
        assert(a.num() == 0);
        cout << " passed." << endl;
    }

    {
        // test non-default constructors and both accessors num() and denom()
        cout << "- more constructors..." << flush;
        RationalNumber a(1,2);
        //a[3] = 1;
        assert(a.isValid());
        assert(a.num() == 1);
        assert(a.denom() == 2);

        // constructors with single argument: equivalent to integer
        RationalNumber b(0);
        assert(b.isValid());
        assert(b.num() == 0 && b.denom() == 1);

        RationalNumber c(7);
        assert(c.isValid());
        assert(c.num() == 7 && c.denom() == 1);

        cout << " passed." << endl;
    }

    {
        // test const RationalNumber objects, operator==(), normalization, and inverse()
        cout << "- const..." << flush;
        const RationalNumber a(6,4), b(3,2);
        assert(a.isValid());
        assert(b.isValid());
        assert(a == b);
        assert(a.inverse() == RationalNumber(2,3));

        cout << " passed." << endl;
    }

    {
        // addition and unary minus
        cout << "- operator+()..." << flush;
        const RationalNumber a(3,2), b(4,3), c(3*3+4*2,2*3);
        assert(a + b == c);
        assert(a + (-a) == RationalNumber(0));

        cout << " passed." << endl;
    }

    {
        // order
        cout << "- ordered sequence..." << flush;
        const RationalNumber a(2,3), b(3,4), c(-4,5);
        assert(a < b);
        assert(c < a);
        assert(c < b);
        assert(!(a < c));
        cout << " passed." << endl;
    }

    cout << "Unit tests for class RationalNumber finished!" << endl;

}

int main()
{
    doMapTests();
//  doUnitTests_RationalNumber();
  //  doUnitTests_RationalNumber();
    return 0;
}
