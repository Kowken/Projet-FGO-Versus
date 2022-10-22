#include "artoria.h"
//#define TRACE_ON
//=========================== CHARISMA B ================================================
std::string CharismaB::getNom()
{
    return m_nom;
}

CharismaB::CharismaB(std::string nomProprio)
:nomProprio(nomProprio)
{

}

CharismaB::~CharismaB()
{

}

void CharismaB::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    std::vector<std::string> beneficiaires;
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        equipeEnCours->at(i)->setCoeffAttaque(1.18);
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
            {
                equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(3);
            }
        }
    }
    m_cooldownAction=5;
    std::cout<<"L'attaque de l'equipe augmente de 18% !"<<std::endl;
}
void CharismaB::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setCoeffAttaque((1/1.18));
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                    std::cout<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                }
            }
        }
    }
}
void CharismaB::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void CharismaB::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void CharismaB::description()
{
    std::cout<<"Augmente l'attaque des allies de 18% pendant 3 tours.";
}
void CharismaB::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//====================================== MANA BURST A ====================================================
std::string ManaBurstA::getNom()
{
    return m_nom;
}

ManaBurstA::ManaBurstA(std::string nomProprio)
:nomProprio(nomProprio)
{

}

ManaBurstA::~ManaBurstA()
{

}

void ManaBurstA::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            equipeEnCours->at(i)->setCoeffATKBuster(1.5);
            for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(1);
                }
            }
        }
    }
    std::cout<<"L'efficacite des cartes de type Buster de "<<nomProprio<<" a augmente de 50% !"<<std::endl;
    m_cooldownAction=5;
}
void ManaBurstA::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setCoeffATKBuster((1/1.5));
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                    std::cout<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                }
            }
        }
    }
}
void ManaBurstA::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void ManaBurstA::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void ManaBurstA::description()
{
    std::cout<<"Augmente l'efficacite des cartes de type Buster de 50% pendant 1 tour.";
}
void ManaBurstA::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//================================================ EXCALIBUR ==============================================

std::string Excalibur::getNomNP()
{
    return nomNP;
}

Excalibur::Excalibur(std::string nomProprio)
:nomProprio(nomProprio)
{

}
Excalibur::~Excalibur()
{

}
void Excalibur::effet(Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            equipeEnCours->at(i)->modifyJaugeNP(20);
            for(unsigned j=0;j<equipeAdverse->size();j++)
            {
                for(unsigned int k=0;k<equipeAdverse->at(j)->getDeckSkills()->size();k++)
                {
                    equipeAdverse->at(j)->getDeckSkills()->at(k)->effetDefense(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
                }
                equipeAdverse->at(j)->getNPCarte()->effetDefense(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
                equipeEnCours->at(i)->calculDefense(this,equipeAdverse->at(j));
            }
        }
    }
}
void Excalibur::resetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void Excalibur::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void Excalibur::Overcharge()
{

}
void Excalibur::description()
{
    std::cout<<"Inflige de lourds degats à tous les ennemis. Recharge sa jauge de Noble Phantasm de 50%.";
}

void Excalibur::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

int Excalibur::getDegats()
{
    return m_degats;
}

int Excalibur::getStarGen()
{
    return m_starGen;
}

int Excalibur::getNP()
{
    return m_NPGen;
}

std::string Excalibur::getTypeCarte()
{
    return TypeCarte;
}

bool Excalibur::getIsNoblePhantasm()
{
    return isNoblePhantasm;
}

std::string Excalibur::getNomProprio()
{
    return nomProprio;
}

//=============================== TREASURY OF BABYLON EX =============================

std::string ShiningPathEX::getNom()
{
    return m_nom;
}

ShiningPathEX::ShiningPathEX(std::string nomProprio)
:nomProprio(nomProprio)
{

}
ShiningPathEX::~ShiningPathEX()
{

}
void ShiningPathEX::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            stockEtoilesEquipeEnCours+=15;
            equipeEnCours->at(i)->modifyJaugeNP(30);
        }
    }
    std::cout<<"La jauge de Noble Phantasm "<<nomProprio<<" a augmente de 30% et l'equipe a gagne 15 etoiles !"<<std::endl;
}
void ShiningPathEX::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void ShiningPathEX::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void ShiningPathEX::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void ShiningPathEX::description()
{
    std::cout<<"Augmente la jauge de Noble Phantasm de l'utilisateur de 30% et donne 15 etoiles à l'equipe."<<std::endl;
}
void ShiningPathEX::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//=========================================== INITIALISER ===================================

Servant* initialiserArtoria(std::string nom)
{
    CharismaB* charismab= new CharismaB(nom);
    ManaBurstA* manabursta = new ManaBurstA(nom);
    ShiningPathEX* shiningpathex = new ShiningPathEX(nom);
    Excalibur* excalibur = new Excalibur(nom);
    Buster* buster1= new Buster(nom);
    Buster* buster2= new Buster(nom);
    Arts* arts1= new Arts(nom);
    Arts* arts2= new Arts(nom);
    Quick* quick1= new Quick(nom);
    Saber* saber= new Saber;
    Servant* Artoria= new Servant (nom,5,16597,12,2,1,1,1,false,true,excalibur,{buster1,buster2,arts1,arts2,quick1},{charismab,manabursta,shiningpathex},saber,79);
    return Artoria;
}

