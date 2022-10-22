#include "head.h"
#include "menu.h"
//#define TRACE_ON
Servant::Servant()
{

}

Servant::~Servant()
{
    //delete CE;
    delete CarteExtra;
    delete NPCarte;
    delete CA;
}

std::string Servant::getNom()
{
    return m_nom;
}

int Servant::getRarete()
{
    return m_rarete;
}

double Servant::getPV()
{
    return m_PV;
}

void Servant::modifyPV(double deltaPV)
{
    m_PV+=deltaPV;
    if(m_PV>m_PVMax)
    {
        m_PV=m_PVMax;
    }
    if(m_PV<0)
    {
        m_PV=0;
    }
}

int Servant::getJaugeNP()
{
    return m_JaugeNP;
}

void Servant::modifyJaugeNP(int deltaNP)
{
    m_JaugeNP+=deltaNP;
    if(m_JaugeNP<0)
    {
        m_JaugeNP=0;
    }

    if(m_JaugeNP>100)
    {
        m_JaugeNP=100;
    }
}

void Servant::afficher(int x,int y)
{
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    gotoligcol(x,y);
    std::cout << "Nom: " << m_nom << std::endl;
    gotoligcol(x+1,y);
//  std::cout << "Classe: " << CA->getNom() << std::endl;
    color(11,0);
    std::cout << "Vie: " << m_PV <<"/"<<m_PVMax<<std::endl;
    gotoligcol(x+2,y);
    color(14,0);
    std::cout << "NP: " << m_JaugeNP <<" %"<< std::endl;
    color(15,0);
    gotoligcol(x+3,y);
    std::cout << "" << std::endl;

}
void Servant::affichage()
{
    std::cout << "Nom: " << m_nom << std::endl;
//  std::cout << "Classe: " << CA->getNom() << std::endl;
    color(11,0);
    std::cout << "Vie: " << m_PV <<"/"<<m_PVMax << std::endl;
    color(14,0);
    std::cout << "NP: " << m_JaugeNP <<" %" << std::endl;
    color(15,0);
    std::cout << "" << std::endl;

}

