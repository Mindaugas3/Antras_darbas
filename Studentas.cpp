#include "Studentas.h"

// konstruktoriaus realizacija
Studentas::Studentas(std::istream& is) { 
  // kreipiasi � Studentas::readStudent;
  readStudent(is);  
}

// Studentas::galBalas realizacija
double Studentas::galBalas(double (*) (vector<double>) = mediana) const {
  // ...
}

// Studentas::readStudent realizacija
std::istream& Studentas::readStudent(std::istream&) {
  // Member funkcijos realizacija paremta ankstesniojo 2-ojo darbo funkcija: 
  // std::istream& readStudent(std::istream&, Studentas&)
}

// Ne Studentas member funkcija, bet dirba su Studentas objektais, tod�l realizacija �ia
bool compare(const Studentas&, const Studentas&) {
  // realizacija 
}

/* Realizacija likusi� (member) funkcij�
 .
 .
 .
*/
