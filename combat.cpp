#include "head.h"
#include "menu.h"

//#define TRACE_ON

Combat::Combat()
{

}

Combat::~Combat()
{

}

void Combat::Combattre()
{
    srand(time(NULL));
    int quiCommence=rand()%2+1;
    std::vector<Servant*> Attaquants;
    std::vector<Servant*> Defenseurs;
    int frontCombat;
    int tailleEquipeJoueur1;
    int tailleEquipeJoueur2;
    std::vector<Servant*> frontEquipeJoueur2;
    std::vector<Servant*> frontEquipeJoueur1;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    color(2,0);
    std::cout<<"On tire au sort..."<<std::endl;
    color(15,0);
    std::cout << "" << std::endl;
    system("pause");
    system("cls");
    if(quiCommence==1)
    {
        Joueur1Encours=true;
        color(1,0);
        std::cout<<"C'est le joueur 1 qui commence."<<std::endl;
        std::cout << "" << std::endl;
        color(15,0);
    }
    else
    {
        Joueur1Encours=false;
        color(4,0);
        std::cout<<"C'est le joueur 2 qui commence."<<std::endl;
        std::cout << "" << std::endl;
        color(15,0);
    }
   /* for(unsigned int i=0;i<3;i++)
        {
            equipeJoueur1[i]->getCE()->effet(&equipeJoueur1,&equipeJoueur2,stockEtoilesJoueur1);
        }
    for(unsigned int i=0;i<3;i++)
        {
            equipeJoueur2[i]->getCE()->effet(&equipeJoueur2,&equipeJoueur1,stockEtoilesJoueur2);
        }*/
    do
    {
    do
    {
        tailleEquipeJoueur1=equipeJoueur1.size();
        tailleEquipeJoueur2=equipeJoueur2.size();
        int choixMenu=0;
        tailleEquipeJoueur1=equipeJoueur1.size();
        tailleEquipeJoueur2=equipeJoueur2.size();
        for(int i=0;i<std::min(3,tailleEquipeJoueur1);i++)
        {
            frontEquipeJoueur1.push_back(equipeJoueur1[i]);
        }
        for(int i=0;i<std::min(3,tailleEquipeJoueur2);i++)
        {
            frontEquipeJoueur2.push_back(equipeJoueur2[i]);
        }
        if(Joueur1Encours)
        {
            frontCombat=std::min(tailleEquipeJoueur1,3);
            for(int i=0;i<frontCombat;i++)
            {
                Attaquants.push_back(equipeJoueur1[i]);
                equipeJoueur1[i]->setIsFrozen(false);
            }
            frontCombat=std::min(tailleEquipeJoueur2,3);
            for(int i=0;i<frontCombat;i++)
            {
                Defenseurs.push_back(equipeJoueur2[i]);
                equipeJoueur2[i]->setIsFrozen(false);
            }
            do
            {
                afficher(&frontEquipeJoueur1,&frontEquipeJoueur2);
                color(1,0);
                std::cout<<"Joueur 1, choisissez l'action à effectuer:"<<std::endl;
                color(15,0);
                std::cout<<"1.Attaquer"<<std::endl<<"2.Utiliser Skill"<<std::endl<<"3.Permuter"<<std::endl;
                std::cin>>choixMenu;
                std::cout << "" << std::endl;
                if(choixMenu==1)
                {
                    Attaque(&Attaquants,&Defenseurs,stockEtoilesJoueur1);
                }
                if(choixMenu==2)
                {
                    UtiliserSkills(&Attaquants,&Defenseurs,stockEtoilesJoueur1);
                }
                if(choixMenu==3)
                {
                    if(equipeJoueur1.size()>=4)
                    {
                        Permutation(&equipeJoueur1);
                    }
                    else
                    {
                        std::cout<<"Vous ne pouvez pas permuter !"<<std::endl;
                    }
                }
            }
            while(choixMenu==2||(choixMenu==3&&equipeJoueur1.size()<=3)||choixMenu<1||choixMenu>3);
            Joueur1Encours=false;
            TourJoueur1Fini=true;
            Attaquants={};
            Defenseurs={};
        }
        else
        {
            frontCombat=std::min(tailleEquipeJoueur2,3);
            for(int i=0;i<frontCombat;i++)
            {
                Attaquants.push_back(equipeJoueur2[i]);
                equipeJoueur2[i]->setIsFrozen(false);
            }
            frontCombat=std::min(tailleEquipeJoueur1,3);
            for(int i=0;i<frontCombat;i++)
            {
                Defenseurs.push_back(equipeJoueur1[i]);
                equipeJoueur1[i]->setIsFrozen(false);
            }
            do
            {
                afficher(&frontEquipeJoueur1,&frontEquipeJoueur2);
                color(4,0);
                std::cout<<"Joueur 2, choisissez l'action à effectuer:"<<std::endl;
                color(15,0);
                std::cout<<"1.Attaquer"<<std::endl<<"2.Utiliser Skill"<<std::endl<<"3.Permuter"<<std::endl;
                std::cin>>choixMenu;
                std::cout << "" << std::endl;
                if(choixMenu==1)
                {
                    Attaque(&Attaquants,&Defenseurs,stockEtoilesJoueur2);
                }
                if(choixMenu==2)
                {
                    UtiliserSkills(&Attaquants,&Defenseurs,stockEtoilesJoueur2);
                }
                if(choixMenu==3)
                {
                    if(equipeJoueur2.size()>=4)
                    {
                        Permutation(&equipeJoueur2);
                    }
                    else
                    {
                        std::cout<<"Vous ne pouvez pas permuter !"<<std::endl;
                    }
                }
            }
            while(choixMenu==2||(choixMenu==3&&equipeJoueur1.size()<=3)||choixMenu<1||choixMenu>3);
            TourJoueur2Fini=true;
            Joueur1Encours=true;
            Attaquants={};
            Defenseurs={};
        }
        frontEquipeJoueur1={};
        frontEquipeJoueur2={};
        tailleEquipeJoueur1=equipeJoueur1.size();
        tailleEquipeJoueur2=equipeJoueur2.size();
        for(int i=0;i<std::min(3,tailleEquipeJoueur1);i++)
        {
            frontEquipeJoueur1.push_back(equipeJoueur1[i]);
        }
        for(int i=0;i<std::min(3,tailleEquipeJoueur2);i++)
        {
            frontEquipeJoueur2.push_back(equipeJoueur2[i]);
        }
        TourSuivant(&frontEquipeJoueur1,&frontEquipeJoueur2);
        frontEquipeJoueur1={};
        frontEquipeJoueur2={};
        mortServant();
    }
    while((!TourJoueur1Fini||!TourJoueur2Fini)&&(!equipeJoueur1.empty()||!equipeJoueur2.empty()));
    TourJoueur1Fini=false;
    TourJoueur2Fini=false;
    }
    while(!finCombat());
}