void Servant::attaquer(Carte* c,Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    if(!IsBeingStunned)
    {
        if(c->getIsNoblePhantasm())
        {
                m_JaugeNP=0;
                std::cout<<m_nom<<" déploie son Noble Phantasm "<<c->getNomNP()<<" !"<<std::endl;
                c->effet(Cible,equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
                for(unsigned int i=0;i<equipeAdverse->size();i++)
                {
                    for(unsigned int j=0;j<equipeAdverse->at(i)->getDeckSkills()->size();j++)
                    {
                        equipeAdverse->at(i)->getDeckSkills()->at(j)->effetDefense(equipeAdverse,equipeEnCours,stockEtoilesEquipeEnCours);
                    }
                    equipeAdverse->at(i)->getNPCarte()->effetDefense(equipeAdverse,equipeEnCours,stockEtoilesEquipeEnCours);
                }
                #if defined(TRACE_ON)
                std::cout<<"Jauge NP après NP: "<<m_JaugeNP<<std::endl;
                #endif // defined
        }
        else
        {
            std::cout<<m_nom<<" attaque "<<Cible->getNom()<<" avec une carte de type "<<c->getTypeCarte()<<" !"<<std::endl;
            calculDefense(c,Cible);
            for(unsigned int i=0;i<equipeAdverse->size();i++)
            {
                for(unsigned int j=0;j<equipeAdverse->at(i)->getDeckSkills()->size();j++)
                {
                    equipeAdverse->at(i)->getDeckSkills()->at(j)->effetDefense(equipeAdverse,equipeEnCours,stockEtoilesEquipeEnCours);
                }
                equipeAdverse->at(i)->getNPCarte()->effetDefense(equipeAdverse,equipeEnCours,stockEtoilesEquipeEnCours);
            }
        }
        genererNP(c);
    }
    else
    {
        std::cout<<m_nom<<"est paralysé !"<<std::endl;
    }
}

void Servant::utiliserSkills(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    int choixSkill=0;
    std::cout<<"Choisissez le skill de "<<m_nom<<" que vous allez utiliser :"<<std::endl;
    for(unsigned int i=0;i<DeckSkills.size();i++)
    {
        std::cout<<i+1<<". "<<DeckSkills[i]->getNom()<<" Cooldown: "<<DeckSkills[i]->getCooldownAct()<<" Effet: ";
        DeckSkills[i]->description();
        std::cout<<std::endl;
    }
    std::cout<<DeckSkills.size()+1<<". Annuler"<<std::endl;
    do
    {
        std::cin>>choixSkill;
    }
    while(choixSkill-1<0||choixSkill-1>DeckSkills.size());
    if(choixSkill-1<DeckSkills.size())
    {
        if(!IsBeingStunned)
        {
            if(!IsBeingSkillSealed)
            {
                if(DeckSkills[choixSkill-1]->getCooldownAct()<=0)
                {
                    std::cout<<m_nom<<" utilise son skill "<<DeckSkills[choixSkill-1]->getNom()<<" !"<<std::endl;
                    DeckSkills[choixSkill-1]->effet(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
                }
                else
                {
                    std::cout<<"Votre Skill n'a pas fini de se recharger !"<<std::endl;
                }
            }
            else
            {
                std::cout<<"Vous ne pouvez pas utiliser de Skill !"<<std::endl;
            }
        }
        else
        {
            std::cout<<m_nom<<"est paralysé !"<<std::endl;
        }
    }
}

double Servant::getCoeffAttaque()
{
    return CoeffAttaque;
}

double Servant::getCoeffDefense()
{
    return CoeffDefense;
}

double Servant::getCoeffATKArts()
{
    return CoeffATKArts;
}

double Servant::getCoeffATKBuster()
{
    return CoeffATKBuster;
}

double Servant::getCoeffATKQuick()
{
    return CoeffATKQuick;
}

double Servant::getCoeffDEFArts()
{
    return CoeffDEFArts;
}

double Servant::getCoeffDEFBuster()
{
    return CoeffDEFBuster;
}

double Servant::getCoeffDEFQuick()
{
    return CoeffDEFQuick;
}

double Servant::getStarGenerationRate()
{
    return StarGenerationRate;
}

double Servant::getNPGenerationRate()
{
    return NPGenerationRate;
}

double Servant::getStarGatherRate()
{
    return StarGatherRate;
}

void Servant::setCoeffAttaque(double deltaCA)
{
    CoeffAttaque*=deltaCA;
}

void Servant::setCoeffDefense(double deltaCD)
{
    CoeffDefense*=deltaCD;
}

void Servant::setCoeffATKArts(double deltaCAA)
{
    CoeffATKArts*=deltaCAA;
}

void Servant::setCoeffATKBuster(double deltaCAB)
{
    CoeffATKBuster*=deltaCAB;
}

void Servant::setCoeffATKQuick(double deltaCAQ)
{
    CoeffATKQuick*=deltaCAQ;
}

void Servant::setCoeffDEFArts(double deltaCDA)
{
    CoeffDEFArts*=deltaCDA;
}

void Servant::setCoeffDEFBuster(double deltaCDB)
{
    CoeffDEFBuster*=deltaCDB;
}

void Servant::setCoeffDEFQuick(double deltaCDQ)
{
    CoeffDEFQuick*=deltaCDQ;
}

void Servant::setStarGenerationRate(double deltaSGR)
{
    StarGenerationRate*=deltaSGR;
}

void Servant::setNPGenerationRate(double deltaNGR)
{
    NPGenerationRate*=deltaNGR;
}

void Servant::setStarGatherRate(double deltaSGTR)
{
    StarGatherRate*=deltaSGTR;
}

int Servant::getDebuffResist()
{
    return DebuffResist;
}

int Servant::getBuffRemovalResist()
{
    return BuffRemovalResist;
}

int Servant::getBuffSuccess()
{
    return BuffSuccess;
}

void Servant::modifyDebuffResist(int deltaDR)
{
    DebuffResist+=deltaDR;
}

void Servant::modifyBuffRemovalResist(int deltaBRR)
{
    BuffRemovalResist+=deltaBRR;
}

void Servant::modifyBuffSuccess(double deltaBS)
{
    BuffSuccess*=deltaBS;
}

bool Servant::getBurn()
{
    return IsBeingBurned;
}

bool Servant::getPoison()
{
    return IsBeingPoisoned;
}

bool Servant::getCurse()
{
    return IsBeingCursed;
}

bool Servant::getStun()
{
    return IsBeingStunned;
}

void Servant::setBurn(bool BurnStatus)
{
    IsBeingBurned=BurnStatus;
}

void Servant::setPoison(bool PoisonStatus)
{
    IsBeingPoisoned=PoisonStatus;
}

void Servant::setCurse(bool CurseStatus)
{
    IsBeingCursed=CurseStatus;
}

void Servant::setStun(bool StunStatus)
{
    IsBeingStunned=StunStatus;
}

bool Servant::getNPSeal()
{
    return IsBeingNPSealed;
}

bool Servant::getSkillSeal()
{
    return IsBeingSkillSealed;
}
void Servant::setNPSeal(bool NPSealStatus)
{
    IsBeingNPSealed=NPSealStatus;
}

void Servant::setSkillSeal(bool SkillSealStatus)
{
    IsBeingSkillSealed=SkillSealStatus;
}

void Servant::modifyCoeffCrit(double CC)
{
    CoeffCrit*=CC;
}

double Servant::getCoeffCrit()
{
    return CoeffCrit;
}

int Servant::getPoids()
{
    return m_poids;
}


bool Servant::getAvoid()
{
    return isAvoiding;
}

bool Servant::getSureHit()
{
    return SureHit;
}

void Servant::setAvoid(bool AvoidStatus)
{
    isAvoiding=AvoidStatus;
}

void Servant::setSureHit(bool SureHitStatus)
{
    SureHit=SureHitStatus;
}

void Servant::modifyCoeffCritQuick(double CCQ)
{
    CoeffCritQuick*=CCQ;
}

void Servant::setProtectionOfKur(bool KurStatus)
{
    ProtectionOfKur=KurStatus;
}

double Servant::getCoeffCritQuick()
{
    return CoeffCritQuick;
}

bool Servant::getProtectionOfKur()
{
    return ProtectionOfKur;
}

void Servant::MiseAJour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    NPCarte->effetParTour(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
    if(!isFrozen)
    {
        problemeStatut();
        for(unsigned int i=0;i<listeBonus.size();i++)
        {
            listeBonus[i]->setNombreTour(-1);
        }
        for(unsigned int i=0;i<listeMalus.size();i++)
        {
            listeMalus[i]->setNombreTour(-1);
        }
    }
    for(unsigned int i=0;i<DeckSkills.size();i++)
    {
        if(m_PV<=0)
        {
            DeckSkills[i]->effetMort(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
        }
        DeckSkills[i]->effetParTour(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
        if(!isFrozen)
        {
            DeckSkills[i]->modifyCooldownAct(-1);
        }
        #if defined(TRACE_ON)
        std::cout<<getNom()<<std::endl;
        std::cout<<DeckSkills[i]->getNom()<<std::endl;
        std::cout<<DeckSkills[i]->getCooldownAct()<<std::endl;
        #endif // defined
        DeckSkills[i]->ResetEffet(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
        #if defined(TRACE_ON)
        std::cout<<"ProcessusResetEffet de DeckSkills"<<std::endl;
        #endif // defined
    }
    for(unsigned int i=0;i<DeckCarte.size();i++)
    {
        DeckCarte[i]->modifyEtoiles(-10);
    }
    NPCarte->resetEffet(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
}

void Servant::setGuts(bool GutStatus)
{
    hasGuts=GutStatus;
}

bool Servant::getGuts()
{
    return hasGuts;
}

bool Servant::getEffetMortSkill()
{
    return EffetMortSkill;
}

bool Servant::getEffetMortNP()
{
    return EffetMortNP;
}

void Servant::setEffetMortSkill(bool EffetMortSkillStatut)
{
    EffetMortSkill=EffetMortSkillStatut;
}

void Servant::setEffetMortNP(bool EffetMortNPStatut)
{
    EffetMortNP=EffetMortNPStatut;
}

int Servant::getFlatDefense()
{
    return FlatDefense;
}
void Servant::modifyFlatDefense(int deltaFlatDefense)
{
    FlatDefense+=deltaFlatDefense;
}

Servant::Servant(std::string nom,int rarete,int PVMax,int poids,int genre,int attribut,int comportement,int alignement,bool isDivine,bool isDragon,Carte* NPCarte,std::vector<Carte*>DeckCarte,std::vector<Skills*>DeckSkills,Classe* CA,int DeathResist)
:m_nom(nom),m_rarete(rarete),m_PV(PVMax),m_PVMax(PVMax),m_poids(poids),genre(genre),attribut(attribut),comportement(comportement),alignement(alignement),isDivine(isDivine),isDragon(isDragon),NPCarte(NPCarte),DeckCarte(DeckCarte),DeckSkills(DeckSkills),CA(CA),DeathResist(DeathResist)
{
    if(attribut==1)
    {
        CoeffATKMan=1.1;
        CoeffATKSky=0.9;
    }
    if(attribut==2)
    {
        CoeffATKEarth=1.1;
        CoeffATKHuman=0.9;
    }
    if(attribut==3)
    {
        CoeffATKEarth=1.1;
        CoeffATKHuman=0.9;
    }
    Extra* ExtraCard= new Extra(nom);
    CarteExtra=ExtraCard;
    CompteurEffet* CharismaAplus=new CompteurEffet("Charisma A+");
    CompteurEffet* GoldenRuleA=new CompteurEffet("Golden Rule A");
    CompteurEffet* TreasuryOfBabylonEX=new CompteurEffet("Treasury Of Babylon EX");
    CompteurEffet* EnumaElish=new CompteurEffet("Enuma Elish");
    CompteurEffet* CharismaB=new CompteurEffet("Charisma B");
    CompteurEffet* ManaBurstA=new CompteurEffet("Mana Burst A");
    CompteurEffet* BattleContinuationA=new CompteurEffet("Battle Continuation A");
    CompteurEffet* ProtectionFromArrowsB=new CompteurEffet("Protection From Arrows B");
    CompteurEffet* GaeBolg=new CompteurEffet("Gae Bolg");
    CompteurEffet* MysticEyesAPlus=new CompteurEffet("Mystic Eyes A+");
    CompteurEffet* MonstrousStrengthB=new CompteurEffet("Monstrous Strength B");
    CompteurEffet* BloodFortAndromedaB=new CompteurEffet("Blood Fort Andromeda B");
    CompteurEffet* Bellerophon=new CompteurEffet("Bellerophon");
    listeBonus.push_back(CharismaAplus);
    listeBonus.push_back(GoldenRuleA);
    listeBonus.push_back(TreasuryOfBabylonEX);
    listeBonus.push_back(EnumaElish);
    listeBonus.push_back(CharismaB);
    listeBonus.push_back(ManaBurstA);
    listeBonus.push_back(BattleContinuationA);
    listeBonus.push_back(ProtectionFromArrowsB);
    listeBonus.push_back(GaeBolg);
    listeMalus.push_back(GaeBolg);
    listeMalus.push_back(MysticEyesAPlus);
    listeBonus.push_back(MonstrousStrengthB);
    listeBonus.push_back(BloodFortAndromedaB);
    listeBonus.push_back(Bellerophon);
    listeMalus.push_back(Bellerophon);

}

Servant::Servant(std::string nom)
:m_nom(nom)
{

}

void Servant::modifyCoeffNoblePhantasm(double deltaCNP)
{
    CoeffNoblePhantasm*=deltaCNP;
}

double Servant::getCoeffNoblePhantasm()
{
    return CoeffNoblePhantasm;
}

void Servant::setGenre(int deltaG)
{
    genre=deltaG;
}
void Servant::setAlignement(int deltaA)
{
    alignement=deltaA;
}
void Servant::setComportement(int deltaC)
{
    comportement=deltaC;
}
int Servant::getGenre()
{
    return genre;
}
int Servant::getAlignement()
{
    return alignement;
}
int Servant::getComportement()
{
    return comportement;
}

void Servant::modifyCoeffSoin(double deltaS)
{
    CoeffSoin*=deltaS;
}
double Servant::getCoeffSoin()
{
    return CoeffSoin;
}

void Servant::modifyDeathResist(int deltaDR)
{
    DeathResist+=deltaDR;
}

int Servant::getDeathResist()
{
    return DeathResist;
}


void  Servant::setDivine(bool DivineStatus)
{
    isDivine=DivineStatus;
}
bool  Servant::getDivine()
{
    return isDivine;
}
void  Servant::setDragon(bool DragonStatus)
{
    isDragon=DragonStatus;
}
bool  Servant::getDragon()
{
    return isDragon;
}

std::vector<Carte*>* Servant::getDeckCarte()
{
    return &DeckCarte;
}

void Servant::setIsInvincible(bool InvincibleStatus)
{
    isInvincible=InvincibleStatus;
}
void Servant::setPierceInvincibility(bool IPStatus)
{
    PierceInvincibility=IPStatus;
}
bool Servant::getIsInvincible()
{
    return isInvincible;
}
bool Servant::getPierceInvincibility()
{
    return PierceInvincibility;
}

CraftEssence* Servant::getCE()
{
    return CE;
}

void Servant::modifyCooldownAct(int deltaCDA)
{
    for(unsigned int i=0;i<DeckSkills.size();i++)
    {
        DeckSkills[i]->modifyCooldownAct(deltaCDA);
    }
}

bool Servant::getNPStatus()
{
    return NPReady;
}
void Servant::setNPStatus()
{
    if(m_JaugeNP==100&&!getNPSeal())
    {
        NPReady=true;
    }
    else
    {
        NPReady=false;
    }
}

Carte* Servant::getNPCarte()
{
    return NPCarte;
}

double Servant::getPVMax()
{
    return m_PVMax;
}
void Servant::modifyPVMax(int deltaPVM)
{
    m_PVMax+=deltaPVM;
}

int Servant::genererEtoiles(Carte* c)
{
    int etoilesGenerees=c->getStarGen()*StarGenerationRate;
    return etoilesGenerees;
}

bool Servant::getTargetFocus()
{
    return hasTargetFocus;
}
void Servant::setTargetFocus(bool deltaTF)
{
    hasTargetFocus=deltaTF;
}

Carte* Servant::getCarteExtra()
{
    return CarteExtra;
}

double Servant::getCoeffATKDragon()
{
    return CoeffATKDragon;
}

double Servant::getCoeffATKDivine()
{
    return CoeffATKDivine;
}
double Servant::getCoeffATKEarth()
{
    return CoeffATKEarth;
}
double Servant::getCoeffATKSky()
{
    return CoeffATKSky;
}
double Servant::getCoeffATKHuman()
{
    return CoeffATKHuman;
}
double Servant::getCoeffATKStar()
{
    return CoeffATKStar;
}
double Servant::getCoeffATKMan()
{
    return CoeffATKMan;
}
double Servant::getCoeffATKWoman()
{
    return CoeffATKWoman;
}
double Servant::getCoeffATKGood()
{
    return CoeffATKGood;
}
double Servant::getCoeffATKEvil()
{
    return CoeffATKEvil;
}
void Servant::modifyCoeffATKDragon(double deltaDR)
{
    CoeffATKDragon*=deltaDR;
}
void Servant::modifyCoeffATKDivine(double deltaDI)
{
    CoeffATKDivine*=deltaDI;
}
void Servant::modifyCoeffATKEarth(double deltaEA)
{
    CoeffATKEarth*=deltaEA;
}
void Servant::modifyCoeffATKSky(double deltaSK)
{
    CoeffATKSky*=deltaSK;
}
void Servant::modifyCoeffATKHuman(double deltaHU)
{
    CoeffATKHuman*=deltaHU;
}
void Servant::modifyCoeffATKStar(double deltaST)
{
    CoeffATKStar*=deltaST;
}
void Servant::modifyCoeffATKMan(double deltaMA)
{
    CoeffATKMan*=deltaMA;
}
void Servant::modifyCoeffATKWoman(double deltaWO)
{
    CoeffATKWoman*=deltaWO;
}
void Servant::modifyCoeffATKGood(double deltaGO)
{
    CoeffATKGood*=deltaGO;
}
void Servant::modifyCoeffATKEvil(double deltaEV)
{
    CoeffATKEvil*=deltaEV;
}

int Servant::getFlatAttaque()
{
    return FlatAttaque;
}
void Servant::modifyFlatAttaque(int deltaFA)
{
    FlatAttaque+=deltaFA;
}
void Servant::calculDefense(Carte* c,Servant* Defense)
{
    int degats=c->getDegats()*CoeffAttaque/Defense->getCoeffDefense();
    #if defined(TRACE_ON)
    std::cout<<"Base:"<<(double)(degats/c->getDegats())<<std::endl;
    std::cout<<"Coeff Attaque: "<<CoeffAttaque<<std::endl;
    #endif // defined
    if(c->coupCritique())
    {
        degats*=2*CoeffCrit;
        std::cout<<"Coup critique !"<<std::endl;
    }
    #if defined(TRACE_ON)
    std::cout<<"Crit: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(c->getTypeCarte()=="Buster")
    {
        degats*=CoeffATKBuster/Defense->getCoeffDEFBuster();
    }
    #if defined(TRACE_ON)
    std::cout<<"Buster: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(c->getTypeCarte()=="Arts")
    {
        degats*=CoeffATKArts/Defense->getCoeffDEFArts();
    }
    #if defined(TRACE_ON)
    std::cout<<"Arts:"<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(c->getTypeCarte()=="Quick")
    {
        degats*=CoeffATKQuick/Defense->getCoeffDEFQuick();
        if(c->coupCritique())
        {
            degats*=CoeffCritQuick;
        }
    }
    #if defined(TRACE_ON)
    std::cout<<"Quick: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(c->getIsNoblePhantasm())
    {
        degats*=CoeffNoblePhantasm;
    }
    #if defined(TRACE_ON)
    std::cout<<"NP: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(Defense->getAlignement()==1)
    {
        degats*=CoeffATKGood;
    }
    #if defined(TRACE_ON)
    std::cout<<"Good: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(Defense->getAlignement()==3)
    {
        degats*=CoeffATKEvil;
    }
    #if defined(TRACE_ON)
    std::cout<<"Evil: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(Defense->getGenre()==1)
    {
        degats*=CoeffATKMan;
    }
    #if defined(TRACE_ON)
    std::cout<<"Man: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(Defense->getGenre()==2)
    {
        degats*=CoeffATKWoman;
    }
    #if defined(TRACE_ON)
    std::cout<<"Woman: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(Defense->getDragon())
    {
        degats*=CoeffATKDragon;
    }
    #if defined(TRACE_ON)
    std::cout<<"Dragon: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(Defense->getDivine())
    {
        degats*=CoeffATKDivine;
    }
    #if defined(TRACE_ON)
    std::cout<<"Divine: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(Defense->getAttribut()==1)
    {
        degats*=CoeffATKEarth;
    }
    #if defined(TRACE_ON)
    std::cout<<"Earth: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(Defense->getAttribut()==2)
    {
        degats*=CoeffATKSky;
    }
    #if defined(TRACE_ON)
    std::cout<<"Sky: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    if(Defense->getAttribut()==3)
    {
        degats*=CoeffATKHuman;
    }
    #if defined(TRACE_ON)
    std::cout<<"Human: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined
    {
        if(CA->getNom()=="Berserker"||Defense->CA->getNom()=="Berserker")
        {
            degats*=1.5;
        }
        else
        {
            for(unsigned int i=0;i<CA->getFaibleContre()->size();i++)
            {
                if(Defense->CA->getNom()==CA->getFaibleContre()->at(i))
                {
                    degats*=0.50;
                    std::cout<<"Ce n'est pas très efficace..."<<std::endl;
                }
            }
            for(unsigned int i=0;i<CA->getFortContre()->size();i++)
            {
                if(Defense->CA->getNom()==CA->getFortContre()->at(i))
                {
                    degats*=2.0;
                    std::cout<<"C'est super efficace !"<<std::endl;
                }
            }
        }
    }
    #if defined(TRACE_ON)
    std::cout<<"Class: "<<(double)(degats/c->getDegats())<<std::endl;
    #endif // defined


    degats+=FlatAttaque-Defense->getFlatDefense();
    if(Defense->isAvoiding&&(!SureHit&&!PierceInvincibility))
    {
        degats*=0;
        std::cout<<Defense->getNom()<<" évite l'attaque !"<<std::endl;
    }
    if(Defense->isInvincible&&!PierceInvincibility)
    {
        degats*=0;
        std::cout<<Defense->getNom()<<" est invincible !"<<std::endl;
    }
    if(degats<0)
    {
        degats=0;
    }
    Defense->modifyPV(-degats);
    #if defined(TRACE_ON)
    std::cout<<"Total: "<<(degats/c->getDegats())<<std::endl;
    #endif // defined
    std::cout<<m_nom<<" inflige "<<degats<<" dégâts à "<<Defense->getNom()<<" !"<<std::endl;
}

/*void Servant::setCraftEssence(CraftEssence* C)
{
    CE=C;
}*/

int Servant::getAttribut()
{
    return attribut;
}

void Servant::genererNP(Carte* c)
{
    modifyJaugeNP(c->getNP()*NPGenerationRate);
    #if defined(TRACE_ON)
    std::cout<<"Jauge NP: "<<m_JaugeNP<<std::endl;
    #endif // defined
}

void Servant::problemeStatut()
{
    if(IsBeingBurned)
    {
        m_PV-=500;
    }
    if(IsBeingCursed)
    {
        m_PV-=1500;
    }
    if(IsBeingPoisoned)
    {
        m_PV-=1000;
    }
}

std::vector<Skills*>* Servant::getDeckSkills()
{
    return &DeckSkills;
}

std::vector<CompteurEffet*>* Servant::getListeBonus()
{
    return &listeBonus;
}

std::vector<CompteurEffet*>* Servant::getListeMalus()
{
    return &listeMalus;
}
bool Servant::getIsFrozen()
{
    return isFrozen;
}
void Servant::setIsFrozen(bool deltaIF)
{
    isFrozen=deltaIF;
}

void Servant::InstaKill(int DeathChance)
{
    srand(time(NULL));
    int mort=rand()%(DeathResist+DeathChance);
    if(mort<=DeathChance)
    {
        m_PV=0;
    }
}

bool Servant::getIsAttacking()
{
    return isAttacking;
}
bool Servant::getIsDefending()
{
    return isDefending;
}
void Servant::setIsAttacking(bool AttackStatus)
{
    isAttacking=AttackStatus;
}
void Servant::setIsDefending(bool DefenseStatus)
{
    isDefending=DefenseStatus;
}
