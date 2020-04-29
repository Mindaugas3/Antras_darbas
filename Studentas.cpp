#include "Studentas.h"

Asmuo::Asmuo(){
	vardas_ = "";
	pavarde_ = "";
}

Asmuo::Asmuo(std::string vardas, std::string pavarde){
	vardas_ = vardas;
	pavarde_ = pavarde;
}

Asmuo::Asmuo(const Asmuo& X){
	Asmuo::set_vardas(X.vardas());
	Asmuo::set_pavarde(X.pavarde());
}

void Asmuo::set_pavarde(std::string pavarde){
	pavarde_ = pavarde;
}

void Asmuo::set_vardas(std::string vardas){
	vardas_ = vardas;
}
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
std::istream& Studentas::readStudent(std::istream& I, Studentas& S) {
  // Member funkcijos realizacija paremta ankstesniojo 2-ojo darbo funkcija: 
  // std::istream& readStudent(std::istream&, Studentas&)
    std::string vardas, pavarde;
  	I >> vardas;
  	I >> pavarde;
  	S.set_vardas(vardas);
  	S.set_pavarde(pavarde);
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

bool Studentas::gavoSkola() const{
	return (this->vidurkis() < 5);
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
	int J = 0;
	if(this->nd_.empty()) return 0;
	
	while(J < this->nd_.size()){
			tempvid += this->nd_.at(J) * 0.4;
			J++;
		}
	tempvid /= J;
	tempvid += this->egzaminas_ * 0.6;
	return tempvid;
}

//operatoriai - priskyrimas
Studentas Studentas::operator = (const Studentas& s){
	this->set_vardas(s.vardas());
	this->set_pavarde(s.pavarde());
	this->set_egzaminas(s.egzaminas());
	this->set_nd(s.printND());
	return *this; //pamirsau return *this, todel crashino
}

//palyginimo operatoriai
bool Studentas::operator > (const Studentas& s) const{
	if(this->vidurkis() == s.vidurkis()) return this->pavarde() > s.pavarde();
	return this->vidurkis() > s.vidurkis();
}

bool Studentas::operator < (const Studentas& s) const{
	if(this->vidurkis() == s.vidurkis()) return this->pavarde() < s.pavarde();
	return this->vidurkis() < s.vidurkis();
}

//destruktorius

Studentas::~Studentas(){
	nd_.clear();
}


/* Realizacija likusiø (member) funkcijø
 .
 .
 .
*/
