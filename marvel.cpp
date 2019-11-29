#include "marvel.hpp"


Personne::Personne(std::string prenom, std::string nom, Personne::Genre genre) :
	_prenom(prenom), _nom(nom), _genre(genre)
{
}

Personne::~Personne()
{
}

std::string Personne::getNom() const
{
	return _nom;
}

std::string Personne::getPrenom() const
{
	return _prenom;
}

Personne::Genre Personne::getGenre() const
{
	return _genre;
}

void Personne::afficher(std::ostream &flux) const
{	
	std::string tab[3]={"HOMME", "FEMME", "INDETERMINE"};
	flux << _prenom << " " << _nom << " [" << tab[_genre] << "]";
}

std::ostream & operator<<(std::ostream & flux, Personne const& p)
{
	p.afficher(flux);
	return flux;
}

Personne Personne::INCONNU("Inconnu", "Inconnu", Personne::INDETERMINE);

bool operator==(const Personne& p1, const Personne& p2)
{
    return p1.getPrenom() == p2.getPrenom() && p1.getNom() == p2.getNom() && p1.getGenre() == p2.getGenre();
}


Super::Super(std::string nomScene, Personne identite, bool anonyme) :
	_nomScene(nomScene), _identite(identite), _anonyme(anonyme)
{
}

Super::~Super()
{
}

std::string Super::getNom() const
{
	return _nomScene;
}

bool Super::estAnonyme() const
{
	return _anonyme;
}

void Super::enregistrer()
{
	_anonyme = false;
}

Personne Super::getIdentite() const
{	
	if(_anonyme==true) throw AnonymeException();
	return _identite;
}


const char* AnonymeException::what() const noexcept
{
	return "identite anonyme";
}

void Super::setIdentite(Personne identite)
{
	_identite = identite;
	_anonyme = true;
}

Capacite::Capacite(std::string nom, int niveau) :
	_nomCapa(nom), _niveau(niveau)
{
}

Capacite::~Capacite()
{
}


Materiel::Materiel(std::string nom, int niveau) : Capacite(nom, niveau)
{
}

Materiel::~Materiel()
{
}

void Materiel::actionner(std::ostream& flux) const
{
	flux << Capacite::_nomCapa << " [" << Capacite::_niveau << "] en action";
}

std::ostream & operator<<(std::ostream & flux, Materiel const& m)
{
	m.actionner(flux);
	return flux;
}

