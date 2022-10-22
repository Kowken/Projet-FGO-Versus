#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include<iostream>
#include <string>
#include <map>
#include <vector>
#include <time.h>
#include <queue>
#include <algorithm>

//================================= DECLARATION ==========================================================
class Servant;
class CraftEssence;
class Classe;
class Combat;
class Skills;
class Carte;
class Buster;
class Arts;
class Quick;
class NoblePhantasmArts;
class NoblePhantasmBuster;
class NoblePhantasmQuick;
class Saber;
class Archer;
class Lancer;
class Caster;
class Rider;
class Assassin;
class Berserker;
class CompteurEffet;


//================================= SERVANT ==============================================================
class Servant
{
private:
    std::string m_nom;
    int m_rarete;
    double m_PV;
    double m_PVMax;
    int m_poids;
    int genre; //1.Homme || 2.Femme || 3. Autre
    int attribut; //1.Terre || 2.Ciel || 3.Humain || 4.Etoile
    int comportement; //1.Lawful || 2.Neutral || 3.Chaotic
    int alignement; //1.Bon || 2.Neutre || 3.Mauvais
    int DeathResist;
    bool isDivine;
    bool isDragon;
    int m_JaugeNP=0;
    double CoeffATKBuster=1.0;
    double CoeffATKArts=1.0;
    double CoeffATKQuick=1.0;
    double CoeffDEFBuster=1.0;
    double CoeffDEFArts=1.0;
    double CoeffDEFQuick=1.0;
    double CoeffAttaque=1.0;
    double CoeffDefense=1.0;
    double StarGenerationRate=1.0;
    double NPGenerationRate=1.0;
    double StarGatherRate=1.0;
    int DebuffResist=0;
    int BuffRemovalResist=0;
    double BuffSuccess=1.0;
    bool IsBeingBurned=false;
    bool IsBeingCursed=false;
    bool IsBeingPoisoned=false;
    bool IsBeingStunned=false;
    bool DebuffImmunity=false;
    double CoeffCrit=1.0;
    bool IsBeingNPSealed=false;
    bool IsBeingSkillSealed=false;
    bool isAvoiding=false;
    bool SureHit=false;
    double CoeffCritQuick=1.0;
    bool ProtectionOfKur=false;
    bool hasGuts=false;
    bool EffetMortSkill=false;
    bool EffetMortNP=false;
    int FlatDefense=0;
    int FlatAttaque=0;
    double CoeffNoblePhantasm=1.0;
    double CoeffSoin=1.0;
    bool isInvincible=false;
    bool PierceInvincibility=false;
    bool NPReady=false;
    bool hasTargetFocus=false;
    double CoeffATKDragon=1.0;
    double CoeffATKDivine=1.0;
    double CoeffATKEarth=1.0;
    double CoeffATKSky=1.0;
    double CoeffATKStar=1.0;
    double CoeffATKHuman=1.0;
    double CoeffATKMan=1.0;
    double CoeffATKWoman=1.0;
    double CoeffATKGood=1.0;
    double CoeffATKEvil=1.0;

