#include "Table.h";

// constructeurs

Table::Table() {
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];
}

Table::Table(int id, int nbPlaces) {
	capacite_ = MAXCAP;
	id_ = id;
	nbPlaces_ = nbPlaces;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];

}

//getters 
int Table::getId() {
	return id_;
}
int  Table:: getNbPlaces() {
	return nbPlaces_;
}
bool  Table::estOccupee() {
	return occupee_;
}

//setters 
void  Table::setId(int id) {
	id_ = id;
}

void  Table::libererTable() {
	occupee_ = false;
	delete[] commande_;
	commande_ = nullptr;
	nbPlats_ = 0;
}

void Table::tableOccuper() {
	occupee_ = true;
}


//autres methodes 
void Table ::commander(Plat* plat) {
	commande_[nbPlats_] = plat;
	nbPlats_ ++;
}

double Table::getChiffreAffaire() {
	double profit = 0;
	for (int i = 0; 1 < nbPlats_; i++) {
		profit += (commande_[i]->getPrix() - commande_[i]->getCout());

	}
	return profit;
}



//affichage
void Table::afficher() {
	cout << getId() << endl;
	cout << "Nombre de plats: " << nbPlats_ << endl;
	cout << "Nombre de places : " << getNbPlaces();
	cout << "Profit: " << getChiffreAffaire() << endl;
}

Table::~Table() {
	delete[] commande_;
}