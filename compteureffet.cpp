#include "head.h"
#define TRACE_ON
CompteurEffet::CompteurEffet(std::string NomEffet)
:NomEffet(NomEffet)
{

}
CompteurEffet::~CompteurEffet()
{

}
std::string CompteurEffet::getNomEffet()
{
    return NomEffet;
}
std::vector<int>* CompteurEffet::getNombreTour()
{
    return &NombreTour;
}
std::vector<int>* CompteurEffet::getNombreFois()
{
    return &NombreFois;
}
void CompteurEffet::setNomEffet(std::string deltaNom)
{
    NomEffet=deltaNom;
}
void CompteurEffet::setNombreTour(int deltaNT)
{
    if(!NombreTour.empty())
    {
        for(unsigned int i=0;i<NombreTour.size();i++)
        {
            #if defined (TRACE_ON)
            std::cout<<"Nombre de tour restant: "<<NombreTour[i]<<std::endl;
            #endif // Defined
            NombreTour[i]+=deltaNT;
            NombreTour[i]=std::max(0,NombreTour[i]);
            #if defined (TRACE_ON)
            std::cout<<"Nombre de tour restant: "<<NombreTour[i]<<std::endl;
            #endif // Defined
        }
    }
}
void CompteurEffet::setNombreFois(int deltaNF)
{
    if(!NombreFois.empty())
    {
        NombreFois[0]+=deltaNF;
        NombreFois[0]=std::max(0,NombreFois[0]);
    }
}
