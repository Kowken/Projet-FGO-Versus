#include "cuChulainn.h"

#define TRACE_ON
//=========================== BATTLE CONTINUATION A ================================================
std::string BattleContinuationA::getNom()
{
    return m_nom;
}

BattleContinuationA::BattleContinuationA(std::string nomProprio)
:nomProprio(nomProprio)
{

}

BattleContinuationA::~BattleContinuationA()
{

}

void BattleContinuationA::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(5);
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreFois()->push_back(1);
                }
            }
        }
    }
    std::cout<<nomProprio<<"est prêt à encaisser les coups !"<<std::endl;
    m_cooldownAction=7;
}
void BattleContinuationA::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreFois()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreFois()->begin());
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                    std::cout<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                }
            }
        }
    }
}
void BattleContinuationA::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->modifyPV(2500);
                    equipeEnCours->at(i)->getListeBonus()->at(j)->setNombreFois(-1);
                    std::cout<<equipeEnCours->at(i)->getNom()<<" a survécu à l'attaque !"<<std::endl;
                }
            }
        }
    }
}
void BattleContinuationA::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void BattleContinuationA::description()
{
    std::cout<<"Permet de survivre à une seule attaque mortelle pendant 5 tours.";
}
void BattleContinuationA::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//====================================== PROTECTION FROM ARROWS B ====================================================
std::string ProtectionFromArrowsB::getNom()
{
    return m_nom;
}

ProtectionFromArrowsB::ProtectionFromArrowsB(std::string nomProprio)
:nomProprio(nomProprio)
{

}

ProtectionFromArrowsB::~ProtectionFromArrowsB()
{

}

void ProtectionFromArrowsB::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            equipeEnCours->at(i)->setAvoid(true);
            equipeEnCours->at(i)->setCoeffDefense(1.16);
            for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(3);
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreFois()->push_back(3);
                }
            }
        }
    }
    std::cout<<"La défense de"<<nomProprio<<"a augmenté de 16% et le voilà prêt à esquiver les 3 prochaines attaques!"<<std::endl;
    m_cooldownAction=6;
}
void ProtectionFromArrowsB::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setCoeffDefense((1/1.16));
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                    std::cout<<"L'effet de défense de "<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                }
            }
        }
    }
}
void ProtectionFromArrowsB::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void ProtectionFromArrowsB::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
            {
                if(equipeEnCours->at(i)->getIsDefending()&&!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreFois()->empty())
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->setNombreFois(-1);
                    if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreFois()->at(0)==0)
                    {
                        equipeEnCours->at(i)->setAvoid(false);
                        equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreFois()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreFois()->begin());
                        std::cout<<"L'effet d'esquive de "<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                    }
                }
            }
        }
    }
}
void ProtectionFromArrowsB::description()
{
    std::cout<<"Permet d'esquiver 3 attaques et augmente la défense de 16% pendant 3 tours.";
}
void ProtectionFromArrowsB::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//================================================GAE BOLG==============================================

std::string GaeBolg::getNomNP()
{
    return nomNP;
}

GaeBolg::GaeBolg(std::string nomProprio)
:nomProprio(nomProprio)
{

}
GaeBolg::~GaeBolg()
{

}
void GaeBolg::effet(Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            equipeEnCours->at(i)->setSureHit(true);
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
                Cible->InstaKill(60);
                Cible->calculDefense(this,equipeAdverse->at(j));
                Cible->setCoeffDefense(0.8);
                for(unsigned int k=0;k<Cible->getListeMalus()->size();k++)
                {
                    if(Cible->getListeMalus()->at(k)->getNomEffet()==nomNP)
                    {
                        Cible->getListeMalus()->at(k)->getNombreTour()->push_back(3);
                    }
                }
            }
        }
    }
}
void GaeBolg::resetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==nomNP&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setSureHit(false);
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                }
            }
        }
    }
    for(unsigned i=0;i<equipeAdverse->size();i++)
    {
        for(unsigned int j=0;j<equipeAdverse->at(i)->getListeMalus()->size();j++)
        {
            if(!equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->empty())
            {
                if(equipeAdverse->at(i)->getListeMalus()->at(j)->getNomEffet()==nomNP&&equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeAdverse->at(i)->setCoeffDefense((1/0.8));
                    equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->erase(equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->begin());
                }
            }
        }
    }
}
void GaeBolg::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void GaeBolg::Overcharge()
{

}
void GaeBolg::description()
{
    std::cout<<"Inflige de lourds dégâts à la cible puis lui baisse sa défense. A une chance de tuer instantanément";
}

void GaeBolg::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

int GaeBolg::getDegats()
{
    return m_degats;
}

int GaeBolg::getStarGen()
{
    return m_starGen;
}

int GaeBolg::getNP()
{
    return m_NPGen;
}

std::string GaeBolg::getTypeCarte()
{
    return TypeCarte;
}

bool GaeBolg::getIsNoblePhantasm()
{
    return isNoblePhantasm;
}

std::string GaeBolg::getNomProprio()
{
    return nomProprio;
}

//=============================== DISENGAGE C =============================

std::string DisengageC::getNom()
{
    return m_nom;
}

DisengageC::DisengageC(std::string nomProprio)
:nomProprio(nomProprio)
{

}
DisengageC::~DisengageC()
{

}
void DisengageC::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            for(unsigned int j=0;j<equipeEnCours->at(i)->getListeMalus()->size();j++)
            {
                equipeEnCours->at(i)->getListeMalus()->at(j)->getNombreTour()->clear();
                equipeEnCours->at(i)->getListeMalus()->at(j)->getNombreFois()->clear();
            }
            equipeEnCours->at(i)->modifyPV(1500);
        }
    }
    std::cout<<nomProprio<<" a perdu tous ses malus et a récupéré de la vie !"<<std::endl;
}
void DisengageC::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void DisengageC::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void DisengageC::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void DisengageC::description()
{
    std::cout<<"Enlève à l'utilisateur tous ses malus avant de lui restaurer de la vie";
}
void DisengageC::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//=========================================== INITIALISER ===================================

Servant* initialiserCuChulainn(std::string nom)
{
    BattleContinuationA* battlecontinuationa= new BattleContinuationA(nom);
    ProtectionFromArrowsB* protectionfromarrowsb = new ProtectionFromArrowsB(nom);
    DisengageC* disengagec = new DisengageC(nom);
    GaeBolg* gaebolg = new GaeBolg(nom);
    Buster* buster1= new Buster(nom);
    Buster* buster2= new Buster(nom);
    Arts* arts1= new Arts(nom);
    Quick* quick1= new Quick(nom);
    Quick* quick2= new Quick(nom);
    Lancer* lancer= new Lancer;
    Servant* CuChulainn= new Servant (nom,3,13007,7,1,1,1,2,false,false,gaebolg,{buster1,buster2,arts1,quick1,quick2},{battlecontinuationa,protectionfromarrowsb,disengagec},lancer,68);
    return CuChulainn;
}

