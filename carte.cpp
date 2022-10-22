#include "head.h"

//================================= CARTE ==============================================================
Carte::Carte()
{

}

Carte::Carte(std::string nomProprio)
:nomProprio(nomProprio)
{

}

Carte::~Carte()
{

}

std::string Carte::getTypeCarte()
{
    return TypeCarte;
}

void Carte::setTypeCarte(std::string deltaTypeCarte)
{
    TypeCarte=deltaTypeCarte;
}

void Carte::effet(Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

void Carte::resetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

void Carte::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

bool Carte::getIsNoblePhantasm()
{
    return isNoblePhantasm;
}

std::string Carte::getNomProprio()
{
    return nomProprio;
}

void Carte::Overcharge()
{

}
int Carte::getEtoiles()
{
    return etoiles;
}
void Carte::modifyEtoiles(int deltaEtoiles)
{
    etoiles+=deltaEtoiles;
    if(etoiles<0)
    {
        etoiles=0;
    }
    if(etoiles>10)
    {
        etoiles=10;
    }
}
std::string Carte::getNomNP()
{
    return nomNP;
}

void Carte::description()
{

}

void Carte::ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    effetParTour(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
    resetEffet(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
}

void Carte::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

int Carte::getDegats()
{
    return m_degats;
}

int Carte::getStarGen()
{
    return m_starGen;
}

int Carte::getNP()
{
    return m_NPGen;
}

bool Carte::coupCritique()
{
    srand(time(NULL));
    int CritChance=rand()%10 + 1;
    if(CritChance<=etoiles)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//================================= BUSTER ==============================================================
std::string Buster::getTypeCarte()
{
    return TypeCarte;
}


Buster::Buster():Carte()
{

}

Buster::Buster(std::string nomProprio)
:Carte(nomProprio)
{

}

Buster::~Buster()
{

}

int Buster::getDegats()
{
    return m_degats;
}

int Buster::getStarGen()
{
    return m_starGen;
}

int Buster::getNP()
{
    return m_NPGen;
}

bool Buster::getIsNoblePhantasm()
{
    return isNoblePhantasm;
}

std::string Buster::getNomProprio()
{
    return nomProprio;
}
//================================= QUICK ==============================================================
std::string Quick::getTypeCarte()
{
    return TypeCarte;
}


Quick::Quick(std::string nomProprio)
:Carte(nomProprio)
{

}

Quick::Quick():Carte()
{

}

Quick::~Quick()
{

}

int Quick::getDegats()
{
    return m_degats;
}

int Quick::getStarGen()
{
    return m_starGen;
}

int Quick::getNP()
{
    return m_NPGen;
}

bool Quick::getIsNoblePhantasm()
{
    return isNoblePhantasm;
}

std::string Quick::getNomProprio()
{
    return nomProprio;
}
//================================= ARTS ==============================================================
std::string Arts::getTypeCarte()
{
    return TypeCarte;
}


Arts::Arts(std::string nomProprio)
:Carte(nomProprio)
{

}

Arts::Arts():Carte()
{

}

Arts::~Arts()
{

}

int Arts::getDegats()
{
    return m_degats;
}

int Arts::getStarGen()
{
    return m_starGen;
}

int Arts::getNP()
{
    return m_NPGen;
}


bool Arts::getIsNoblePhantasm()
{
    return isNoblePhantasm;
}

std::string Arts::getNomProprio()
{
    return nomProprio;
}
//================================= EXTRA ==============================================================
Extra::Extra(std::string nomProprio)
:Carte(nomProprio)
{

}

Extra::Extra()
:Carte()
{

}

Extra::~Extra()
{

}

int Extra::getDegats()
{
    return m_degats;
}

int Extra::getStarGen()
{
    return m_starGen;
}

int Extra::getNP()
{
    return m_NPGen;
}

bool Extra::getIsNoblePhantasm()
{
    return isNoblePhantasm;
}

std::string Extra::getNomProprio()
{
    return nomProprio;
}

std::string Extra::getTypeCarte()
{
    return TypeCarte;
}
