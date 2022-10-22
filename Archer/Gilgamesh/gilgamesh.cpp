#include "Gilgamesh.h"
#define TRACE_ON
//=========================== CHARISMA A+ ================================================
std::string CharismaAplus::getNom()
{
    return m_nom;
}

CharismaAplus::CharismaAplus(std::string nomProprio)
:nomProprio(nomProprio)
{

}

CharismaAplus::~CharismaAplus()
{

}

void CharismaAplus::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        equipeEnCours->at(i)->setCoeffAttaque(1.21);
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
            {
                equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(3);
            }
        }
    }
    m_cooldownAction=5;
    std::cout<<"L'attaque de l'equipe augmente de 21% !"<<std::endl;
}
void CharismaAplus::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setCoeffAttaque((1/1.21));
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                    std::cout<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                }
            }
        }
    }
}
void CharismaAplus::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void CharismaAplus::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void CharismaAplus::description()
{
    std::cout<<"Augmente l'attaque des allies de 21% pendant 3 tours.";
}
void CharismaAplus::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//====================================== GOLDEN RULE A ====================================================
std::string GoldenRuleA::getNom()
{
    return m_nom;
}

GoldenRuleA::GoldenRuleA(std::string nomProprio)
:nomProprio(nomProprio)
{

}

GoldenRuleA::~GoldenRuleA()
{

}

void GoldenRuleA::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            equipeEnCours->at(i)->setNPGenerationRate(1.5);
            for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(3);
                }
            }
        }
    }
    std::cout<<"Le taux de generation de Noble Phantasm de "<<nomProprio<<" a augmente de 50% !"<<std::endl;
    m_cooldownAction=6;
}
void GoldenRuleA::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setNPGenerationRate((1/1.5));
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                    std::cout<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                }
            }
        }
    }
}
void GoldenRuleA::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void GoldenRuleA::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void GoldenRuleA::description()
{
    std::cout<<"Augmente le taux de generation de Noble Phantasm de 50% pendant 3 tours.";
}
void GoldenRuleA::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//================================================ENUMA ELISH==============================================

std::string EnumaElish::getNomNP()
{
    return nomNP;
}

EnumaElish::EnumaElish(std::string nomProprio)
:nomProprio(nomProprio)
{

}
EnumaElish::~EnumaElish()
{

}
void EnumaElish::effet(Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            equipeEnCours->at(i)->modifyCoeffNoblePhantasm(1.3);
            equipeEnCours->at(i)->modifyCoeffATKEarth(1.5);
            equipeEnCours->at(i)->modifyCoeffATKSky(1.5);
            equipeEnCours->at(i)->modifyCoeffATKHuman(1.5);
            for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==nomNP)
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(1);
                }
            }
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
void EnumaElish::resetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==nomNP&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->modifyCoeffNoblePhantasm((1/1.3));
                    equipeEnCours->at(i)->modifyCoeffATKEarth((1/1.5));
                    equipeEnCours->at(i)->modifyCoeffATKSky((1/1.5));
                    equipeEnCours->at(i)->modifyCoeffATKMan((1/1.5));
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                }
            }
        }
    }
}
void EnumaElish::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void EnumaElish::Overcharge()
{

}
void EnumaElish::description()
{
    std::cout<<"Augmente la puissance de son Noble Phantasm (1 tour) avant d'infliger de lourds degats à tous les ennemis. Inflige des degats supplementaires à tous les Servants ayant l'attribut Terre, Ciel ou Humain.";
}

void EnumaElish::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

int EnumaElish::getDegats()
{
    return m_degats;
}

int EnumaElish::getStarGen()
{
    return m_starGen;
}

int EnumaElish::getNP()
{
    return m_NPGen;
}

std::string EnumaElish::getTypeCarte()
{
    return TypeCarte;
}

bool EnumaElish::getIsNoblePhantasm()
{
    return isNoblePhantasm;
}

std::string EnumaElish::getNomProprio()
{
    return nomProprio;
}

//=============================== TREASURY OF BABYLON EX =============================

std::string TreasuryOfBabylonEX::getNom()
{
    return m_nom;
}

TreasuryOfBabylonEX::TreasuryOfBabylonEX(std::string nomProprio)
:nomProprio(nomProprio)
{

}
TreasuryOfBabylonEX::~TreasuryOfBabylonEX()
{

}
void TreasuryOfBabylonEX::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            equipeEnCours->at(i)->setStarGatherRate(6);
            equipeEnCours->at(i)->modifyJaugeNP(30);
            for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(3);
                }
            }
        }
    }
    std::cout<<"La jauge de Noble Phantasm "<<nomProprio<<" a augmente de 30% et son taux d'absorption d'etoiles de 600% !"<<std::endl;
}
void TreasuryOfBabylonEX::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setStarGatherRate((1/6));
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                    std::cout<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                    #if defined (TRACE_ON)
                    std::cout<<"reset batard"<<std::endl;
                    #endif // defined
                }
            }
        }
    }
}
void TreasuryOfBabylonEX::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void TreasuryOfBabylonEX::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void TreasuryOfBabylonEX::description()
{
    std::cout<<"Augmente la jauge de Noble Phantasm de l'utilisateur de 30% et son taux d'absorption d'etoiles de 600% pendant 3 tours.";
}
void TreasuryOfBabylonEX::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//=========================================== INITIALISER ===================================

Servant* initialiserGilgamesh(std::string nom)
{
    CharismaAplus* charismaaplus= new CharismaAplus(nom);
    GoldenRuleA* goldenrulea = new GoldenRuleA(nom);
    TreasuryOfBabylonEX* treasuryofbabylonex = new TreasuryOfBabylonEX(nom);
    EnumaElish* enumaelish = new EnumaElish(nom);
    Buster* buster1= new Buster(nom);
    Buster* buster2= new Buster(nom);
    Arts* arts1= new Arts(nom);
    Arts* arts2= new Arts(nom);
    Quick* quick1= new Quick(nom);
    Archer* archer= new Archer;
    Servant* Gilgamesh= new Servant (nom,5,13097,12,1,2,3,1,true,false,enumaelish,{buster1,buster2,arts1,arts2,quick1},{charismaaplus,goldenrulea,treasuryofbabylonex},archer,70);
    return Gilgamesh;
}