void Combat::TourSuivant(std::vector<Servant*>* frontEquipeJoueur1, std::vector<Servant*>* frontEquipeJoueur2)
{
    if(!Joueur1Encours)
    {
        #if defined(TRACE_ON)
        color(1,0);
        std::cout<<"Fin tour joueur 1"<<std::endl;
        color(15,0);
        #endif // defined
        for(int i=0;i<equipeJoueur1.size();i++)
        {
            equipeJoueur1[i]->MiseAJour(frontEquipeJoueur1,frontEquipeJoueur2,stockEtoilesJoueur1);
        }
        for(unsigned int i=0;i<cimetiereJoueur1.size();i++)
        {
            cimetiereJoueur1[i]->MiseAJour(frontEquipeJoueur1,frontEquipeJoueur2,stockEtoilesJoueur2);
        }
    }
    if(Joueur1Encours)
    {
        #if defined(TRACE_ON)
        color(4,0);
        std::cout<<"Fin tour joueur 2"<<std::endl;
        color(15,0);
        #endif // defined
        for(int i=0;i<equipeJoueur2.size();i++)
        {
            equipeJoueur2[i]->MiseAJour(frontEquipeJoueur2,frontEquipeJoueur1,stockEtoilesJoueur2);
        }

        for(unsigned int i=0;i<cimetiereJoueur2.size();i++)
        {
            cimetiereJoueur2[i]->MiseAJour(frontEquipeJoueur2,frontEquipeJoueur1,stockEtoilesJoueur2);
        }
    }
}

