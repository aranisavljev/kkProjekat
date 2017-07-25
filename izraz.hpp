#ifndef __IZRAZ_HPP__ 
#define __IZRAZ_HPP__ 1

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>

using namespace std;

class Izraz
{
public:
    virtual int vrednost() const=0;
    virtual ~Izraz() {

    }
    virtual Izraz* klon() const=0;
};

class iKonstanta : public Izraz
{
public:
    iKonstanta(int vr)
        :_vr(vr) {}
    int vrednost() const;
    Izraz* klon() const;
private:
    int _vr;
};

class fKonstanta : public Izraz
{
public:
    fKonstanta(float vr)
        :_vr(vr) {}
    int vrednost() const;
    Izraz* klon() const;
private:
    float _vr;
};

class bKonstanta : public Izraz
{
public:
    bKonstanta(int vr)
        :_vr(vr) {}
    int vrednost() const;
    Izraz* klon() const;
private:
    int _vr;
};

class Promenljiva : public Izraz
{
public:
    Promenljiva(string id)
        :_id(id) {}
    int vrednost() const;
    Izraz* klon() const;
private:
    string _id;
};

class BinarniOp : public Izraz
{
public:
    BinarniOp(Izraz* levi, Izraz* desni)
        :_levi(levi->klon()), _desni(desni->klon()) {}
    BinarniOp(const BinarniOp &op);
    BinarniOp &operator=(const BinarniOp &op);
    ~BinarniOp();

protected:
    Izraz *_levi;
    Izraz *_desni; 
};

class Zbir : public BinarniOp
{
public:
    Zbir(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;    
};

class Razlika : public BinarniOp
{
public:
    Razlika(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;  
};

class Proizvod : public BinarniOp
{
public:
    Proizvod(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;     
};

class Kolicnik : public BinarniOp
{
public:
    Kolicnik(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;  
};

class Mod : public BinarniOp
{
public:
    Mod(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;    
};

class VeceJednako : public BinarniOp
{
public:
    VeceJednako(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;
     
};

class ManjeJednako : public BinarniOp
{
public:
    ManjeJednako(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;  
};

class Vece : public BinarniOp
{
public:
    Vece(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;   
};

class Manje : public BinarniOp
{
public:
    Manje(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;
};

class Jednako : public BinarniOp
{
public:
    Jednako(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;  
};

class NijeJednako : public BinarniOp
{
public:
    NijeJednako(Izraz* levi, Izraz* desni)
        :BinarniOp(levi, desni) {}
    int vrednost() const;
    Izraz* klon() const;  
};

#endif 