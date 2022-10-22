#include "medusa.h"
//#define TRACE_ON
//=========================== MYSTIC EYES ================================================
std::string MysticEyesAPlus::getNom()
{
    return m_nom;
}

MysticEyesAPlus::MysticEyesAPlus(std::string nomProprio)
:nomProprio(nomProprio)
{

}

MysticEyesAPlus::~MysticEyesAPlus()
{

}

void MysticEyesAPlus::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    bool TargetFocusCase=false;
    int choixCible=0;
    std::cout<<"Choisissez votre cible:"<<std::endl;
    for(unsigned int i=0;i<equipeAdverse->size();i++)
    {
        if(equipeAdverse->at(i)->getTargetFocus())
        {
            TargetFocusCase=true;
        }
    }
    if(TargetFocusCase)
    {
        for(unsigned int i=0;i<equipeAdverse->size();i++)
        {
            if(equipeAdverse->at(i)->getTargetFocus())
            {
                std::cout<<i+1<<". "<<equipeAdverse->at(i)->getNom()<<std::endl;
            }
        }
        do
        {
            std::cin>>choixCible;
        }
        while(choixCible-1<0||choixCible-1>=3||!equipeAdverse->at(choixCible-1)->getTargetFocus());
    }
    else
    {
        for(unsigned int i=0;i<3;i++)
        {
            std::cout<<i+1<<". "<<equipeAdverse->at(i)->getNom()<<std::endl;
        }
        do
        {
            std::cin>>choixCible;
        }
        while(choixCible-1<0||choixCible-1>=3);
    }
    equipeAdverse->at(choixCible-1)->setStun(true);
    for(unsigned int i=0;i<equipeAdverse->at(choixCible-1)->getListeMalus()->size();i++)
    {
        if(equipeAdverse->at(choixCible-1)->getListeMalus()->at(i)->getNomEffet()==m_nom)
        {
            equipeAdverse->at(choixCible-1)->getListeMalus()->at(i)->getNombreTour()->push_back(1);
        }
    }
    m_cooldownAction=5;
    std::cout<<equipeAdverse->at(choixCible-1)->getNom()<<" est paralyse !"<<std::endl;
}
void MysticEyesAPlus::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeAdverse->size();i++)
    {
        for(unsigned int j=0;j<equipeAdverse->at(i)->getListeMalus()->size();j++)
        {
            if(!equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->empty())
            {
                if(equipeAdverse->at(i)->getListeMalus()->at(j)->getNomEffet()==m_nom&&equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeAdverse->at(i)->setStun(false);
                    equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->erase(equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->begin());
                }
            }
        }
    }
}
void MysticEyesAPlus::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void MysticEyesAPlus::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void MysticEyesAPlus::description()
{
    std::cout<<"Capable d'infliger un etourdissement a un seul ennemi pendant 1 tour.";
}
void MysticEyesAPlus::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//====================================== MONSTROUS STRENGTH B ====================================================
std::string MonstrousStrengthB::getNom()
{
    return m_nom;
}

MonstrousStrengthB::MonstrousStrengthB(std::string nomProprio)
:nomProprio(nomProprio)
{

}

MonstrousStrengthB::~MonstrousStrengthB()
{

}

void MonstrousStrengthB::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            equipeEnCours->at(i)->setCoeffAttaque(1.3);
            for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(2);
                }
            }
        }
    }
    std::cout<<"L'attaque de " <<nomProprio<< " a augmente de 30% !"<<std::endl;
    m_cooldownAction=5;
}
void MonstrousStrengthB::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setCoeffAttaque((1/1.3));
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                    std::cout<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                }
            }
        }
    }
}
void MonstrousStrengthB::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void MonstrousStrengthB::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void MonstrousStrengthB::description()
{
    std::cout<<"Augmente l'attaque de 30% pendant 2 tours.";
}
void MonstrousStrengthB::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//================================================ BELLEROPHON ==============================================

std::string Bellerophon::getNomNP()
{
    return nomNP;
}

