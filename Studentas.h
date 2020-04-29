#include <iostream>
#include <string>
#include <vector>

class Asmuo {	
	protected:
		std::string vardas_;
		std::string pavarde_;
		Asmuo();
		Asmuo(std::string vardas, std::string pavarde);
		Asmuo(const Asmuo& X);
	public:
  		virtual void set_vardas(std::string vardas) = 0;
  		virtual void set_pavarde(std::string pavarde) = 0;
	 	virtual std::string vardas() const = 0;    // get'eriai, inline
  		virtual std::string pavarde() const = 0;  // get'eriai, inline
		virtual ~Asmuo(){};
};

class Studentas : public Asmuo{
// realizacija
private:
  float egzaminas_;
  std::vector<float> nd_;
// interfeisas
public:
  //konstruktoriai
  Studentas() : egzaminas_(0) { }  // default konstruktorius
  Studentas(std::istream& is);
  Studentas(const Studentas& s);
  //geteriai

  inline std::vector<float> printND() const { return nd_;}
  float vidurkis() const;
  bool gavoSkola() const;
  inline float egzaminas() const { return egzaminas_;}
   std::string pavarde() const { return pavarde_; }
   std::string vardas() const { return vardas_; }
  //seteriai

  	void set_vardas(std::string vardas);
  	void set_pavarde(std::string pavarde);
    void set_egzaminas(float balas);
    void set_nd(std::vector<float> nd);

  std::istream& readStudent(std::istream& I, Studentas& s);  // set'eriai
  Studentas operator= (const Studentas& s);
  bool operator> (const Studentas& s) const;
  bool operator< (const Studentas& s) const;
  ~Studentas();
};
