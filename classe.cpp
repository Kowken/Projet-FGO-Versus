#include "head.h"

Classe::Classe()
{

}
Classe::~Classe()
{

}

void Classe::coefficientClasse(Servant* Ennemi)
{

}

std::string Classe::getNom()
{
    return m_nom;
}

std::vector<std::string>* Classe::getFortContre()
{
    return &fortContre;
}

std::vector<std::string>* Classe::getFaibleContre()
{
    return &faibleContre;
}

void Classe::setFortContre(std::vector<std::string> deltaFOC)
{
    fortContre=deltaFOC;
}

void Classe::setFaibleContre(std::vector<std::string> deltaFAC)
{
    faibleContre=deltaFAC;
}

//======================== SABER ==================

Saber::Saber()
:Classe()
{

}

Saber::~Saber()
{

}

void Saber::coefficientClasse(Servant* Ennemi)
{

}

std::string Saber::getNom()
{
    return m_nom;
}

std::vector<std::string>* Saber::getFortContre()
{
    return &fortContre;
}

std::vector<std::string>* Saber::getFaibleContre()
{
    return &faibleContre;
}

//======================== ARCHER ==================

Archer::Archer()
:Classe()
{

}

Archer::~Archer()
{

}

void Archer::coefficientClasse(Servant* Ennemi)
{

}

std::string Archer::getNom()
{
    return m_nom;
}

std::vector<std::string>* Archer::getFortContre()
{
    return &fortContre;
}

std::vector<std::string>* Archer::getFaibleContre()
{
    return &faibleContre;
}

//======================== LANCER ==================

Lancer::Lancer()
:Classe()
{

}

Lancer::~Lancer()
{

}

std::string Lancer::getNom()
{
    return m_nom;
}

void Lancer::coefficientClasse(Servant* Ennemi)
{

}

std::vector<std::string>* Lancer::getFortContre()
{
    return &fortContre;
}

std::vector<std::string>* Lancer::getFaibleContre()
{
    return &faibleContre;
}

//======================== CASTER ==================

Caster::Caster()
:Classe()
{

}

Caster::~Caster()
{

}

void Caster::coefficientClasse(Servant* Ennemi)
{

}

std::string Caster::getNom()
{
    return m_nom;
}

std::vector<std::string>* Caster::getFortContre()
{
    return &fortContre;
}

std::vector<std::string>* Caster::getFaibleContre()
{
    return &faibleContre;
}

//======================== RIDER ==================

Rider::Rider()
:Classe()
{

}

Rider::~Rider()
{

}

void Rider::coefficientClasse(Servant* Ennemi)
{

}

std::string Rider::getNom()
{
    return m_nom;
}

std::vector<std::string>* Rider::getFortContre()
{
    return &fortContre;
}

std::vector<std::string>* Rider::getFaibleContre()
{
    return &faibleContre;
}

//======================== ASSASSIN ==================

Assassin::Assassin()
:Classe()
{

}

Assassin::~Assassin()
{

}

void Assassin::coefficientClasse(Servant* Ennemi)
{

}

std::string Assassin::getNom()
{
    return m_nom;
}

std::vector<std::string>* Assassin::getFortContre()
{
    return &fortContre;
}

std::vector<std::string>* Assassin::getFaibleContre()
{
    return &faibleContre;
}

//======================== BERSERKER ==================

Berserker::Berserker()
:Classe()
{

}

Berserker::~Berserker()
{

}

void Berserker::coefficientClasse(Servant* Ennemi)
{

}

std::string Berserker::getNom()
{
    return m_nom;
}

std::vector<std::string>* Berserker::getFortContre()
{
    return &fortContre;
}

std::vector<std::string>* Berserker::getFaibleContre()
{
    return &faibleContre;
}
