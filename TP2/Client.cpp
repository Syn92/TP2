/********************************************
* Titre: Travail pratique #2 - Client.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Client.h"

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal },
	dateNaissance_{ date },
	monPanier_{ nullptr }
{
}

Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

// Methodes d'acces
string Client::obtenirNom() const
{
	return nom_;
}

string Client::obtenirPrenom() const
{
	return prenom_;
}

int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

string Client::obtenirCodePostal() const
{
	return codePostal_;
}

long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

// Methodes de modification
void  Client::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(4);
	monPanier_->ajouter(prod);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

void Client::afficherPanier() const
{
	if (monPanier_ != nullptr) {
		cout << "Le panier de " << prenom_ << ": " << endl;
		monPanier_->afficher();
	}
	else {
		cout << "Le panier de " <<prenom_ << " est vide !" << endl;
	}
}

//Cette méthode écrase les attributs de l’objet de gauche par les attributs de l’objet passé en paramètre.
void Client::operator=(const Client& c2) {
	modifierNom(c2.nom_);
	modifierPrenom(c2.prenom_);
	modifierIdentifiant(c2.identifiant_);
	modifierCodePostal(c2.codePostal_);
	modifierDateNaissance(c2.dateNaissance_);
	monPanier_ = c2.monPanier_; //modifier cette partie de code.
}


//les deux prochaines fonctions permettent de verifier dans un premier temps si l'identifiant en paramètre
//correspond à l'identifiant du client. Dans un deuxième temps, si l'idenfiant en question correspond à celui 
// du client en paramètre.
bool Client::operator==(int Identifiant) {
	return identifiant_ == Identifiant;
}

bool Client::operator==(Client unClient) {
	return identifiant_ == unClient.obtenirIdentifiant();
}

ostream& operator<<(ostream& o, const Client& client) {
	if (client.monPanier_ != nullptr) {
		for (int i = 0; i < client.monPanier_->obtenirContenuPanier.size(); i++) {
			cout << "Le panier de" << client.prenom_ << ":" << endl << client.monPanier_->obtenirContenuPanier()[i].obtenirNom() << " " << client.monPanier_->obtenirContenuPanier()[i].obtenirReference() << " " << client.monPanier_->obtenirContenuPanier()[i].obtenirPrix();

		}
		
	} else {
		cout << "Le panier de " << client.prenom_ << " est vide !" << endl; 
	}
}
