#include <iostream>
#include <vector>
using namespace std;
class MedicalSec
{
  protected:
  string name;
  int patient, health, death, mid_years;
  public:
  MedicalSec(string name, int patient, int health, int death, int mid_years):
  name(name), patient(patient), health(health), death(death), mid_years(mid_years){};
  virtual void info() = 0;
  virtual int get_patient() = 0;
  virtual int year_old() = 0;
};
///////////////////////////

template<class T>
class Container
{
  vector<T>cont;
  public:
  void push(T obj);
  void sort();
  void old_sort();
  void display(T obj);
  void display_full();
  void operator[](int index);
  void clear();
};

template<class T>
void Container<T>::clear() {
  cont.clear();
}

template<class T>
void Container<T>::push(T obj) {
  cont.push_back(obj);
}

template<class T>
void Container<T>::display(T obj) {
  obj -> info();
}

template<class T>
void Container<T>::display_full() {
  for(auto i : cont) {
    i -> info();
  }
}

template<class T>
void Container<T>::sort() {
  const double step = 1.25;
  int  value = cont.size() - 1;

  while(value >= 1) {
    for(size_t i = 0; i + value < cont.size(); i++) {
        if(cont[i + value] -> get_patient() > cont[i] -> get_patient()){
            swap(cont[i + value], cont[i]);
        }
    }
    value /= step;
  }
}

template<class T>
void Container<T>::operator[](int index) {
  if(index >= 0)
    cont[index] -> info();
  else
    cout << "Wrong value" << endl;
}

template<class T>
void Container<T>::old_sort() {
  const double step = 1.25;
  int  value = cont.size() - 1;

  while(value >= 1) {
    for(size_t i = 0; i + value < cont.size(); i++) {
        if(cont[i + value] -> year_old() > cont[i] -> year_old()){
            swap(cont[i + value], cont[i]);
        }
    }
    value /= step;
  }
}


///////////////////////////
class Policklinik: public MedicalSec
{
  public:
  Policklinik(string name, int patient, int health, int death, int mid_years):
  MedicalSec(name, patient, health, death, mid_years){};
  Policklinik(Policklinik &obj):
  MedicalSec(obj.name, obj.patient, obj.health, obj.death, obj.mid_years) {};
  virtual void info();
  virtual int get_patient(){return health;};
  virtual int year_old(){return mid_years;};
};



void Policklinik::info() {
   cout << "Name:" << name << endl;
   cout << "Number of patients:" << patient << endl;
   cout << "Total recovered patients:" << health << endl;
   cout << "Total dead:" << death << endl;
   cout << "Average patient age:" << mid_years << endl << endl;
}
/////////////////////

class San_chast: public MedicalSec
{
  public:
  San_chast(string name, int patient, int health, int death, int mid_years):
  MedicalSec(name, patient, health, death, mid_years){};
  San_chast(San_chast &obj):
  MedicalSec(obj.name, obj.patient, obj.health, obj.death, obj.mid_years) {};
  virtual void info();
  virtual int get_patient(){return health;};
  virtual int year_old(){return mid_years;};
};



void San_chast::info() {
   cout << "Name:" << name << endl;
   cout << "Number of patients(now):" << patient << endl;
   cout << "Total recovered patients:" << health << endl;
   cout << "Total dead:" << death << endl;
   cout << "Average patient age:" << mid_years << endl << endl;
}
///////////////////////

class Hospital: public MedicalSec
{
  public:
  Hospital(string name, int patient, int health, int death, int mid_years):
  MedicalSec(name, patient, health, death, mid_years){};
  Hospital(Hospital &obj):
  MedicalSec(obj.name, obj.patient, obj.health, obj.death, obj.mid_years) {};
  virtual int get_patient(){return health;};
  virtual void info();
  virtual int year_old(){return mid_years;};
};

void Hospital::info() {
   cout << "Name:" << name << endl;
   cout << "Number of patients(now):" << patient << endl;
   cout << "Total recovered patients:" << health << endl;
   cout << "Total dead:" << death << endl;
   cout << "Average patient age:" << mid_years << endl << endl;
}
///////////////////

class Sanatorium: public MedicalSec
{
  public:
  Sanatorium(string name, int patient, int health, int death, int mid_years):
  MedicalSec(name, patient, health, death, mid_years){};
  Sanatorium(Sanatorium &obj):
  MedicalSec(obj.name, obj.patient, obj.health, obj.death, obj.mid_years) {};
  virtual int get_patient(){return health;};
  virtual void info();
  virtual int year_old(){return mid_years;};
};

void Sanatorium::info() {
   cout << "Name:" << name << endl;
   cout << "Number of patients(now):" << patient << endl;
   cout << "Total recovered patients:" << health << endl;
   cout << "Total dead:" << death << endl;
   cout << "Average patient age:" << mid_years << endl << endl;
}
///////////////////

class Clinic: public MedicalSec
{
  public:
  Clinic(string name, int patient, int health, int death, int mid_years):
  MedicalSec(name, patient, health, death, mid_years){};
  Clinic(Clinic &obj):
  MedicalSec(obj.name, obj.patient, obj.health, obj.death, obj.mid_years) {};
  virtual int get_patient(){return health;};
  virtual void info();
  virtual int year_old(){return mid_years;};
};

void Clinic::info() {
   cout << "Name:" << name << endl;
   cout << "Number of patients(now):" << patient << endl;
   cout << "Total recovered patients:" << health << endl;
   cout << "Total dead:" << death << endl;
   cout << "Average patient age:" << mid_years << endl << endl;
}


int main()
{
    Sanatorium san("San center", 120, 45, 5, 67);
    Container <MedicalSec*> data;
    data.push(&san);
    cout << "Sanatorium test info:" << endl;
    data.display(&san);

    cout << "Clinic test info:" << endl;
    Clinic clnc("Clinic center", 200, 75, 4, 45);
    data.push(&clnc);
    data.display(&clnc);

    Hospital hosp("Hospital of st Maria", 600, 800, 170, 25);
    data.push(&hosp);
    Hospital hosp1("John's Hospital", 700, 250, 20, 30);
    Policklinik obj(hosp1);
    data.push(&obj);

    cout << "View full stack:" << endl;
    data.display_full();

    cout << "If you want rate table:" << endl;
    data.sort();
    data.display_full();

    cout << "If you want see first place in this rate:" << endl;
    data[0];

    cout << "If you want old category:" << endl;
    data.old_sort();
    data.display_full();

    data.clear();
    return 0;
}
