#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
template <typename U> struct Edge;
template <typename T> struct Vetex;
typedef std::set <int> list_adjacency; // список - сет id смежных вершин



template <typename U>
struct Edge {
    int id;
    int first_v;
    int second_v;
    U weight;
    Edge(){;}
    Edge (int _first_v, int _second_v, U _weight):id(((_first_v + _second_v) * (_first_v + _second_v) + 3 * _first_v + _second_v)/2 ), first_v(_first_v), second_v(_second_v), weight( _weight){;}
    bool operator == (const Edge& edg) const{ return (id == edg.id); }
    bool operator < (const Edge &edg) const { return (id < edg.id); }
    Edge & operator = (const Edge & edg){
        id = edg.id;
        first_v = edg.first_v;
        second_v = edg.second_v;
        weight = edg.weight;
        return (*this);
    }
    friend std::istream& operator>> (std::istream& istr, Edge<U> & edr){
        istr >> edr.first_v >> edr.second_v >> edr.weight;
        edr.id = ((edr.first_v + edr.second_v)* (edr.first_v + edr.second_v) + 3 * edr.first_v + edr.second_v)/2 ;
        return istr;
    }

    friend std::ostream& operator << (std::ostream& ostr, Edge<U> const & edr) {
        ostr << edr.id << " " << edr.first_v << "-" << edr.second_v <<" "<< edr.weight<<'\n';
        return ostr;
    }

};

template <typename T>
struct Vetex {
    int id;
    T value;
    list_adjacency list;
    Vetex(){;}
    Vetex(int _id, T _value): id(_id), value(_value){;}
    bool operator == (const Vetex & vtx) const { return (id == vtx.id); }
    bool operator < (const Vetex & vtx) const { return (id < vtx.id); }

    Vetex & operator = (const Vetex & vtx){
        id = vtx.id;
        value = vtx.value;
        list = vtx.list;
        return (*this);
    }
    friend std::istream& operator >>  (std::istream& istr, Vetex<T> & vtx){
        istr >> vtx.id >> vtx.value;
        return istr;
    }

    friend std::ostream& operator << (std::ostream& ostr, Vetex<T> const & vtx) {
        ostr << vtx.id << " " << vtx.value << '\n';
        return ostr;
    }
};


template < typename T, typename U> class Graph
{

    map <int, Vetex<T> > map_vtx;// ключ id - значение - id, вес вершины список смежности
    map <int, Edge<U> > map_edg; // id ребра, начала, конца, вес

public:
    Graph(){;}

    bool add_vtx(const Vetex <T> &_vtx);
    bool add_edg(const Edge<U> & _edg);
    bool rem_vtx (const int & _id);
    void erase (const int &_id);
};
    //Добавление вершины
template < typename T, typename U>
    bool Graph<T, U>::add_vtx(const Vetex <T> &_vtx) {
        std::pair<int, Vetex<T> > vtx;
        vtx.first = _vtx.id;
        vtx.second = _vtx;
        if (map_vtx.insert(vtx).second != true){
            throw ("recurring_id");
            return false;
        }
        return true;
    }

    //Добавление ребра
template < typename T, typename U>
     bool Graph<T, U>::add_edg (const Edge<U> & _edg) {
        pair<int, Edge<U> > edg;
        edg.first = _edg.id;
        edg.second = _edg;
        if (map_edg.insert(edg).second == true) { // добавили в сет графов
            typename map<int, Vetex<T> >::iterator itr;// = map_vtx.find(_first);
            if (itr == map_vtx.end()) {
                throw ("unknown_vetex");
                return false;
            }
            if ((itr->second.list.insert(_edg.second_v)).second == false) { //вставили в список для вершины начала вторую вершину
                throw ("recurring_id");
                return false;
            }
        }
        return true;
    }

     // Удаление вершины
template < typename T, typename U>
     bool Graph<T, U>::rem_vtx (const int & _id) {
         typename map <int, Vetex<T> >::iterator itr_id;
         itr_id = map_vtx.find(_id);
         if (itr_id == map_vtx.end()){
             return false;
         } else {
             typename list_adjacency::iterator itr_i;
             itr_i = (*itr_id).second.list.begin();
             for (; itr_i != (*itr_id).second.list.end(); ++itr_i) {
                 map_edg.erase((((_id + (*itr_i))* (_id + (*itr_i)) + 3 * _id + (*itr_i))/2));
             }
             return true;
         }
     }



#endif // GRAPH_H
