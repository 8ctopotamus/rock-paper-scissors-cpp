#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string choices[3] = { "r", "p", "s" };

string toLowerCase(string s) 
{
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

bool isValidChoice(string choice)
{
  return find(begin(choices), end(choices), choice) != end(choices);
}