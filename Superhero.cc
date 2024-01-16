#include <iostream>
#include <vector>
#include <string>
#include "Superhero.h"

Superhero::Superhero(std::string* firstName, std::string* lastName, std::string* heroName) {
   this->firstName = new std::string(*firstName);
   this->lastName = new std::string(*lastName);
   this->heroName = new std::string(*heroName);
 };
  
std::string Superhero::getHeroName() {
  return *this->heroName;
  }

Superhero::Superhero(const Superhero& sh) {
  this->firstName = new std::string(*sh.firstName);
  this->lastName = new std::string(*sh.lastName);
  this->heroName = new std::string(*sh.heroName);
}

Superhero::~Superhero() {
  delete(this->firstName);
  delete(this->lastName);
  delete(this->heroName);//fn, lm, hm
    std::cout << "Dst called\n";
}

Superhero& Superhero::operator=(const Superhero& sh) { //took out  Superhero:: before operator

  delete(this->firstName);
  delete(this->lastName);
  delete(this->heroName);
  
 this->firstName = new std::string(*sh.firstName);
  this->lastName = new std::string(*sh.lastName);
  this->heroName = new std::string(*sh.heroName);
  
  std::cout << "assign\n";
  
  return *this;
}

bool Superhero::operator==(const Superhero& sh) const {
  
  return ((*this->firstName == *sh.firstName) && (*this->lastName == *sh.lastName) && (*this->heroName == *sh.heroName));
}

std::ostream& operator<<(std::ostream& os, const Superhero& sh) {
  os << *sh.firstName << " "  << *sh.lastName;
  return os;
}

//less than operator
bool Superhero::operator<(const Superhero& sh) {
  if(*this->lastName != *sh.lastName) {
    return (*this->lastName > *sh.lastName);
  } else {
    return (*this->firstName > *sh.firstName);
  }
}
