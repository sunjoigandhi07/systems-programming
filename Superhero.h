#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <stdbool.h>
#include <string>

class Superhero {

 private:
  std::string* firstName;
  std::string* lastName;
  std::string* heroName;

 
 public:
  
  Superhero(std::string* firstName, std::string* lastName, std::string* heroName);
  std::string getHeroName();
  Superhero(const Superhero& sh);

  ~Superhero();

  Superhero& operator=(const Superhero& sh); //assignment operator, removed Superhero::
  bool operator==(const Superhero& sh) const; //comparison operator, removed Superhero::
  bool operator<(const Superhero& sh); //less than operator
friend std::ostream& operator<<(std::ostream& os, const Superhero& sh); //output operator  
};

    #endif