bool Combat::finCombat()
{
    if(equipeJoueur1.empty())
    {
        color(4,0);
        std::cout<<"Le combat est terminé : le joueur 2 a gagné !"<<std::endl;
        color(15,0);
        return true;
    }
    if(equipeJoueur2.empty())
    {
        color(1,0);
        std::cout<<"Le combat est terminé : le joueur 1 a gagné !"<<std::endl;
        color(15,0);
        return true;
    }
    return false;
}

void Combat::Attaque(std::vector<Servant*>*equipeAttaquant,std::vector<Servant*>*equipeDefenseur,int& stockEtoilesEquipeEnCours)
{
    std::vector<Servant*>beneficiairesCardChain;
    unsigned int aleatoire=0;
    unsigned int Carte1=0;
    unsigned int Carte2=0;
    unsigned int Carte3=0;
    unsigned int choixCible=0;
    bool BusterChainTrue=false;
    bool TargetFocusCase=false;
    std::cout << "" << std::endl;
    std::cout<<"Choisissez les 3 cartes avec lesquelles vous allez attaquer:"<<std::endl;
    std::vector<Carte*>CartesServantsFront;
    std::vector<Carte*>SelectionAleatoire;
    std::vector<Carte*>SelectionAttaque;

        for(unsigned int i=0;i<equipeAttaquant->size();i++)
        {
            equipeAttaquant->at(i)->setNPStatus();
            for(unsigned int j=0;j<equipeAttaquant->at(i)->getDeckCarte()->size();j++)
            {
                CartesServantsFront.push_back(equipeAttaquant->at(i)->getDeckCarte()->at(j));
            }
        }
        for(int i=0;i<5;i++)
        {
            srand (time(NULL));
            aleatoire=rand()%(CartesServantsFront.size()-1);
            SelectionAleatoire.push_back(CartesServantsFront[aleatoire]);
            CartesServantsFront.erase(CartesServantsFront.begin()+aleatoire);
        }
        RepartitionEtoiles(&SelectionAleatoire,equipeAttaquant,stockEtoilesEquipeEnCours);
        for(unsigned int i=0;i<equipeAttaquant->size();i++)
        {
            if(equipeAttaquant->at(i)->getNPStatus()&&!equipeAttaquant->at(i)->getNPSeal())
            {
                SelectionAleatoire.push_back(equipeAttaquant->at(i)->getNPCarte());
            }
        }
        for(unsigned int i=0;i<SelectionAleatoire.size();i++)
        {
            if(SelectionAleatoire[i]->getIsNoblePhantasm())
            {
                std::cout<<i+1<<". "<<SelectionAleatoire[i]->getNomProprio()<<": "<<SelectionAleatoire[i]->getTypeCarte()<<": "<<SelectionAleatoire[i]->getNomNP()<<" ";
                SelectionAleatoire[i]->description();
                std::cout<<std::endl;
            }
            else
            {
                std::cout<<i+1<<". "<<SelectionAleatoire[i]->getNomProprio()<<": "<<SelectionAleatoire[i]->getTypeCarte()<<" "<<SelectionAleatoire[i]->getEtoiles()*10<<"% de coup critique"<<std::endl;
            }
        }
        do
        {
            std::cin>>Carte1>>Carte2>>Carte3;
            if(Carte1==Carte2||Carte2==Carte3||Carte3==Carte1||(Carte1-1<0||Carte1-1>=SelectionAleatoire.size())||(Carte2-1<0||Carte2-1>=SelectionAleatoire.size())||(Carte3-1<0||Carte3-1>=SelectionAleatoire.size()))
            {
                std::cout<<"Combinaison invalide, recommencez."<<std::endl;
            }
        }
        while(Carte1==Carte2||Carte2==Carte3||Carte3==Carte1||(Carte1-1<0||Carte1-1>=SelectionAleatoire.size())||(Carte2-1<0||Carte2-1>=SelectionAleatoire.size())||(Carte3-1<0||Carte3-1>=SelectionAleatoire.size()));
        SelectionAttaque.push_back(SelectionAleatoire[Carte1-1]);
        SelectionAttaque.push_back(SelectionAleatoire[Carte2-1]);
        SelectionAttaque.push_back(SelectionAleatoire[Carte3-1]);
        TripleCouleur(&SelectionAttaque,equipeAttaquant,BusterChainTrue,&beneficiairesCardChain);
        attaqueExtra(equipeAttaquant,&SelectionAttaque);
        //Overcharge(SelectionAttaque);
        std::cout<<"Choisissez votre cible:"<<std::endl;

        for(unsigned int i=0;i<equipeDefenseur->size();i++)
        {
            if(equipeDefenseur->at(i)->getTargetFocus())
            {
                TargetFocusCase=true;
            }
        }
        if(TargetFocusCase)
        {
            for(unsigned int i=0;i<equipeDefenseur->size();i++)
            {
                if(equipeDefenseur->at(i)->getTargetFocus())
                {
                    std::cout<<i+1<<". "<<equipeDefenseur->at(i)->getNom()<<std::endl;
                }
            }
            do
            {
                std::cin>>choixCible;
            }
            while(choixCible-1<0||choixCible-1>=3||!equipeDefenseur->at(choixCible-1)->getTargetFocus());
        }
        else
        {
            for(unsigned int i=0;i<3;i++)
            {
                std::cout<<i+1<<". "<<equipeDefenseur->at(i)->getNom()<<std::endl;
            }
            do
            {
                std::cin>>choixCible;
            }
            while(choixCible-1<0||choixCible-1>=3);
        }
        for(unsigned int j=0;j<SelectionAttaque.size();j++)
        {
            for(unsigned int i=0;i<equipeAttaquant->size();i++)
            {
                if(equipeAttaquant->at(i)->getNom()==SelectionAttaque[j]->getNomProprio())
                {
                    equipeAttaquant->at(i)->setIsAttacking(true);
                    equipeDefenseur->at(choixCible-1)->setIsDefending(true);
                    #if defined(TRACE_ON)
                    std::cout<<equipeDefenseur->at(choixCible-1)->getNom()<<" "<<equipeDefenseur->at(choixCible-1)->getIsDefending()<<std::endl;
                    #endif // defined
                    equipeAttaquant->at(i)->attaquer(SelectionAttaque[j],equipeDefenseur->at(choixCible-1),equipeAttaquant,equipeDefenseur,stockEtoilesEquipeEnCours);
                    equipeAttaquant->at(i)->setIsAttacking(false);
                    equipeDefenseur->at(choixCible-1)->setIsDefending(false);
                    #if defined(TRACE_ON)
                    std::cout<<equipeDefenseur->at(choixCible-1)->getNom()<<" "<<equipeDefenseur->at(choixCible-1)->getIsDefending()<<std::endl;
                    #endif // defined
                }

                if(equipeDefenseur->at(choixCible-1)->getPV()<=0)
                {
                    if((SelectionAttaque[j]->getNomProprio()!=SelectionAttaque[j+1]->getNomProprio()&&j<2)||(SelectionAttaque[j]->getNomProprio()==SelectionAttaque[j+1]->getNomProprio()&&j<2&&SelectionAttaque[j+1]->getIsNoblePhantasm()))
                    {
                        if(choixCible<equipeDefenseur->size())
                        {
                            choixCible+=1;
                        }
                        else
                        {
                            choixCible=1;
                        }
                    }
                    else
                    {

                    }
                }
            }
        }
    generationEtoiles(equipeAttaquant,&SelectionAttaque,stockEtoilesEquipeEnCours);
    #if defined(TRACE_ON)
    std::cout<<"étoiles de l'équipe: "<<stockEtoilesEquipeEnCours<<std::endl;
    #endif // defined
    ResetBusterChain(equipeAttaquant,&beneficiairesCardChain,BusterChainTrue);
}
void Combat::UtiliserSkills(std::vector<Servant*>* equipeEnCours,std::vector<Servant*>* equipeAdverse,int& stockEtoilesEquipeEnCours)
{
    unsigned int choixServant=0;
        std::cout<<"Choisissez le Servant dont vous allez utiliser les Skills:"<<std::endl;
        for(unsigned int i=0;i<equipeEnCours->size();i++)
        {
            std::cout<<i+1<<". "<<equipeEnCours->at(i)->getNom()<<std::endl;
        }
        do
        {
            std::cin>>choixServant;
        }
        while(choixServant-1<0||choixServant-1>=3);
        equipeEnCours->at(choixServant-1)->utiliserSkills(equipeEnCours,equipeAdverse,stockEtoilesEquipeEnCours);
}

