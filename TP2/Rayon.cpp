/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/

#include "Rayon.h"

Rayon::Rayon(const string& cat) :
	categorie_{ cat },
	tousProduits_{ nullptr },
	capaciteProduits_{ 0 },
	nombreProduits_{ 0 }
{
}

/*Rayon::~Rayon()
{
	if (tousProduits_ != nullptr)
		delete[] tousProduits_;
}*/

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

vector<Produit*> Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

// Methodes de modification
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}

/*void Rayon::ajouterProduit(Produit * produit)
{
	if (tousProduits_ != nullptr)
	{
		if (nombreProduits_ >= capaciteProduits_)
		{
			Produit ** temp;
			capaciteProduits_ += 5;
			temp = new Produit*[capaciteProduits_];
			for (int i = 0; i < nombreProduits_; i++)
				temp[i] = tousProduits_[i];
			delete[] tousProduits_;
			tousProduits_ = temp;

		}
		tousProduits_[nombreProduits_++] = produit;
	}
	else
	{
		capaciteProduits_ = 5;
		tousProduits_ = new Produit*[capaciteProduits_];
		tousProduits_[nombreProduits_++] = produit;
	}
}*/
int Rayon::compterDoublons(const Produit& produit) {
	int occurence = 0;
	for (int i = 0; i < nombreProduits_; i++)
	{
		if ((*tousProduits_[i]) == produit)
			occurence++;
	}
}
Rayon Rayon::operator+=(Produit *produit) {
	tousProduits_.push_back(produit);
	return *this;
}

void Rayon::operator=(const Rayon &rayon) {
	categorie_ = rayon.categorie_;
	capaciteProduits_ = rayon.capaciteProduits_;	
	tousProduits_.clear();
	nombreProduits_ = rayon.nombreProduits_;
	for (int i = 0; i < rayon.nombreProduits_; i++)
	{
		tousProduits_.push_back(rayon.tousProduits_[i]);
	}
	
}

ostream& operator<<(ostream &oss, const Rayon &rayon) {
	oss << "Le rayon " << rayon.categorie_ << ": " << endl;
	for (int i = 0; i < rayon.nombreProduits_; i++)
	{
		oss << "----> " << rayon.tousProduits_[i]->afficher() //corriger erreur
			<< endl;
	}
	return oss;
}

void Rayon::afficher() const
{
	cout << "Le rayon " << categorie_ << ": " << endl;
	for (int i = 0; i < nombreProduits_; i++) {
		cout << "----> ";
		tousProduits_[i]->afficher();
	}
}