    Carte* NPCarte;
    std::vector<Carte*>DeckCarte;
    Carte* CarteExtra;
    std::vector<Skills*>DeckSkills;
    CraftEssence *CE;
    Classe *CA;
    std::vector<CompteurEffet*> listeBonus;
    std::vector<CompteurEffet*> listeMalus;
    bool isFrozen=true;
    bool isAttacking=false;
    bool isDefending=true;

public:
    Servant(std::string nom,int rarete,int PVMax,int poids,int genre,int attribut,int comportement,int alignement,bool isDivine,bool isDragon,Carte* NPCarte,std::vector<Carte*>DeckCarte,std::vector<Skills*>DeckSkills,Classe* CA,int DeathResist);
    Servant();
    Servant(std::string nom);
    ~Servant();
    void affichage();
    void afficher(int x,int y);
    void attaquer(Carte* c,Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void calculDefense(double degats);
    void utiliserSkills(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void MiseAJour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    int genererEtoiles(Carte* c);
    void calculDefense(Carte* c,Servant* Defense);
    void genererNP(Carte* c);
    void problemeStatut();

//========Getters et setters==============

    std::string getNom();
    int getRarete();
    double getPV();
    void modifyPV(double deltaPV);
    int getJaugeNP();
    void modifyJaugeNP(int deltaNP);
    double getCoeffAttaque();
    double getCoeffDefense();
    double getCoeffATKArts();
    double getCoeffATKBuster();
    double getCoeffATKQuick();
    double getCoeffDEFArts();
    double getCoeffDEFBuster();
    double getCoeffDEFQuick();
    double getStarGenerationRate();
    double getNPGenerationRate();
    double getStarGatherRate();
    void setCoeffAttaque(double deltaCA);
    void setCoeffDefense(double deltaCD);
    void setCoeffATKArts(double deltaCAA);
    void setCoeffATKBuster(double deltaCAB);
    void setCoeffATKQuick(double deltaCAQ);
    void setCoeffDEFArts(double deltaCDA);
    void setCoeffDEFBuster(double deltaCDB);
    void setCoeffDEFQuick(double deltaCDQ);
    void setStarGenerationRate(double deltaSGR);
    void setNPGenerationRate(double deltaNGR);
    void setStarGatherRate(double deltaSGTR);
    int getDebuffResist();
    int getBuffRemovalResist();
    int getBuffSuccess();
    void modifyDebuffResist(int deltaDR);
    void modifyBuffRemovalResist(int deltaBRR);
    void modifyBuffSuccess(double deltaBS);
    bool getBurn();
    bool getPoison();
    bool getCurse();
    bool getStun();
    void setBurn(bool BurnStatus);
    void setPoison(bool PoisonStatus);
    void setCurse(bool CurseStatus);
    void setStun(bool StunStatus);
    bool getNPSeal();
    bool getSkillSeal();
    void setNPSeal(bool NPSealStatus);
    void setSkillSeal(bool SkillSealStatus);
    void modifyCoeffCrit(double CC);
    double getCoeffCrit();
    int getPoids();
    bool getAvoid();
    void setAvoid(bool AvoidStatus);
    bool getSureHit();
    void setSureHit(bool SureHitStatus);
    void modifyCoeffCritQuick(double CCQ);
    void setProtectionOfKur(bool KurStatus);
    double getCoeffCritQuick();
    bool getProtectionOfKur();
    void setGuts(bool GutStatus);
    bool getGuts();
    bool getEffetMortSkill();
    bool getEffetMortNP();
    void setEffetMortSkill(bool EffetMortSkillStatus);
    void setEffetMortNP(bool EffetMortNPStatus);
    int getFlatDefense();
    void modifyFlatDefense(int deltaFlatDefense);
    void modifyCoeffNoblePhantasm(double deltaCNP);
    double getCoeffNoblePhantasm();
    void setGenre(int deltaG);
    void setAlignement(int deltaA);
    void setComportement(int deltaC);
    int getGenre();
    int getAlignement();
    int getComportement();
    int getAttribut();
    void modifyCoeffSoin(double deltaS);
    double getCoeffSoin();
    void modifyDeathResist(int deltaDR);
    int getDeathResist();
    void setDivine(bool DivineStatus);
    bool getDivine();
    void setDragon(bool DragonStatus);
    bool getDragon();
    std::vector<Carte*>* getDeckCarte();
    void setIsInvincible(bool InvincibleStatus);
    void setPierceInvincibility(bool IPStatus);
    bool getIsInvincible();
    bool getPierceInvincibility();
    CraftEssence* getCE();
    void modifyCooldownAct(int deltaCDA);
    bool getNPStatus();
    void setNPStatus();
    Carte* getNPCarte();
    double getPVMax();
    void modifyPVMax(int deltaPVM);
    bool getTargetFocus();
    void setTargetFocus(bool deltaTF);
    Carte* getCarteExtra();
    double getCoeffATKDragon();
    double getCoeffATKDivine();
    double getCoeffATKEarth();
    double getCoeffATKSky();
    double getCoeffATKHuman();
    double getCoeffATKStar();
    double getCoeffATKMan();
    double getCoeffATKWoman();
    double getCoeffATKGood();
    double getCoeffATKEvil();
    void modifyCoeffATKDragon(double deltaDR);
    void modifyCoeffATKDivine(double deltaDI);
    void modifyCoeffATKEarth(double deltaEA);
    void modifyCoeffATKSky(double deltaSK);
    void modifyCoeffATKHuman(double deltaHU);
    void modifyCoeffATKStar(double deltaST);
    void modifyCoeffATKMan(double deltaMA);
    void modifyCoeffATKWoman(double deltaWO);
    void modifyCoeffATKGood(double deltaGO);
    void modifyCoeffATKEvil(double deltaEV);
    int getFlatAttaque();
    void modifyFlatAttaque(int deltaFA);
    void setCraftEssence(CraftEssence* C);
    std::vector<Skills*>* getDeckSkills();
    std::vector<CompteurEffet*>* getListeBonus();
    std::vector<CompteurEffet*>* getListeMalus();
    bool getIsFrozen();
    void setIsFrozen(bool deltaIF);
    void InstaKill(int DeathChance);
    bool getIsAttacking();
    bool getIsDefending();
    void setIsAttacking(bool AttackStatus);
    void setIsDefending(bool DefenseStatus);
};


//================================= CRAFT ESSENCE ==============================================================
/*class CraftEssence
{
private:
    std::string m_nom;
    int m_poids;
    std::string nomProprio;
public:
    CraftEssence();
    virtual ~CraftEssence();//=0;
    virtual void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual int getPoids();
    virtual std::string getNom();
    virtual void description();
    virtual void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void modifyCooldownEff(int deltaCDE);
    virtual void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};
*/

//================================= CLASSE ==============================================================
class Classe
{
protected:
    std::string m_nom;
    std::vector<std::string> fortContre;
    std::vector<std::string> faibleContre;
    double coefficientATKClasse=1;
    double coefficientDEFClasse=1;
public:
    Classe();
    virtual ~Classe()=0;
    virtual void coefficientClasse(Servant* Ennemi);
    virtual std::string getNom();
    virtual std::vector<std::string>* getFortContre();
    virtual std::vector<std::string>* getFaibleContre();
    void setFortContre(std::vector<std::string> deltaFOC);
    void setFaibleContre(std::vector<std::string> deltaFAC);
};


//================================= COMBAT ==============================================================
class Combat
{
private:
    int m_nbTour=0;
    std::vector<Servant*>ChoixEquipeJoueur1;
    std::vector<Servant*>ChoixEquipeJoueur2;
    std::vector<CraftEssence*>ChoixCraftEssenceJoueur1;
    std::vector<CraftEssence*>ChoixCraftEssenceJoueur2;
    std::vector<Servant*>equipeJoueur1;
    std::vector<Servant*>equipeJoueur2;
    std::vector<Servant*>cimetiereJoueur1;
    std::vector<Servant*>cimetiereJoueur2;
    int stockEtoilesJoueur1=0;
    int stockEtoilesJoueur2=0;
    bool TourJoueur1Fini=false;
    bool TourJoueur2Fini=false;
    bool Joueur1Encours = true;

public:
    Combat();
    ~Combat();
    void InitialiserCombat();
    void Combattre();
    void TourSuivant(std::vector<Servant*>* frontEquipeJoueur1, std::vector<Servant*>* frontEquipeJoueur2);
    void Attaque(std::vector<Servant*>*equipeAttaquant,std::vector<Servant*>*equipeDefenseur,int& stockEtoilesEquipeEnCours);
    void Permutation(std::vector<Servant*>* equipeEnCours);
    void UtiliserSkills(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void mortServant();
    bool finCombat();
    void permuterServant(std::vector<Servant*>*equipe,int devant,int derriere);
    void attaqueExtra(std::vector<Servant*>*equipeEnCours,std::vector<Carte*>* SelectionCartes);
    void TripleCouleur(std::vector<Carte*>* SelectionCartes,std::vector<Servant*>* equipeEnCours,bool& ExistanceBusterChain,std::vector<Servant*>* beneficiaires);
    void RepartitionEtoiles(std::vector<Carte*>* SelectionCartes,std::vector<Servant*>* equipeEnCours,int& stockEtoilesEquipeEnCours);
    void ResetBusterChain(std::vector<Servant*>* equipeEnCours,std::vector<Servant*>* beneficiaires,bool& ExistanceBusterChain);
    void generationEtoiles(std::vector<Servant*>* equipeEnCours,std::vector<Carte*>* SelectionCartes,int& stockEtoilesEquipeEnCours);
    std::vector<Servant*>& getChoixEquipeJoueur1();
    std::vector<Servant*>& getChoixEquipeJoueur2();
    void SelectionEquipes();
    void TrueSelectionEquipes(int limite);
    void afficher(std::vector<Servant*>* frontEquipeJoueur1, std::vector<Servant*>* frontEquipeJoueur2);
};


//================================= SKILLS ==============================================================
class Skills
{
protected:
    std::string m_nom;
    int m_cooldownAction=0;
    std::string nomProprio;

public:
    Skills();
    Skills(std::string nomProprio);
    virtual ~Skills();
    virtual std::string getNom();
    virtual void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void modifyCooldownAct(int deltaCDA);
    virtual void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    int getCooldownAct();
    virtual void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetBonus(std::vector<Servant*>*equipeEnCours);
    void ResetMalus(std::vector<Servant*>*equipeAdverse);
    virtual void description();
    virtual void ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
};


//================================= CARTE ==============================================================
class Carte
{
protected:
    int m_degats=0;
    int m_starGen=0;
    int m_NPGen=0;
    std::string TypeCarte;
    std::string nomProprio;
    bool isNoblePhantasm=false;
    int etoiles=0;
    std::string nomNP;

public:
    Carte();
    Carte(std::string nomProprio);
    virtual ~Carte()=0;
    virtual std::string getTypeCarte();
    void setTypeCarte(std::string deltaTypeCarte);
    virtual void effet(Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual void resetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual bool getIsNoblePhantasm();
    virtual std::string getNomProprio();
    virtual void Overcharge();
    int getEtoiles();
    void modifyEtoiles(int deltaEtoiles);
    virtual std::string getNomNP();
    void ResetBonus(std::vector<Servant*>*equipeEnCours);
    void ResetMalus(std::vector<Servant*>*equipeAdverse);
    virtual void description();
    void modifyCooldownEff(int deltaCDE);
    virtual void ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    virtual int getDegats();
    virtual int getStarGen();
    virtual int getNP();
    bool coupCritique();

};


//================================= BUSTER ==============================================================
class Buster : public Carte
{
protected:
    std::string TypeCarte="Buster";
    int m_degats=2000;
    int m_starGen=5;
    int m_NPGen=5;

public:
    std::string getTypeCarte();
    Buster(std::string nomProprio);
    Buster();
    ~Buster();
    int getDegats();
    int getStarGen();
    int getNP();
    void setTypeCarte(std::string deltaTypeCarte);
    bool getIsNoblePhantasm();
    std::string getNomProprio();
    int getEtoiles();

};

//================================= QUICK ==============================================================
class Quick : public Carte
{
protected:
    std::string TypeCarte="Quick";
    int m_degats=500;
    int m_starGen=10;
    int m_NPGen=10;

public:
    std::string getTypeCarte();
    Quick(std::string nomProprio);
    Quick();
    ~Quick();
    int getDegats();
    int getStarGen();
    int getNP();
    void setTypeCarte(std::string deltaTypeCarte);
    bool getIsNoblePhantasm();
    std::string getNomProprio();
    int getEtoiles();

};


//================================= ARTS ==============================================================
class Arts : public Carte
{
protected:
    std::string TypeCarte="Arts";
    int m_degats=1000;
    int m_starGen=1;
    int m_NPGen=20;

public:
    std::string getTypeCarte();
    Arts(std::string nomProprio);
    Arts();
    ~Arts();
    int getDegats();
    int getStarGen();
    int getNP();
    void setTypeCarte(std::string deltaTypeCarte);
    bool getIsNoblePhantasm();
    std::string getNomProprio();
    int getEtoiles();
};

//================================= EXTRA ==============================================================
class Extra : public Carte
{
private:
    std::string TypeCarte="Extra";
    int m_degats=1000;
    int m_starGen=10;
    int m_NPGen=10;

public:
    std::string getTypeCarte();
    Extra();
    Extra(std::string nomProprio);
    ~Extra();
    int getDegats();
    int getStarGen();
    int getNP();
    void setTypeCarte(std::string deltaTypeCarte);
    bool getIsNoblePhantasm();
    std::string getNomProprio();
    int getEtoiles();
};


//================================= NP Buster ==============================================================
class NoblePhantasmBuster : public Buster
{
protected:
    bool isNoblePhantasm=true;
    std::string nomNP;
public:
    NoblePhantasmBuster(std::string nomNP,std::string nomProprio);
    NoblePhantasmBuster();
    virtual ~NoblePhantasmBuster()=0;
};

//================================= NP Arts ==============================================================

class NoblePhantasmArts : public Arts
{
protected:
    bool isNoblePhantasm=true;
    std::string nomNP;
public:
    NoblePhantasmArts(std::string nomNP,std::string nomProprio);
    NoblePhantasmArts();
    virtual ~NoblePhantasmArts()=0;
    };

//================================= NP Quick ==============================================================

class NoblePhantasmQuick : public Quick
{
protected:
    bool isNoblePhantasm=true;
    std::string nomNP;
public:
    NoblePhantasmQuick(std::string nomNP,std::string nomProprio);
    NoblePhantasmQuick();
    virtual ~NoblePhantasmQuick()=0;
};

//=============================== SABER ======================

class Saber : public Classe
{
private:
    std::string m_nom="Saber";
    std::vector<std::string> fortContre={"Lancer"};
    std::vector<std::string> faibleContre={"Archer"};
    double coefficientATKClasse=1;
    double coefficientDEFClasse=1;
public:
    Saber();
    ~Saber();
    void coefficientClasse(Servant* Ennemi);
    std::string getNom();
    std::vector<std::string>* getFortContre();
    std::vector<std::string>* getFaibleContre();
    void setFortContre(std::vector<std::string> deltaFOC);
    void setFaibleContre(std::vector<std::string> deltaFAC);
};

//=============================== ARCHER =======================

class Archer : public Classe
{
private:
    std::string m_nom="Archer";
    std::vector<std::string> fortContre={"Saber"};
    std::vector<std::string> faibleContre={"Lancer"};
    double coefficientATKClasse=1;
    double coefficientDEFClasse=1;
public:
    Archer();
    ~Archer();
    void coefficientClasse(Servant* Ennemi);
    std::string getNom();
    std::vector<std::string>* getFortContre();
    std::vector<std::string>* getFaibleContre();
    void setFortContre(std::vector<std::string> deltaFOC);
    void setFaibleContre(std::vector<std::string> deltaFAC);
};

//================================= LANCER ======================

class Lancer : public Classe
{
private:
    std::string m_nom="Lancer";
    std::vector<std::string> fortContre={"Archer"};
    std::vector<std::string> faibleContre={"Saber"};
    double coefficientATKClasse=1;
    double coefficientDEFClasse=1;
public:
    Lancer();
    ~Lancer();
    void coefficientClasse(Servant* Ennemi);
    std::string getNom();
    std::vector<std::string>* getFortContre();
    std::vector<std::string>* getFaibleContre();
    void setFortContre(std::vector<std::string> deltaFOC);
    void setFaibleContre(std::vector<std::string> deltaFAC);
};

//=============================== CASTER =========================

class Caster : public Classe
{
private:
    std::string m_nom="Caster";
    std::vector<std::string> fortContre={"Assassin"};
    std::vector<std::string> faibleContre={"Rider"};
    double coefficientATKClasse=1;
    double coefficientDEFClasse=1;
public:
    Caster();
    ~Caster();
    void coefficientClasse(Servant* Ennemi);
    std::string getNom();
    std::vector<std::string>* getFortContre();
    std::vector<std::string>* getFaibleContre();
    void setFortContre(std::vector<std::string> deltaFOC);
    void setFaibleContre(std::vector<std::string> deltaFAC);
};

//=============================== RIDER ============================

class Rider : public Classe
{
private:
    std::string m_nom="Rider";
    std::vector<std::string> fortContre={"Caster"};
    std::vector<std::string> faibleContre={"Assassin"};
    double coefficientATKClasse=1;
    double coefficientDEFClasse=1;
public:
    Rider();
    ~Rider();
    void coefficientClasse(Servant* Ennemi);
    std::string getNom();
    std::vector<std::string>* getFortContre();
    std::vector<std::string>* getFaibleContre();
    void setFortContre(std::vector<std::string> deltaFOC);
    void setFaibleContre(std::vector<std::string> deltaFAC);
};

//============================= ASSASSIN ============================

class Assassin : public Classe
{
private:
    std::string m_nom="Assassin";
    std::vector<std::string> fortContre={"Rider"};
    std::vector<std::string> faibleContre={"Caster"};
    double coefficientATKClasse=1;
    double coefficientDEFClasse=1;
public:
    Assassin();
    ~Assassin();
    void coefficientClasse(Servant* Ennemi);
    std::string getNom();
    std::vector<std::string>* getFortContre();
    std::vector<std::string>* getFaibleContre();
    void setFortContre(std::vector<std::string> deltaFOC);
    void setFaibleContre(std::vector<std::string> deltaFAC);
};

//============================== BERSERKER ===========================

class Berserker : public Classe
{
    private:
    std::string m_nom="Berserker";
    std::vector<std::string> fortContre={"Saber","Archer","Lancer","Rider","Caster","Assassin","Berserker"};
    std::vector<std::string> faibleContre={"Saber","Archer","Lancer","Rider","Caster","Assassin","Berserker"};
    double coefficientATKClasse=1;
    double coefficientDEFClasse=1;
public:
    Berserker();
    ~Berserker();
    void coefficientClasse(Servant* Ennemi);
    std::string getNom();
    std::vector<std::string>* getFortContre();
    std::vector<std::string>* getFaibleContre();
    void setFortContre(std::vector<std::string> deltaFOC);
    void setFaibleContre(std::vector<std::string> deltaFAC);
};

class CompteurEffet
{
private:
    std::string NomEffet;
    std::vector<int> NombreTour={};
    std::vector<int> NombreFois={};
public:
    CompteurEffet(std::string NomEffet);
    ~CompteurEffet();
    std::string getNomEffet();
     std::vector<int>* getNombreTour();
     std::vector<int>* getNombreFois();
    void setNomEffet(std::string deltaNom);
    void setNombreTour(int deltaNT);
    void setNombreFois(int deltaNF);
};
#endif // HEAD_H_INCLUDED
