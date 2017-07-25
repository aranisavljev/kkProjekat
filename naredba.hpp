#ifndef __NAREDBA_HPP__
#define __NAREDBA_HPP__ 1
#include <string>
#include "izraz.hpp"
#include <vector>
#include <map>

using namespace std;

class Naredba{
public:
    virtual void interpretiraj() const=0;
    virtual ~Naredba() {}
    virtual Naredba* klon() const =0;
};

class IspisiString : public Naredba {
public:
    IspisiString(string s)
        :_s(s) {}
    void interpretiraj() const;
    Naredba* klon() const;
private:
    string _s;
};

class IspisiIzraz : public Naredba {
public:
    IspisiIzraz(Izraz *iz)
        :_iz(iz->klon()) {}
    void interpretiraj() const;
    Naredba* klon() const;
    IspisiIzraz& operator=(const IspisiIzraz& a);
    ~IspisiIzraz();
    IspisiIzraz(const IspisiIzraz &n);
private:
    Izraz *_iz;
};

class UcitajVrednost : public Naredba {
public:
    UcitajVrednost(string id)
        :_id(id) {}
    void interpretiraj() const;
    Naredba* klon() const;
private:
    string _id;
};

class Dodela : public Naredba {
public:
    Dodela(string id, Izraz *iz)
        :_id(id), _iz(iz->klon()) {}
    void interpretiraj() const;
    Dodela& operator=(const Dodela& a);
    ~Dodela();
    Dodela(const Dodela& a);
    Naredba* klon() const;
private:
    string _id;
    Izraz *_iz;    
};

class AkoJeOnda : public Naredba {
public:
    AkoJeOnda(Izraz *us, Naredba *n)
        :_us(us->klon()), _n(n->klon()) {}
    void interpretiraj() const;
    ~AkoJeOnda();
    Naredba* klon() const;
private:
    AkoJeOnda& operator=(const AkoJeOnda& a);
    AkoJeOnda(const AkoJeOnda& a);
    Izraz *_us;
    Naredba *_n;
};

class AkoJeOndaInace : public Naredba {
public:
    AkoJeOndaInace(Izraz *us, Naredba *n1, Naredba *n2)
        :_us(us->klon()), _n1(n1->klon()), _n2(n2->klon()) {} 
    void interpretiraj() const;
    ~AkoJeOndaInace();
    Naredba* klon() const;
private:
    AkoJeOndaInace& operator=(const AkoJeOndaInace& a);
    AkoJeOndaInace(const AkoJeOndaInace& a);
    Izraz *_us;
    Naredba *_n1;
    Naredba *_n2;
};

class DokJeOnda : public Naredba {
public:
    DokJeOnda(Izraz *us, Naredba *n)
        :_us(us->klon()), _n(n->klon()) {} 
    void interpretiraj() const;
    ~DokJeOnda();  
    Naredba* klon() const;
private:
    DokJeOnda& operator=(const DokJeOnda& a);
    DokJeOnda(const DokJeOnda& a);  
    Izraz *_us;
    Naredba *_n;
};

class ForPetlja : public Naredba {
public:
    ForPetlja(string id, Izraz *iz1, Izraz *iz2, Naredba *n, int oznaka)
        :_id(id), _iz1(iz1->klon()), _iz2(iz2->klon()), _n(n->klon()), _oznaka(oznaka) {} 
    void interpretiraj() const;
    ~ForPetlja();  
    Naredba* klon() const;
private:
    ForPetlja& operator=(const ForPetlja& a);
    ForPetlja(const ForPetlja& a);  
    string _id;
    Izraz *_iz1;
    Izraz *_iz2;
    Naredba *_n;
    int _oznaka;
};


class Blok : public Naredba {
public:
    Blok(vector<Naredba*> vn)
        :_vn(vn) {}
    void interpretiraj() const;
    Naredba* klon() const;
private:
    Blok& operator=(const Blok& a);
    Blok(const Blok& a);
    vector<Naredba*> _vn;
};



#endif