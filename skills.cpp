#include "head.h"
//#define TRACE_ON

Skills::Skills()
{

}

Skills::Skills(std::string nomProprio)
:nomProprio(nomProprio)
{

}

Skills::~Skills()
{

}

void Skills::effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

void Skills::description()
{

}

void Skills::modifyCooldownAct(int deltaCDA)
{
    m_cooldownAction+=deltaCDA;
    m_cooldownAction=std::max(m_cooldownAction,0);
}

int Skills::getCooldownAct()
{
    return m_cooldownAction;
}

std::string Skills::getNom()
{
    return m_nom;
}

void Skills::ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

void Skills::effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

void Skills::effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}

void Skills::ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    effetParTour(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
    ResetEffet(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
}

void Skills::effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours)
{

}