void Combat::Permutation(std::vector<Servant*>* equipeEnCours)
{
    unsigned int ChoixServantEntrant=0;
    int ConfirmationChoix=0;
    for(int i=0;i<3;i++)
    {
        do
        {
            std::cout<<"Voulez-vous faire sortir "<<equipeEnCours->at(i)->getNom()<<" ?"<<std::endl<<"1. Oui"<<std::endl<<"2. Non"<<std::endl;
            std::cin>>ConfirmationChoix;
        }
        while(ConfirmationChoix!=1&&ConfirmationChoix!=2);
        if(ConfirmationChoix==1)
        {
            std::cout<<"Choisissez le Servant entrant:"<<std::endl;
            for(unsigned int j=0;j<equipeEnCours->size()-3;j++)
            {
                std::cout<<j+1<<". "<<equipeEnCours->at(j+3)->getNom()<<std::endl;
            }
            do
            {
                    std::cin>>ChoixServantEntrant;
            }
            while((ChoixServantEntrant+2)>equipeEnCours->size()||(ChoixServantEntrant+2)<=2);
            permuterServant(equipeEnCours,i,ChoixServantEntrant+2);
        }
    }
}

void Combat::permuterServant(std::vector<Servant*>*equipe,int devant,int derriere)
{
    equipe->insert(equipe->begin()+devant,equipe->at(derriere));
    equipe->erase(equipe->begin()+derriere+1);
    equipe->insert(equipe->begin()+derriere+1,equipe->at(devant+1));
    equipe->erase(equipe->begin()+devant+1);
    equipe->at(devant)->setIsFrozen(false);
    equipe->at(devant)->setIsFrozen(true);
}

