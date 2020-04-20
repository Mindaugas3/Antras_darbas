#include <iostream>
#include <string>
#include <vector>



class Studentas {
// realizacija
private:
  std::string vardas_;
  std::string pavarde_;
  float egzaminas_;
  std::vector<float> nd_;
// interfeisas
public:
  Studentas() : egzaminas_(0) { }  // default konstruktorius
  Studentas(std::istream& is);
  inline std::string vardas() const { return vardas_; }    // get'eriai, inline
  inline std::string pavarde() const { return pavarde_; }  // get'eriai, inline
  inline std::vector<float> printND() const { return nd_;}
  inline float egzaminas() const { return egzaminas_;}
  float vidurkis() const;
  std::istream& readStudent(std::istream& I, const Studentas& s);  // set'eriai
};
