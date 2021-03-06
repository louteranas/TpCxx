#include "Dvector.h"



Dvector::Dvector()
{
	this->dim = 0;
	this->data = nullptr;
    //cout << "Constructeur par défaut appelé ! \n";
}

Dvector::Dvector(int size, const double ini)
{
    this->dim = size;
    this->data = new double[size];
    for(int i = 0; i < size; i++){
        this->data[i] = ini;
    }
    //cout << "Constructeur avec initialisation appelé ! \n";
}

Dvector::Dvector(const Dvector &vector){
    this->dim = vector.dim;
    if(this->dim == 0){
        this->data = nullptr;
        return;
    }
    this->data = new double[vector.dim];
    for(int i =0; i < this->dim; i++){
        this->data[i] = vector.data[i];
    }
    //cout << "Constructeur par copie appelé ! \n";
}

Dvector::~Dvector(){
	if(this->data != nullptr){
		delete[] this->data;
	}
	this->data = nullptr;
    //cout << "Destructeur appelé ! \n";
}

Dvector::Dvector(string file){
    ifstream fichier(file, ios::in);
    if(!fichier) //si l'ouverture a échoué
    {
        this->dim = 0;
        this->data = nullptr;
    }
    else{
        int taille = 0;
        while(fichier.ignore(numeric_limits<int>::max(), '\n'))
            taille++;
        fichier.clear();
        fichier.seekg(0, ios::beg);
        this->dim = taille;
        //cout << taille << "\n";
        this->data = new double[taille];
        string ligneData;
        int ligne = 0;
        while(getline(fichier, ligneData)){
            if(ligneData != "\n"){
                this->data[ligne] = stod(ligneData);
                ligne++;
            }
        }
        fichier.close();
    }
    //cout << "Constructeur par fichier appelé ! \n";
}

double &Dvector::operator()(int index){
    return this->data[index];
}

double Dvector::operator()(int index) const{
    return this->data[index];
}

Dvector &Dvector::operator=(const Dvector &sourceVecteur){
    this->dim = sourceVecteur.dim;
    this->data = new double[this->dim];
    memcpy(this->data, sourceVecteur.data, dim*sizeof(double));
    return *this;
}

Dvector &Dvector::operator-=(const double op){
    for(int i = 0; i< this->dim; i++){
        this->data[i] = this->data[i] - op;
    }
    return *this;
}

Dvector &Dvector::operator*=(const double op){
    for(int i = 0; i< this->dim; i++){
        this->data[i] = this->data[i] * op;
    }
    return *this;
}

Dvector &Dvector::operator/=(const double op){
    if(op!=0){
        for(int i = 0; i< this->dim; i++){
    this->data[i] = this->data[i]/ op;
        }
        return *this;
    }
    else{
        cerr << "Division par 0 \n";
        exit(1);
    }
}

Dvector &Dvector::operator+=(const double op){
    for(int i = 0; i< this->dim; i++){
        this->data[i] = this->data[i] + op;
    }
    return *this;
}

Dvector &Dvector::operator=(Dvector &&d){
	swap(this->dim, d.dim);
	swap(this->data, d.data);
	return *this;
}

Dvector &Dvector::operator+=(const Dvector &sourceVecteur){
    if(sourceVecteur.dim != this->dim){
       cerr << "les vecteurs n'ont pas la meme taille \n";
       exit(1);
    }
    else{
        for(int i = 0; i< this->dim; i++){
            this->data[i] = this->data[i] + sourceVecteur.data[i];
        }
        return *this;
    }
}


Dvector &Dvector::operator-=(const Dvector &sourceVecteur){
    if(sourceVecteur.dim != this->dim){
       cerr << "les vecteurs n'ont pas la meme taille \n";
       exit(1);
    }
    else{
        for(int i = 0; i< this->dim; i++){
            this->data[i] = this->data[i] - sourceVecteur.data[i];
        }
        return *this;
    }
}

ostream &operator<<(ostream &out, const Dvector &vect){
    out << "Dvector : ";
    for(int i = 0; i< vect.size()-1; i++){
        out << vect(i) <<", ";
    }
    out << vect(vect.size()-1) <<"." << "\n";
    return out;
}

istream &operator>>(istream &in, const Dvector &vect){
    cout << "coucou \n";
    for(int i = 0; i< vect.size(); i++){
        /*cout << i<<"\n";
        double *number;
        in >> *number;
        memcpy(vect(0) +i*sizeof(double), number, sizeof(double));
        */
    }
    return in;
}

Dvector operator+(const Dvector &v1, const double op){
    Dvector outputVect(v1);
    outputVect += op;
    return outputVect;
}


Dvector operator-(const Dvector &v1, const double op){
    Dvector outputVect(v1);
    outputVect -= op;
    return outputVect;
}

Dvector operator*(const Dvector &v1, const double op){
    Dvector outputVect(v1);
    /*for(int i = 0; i< v1.size(); i++){
        outputVect(i) = v1(i) * op;
    }*/
    outputVect *= op;
    return outputVect;
}

Dvector operator/(const Dvector &v1, const double op){
      if(op!=0){
          Dvector outputVect(v1);
          /*for(int i = 0; i< v1.size(); i++){
              outputVect(i) = v1(i) / op;
          }*/
          outputVect /= op;
          return outputVect;
      }
      else{
          cerr << "Division par 0 \n";
          exit(1);
      }

}

Dvector operator+(const Dvector &v1, const Dvector &v2){
    Dvector outputVect(v1);
    for(int i = 0; i< v1.size(); i++){
        outputVect(i) = v1(i) + v2(i);
    }
    return outputVect;
}


Dvector operator-(const Dvector &v1, const Dvector &v2){
     Dvector outputVect(v1.size());
     for(int i = 0; i< v1.size(); i++){
         outputVect(i) = v1(i) - v2(i);
     }
     return outputVect;
}


Dvector operator-(const Dvector &v1){
    Dvector outputVect(v1.size());
     for(int i = 0; i< v1.size(); i++){
         outputVect(i) = - v1(i);
     }
     return outputVect;
}


bool Dvector::operator==(const Dvector &v2){
    if(this->dim != v2.dim){
        return false;
    }
    for(int i = 0; i< v2.dim; i++){
        if(this->data[i] != v2.data[i]){
            return false;
        }
    }
    return true;
}



void Dvector::display(ostream& str) const{
	str << setprecision(3);
	for (int i = 0; i<this->dim; i++){
		str << this->data[i] << "\n";
	}

}

void Dvector::resize(int newSize, double init){
    if(this->dim == newSize) {
        return;
    } else if(this->dim > newSize) {
        this->dim = newSize;
    } else {
        double* newData = new double[newSize];
        for(int i = 0; i < this->dim; i++){
            newData[i] = this->data[i];
        }
        for(int i = this->dim; i < newSize; i++){
            newData[i] = init;
        }
        this->data = newData;
        this->dim = newSize;
    }

}


int Dvector::size()
{
    return this->dim;
}

int Dvector::size()const
{
    return this->dim;
}

void Dvector::fillRandomly(){
    srand(time(NULL));
    for(int i = 0; i<this->dim; i++){
        this->data[i] = (double)rand()/(double) RAND_MAX;
    }
}