void Combat::mortServant()
{
    for(unsigned int i=0;i<equipeJoueur1.size();i++)
    {
        if(equipeJoueur1[i]->getPV()<=0)
        {
            std::cout<<"Le Servant "<<equipeJoueur1[i]->getNom()<<" a été vaincu !"<<std::endl;
            cimetiereJoueur1.push_back(equipeJoueur1[i]);
            equipeJoueur1.erase(equipeJoueur1.begin()+i);
            equipeJoueur1.shrink_to_fit();
        }
    }
    for(unsigned int i=0;i<equipeJoueur2.size();i++)
    {
        if(equipeJoueur2[i]->getPV()<=0)
        {
            std::cout<<"Le Servant "<<equipeJoueur2[i]->getNom()<<" a été vaincu !"<<std::endl;
            cimetiereJoueur2.push_back(equipeJoueur2[i]);
            equipeJoueur2.erase(equipeJoueur2.begin()+i);
            equipeJoueur2.shrink_to_fit();
        }
    }
}

void Combat::TripleCouleur(std::vector<Carte*>*SelectionCartes,std::vector<Servant*>*equipeEnCours,bool& ExistanceBusterChain,std::vector<Servant*>* beneficiaires)
{
    bool BusterChain=true;
    bool ArtsChain=true;
    bool QuickChain=true;
    bool dejaLa=false;

    for(unsigned int i=0;i<SelectionCartes->size();i++)
    {
        if(SelectionCartes->at(i)->getTypeCarte()=="Buster")
        {
            QuickChain=false;
            ArtsChain=false;
        }
        if(SelectionCartes->at(i)->getTypeCarte()=="Arts")
        {
            BusterChain=false;
            QuickChain=false;
        }
        if(SelectionCartes->at(i)->getTypeCarte()=="Quick")
        {
            ArtsChain=false;
            BusterChain=false;
        }
    }
    if(BusterChain)
    {
    color(4,0);
    std::cout<<"Chaîne de carte de type Buster !"<<std::endl;
    color(15,0);
    ExistanceBusterChain=true;
        for(unsigned int j=0; j<SelectionCartes->size();j++)
        {
            for(unsigned int i=0;i<equipeEnCours->size();i++)
            {
                if(equipeEnCours->at(i)->getNom()==SelectionCartes->at(j)->getNomProprio())
                {
                    if(beneficiaires->empty())
                    {
                        beneficiaires->push_back(equipeEnCours->at(i));
                    }
                    else
                    {
                        for(unsigned int k=0;k<beneficiaires->size();k++)
                        {
                            if(equipeEnCours->at(i)->getNom()==beneficiaires->at(k)->getNom())
                            {
                                dejaLa=true;
                            }
                        }
                        if(!dejaLa)
                        {
                            beneficiaires->push_back(equipeEnCours->at(i));
                        }
                        dejaLa=false;
                    }
                }
            }
        }
        for(unsigned int i=0;i<beneficiaires->size();i++)
        {
            beneficiaires->at(i)->setCoeffAttaque(1.2);
        }
    }

    if(ArtsChain)
    {
        color(3,0);
        std::cout<<"Chaîne de carte de type Arts !"<<std::endl;
        color(15,0);
         for(unsigned int j=0; j<SelectionCartes->size();j++)
        {
            for(unsigned int i=0;i<equipeEnCours->size();i++)
            {
                if(equipeEnCours->at(i)->getNom()==SelectionCartes->at(j)->getNomProprio())
                {
                    if(beneficiaires->empty())
                    {
                        beneficiaires->push_back(equipeEnCours->at(i));
                    }
                    else
                    {
                        for(unsigned int k=0;k<beneficiaires->size();k++)
                        {
                            if(equipeEnCours->at(i)->getNom()==beneficiaires->at(k)->getNom())
                            {
                                dejaLa=true;
                            }
                        }
                        if(!dejaLa)
                        {
                            beneficiaires->push_back(equipeEnCours->at(i));
                        }
                        dejaLa=false;
                    }
                }
            }
        }
        for(unsigned int i=0;i<beneficiaires->size();i++)
        {
            beneficiaires->at(i)->modifyJaugeNP(20);
        }
    }

    if(QuickChain)
    {
        color(2,0);
        std::cout<<"Chaîne de carte de type Quick !"<<std::endl;
        color(15,0);
        if(Joueur1Encours)
        {
            stockEtoilesJoueur1+=10;
        }
        else
        {
            stockEtoilesJoueur2+=10;
        }
    }
}

