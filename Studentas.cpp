#include "Studentas.h"

// konstruktoriaus realizacija
Studentas::Studentas(std::istream& is) { 
  // kreipiasi á Studentas::readStudent;
  readStudent(is, *this);  
}

// Studentas::readStudent realizacija
std::istream& Studentas::readStudent(std::istream& I, const Studentas& S) {
  // Member funkcijos realizacija paremta ankstesniojo 2-ojo darbo funkcija: 
  // std::istream& readStudent(std::istream&, Studentas&)
    std::string vardas, pavarde;
  	I >> vardas;
  	I >> pavarde;
  	S.vardas_ = vardas;
  	S.pavarde_ = pavarde;
  	float ndbalas;
	std::vector<float> ndzmogui;
	while(I >> ndbalas){
		//namu darbai - vektorius.
		ndzmogui.push_back(ndbalas);			
	}
	int J = (int) ndzmogui.size();
	float egzaminas = ndzmogui.at(J - 1);
	ndzmogui.pop_back();
	S.nd_ = ndzmogui;
	//S.egzaminas_ = egzaminas; 
    return I;
}

// Ne Studentas member funkcija, bet dirba su Studentas objektais, todël realizacija èia
bool compare(const Studentas&, const Studentas&) {
  // realizacija 
}

float Studentas::vidurkis() const{
	float tempvid = 0;
	int J = 0;
	while(J < this->nd_.size()){
			tempvid += this->nd_.at(J) * 0.4;
			J++;
		}
	tempvid /= J;
	tempvid += this->egzaminas_ * 0.6;
	return tempvid;
}

/* Realizacija likusiø (member) funkcijø
 .
 .
 .
*/
