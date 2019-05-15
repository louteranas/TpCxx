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
    double **tab;
    tab = new double*[size];
    for(int i = 0; i < size; i++) {
        tab[i] = new double[2];
        tab[i][0] = ini;
        tab[i][1] = ini;
    }
    this->data = tab;
    //cout << "Constructeur avec initialisation appelé ! \n";
}

Dvector::Dvector(const Dvector &vector){
    this->dim = vector.dim;
    if(this->dim == 0){
        this->data = nullptr;
        return;
    }
    this->data = new double*[vector.dim];
    for(int i = 0; i < this->dim; i++){
        this->data[i] = new double[2];
        this->data[i][0] = vector.data[i][0];
        this->data[i][1] = vector.data[i][1];
    }
    //cout << "Constructeur par copie appelé ! \n";
}

Dvector::~Dvector(){
	if(this->data != nullptr){
        for(int i = 0; i < this->dim; i++) {
            delete[] this->data[i];
        }
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
        this->data = new double*[taille];
        string ligneData;
        int ligne = 0;
        while(getline(fichier, ligneData)){
            if(ligneData != "\n"){
                this->data[ligne] = new double[2];                
                this->data[ligne][0] = stod(ligneData);
                this->data[ligne][1] = 0;
                ligne++;
            }
        }
        fichier.close();
    }
    //cout << "Constructeur par fichier appelé ! \n";
}

double** &Dvector::getdata() {
    return this->data;
}

double** Dvector::getdata() const {
    return this->data;
}

double &Dvector::operator()(int index){
    return this->data[index][0];
}

double Dvector::operator()(int index) const{
    return this->data[index][0];
}

Dvector &Dvector::operator=(const Dvector &sourceVecteur){
    this->dim = sourceVecteur.dim;
    this->data = new double*[this->dim];
    for(int i = 0; i < this->dim; i++) {
        this->data[i] = new double[2];
        this->data[i][0] = sourceVecteur.getdata()[i][0];
        this->data[i][1] = sourceVecteur.getdata()[i][1];
    }
    return *this;
}

Dvector &Dvector::operator-=(const double op){
    for(int i = 0; i< this->dim; i++){
        this->data[i][0] = this->data[i][0] - op;
    }
    return *this;
}

Dvector &Dvector::operator*=(const double op){
    for(int i = 0; i< this->dim; i++){
        this->data[i][0] = this->data[i][0] * op;
    }
    return *this;
}

Dvector &Dvector::operator/=(const double op){
    if(op!=0){
        for(int i = 0; i< this->dim; i++){
            this->data[i][0] = this->data[i][0]/ op;
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
        this->data[i][0] = this->data[i][0] + op;
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
            this->data[i][0] = this->data[i][0] + sourceVecteur.data[i][0];
            this->data[i][1] = this->data[i][1] + sourceVecteur.data[i][1];
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
            this->data[i][0] = this->data[i][0] - sourceVecteur.data[i][0];
            this->data[i][1] = this->data[i][1] - sourceVecteur.data[i][1];
        }
        return *this;
    }
}

ostream &operator<<(ostream &out, const Dvector &vect){
    out << "Dvector : ";
    for(int i = 0; i< vect.size()-1; i++){
        out << "(" << vect.getdata()[i][0] <<", " << vect.getdata()[i][1] << "), ";
    }
    out << "(" << vect.getdata()[vect.size()-1][0] << ", " << vect.getdata()[vect.size()-1][1] << ")." << "\n";
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
        outputVect.getdata()[i][0] = v1.getdata()[i][0] + v2.getdata()[i][0];
        outputVect.getdata()[i][1] = v1.getdata()[i][1] + v2.getdata()[i][1];
    }
    return outputVect;
}


Dvector operator-(const Dvector &v1, const Dvector &v2){
     Dvector outputVect(v1.size());
     for(int i = 0; i< v1.size(); i++){
        outputVect.getdata()[i][0] = v1.getdata()[i][0] - v2.getdata()[i][0];
        outputVect.getdata()[i][1] = v1.getdata()[i][1] - v2.getdata()[i][1];
     }
     return outputVect;
}


Dvector operator-(const Dvector &v1){
    Dvector outputVect(v1.size());
     for(int i = 0; i< v1.size(); i++){
         outputVect.getdata()[i][0] = - v1.getdata()[i][0];
         outputVect.getdata()[i][1] = - v1.getdata()[i][1];
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
		str << "(" << this->data[i][0] << ", " << this->data[i][1] <<")\n";
	}
}

