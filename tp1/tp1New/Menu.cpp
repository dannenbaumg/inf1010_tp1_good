#include "Menu.h";
#include "Plat.h";
#include <string>;
#include  <cstdio> ;

//constructeurs

Menu::Menu() {
	capacite_ = MAXPLAT;
	listePlats_ = new Plat* [capacite_];
	nbPlats_ = 0;
	type_ = Matin;
}


Menu::Menu(string fichier, TypeMenu type) {
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	listePlats_ = new Plat*[capacite_];
	type_ = type;
	lireMenu(fichier);

}

//getters
int Menu::getNbPlats() {
	return nbPlats_;
}



//methodes en plus
Plat* Menu::trouverPlat(string& nom) {
	for (int i = 0; i < nbPlats_; i++) {
		if (nom == listePlats_[i]->getNom()) {
			return listePlats_[i];
		}
	}
	return nullptr;
}

void Menu :: ajouterPlat(Plat & plat) {

	if (nbPlats_ == capacite_) {
		capacite_ *= 2;
		Plat ** nouveauListePlats = new  Plat*[capacite_];
		for (int i = 0; i < nbPlats_; i++) {
			nouveauListePlats[i] = listePlats_[i];
		}
		delete[] listePlats_;
		listePlats_ = nouveauListePlats;
	}

	Plat* ptrPlat = new Plat(plat.getNom(), plat.getPrix(), plat.getCout());
	
	listePlats_[nbPlats_] = ptrPlat; 
	
	nbPlats_++;

}

void Menu::ajouterPlat(string& nom, double montant, double cout) {

	Plat Plat(nom, montant,cout);
	
	ajouterPlat(Plat);
}

//fonction pour convertir string en enum pour le type de menu

bool Menu :: lireMenu(string& fichier) {
	string type;

	switch (type_){
		case (Matin):
			type = "-MATIN";
			break;
		case (Midi):
			type = "-MIDI";
			break;
		case (Soir):
			type = "-SOIR";
			break;

	}

	ifstream fichierO("polyFood.txt");
	string tempString;
	string nom;
	double montant;
	double cout;
	
	if (fichierO.fail()) {
		return false;
	}
	while (!fichierO.eof()) {
		fichierO >> ws;
		getline(fichierO, tempString);
	
		if (tempString == type) {
			fichierO >> nom >> ws >> montant >> ws >> cout;
			ajouterPlat(nom, montant, cout);
			
			do{
			fichierO >> nom >> ws >> montant >> ws >> cout;
			if (nom[0] != '-') {
				ajouterPlat(nom, montant, cout);
			}
			} while (nom[0] != '-');
			
		}
	
	}

	fichierO.close();
	return true;

}


//affichage
void  Menu:: afficher() {
	cout << type_ << ':' << endl;
	cout << nbPlats_ << endl;
	for (int i = 0; i < nbPlats_; i++) {
		cout << &listePlats_[i];

	}

}

Menu :: ~Menu() {
	delete[] listePlats_;
}
