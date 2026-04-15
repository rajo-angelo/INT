void viderligne();
char *creatFichierInforamtion();
char *remplierInformaton();
void ajouterInformation(const char *fichierDInformation);
void afficherFicherDInformation(const char *leFicherDInformation);
void modifierLigneParContenu(const char *nomFichier, const char *ancienTexte, const char *nouveauTexte);
char *rechecheUnInformation(const char *leFichier,const char *element);
void supprimerUnInformation(const char *nomFichier, const char *ancienTexte);