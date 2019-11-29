#ifndef marvel__hpp
#define marvel__hpp
#include <string>
#include <iostream>
#include <exception>

class Personne
{
	public:
		enum Genre
		{
			HOMME,
			FEMME,
			INDETERMINE
		};

	private:
		std::string _prenom;
		std::string _nom;
		Genre _genre;

	public:
		Personne(std::string prenom = "Inconnu", std::string nom = "Inconnu", Genre genre = INDETERMINE);
		~Personne();
		std::string getNom() const;
		std::string getPrenom() const;
		Genre getGenre() const;
		void afficher(std::ostream&) const;
		static Personne INCONNU;

};

std::ostream& operator<<(std::ostream &, Personne const&);

bool operator==(const Personne&, const Personne&);

class Super 
{
	private:
		std::string _nomScene;
		Personne _identite;
		bool _anonyme;

	public:
		Super(std::string nomScene = "Inconnu", Personne identite = Personne::INCONNU, bool anonyme =  true);
		~Super();
		std::string getNom() const;
		bool estAnonyme() const;
		void enregistrer();
		Personne getIdentite() const;
		void setIdentite(Personne);
};


class AnonymeException : public std::exception
{
	public:
		virtual const char* what() const noexcept;

};


class Capacite
{
	protected:
		std::string _nomCapa;
		int _niveau;
	public:
		Capacite(std::string nom = "", int niveau = 0);
		virtual ~Capacite();
};

class Materiel : public Capacite
{
	/*
	private:
		std::string _nomMat;
		int _niveauMat;
	*/
	public:
		Materiel(std::string, int);
		~Materiel();
		void actionner(std::ostream &) const;
};

std::ostream & operator<<(std::ostream &, Materiel const&);

#endif
