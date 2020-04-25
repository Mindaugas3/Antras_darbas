#include "Studentas.h"

// konstruktoriaus realizacija
Studentas::Studentas(std::istream& is) { 
  // kreipiasi á Studentas::readStudent;
  readStudent(is, *this);  
}

Studentas::Studentas(const Studentas& s){
	//kopijavimo konstruktorius
	this->vardas_ = s.vardas();
	this->pavarde_ = s.pavarde();
	this->nd_ = s.printND();
	this->egzaminas_ = s.egzaminas();
}

// Studentas::readStudent realizacija
std::istream& Studentas::readStudent(std::istream& I, const Studentas& S) {
  // Member funkcijos realizacija paremta ankstesniojo 2-ojo darbo funkcija: 
  // std::istream& readStudent(std::istream&, Studentas&)
    std::string vardas, pavarde;
  	I >> vardas;
  	I >> pavarde;
  	set_vardas(vardas);
  	set_pavarde(pavarde);
  	float ndbalas;
	std::vector<float> ndzmogui;
	while(I >> ndbalas){
		//namu darbai - vektorius.
		ndzmogui.push_back(ndbalas);			
	}
	int J = (int) ndzmogui.size();
	set_egzaminas(ndzmogui.at(J - 1));
	ndzmogui.pop_back();
	set_nd(ndzmogui);
	//S.egzaminas_ = egzaminas; 
    return I;
}

// Ne Studentas member funkcija, bet dirba su Studentas objektais, todël realizacija èia
bool compare(const Studentas&, const Studentas&) {
  // realizacija 
}

//seteriai
void Studentas::set_vardas(std::string vardas){
	this->vardas_ = vardas;
}

void Studentas::set_pavarde(std::string pavarde){
	this->pavarde_ = pavarde;
}

void Studentas::set_egzaminas(float balas){
	this->egzaminas_ = balas;
}

void Studentas::set_nd(std::vector<float> nd){
	this->nd_ = nd;
}

float Studentas::vidurkis() const{
	float tempvid = 0;
	int J = 1;
	while(J < this->nd_.size()){
			tempvid += this->nd_.at(J - 1) * 0.4;
			J++;
		}
	tempvid /= J;
	tempvid += this->egzaminas_ * 0.6;
	return tempvid;
}

//operatoriai - priskyrimas
Studentas Studentas::operator= (const Studentas& s){
	this->set_vardas(s.vardas());
	this->set_pavarde(s.pavarde());
	this->set_egzaminas(s.egzaminas());
	this->set_nd(s.printND());
}

//destruktorius
Studentas::~Studentas(){
	//nd_.clear();
}

/* Realizacija likusiø (member) funkcijø
 .
 .
 .
*/
