
#include "izraz.hpp"
#include <map>
#include <vector>
using namespace std;

extern map<string, int> map_int;
extern vector<string> id_int;

//vrednost
int iKonstanta::vrednost() const {
    return _vr;
}

int fKonstanta::vrednost() const {
    return _vr;
}

int bKonstanta::vrednost() const {
    return _vr;
}

int Promenljiva::vrednost() const {
    map<string, int> :: iterator it;
    it = map_int.find(_id);
    if(it != map_int.end())
        return it->second;
    else {
        cerr << "Nije definisana promenljiva: " << _id << endl;
        exit(EXIT_FAILURE);
    }
}

int Zbir::vrednost() const {
    return _levi->vrednost() + _desni->vrednost();
}

int Razlika::vrednost() const {
    return _levi->vrednost() - _desni->vrednost();
}

int Proizvod::vrednost() const {
    return _levi->vrednost() * _desni->vrednost();
}

int Kolicnik::vrednost() const {
    return _levi->vrednost() / _desni->vrednost();
}

int Mod::vrednost() const {
    return _levi->vrednost() % _desni->vrednost();
}

int VeceJednako::vrednost() const {
    return _levi->vrednost() >= _desni->vrednost();
}

int ManjeJednako::vrednost() const {
    return _levi->vrednost() <= _desni->vrednost();
}

int Vece::vrednost() const {
    return _levi->vrednost() > _desni->vrednost();
}

int Manje::vrednost() const {
    if(_levi->vrednost() < _desni->vrednost())
        return 1;
    else 
        return 0;
}

int Jednako::vrednost() const {
    return _levi->vrednost() == _desni->vrednost();
}

int NijeJednako::vrednost() const {
    return _levi->vrednost() != _desni->vrednost();
}

//klonovi

Izraz* iKonstanta:: klon() const {
    return new iKonstanta(*this);
}

Izraz* fKonstanta:: klon() const {
    return new fKonstanta(*this);
}

Izraz* bKonstanta:: klon() const {
    return new bKonstanta(*this);
}

Izraz* Promenljiva:: klon() const {
    return new Promenljiva(*this);
}

Izraz* Zbir:: klon() const {
    return new Zbir(*this);
}

Izraz* Razlika:: klon() const {
    return new Razlika(*this);
}

Izraz* Proizvod:: klon() const {
    return new Proizvod(*this);
}

Izraz* Kolicnik:: klon() const {
    return new Kolicnik(*this);
}

Izraz* Mod:: klon() const {
    return new Mod(*this);
}

Izraz* VeceJednako:: klon() const {
    return new VeceJednako(*this);
}

Izraz* ManjeJednako:: klon() const {
    return new ManjeJednako(*this);
}

Izraz* Vece:: klon() const {
    return new Vece(*this);
}

Izraz* Manje:: klon() const {
    return new Manje(*this);
}

Izraz* Jednako:: klon() const {
    return new Jednako(*this);
}

Izraz* NijeJednako:: klon() const {
    return new NijeJednako(*this);
}

BinarniOp::~BinarniOp () {
  delete _levi;
  delete _desni;
}

BinarniOp::BinarniOp(const BinarniOp& op) {
  _levi = op._levi->klon();
  _desni = op._desni->klon();
}

BinarniOp& BinarniOp::operator=(const BinarniOp& op) {
  if (this != &op) {
    delete _levi;
    delete _desni;
    _levi = op._levi->klon();
    _desni = op._desni->klon();
  }
  return *this;
}

