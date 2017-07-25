#include "naredba.hpp"
#include <map>
#include <vector>
#include <iostream>
using namespace std;

extern map<string, int> map_int;
extern vector<string> id_int;

//kopi konstruktori

IspisiIzraz::IspisiIzraz(const IspisiIzraz &n) {
  _iz = n._iz->klon();
}

Dodela::Dodela(const Dodela& a){
    _id=a._id;
    _iz=a._iz->klon();
}

AkoJeOnda::AkoJeOnda(const AkoJeOnda& a){
    _us=a._us->klon();
    _n=a._n->klon();
}

AkoJeOndaInace::AkoJeOndaInace(const AkoJeOndaInace& a){
    _us=a._us->klon();
    _n1=a._n1->klon();
    _n2=a._n2->klon();
}

DokJeOnda::DokJeOnda(const DokJeOnda& a){
    _us=a._us->klon();
    _n=a._n->klon();
}

ForPetlja::ForPetlja(const ForPetlja& a){
    _id=a._id;
    _iz1=a._iz1->klon();
    _iz2=a._iz2->klon();
    _n=a._n->klon();
}

Blok::Blok(const Blok& a){
    for(auto i : a._vn)
        _vn.push_back(i);
}


//operatori dodele

IspisiIzraz& IspisiIzraz::operator=(const IspisiIzraz& a) {
  if(this != &a) {
    delete _iz;
    _iz = a._iz->klon();
  }
  return *this;
}


Dodela& Dodela::operator=(const Dodela& a) {
  if(this != &a) {
    delete _iz;
    _iz = a._iz->klon();
    _id = a._id;
  }
  return *this;
}

AkoJeOnda& AkoJeOnda::operator=(const AkoJeOnda& a) {
  if(this != &a) {
    delete _us;
    delete _n;
    _us = a._us->klon();
    _n = a._n;
  }
  return *this;
}

AkoJeOndaInace& AkoJeOndaInace::operator=(const AkoJeOndaInace& a) {
  if(this != &a) {
    delete _us;
    delete _n1;
    delete _n2;
    _us = a._us->klon();
    _n1 = a._n1->klon();
    _n2 = a._n2->klon();    
  }
  return *this;
}

DokJeOnda& DokJeOnda::operator=(const DokJeOnda& a) {
  if(this != &a) {
    delete _us;
    delete _n;
    _us = a._us->klon();
    _n = a._n;
  }
  return *this;
}


ForPetlja& ForPetlja::operator=(const ForPetlja& a) {
  if(this != &a) {
      delete _iz1;
      delete _iz2;
      delete _n;
      _iz1 = a._iz1->klon();
      _iz2 = a._iz2->klon();
      _n = a._n->klon();
  }
  return *this;
}


Blok& Blok::operator=(const Blok& a) {
  if(this != &a) {
    for(auto i : _vn)
        delete i;
    for(auto i : a._vn)
        _vn.push_back(i);
  }
  return *this;
}

//interpreter

void IspisiString::interpretiraj() const{
    cout << _s << endl;
}

void IspisiIzraz::interpretiraj() const {
    cout << _iz->vrednost() << endl;
}

void UcitajVrednost::interpretiraj() const {
    for(vector<string>::iterator i=id_int.begin(); i!=id_int.end(); ++i)
        if(!(_id.compare(*i))) {
            int pom;
            cin >> pom;
            if(map_int.count(_id))
                map_int[_id] = pom;
            else
                map_int.insert(std::pair<string,int>(_id,pom)); 
        }
}

void Dodela::interpretiraj() const {
    for(vector<string>::iterator i=id_int.begin(); i!=id_int.end(); ++i)
        if(!(_id.compare(*i))) {
            if(map_int.count(_id))
                map_int[_id] = _iz->vrednost();
            else
                map_int.insert(std::pair<string,int>(_id,_iz->vrednost())); 
        }
}

void AkoJeOnda::interpretiraj() const {
    if(_us->vrednost()){
        _n->interpretiraj();
        }
}

void AkoJeOndaInace::interpretiraj() const {
    if(_us->vrednost())
        _n1->interpretiraj();
    else
        _n2->interpretiraj();
}

void DokJeOnda::interpretiraj() const {
    while(_us->vrednost())
        _n->interpretiraj();
}

void ForPetlja::interpretiraj() const {
    for(vector<string>::iterator i=id_int.begin(); i!=id_int.end(); ++i)
        if(!(_id.compare(*i))) {
            if(map_int.count(_id))
                map_int[_id] = _iz1->vrednost();
            else
                map_int.insert(std::pair<string,int>(_id,_iz1->vrednost())); 
        }
    if(_oznaka==1){
        while(map_int[_id] < _iz2->vrednost()){
            _n->interpretiraj();
            map_int[_id]++;
        }
    }
    else {
        while(map_int[_id] > _iz2->vrednost()){
            _n->interpretiraj();
            map_int[_id]--;
        }
    }
}

void Blok::interpretiraj() const {
    for(Naredba* i : _vn)
        i->interpretiraj();
    
}

//destruktori

IspisiIzraz::~IspisiIzraz() {
    delete _iz;
}

Dodela::~Dodela() {
    delete _iz;
}

AkoJeOnda::~AkoJeOnda() {
    delete _us;
    delete _n;
}
AkoJeOndaInace::~AkoJeOndaInace() {
    delete _us;
    delete _n1;
    delete _n2;
}
DokJeOnda::~DokJeOnda() {
    delete _us;
    delete _n;

}

ForPetlja::~ForPetlja(){
    delete _iz1;
    delete _iz2;
    delete _n;
}

// klon

Naredba* IspisiString::klon() const {
    return new IspisiString(*this);
}

Naredba*  IspisiIzraz::klon() const {
    return new IspisiIzraz(*this);
}

Naredba* UcitajVrednost:: klon() const {
    return new UcitajVrednost(*this);
}

Naredba* Dodela:: klon() const {
    return new Dodela(*this);
}

Naredba* AkoJeOnda:: klon() const {
    return new AkoJeOnda(*this);
}

Naredba* AkoJeOndaInace:: klon() const {
    return new AkoJeOndaInace(*this);
}

Naredba* DokJeOnda:: klon() const {
    return new DokJeOnda(*this);
}

Naredba* ForPetlja:: klon() const {
    return new ForPetlja(*this);
}

Naredba* Blok:: klon() const {
    return new Blok(*this);
}