/*void Combat::Overcharge(std::vector<Carte*> SelectionCartes)
{

}*/
void Combat::RepartitionEtoiles(std::vector<Carte*>* SelectionCartes,std::vector<Servant*>* equipeEnCours,int& stockEtoilesEquipeEnCours)
{
    double sommePoidsEtoile=0;
    std::array<int,3>ratioCartesServant={0,0,0};
        for(unsigned int i=0;i<equipeEnCours->size();i++)
        {
            sommePoidsEtoile+=equipeEnCours->at(i)->getStarGatherRate();
            #if defined (TRACE_ON)
            std::cout<<"PoidsEtoile de "<<equipeEnCours->at(i)->getNom()<<" : "<<equipeEnCours->at(i)->getStarGatherRate()<<std::endl;
            #endif // defined
        }
        #if defined (TRACE_ON)
        std::cout<<"sommePoidsEtoile: "<<sommePoidsEtoile<<std::endl;
        #endif // defined
    for(unsigned int i=0;i<SelectionCartes->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->size();j++)
        {
            if(SelectionCartes->at(i)->getNomProprio()==equipeEnCours->at(j)->getNom())
            {
                ratioCartesServant[j]++;
                #if defined (TRACE_ON)
                std::cout<<"Ratio Carte de "<<equipeEnCours->at(j)->getNom()<<" : "<<ratioCartesServant[j]<<std::endl;
                #endif // defined
            }
        }
    }
    for(unsigned int i=0;i<SelectionCartes->size();i++)
    {
        for(unsigned int j=0;j<equipeEnCours->size();j++)
        {
            if(SelectionCartes->at(i)->getNomProprio()==equipeEnCours->at(j)->getNom())
            {
                #if defined (TRACE_ON)
                std::cout<<"NBETOILE de "<<equipeEnCours->at(j)->getNom()<<" : "<<(equipeEnCours->at(j)->getStarGatherRate()*1)/(sommePoidsEtoile*ratioCartesServant[j])<<std::endl;
                #endif // defined
                SelectionCartes->at(i)->modifyEtoiles((equipeEnCours->at(j)->getStarGatherRate()*stockEtoilesEquipeEnCours)/(sommePoidsEtoile*ratioCartesServant[j]));
                stockEtoilesEquipeEnCours-=(equipeEnCours->at(j)->getStarGatherRate()*stockEtoilesEquipeEnCours)/(sommePoidsEtoile*ratioCartesServant[j]);
            }
        }
    }

}

