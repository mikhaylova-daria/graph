//#include <iostream>
#include "graph.h"
using namespace std;
template <typename T>
struct my_show {
    void operator() (T x) {
        std::cout << x;
        return;
    }
};


int main()
{
    struct my_show<Vetex<int> > show_vtx;
    struct my_show <Edge<int> > show_edg;
//    Vetex <int> b, c;
//    cin>>b;
//    cout<<b;
//    cin>>c;
//    cout<<c;
//    Edge <int> a;
//    cin >> a;
//    cout<< a;
    Graph<int, int> x;
//    x.add_vtx(b);
//    //cout<<"!"<<endl;
//    x.add_vtx(c);
//    //cout<<"!"<<endl;
//    x.add_edg(a);

    cin>>x;

    cout<<"\ncout<<\n";
    cout<<x<<'\n';

    cout<<"\nx.transpose():\n";
    x.transpose();
    cout<<x;

    list<Vetex<int> > list_vtx;
    cout<<"\nx.get_vetices():\n";
    list_vtx = x.get_vetices();
    for_each(list_vtx.begin(), list_vtx.end(), show_vtx);

    cout<<"\nx.get_vetices_inbox(1):\n";
    list_vtx = x.get_vetices_inbox(1);
    for_each(list_vtx.begin(), list_vtx.end(), show_vtx);

    cout<<"\nx.get_vetices_outbox(1):\n";
    list_vtx = x.get_vetices_outbox(1);
    for_each(list_vtx.begin(), list_vtx.end(), show_vtx);

    cout<<"\nx.get_edges():\n";
    list<Edge<int> > list_edg;
    list_edg = x.get_edges();
    for_each(list_edg.begin(), list_edg.end(), show_edg);

    cout<<"\nx.get_edges_inbox(1):\n";
    list_edg = x.get_edges_inbox(1);
    for_each(list_edg.begin(), list_edg.end(), show_edg);

    cout<<"\nx.get_edges_outbox(1):\n";
    list_edg = x.get_edges_outbox(1);
    for_each(list_edg.begin(), list_edg.end(), show_edg);

    return 0;
}

