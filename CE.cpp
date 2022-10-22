#include "head.h"

/*void CraftEssence::modifyCooldownEff(int deltaCDE)
{
    cooldownEffet+=deltaCDE;
}

CraftEssence::CraftEssence()
{

}
CraftEssence::~CraftEssence()
{

}
void CraftEssence::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
int CraftEssence::getPoids()
{
    return m_poids;
}
std::string CraftEssence::getNom()
{
    return m_nom;
}
void CraftEssence::description()
{

}
void CraftEssence::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void CraftEssence::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void CraftEssence::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void CraftEssence::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
void CraftEssence::ResetBonus(std::vector<Servant*>*equipeEnCours)
{
    bool ExistanceBuff=false;
    for(unsigned int i=0;i<listeBeneficiaires.front().size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->size();j++)
        {
            for(unsigned int k=0;k<equipeEnCours->at(j)->getlisteSupportsSkills()->size();k++)
            {
                if(listeBeneficiaires.front()[i]==equipeEnCours->at(j)->getNom()&&equipeEnCours->at(j)->getlisteSupportsSkills()->at(k)==nomProprio)
                {
                    ExistanceBuff=true;
                }
            }
            if(!ExistanceBuff)
            {
                listeBeneficiaires.front().erase(listeBeneficiaires.front().begin()+i);
            }
            ExistanceBuff=false;
        }
    }
}
void CraftEssence::ResetMalus(std::vector<Servant*>*equipeAdverse)
{
    bool ExistanceDebuff=false;
    for(unsigned int i=0;i<listeVictimes.front().size();i++)
    {
        for(unsigned int j=0;j<equipeAdverse->size();j++)
        {
            for(unsigned int k=0;k<equipeAdverse->at(j)->getlisteAssaillantsSkills()->size();k++)
            {
                if(listeVictimes.front()[i]==equipeAdverse->at(j)->getNom()&&equipeAdverse->at(j)->getlisteAssaillantsSkills()->at(k)==nomProprio)
                {
                    ExistanceDebuff=true;
                }
            }
            if(!ExistanceDebuff)
            {
                listeVictimes.front().erase(listeVictimes.front().begin()+i);
            }
            ExistanceDebuff=false;
        }
    }
}
*/