void Combat::ResetBusterChain(std::vector<Servant*>* equipeEnCours,std::vector<Servant*>* beneficiaires,bool& ExistanceBusterChain)
{
    if(ExistanceBusterChain)
    {
        for(unsigned int i=0;i<equipeEnCours->size();i++)
        {
            for(unsigned int j=0;j<beneficiaires->size();j++)
            {
                if(equipeEnCours->at(i)->getNom()==beneficiaires->at(j)->getNom())
                {
                    equipeEnCours->at(i)->setCoeffAttaque(1/1.2);
                }
            }
        }
    }
    beneficiaires={};
}

void Combat::generationEtoiles(std::vector<Servant*>* equipeEnCours,std::vector<Carte*>* SelectionCartes,int& stockEtoilesEquipeEnCours)
{
    for(unsigned int i=0;i<equipeEnCours->size();i++)
    {
        for(unsigned j=0;j<SelectionCartes->size();j++)
        {
            if(SelectionCartes->at(j)->getNomProprio()==equipeEnCours->at(i)->getNom())
            {
                stockEtoilesEquipeEnCours+=equipeEnCours->at(i)->genererEtoiles(SelectionCartes->at(j));
            }
        }
    }
}

void Combat::attaqueExtra(std::vector<Servant*>* equipeEnCours,std::vector<Carte*>* SelectionCartes)
{
    bool memeServant=true;
    for(unsigned int i=0;i<SelectionCartes->size()-1;i++)
    {
            if(SelectionCartes->at(i)->getNomProprio()!=SelectionCartes->at(i+1)->getNomProprio())
            {
                memeServant=false;
            }
    }
    if(memeServant)
    {
        for(unsigned int i=0;i<equipeEnCours->size();i++)
        {
            if(SelectionCartes->at(0)->getNomProprio()==equipeEnCours->at(i)->getNom())
            {
                SelectionCartes->push_back(equipeEnCours->at(i)->getCarteExtra());
            }
        }
        std::cout<<"Attaque Extra !"<<std::endl;
    }
}

std::vector<Servant*>& Combat::getChoixEquipeJoueur1()
{
    return ChoixEquipeJoueur1;
}
std::vector<Servant*>& Combat::getChoixEquipeJoueur2()
{
    return ChoixEquipeJoueur2;
}

void Combat::SelectionEquipes()
{
    for(unsigned int i=0;i<ChoixEquipeJoueur1.size();i++)
    {
        equipeJoueur1.push_back(ChoixEquipeJoueur1[i]);
    }
    ChoixEquipeJoueur1.clear();
    for(unsigned int i=0;i<ChoixEquipeJoueur2.size();i++)
    {
        equipeJoueur2.push_back(ChoixEquipeJoueur2[i]);
    }
    ChoixEquipeJoueur2.clear();
}

