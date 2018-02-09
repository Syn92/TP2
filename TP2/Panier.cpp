/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Panier.h"


Panier::Panier(int capacite) :
	capaciteContenu_{ capacite },
	nombreContenu_{ 0 },
	contenuPanier_{ new Produit *[capaciteContenu_] },
	totalAPayer_{ 0 }
{
}

Panier::~Panier()
{
}

// methodes d'accès
Produit **  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return nombreContenu_;
}

double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

// méthodes de modification

// autres méthodes
void Panier::ajouter(Produit * prod)
{
	if (nombreContenu_ >= capaciteContenu_)
	{
		Produit ** temp;
		capaciteContenu_ *= 2;
		temp = new Produit*[capaciteContenu_];
		for (int i = 0; i < nombreContenu_; i++)
			temp[i] = contenuPanier_[i];
		delete contenuPanier_;
		contenuPanier_ = temp;
	}
	contenuPanier_[nombreContenu_++] = prod;
	totalAPayer_ += prod->obtenirPrix();
}

void Panier::livrer()
{
	delete[]contenuPanier_;
	nombreContenu_ = 0;
	totalAPayer_ = 0;
	contenuPanier_ = new Produit *[capaciteContenu_];
}

Produit * Panier::trouverProduitPlusCher()
{
	// TODO: Implementez la methode
	Produit* produitPlusCher = contenuPanier_[0];
	int indice;
	for (int i = 1; i < nombreContenu_; i++){
		if (contenuPanier_[i]->obtenirPrix() >= produitPlusCher->obtenirPrix()) {
			produitPlusCher->modifierPrix(contenuPanier_[i]->obtenirPrix());
			indice = i;
		}
	}
	return contenuPanier_[indice];
}

ostream& operator<<(ostream& o, const Panier& p){
	for (int i = 0; i < p.nombreContenu_; i++)
		p.contenuPanier_[i]->afficher();

	cout << "----> total a payer : " << p.totalAPayer_ << endl;
}
