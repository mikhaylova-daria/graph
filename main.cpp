//#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    Vetex <int> b, c;
    cin>>b;
    cout<<b;
    cin>>c;
    cout<<c;
    Edge <int> a;
    cin >> a;
    cout<< a;
    Graph<int, int> x;
    x.add_vtx(b);
    //cout<<"!"<<endl;
    x.add_vtx(c);
    //cout<<"!"<<endl;
    x.add_edg(a);

    //cout<<"!"<<endl;
    cin>>x;
    cout<<x;
    x.rem_vtx(b.id);
    return 0;
}