void Combat::TrueSelectionEquipes(int limite)
{
    int poidsCumule=0;
    int choixServant=0;
    std::cout << "" << std::endl;
    color(1,0);
    std::cout<<"Joueur 1, choisissez vos Servants: "<<std::endl;
    color(15,0);
    do
    {
        for(unsigned int i=0;i<ChoixEquipeJoueur1.size();i++)
        {
            std::cout<<i+1<<". "<<ChoixEquipeJoueur1[i]->getNom()<<" Poids: "<<ChoixEquipeJoueur1[i]->getPoids()<<std::endl;
        }
        do
        {
            std::cin>>choixServant;
        }
        while(choixServant-1<0||choixServant>ChoixEquipeJoueur1.size());
        poidsCumule+=ChoixEquipeJoueur1[choixServant-1]->getPoids();
        std::cout<<ChoixEquipeJoueur1[choixServant-1]->getNom()<<" a été ajouté à l'équipe du joueur 1."<<std::endl<<"Poids restant: "<<poidsCumule<<std::endl;
        equipeJoueur1.push_back(ChoixEquipeJoueur1[choixServant-1]);
        ChoixEquipeJoueur1.erase(ChoixEquipeJoueur1.begin()+choixServant-1);
    }
    while(equipeJoueur1.size()<6&&poidsCumule<limite&&!ChoixEquipeJoueur1.empty());
    poidsCumule=0;
    std::cout << "" << std::endl;
    color(4,0);
    std::cout<<"Joueur 2, choisissez vos Servants: "<<std::endl;
    color(15,0);
    do
    {
        for(unsigned int i=0;i<ChoixEquipeJoueur2.size();i++)
        {
            std::cout<<i+1<<". "<<ChoixEquipeJoueur2[i]->getNom()<<" Poids: "<<ChoixEquipeJoueur2[i]->getPoids()<<std::endl;
        }
        do
        {
            std::cin>>choixServant;
        }
        while(choixServant-1<0||choixServant>ChoixEquipeJoueur2.size());
        poidsCumule+=ChoixEquipeJoueur2[choixServant-1]->getPoids();
        std::cout<<ChoixEquipeJoueur1[choixServant-1]->getNom()<<" a été ajouté à l'équipe du joueur 1."<<std::endl<<"Poids restant: "<<poidsCumule<<std::endl;
        equipeJoueur2.push_back(ChoixEquipeJoueur2[choixServant-1]);
        ChoixEquipeJoueur2.erase(ChoixEquipeJoueur2.begin()+choixServant-1);
    }
    while(equipeJoueur2.size()<6&&poidsCumule<limite&&!ChoixEquipeJoueur2.empty());
}


void Combat::afficher(std::vector<Servant*>* frontEquipeJoueur1, std::vector<Servant*>* frontEquipeJoueur2)
{
    /// affichage avec position mais problème ///
    /*
    color(1,0);
    gotoligcol(2,3);
    std::cout << "Joueur 1" << std::endl;
    color(15,0);
    for(auto elem : *frontEquipeJoueur1)
    {
        elem->afficher(3,3);
    }
    std::cout << "" << std::endl;
    color(4,0);
    gotoligcol(14,3);
    std::cout << "Joueur 2" << std::endl;
    color(15,0);
    for(auto elem2 : *frontEquipeJoueur2)
    {
        elem2->afficher(15,3);
    }
    std::cout << "" << std::endl;*/

    /// affichage de tous les servants sans position ///
    std::cout << "--------------------" << std::endl;
    color(1,0);
    std::cout << "Joueur 1" << std::endl;
    color(15,0);
    for(auto elem3 : *frontEquipeJoueur1)
    {
        elem3->affichage();
    }
    std::cout << "--------------------" << std::endl;
    color(4,0);
    std::cout << "Joueur 2" << std::endl;
    color(15,0);
    for(auto elem4 : *frontEquipeJoueur2)
    {
        elem4->affichage();
    }
    std::cout << "--------------------" << std::endl;
    std::cout << "" << std::endl;
}