Bellerophon::Bellerophon(std::string nomProprio)
:nomProprio(nomProprio)
{

}
Bellerophon::~Bellerophon()
{

}
void Bellerophon::effet(Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            for(unsigned j=0;j<equipeAdverse->size();j++)
            {
                for(unsigned int k=0;k<equipeAdverse->at(j)->getDeckSkills()->size();k++)
                {
                    equipeAdverse->at(j)->getDeckSkills()->at(k)->effetDefense(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
                }
                equipeAdverse->at(j)->getNPCarte()->effetDefense(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
                equipeAdverse->at(j)->calculDefense(this,equipeAdverse->at(j));
                equipeAdverse->at(j)->setStarGenerationRate(0.8);
                for(unsigned int k=0;k<equipeAdverse->at(j)->getListeMalus()->size();k++)
                {
                    if(equipeAdverse->at(j)->getListeMalus()->at(k)->getNomEffet()==nomNP)
                    {
                        equipeAdverse->at(j)->getListeMalus()->at(k)->getNombreTour()->push_back(3);
                    }
                }
            }
        }
        equipeEnCours->at(i)->setStarGenerationRate(1.5);
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==nomNP)
            {
                equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(3);
            }
        }
    }
}
void Bellerophon::resetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==nomNP&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setStarGenerationRate((1/1.5));
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
                    equipeAdverse->at(i)->setStarGenerationRate((1/0.8));
                    equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->erase(equipeAdverse->at(i)->getListeMalus()->at(j)->getNombreTour()->begin());
                }
            }
        }
    }
}
void Bellerophon::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void Bellerophon::Overcharge()
{

}
void Bellerophon::description()
{
    std::cout<<"Fais de gros degats à tous les ennemis. Diminue de 20% le taux critique pour tous les ennemis et augmente le taux critique des etoiles pour tous les allies pendant 3 tours.";
}

void Bellerophon::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

int Bellerophon::getDegats()
{
    return m_degats;
}

int Bellerophon::getStarGen()
{
    return m_starGen;
}

int Bellerophon::getNP()
{
    return m_NPGen;
}

std::string Bellerophon::getTypeCarte()
{
    return TypeCarte;
}

bool Bellerophon::getIsNoblePhantasm()
{
    return isNoblePhantasm;
}

std::string Bellerophon::getNomProprio()
{
    return nomProprio;
}

//=============================== BLOOD FORT ANDROMEDA =============================

std::string BloodFortAndromedaB::getNom()
{
    return m_nom;
}

BloodFortAndromedaB::BloodFortAndromedaB(std::string nomProprio)
:nomProprio(nomProprio)
{

}
BloodFortAndromedaB::~BloodFortAndromedaB()
{

}
void BloodFortAndromedaB::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        if(equipeEnCours->at(i)->getNom()==nomProprio)
        {
            equipeEnCours->at(i)->modifyJaugeNP(20);
            equipeEnCours->at(i)->setNPGenerationRate(1.3);
            for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom)
                {
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->push_back(3);
                }
            }
        }
    }
    std::cout<<"La jauge de Noble Phantasm " <<nomProprio<< " a augmente de 20% et son taux de generation de Noble Phantasm a augmente de 30% !"<<std::endl;
    m_cooldownAction=6;
}
void BloodFortAndromedaB::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    for(unsigned i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->at(i)->getListeBonus()->size();j++)
        {
            if(!equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->empty())
            {
                if(equipeEnCours->at(i)->getListeBonus()->at(j)->getNomEffet()==m_nom&&equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->at(0)==0)
                {
                    equipeEnCours->at(i)->setNPGenerationRate((1/1.3));
                    equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->erase(equipeEnCours->at(i)->getListeBonus()->at(j)->getNombreTour()->begin());
                    std::cout<<m_nom<<" ne fait plus effet sur "<<equipeEnCours->at(i)->getNom()<<" !"<<std::endl;
                }
            }
        }
    }
}
void BloodFortAndromedaB::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void BloodFortAndromedaB::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void BloodFortAndromedaB::description()
{
    std::cout<<"Augmente la jauge de Noble Phantasm de l'utilisateur de 20% et augmente son propre gain de Noble Phantasm pendant 3 tours."<<std::endl;
}
void BloodFortAndromedaB::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

//=========================================== INITIALISER ===================================

Servant* initialiserMedusa(std::string nom)
{
    MysticEyesAPlus* mysticeyesaplus= new MysticEyesAPlus(nom);
    MonstrousStrengthB* monstrousstrengthb = new MonstrousStrengthB(nom);
    BloodFortAndromedaB* bloodfortandromedab = new BloodFortAndromedaB(nom);
    Bellerophon* bellerophon = new Bellerophon(nom);
    Buster* buster1= new Buster(nom);
    Arts* arts1= new Arts(nom);
    Arts* arts2= new Arts(nom);
    Quick* quick1= new Quick(nom);
    Quick* quick2= new Quick(nom);
    Rider* rider= new Rider;
    Servant* Medusa= new Servant (nom,3,12117,7,2,1,3,1,true,false,bellerophon,{buster1,arts1,arts2,quick1,quick2},{mysticeyesaplus,monstrousstrengthb,bloodfortandromedab},rider,65);
    return Medusa;
}

