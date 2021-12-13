#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

//fctn prototypes
string makelower(string ing);
void print(vector<string> ing, vector<string> check);
void goodalc(vector<string> ing);
void badalc(vector<string> ing);
void humect(vector<string> ing);
void prot(vector<string> ing);

int main()
{
  //read in ingredients
  cout << endl;
  ifstream fin_ing;
  fin_ing.open("ingredients.txt");
  vector<string> ingredients;

  string ing;
  while (getline(fin_ing, ing))
  {
    //make lower case so can compare to lowercase letters
    ing = makelower(ing);
    ingredients.push_back(ing);
  }
  fin_ing.close();

  //check for and print ingredients
  goodalc(ingredients);
  badalc(ingredients);
  humect(ingredients);
  prot(ingredients);

  return 0;
}

string makelower(string ing) {
  for (int i = 0; i < ing.size(); i++) {
    char low;
    low = tolower(ing[i]);
    ing[i] = low;
  }
  return ing;
}

void print(vector<string> ing, vector<string> check) {
  int j = 0, count = 0;
  while (j != check.size())
  {
    for (int i = 0; i < ing.size(); i++)  //until reached end of ingredients list
    {
      string ing_str, check_str;
      ing_str = ing[i];
      check_str = check[j];
      
      int found = ing_str.find(check_str);
      if (found != string::npos)
      {
        count++;
        cout << count << ". ingredient: " << ing_str << endl;
        cout << setw(15) << "found: " << check_str << endl;
      }
    }
    j++;
  }
  if (count == 0)
    cout << "none" << endl;
  cout << endl;
}

void goodalc(vector<string> ing) {
  //read good alcohols
  ifstream fin_goodalc;
  fin_goodalc.open("goodalcohols.txt");
  vector<string> goodalcohols;

  string goodalc;
  while (getline(fin_goodalc, goodalc))
  {
    goodalc = makelower(goodalc);
    goodalcohols.push_back(goodalc);
  }
  fin_goodalc.close();

  cout << "**********************" << endl 
    << setfill(' ') << setw(17) << "GOOD ALCOHOLS" << endl 
    << "**********************" << endl;
  
  print(ing, goodalcohols);
}

void badalc(vector<string> ing)
{
  //read bad alcohols
  ifstream fin_badalc;
  fin_badalc.open("badalcohols.txt");
  vector<string> badalcohols;

  string badalc;
  while (getline(fin_badalc, badalc))
  {
    badalc = makelower(badalc);
    badalcohols.push_back(badalc);
  }
  fin_badalc.close();

  cout << "**********************" << endl 
    << setfill(' ') << setw(17) << "BAD ALCOHOLS" << endl 
    << "**********************" << endl;
  
  print(ing, badalcohols);
}

void humect(vector<string> ing)
{
  //read humectants
  ifstream fin_humect;
  fin_humect.open("humectants.txt");
  vector<string> humectants;

  string humect;
  while (getline(fin_humect, humect))
  {
    humect = makelower(humect);
    humectants.push_back(humect);
  }
  fin_humect.close();

  cout << "**********************" << endl 
    << setfill(' ') << setw(16) << "HUMECTANTS" << endl 
    << "**********************" << endl;

  print(ing, humectants);
}

void prot(vector<string> ing)
{
  //read proteins
  ifstream fin_prot;
  fin_prot.open("proteins.txt");
  vector<string> proteins;

  string prot;
  while (getline(fin_prot, prot))
  {
    prot = makelower(prot);
    proteins.push_back(prot);
  }
  fin_prot.close();

  cout << "**********************" << endl 
    << setfill(' ') << setw(14) << "PROTEINS" << endl 
    << "**********************" << endl;
  
  print(ing, proteins);
}