void Dvector::resize(int newSize, double init){
    if(this->dim == newSize) {
        return;
    } else if(this->dim > newSize) {
        this->dim = newSize;
    } else {
        double** newData = new double*[newSize];
        for(int i = 0; i < this->dim; i++){
            newData[i] = new double[2];
            newData[i][0] = this->data[i][0];
            newData[i][1] = this->data[i][1];
        }
        for(int i = this->dim; i < newSize; i++){
            newData[i] = new double[2];
            newData[i][0] = init;
            newData[i][1] = init;
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
        this->data[i][0] = (double)rand()/(double) RAND_MAX;
        this->data[i][1] = (double)rand()/(double) RAND_MAX;
    }
}

void Dvector::fft() {
  //On suppose dim puissance de 2
  if(this->dim <=1) {
    return;
  }
  Dvector even(this->dim / 2), odd(this->dim / 2);
  for(int i = 0, j = 0, k = 0; i < this->dim; i++) {
    if(i%2 == 0) {
      even.getdata()[j][0] = this->data[i][0];      
      even.getdata()[j][1] = this->data[i][1];
      j++;
    } else {
      odd.getdata()[k][0] = this->data[i][0];      
      odd.getdata()[k][1] = this->data[i][1];
      k++;
    }
  }
  // cout << "even : " << even;
  // cout << "odd : " << odd;
  even.fft();
  odd.fft();
  double t[2];
  for(int k = 0; k < (this->dim / 2); k++) {
      double x = odd.getdata()[k][0];
      double y = odd.getdata()[k][1];
      double theta = -2.0 * 3.14159265358979323846 * k / this->dim;
      t[0] = x * cos(theta) - y * sin(theta) ;
      t[1] = x * sin(theta) + y * cos(theta);
      this->data[k][0] = t[0] + even.getdata()[k][0];
      this->data[k][1] = t[1] + even.getdata()[k][1];
      this->data[k + (this->dim / 2)][0] = even.getdata()[k][0] - t[0];
      this->data[k + (this->dim / 2)][1] = even.getdata()[k][1] - t[1];
  }
}

void Dvector::ifft() {
  if(this->dim <=1) {
    return;
  }
  //Conjugué
  for(int i = 0; i < this->dim; i++) {
    this->data[i][1] = - this->data[i][1];
  }
  this->fft();
  for(int i = 0; i < this->dim; i++) {
    this->data[i][1] = - this->data[i][1] / this->dim;
    this->data[i][0] = this->data[i][0] / this->dim;
  }  
}

void Dvector::fft2d(int nx, int ny){
  Dvector vnx(nx);
  Dvector vny(ny);
  // FFT DE CHAQUE LIGNE
  for(int i = 0; i < ny; i++) {
    //Recopiage de la ligne i dans vnx
    for(int x = 0; x < nx; x++) {
      vnx.getdata()[x][0] = this->data[i*nx + x][0];
      vnx.getdata()[x][1] = this->data[i*nx + x][1];
    }
    //Fft 1D de vnx
    vnx.fft();
    //Recopiage de vnx dans la ligne i
    for(int x = 0; x < nx; x++) {
      this->data[i*nx + x][0] = vnx.getdata()[x][0];
      this->data[i*nx + x][1] = vnx.getdata()[x][1];
    }
  }
  // FFT DE CHAQUE COLONNE (modifiées par la 1ere étape)
  for(int j = 0; j < nx; j++) {
    //Recopiage de la colone j dans vny
    for(int x = 0; x < ny; x++) {
      vny.getdata()[x][0] = this->data[x*nx + j][0];
      vny.getdata()[x][1] = this->data[x*nx + j][1];
    }
    //FFT 1d de vny
    vny.fft();
    //Recopiage de vny dans la colone j
    for(int x = 0; x < ny; x++) {
      this->data[x*nx + j][0] = vny.getdata()[x][0];
      this->data[x*nx + j][1] = vny.getdata()[x][1];
    }
  }
}

void Dvector::ifft2d(int nx, int ny) {
  Dvector vnx(nx);
  Dvector vny(ny);

  // FFT DE CHAQUE COLONNE (modifiées par la 1ere étape)
  for(int j = 0; j < nx; j++) {
    //Recopiage de la colone j dans vny
    for(int x = 0; x < ny; x++) {
      vny.getdata()[x][0] = this->data[x*nx + j][0];
      vny.getdata()[x][1] = this->data[x*nx + j][1];
    }
    //IFFT 1d de vny
    vny.ifft();
    //Recopiage de vny dans la colone j
    for(int x = 0; x < ny; x++) {
      this->data[x*nx + j][0] = vny.getdata()[x][0];
      this->data[x*nx + j][1] = vny.getdata()[x][1];
    }
  }

  // FFT DE CHAQUE LIGNE
  for(int i = 0; i < ny; i++) {
    //Recopiage de la ligne i dans vnx
    for(int x = 0; x < nx; x++) {
      vnx.getdata()[x][0] = this->data[i*nx + x][0];
      vnx.getdata()[x][1] = this->data[i*nx + x][1];
    }
    //Fft 1D de vnx
    vnx.ifft();
    //Recopiage de vnx dans la ligne i
    for(int x = 0; x < nx; x++) {
      this->data[i*nx + x][0] = vnx.getdata()[x][0];
      this->data[i*nx + x][1] = vnx.getdata()[x][1];
    }
  }
}