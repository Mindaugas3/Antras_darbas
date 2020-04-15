#include "Studentas.h"

// konstruktoriaus realizacija
Studentas::Studentas(std::istream& is) { 
  // kreipiasi á Studentas::readStudent;
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

// Ne Studentas member funkcija, bet dirba su Studentas objektais, todël realizacija èia
bool compare(const Studentas&, const Studentas&) {
  // realizacija 
}

/* Realizacija likusiø (member) funkcijø
 .
 .
 .
*/
