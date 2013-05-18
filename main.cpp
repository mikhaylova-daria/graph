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

    Graph<int, int> x;

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

    cout<<"\nx.add_vtx (введите вершину):\n";
    Vetex <int> b;
    cin>>b;
    try {
        x.add_vtx(b);
    } catch (const char * & exp) {
        cout<< exp;
    }

    cout<<"\nx.add_edg (введите ребро):\n";
    Edge <int> a;
    cin >> a;
    try {
        x.add_edg(a);
    } catch (const char * & exp) {
        cout << exp;
    }

    cout<<"\ncout<<\n";
    cout<<x<<'\n';

    cout<<"\nx.rem_edg (введите id вершины начала и конца через пробел):\n";
    int i, j;
    cin >> i >> j;
    try {
        x.rem_edg(i , j);
    } catch (const char * & exp) {
        cout << exp;
    }

    cout<<"\nx.rem_vtx (введите id вершины):\n";
    int id;
    cin>>id;
    try {
        x.rem_vtx(id);
    } catch (const char * & exp) {
        cout<< exp;
    }

    cout<<"\ncout<<\n";
    cout<<x<<'\n';

    return 0;
}

