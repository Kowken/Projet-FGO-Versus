#include "menu.h"


//================================= AIDE SERVANTS ========================================================
void aideServants()
{
    system("cls");
    std::cout << "" << std::endl;
    std::cout << "Chaque Servant appartient à une certaine classe." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Un Servant dont la classe a un avantage sur la classe d'un autre Servant inflige plus de dégâts et prend moins de dégâts à son adversaire." << std::endl;
    std::cout << "Un Servant dont la classe est désavantagée fera moins de dégâts et prendra plus de dégâts à son adversaire." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Pour résumer :" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Saber";
    color(4,0);
    std::cout << " est efficace contre ";
    color(15,0);
    std::cout << "Lancer";
    color(3,0);
    std::cout << " et inefficace contre ";
    color(15,0);
    std::cout << "Archer." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Lancer";
    color(4,0);
    std::cout << " est efficace contre ";
    color(15,0);
    std::cout << "Archer";
    color(3,0);
    std::cout << " et inefficace contre ";
    color(15,0);
    std::cout << "Saber." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Archer";
    color(4,0);
    std::cout << " est efficace contre ";
    color(15,0);
    std::cout << "Saber";
    color(3,0);
    std::cout << " et inefficace contre ";
    color(15,0);
    std::cout << "Lancer." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Rider";
    color(4,0);
    std::cout << " est efficace contre ";
    color(15,0);
    std::cout << "Caster";
    color(3,0);
    std::cout << " et inefficace contre ";
    color(15,0);
    std::cout << "Assassin." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Caster";
    color(4,0);
    std::cout << " est efficace contre ";
    color(15,0);
    std::cout << "Assassin";
    color(3,0);
    std::cout << " et inefficace contre ";
    color(15,0);
    std::cout << "Rider." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Assassin";
    color(4,0);
    std::cout << " est efficace contre ";
    color(15,0);
    std::cout << "Rider";
    color(3,0);
    std::cout << " et inefficace contre ";
    color(15,0);
    std::cout << "Caster." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Berserker";
    color(4,0);
    std::cout << " est efficace contre ";
    color(15,0);
    std::cout << "toutes les classes";
    color(3,0);
    std::cout << " mais elles sont efficaces contre lui.";
    color(15,0);
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Pendant la phase de combat, vous pouvez utiliser les compétences que chaque Servant possède." << std::endl;
    std::cout << "Ces compétences nommées Skills, peuvent être utilisées à nouveau après un nombre indiqué de tours." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    system("pause");
    aide();

}



//================================= AIDE CARTES ========================================================
void aideCartes()
{
    system("cls");
    std::cout << "" << std::endl;
    std::cout << "Pendant le combat, vous devrez choisir 3 cartes d'attaque pour que vos servants puissent attaquer." << std::endl;
    std::cout << "Il existe 3 types de cartes différents : Buster, Quick, Arts." << std::endl;
    std::cout << "" << std::endl;
    color(2,0);
    std::cout << "Quick : Ces cartes permettent de gagner des étoiles critiques." << std::endl;
    std::cout << "" << std::endl;
    color(3,0);
    std::cout << "Arts : Ces cartes permettent de remplir la jauge de NP plus rapidement." << std::endl;
    std::cout << "" << std::endl;
    color(4,0);
    std::cout << "Buster : Ces cartes vous permettent d'accorder plus de dégâts." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    color(15,0);
    std::cout << "Si on choisit 3 cartes du même servant, on obtient une attaque supplémentaire." << std::endl;
    std::cout << "Cette carte est connue sous le nom de carte Extra." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    color(2,0);
    std::cout << "Lorsque les 3 cartes sélectionnées sont des cartes Quick," << std::endl;
    std::cout << "il y aura un gain des étoiles critiques qui augment votre taux de réussite critique au prochain tour." << std::endl;
    std::cout << "Les étoiles critiquent vous permettent d'augmenter considérablement vos dégâts." << std::endl;
    std::cout << "" << std::endl;
    color(3,0);
    std::cout << "Lorsque les 3 cartes sélectionnées sont des cartes Arts," << std::endl;
    std::cout << "il y aura une augmentation du NP pour aider à remplir la jauge de NP." << std::endl;
    std::cout << "" << std::endl;
    color(4,0);
    std::cout << "Lorsque les 3 cartes sélectionnées sont des cartes Buster," << std::endl;
    std::cout << "il y aura une augmentation des dégâts infligés pour ce tour." << std::endl;
    color(15,0);
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Elaborez des stratégies pour obtenir les bonus vous donnera un avantage décisif dans la bataille." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    system("pause");
    aide();
}



//================================= AIDE NP ========================================================
void aideNP()
{
    system("cls");
    std::cout << "" << std::endl;
    color(14,0);
    std::cout << "Tous les Servants possèdent une puissante capacité appelé Noble Phantasm (NP)." << std::endl;
    std::cout << "Le Noble Phantasm est l'attaque spéciale unique d'un Servant." << std::endl;
    std::cout << "Lorsque cette jauge se remplit à 100 %, le Servant peut utiliser cette attaque spéciale." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Après l'utlisation de cette attaque, la jauge redescend à 0 %." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Pour que la jauge monte rapidement, il faut utiliser des cartes Arts." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    color(15,0);
    system("pause");
    aide();
}

//================================= AIDE JEU ========================================================
void aideJeu()
{
    system("cls");
    std::cout << "" << std::endl;
    color(12,0);
    std::cout << "Avant de commencer un combat, il y a un tirage au sort pour savoir qui va commencer en premier." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Lors d'un combat, le joueur peut attaquer ou permuter." << std::endl;
    std::cout << "En effet, cela mettra ensuite fin à son tour. Donc il faut prendre le temps de réfléchir, il y a de la stratégie." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Lorsque le joueur attaque, il utilise les cartes de ses Servants. Mais il peut utiliser les Skills de ses Servants avant d'attaquer." << std::endl;
    std::cout << "Donc il peut jouer les Skills quand il veut mais il y a un temps de recharge pour chaque Skill." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Lorsque le joueur permute, cela lui permet de remplacer son Servant par un autre Servant en réserve." << std::endl;
    std::cout << "Il pourra choisir un Servant qui sera efficace au combat." << std::endl;
    std::cout << "Mais le fait d'utiliser une permutation met fin au tour." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Le combat se termina lorsqu'il y aura un vainqueur." << std::endl;
    std::cout << "Lorsque tous ses Servants seront vaincus." << std::endl;
    color(15,0);
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    system("pause");
    aide();

}

//================================= AIDE ========================================================
void aide()
{
    system("cls");
    int choix;
    std::cout << "" << std::endl;
    color(9,0);
    std::cout << "Fate/Grand Order est un jeu de rôle avec une mécanique de jeu au tour par tour." << std::endl;
    std::cout << "Chaque Servant a ses points de vie et sa barre qui indique une jauge pour l'utilisation de leur Noble Phantasm." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Le joueur possède 6 Servants dans son équipe, dont 3 pour le combat et 3 en réserve." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Les combats consistent en de phases de tactique et de commande." << std::endl;
    std::cout << "Les Servants attaquent et ensuite les ennemis attaquent à leur tour." << std::endl;
    std::cout << "Cela complète un tour." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Durant la phase de tactique, les Servants peuvent utiliser leurs compétences." << std::endl;
    std::cout << "Certains Servants possèdent des compétences de soutient pour les autres Servants alliés." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    color(11,0);
    std::cout << "Règles du jeu" << std::endl;
    color(15,0);
    std::cout << "" << std::endl;
    std::cout << "1 : Explication du déroulement du jeu" << std::endl;
    std::cout << "2 : Explication des servants" << std::endl;
    std::cout << "3 : Explication des cartes" << std::endl;
    std::cout << "4 : Explication du Noble Phantasm" << std::endl;
    std::cout << "5 : Retour au menu" << std::endl;

    std::cout << "" << std::endl;
    std::cin >> choix;
    std::cout << "" << std::endl;
    switch(choix)
    {
        case 1: aideJeu();
            break;
        case 2: aideServants();
            break;
        case 3: aideCartes();
            break;
        case 4: aideNP();
            break;
        case 5: menu();
            break;
        default: aide();
    }
}

//================================= EQUIPE ==========================================================
void initialiserEquipe(Combat* cbt)
{
Servant* Gilgamesh1 = initialiserGilgamesh("Gilgamesh1");
    Servant* Medusa1 = initialiserMedusa("Medusa1");
    Servant* CuChulainn1 = initialiserCuChulainn("CuChulainn1");
    Servant* Artoria1 = initialiserArtoria("Artoria1");
    Servant* Artoria2 = initialiserArtoria("Artoria2");
    Servant* CuChulainn2 = initialiserCuChulainn("CuChulainn2");
    Servant* Gilgamesh2 = initialiserGilgamesh("Gilgamesh2");
    Servant* Medusa2 = initialiserMedusa("Medusa2");
    cbt->getChoixEquipeJoueur1().push_back(Gilgamesh1);
    cbt->getChoixEquipeJoueur1().push_back(Artoria1);
    cbt->getChoixEquipeJoueur1().push_back(CuChulainn1);
    cbt->getChoixEquipeJoueur1().push_back(Medusa1);
    cbt->getChoixEquipeJoueur2().push_back(Artoria2);
    cbt->getChoixEquipeJoueur2().push_back(CuChulainn2);
    cbt->getChoixEquipeJoueur2().push_back(Gilgamesh2);
    cbt->getChoixEquipeJoueur2().push_back(Medusa2);

}

//================================= JEU ==========================================================
void jeu()
{
    system("cls");
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    const char *filename = "servants.txt";
    std::ifstream ifs(filename);
    if(!ifs)
    {
        std::cout << "Le fichier [" << filename << "] n'existe pas" << std::endl;
    }
    std::string line;
    while(std::getline(ifs,line)) std::cout << line << std::endl;
    ifs.close();
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    system("pause");
    system("cls");
    std::cout << "" << std::endl;
    Combat* cbt=new Combat();
    initialiserEquipe(cbt);
    cbt->TrueSelectionEquipes(50);
    cbt->Combattre();
    sauvegarde(cbt);
}


//================================= MENU BASE ========================================================
void menu()
{
    system("cls");
    int choix;
    color(4,0);
    std::cout << "Fate/Grand Order Versus" << std::endl;
    std::cout << "" << std::endl;
    color(15,0);
    std::cout << "1 : Jouer" << std::endl;
    std::cout << "2 : Aide" << std::endl;
    std::cout << "3 : Quitter" << std::endl;
    std::cout << "" << std::endl;
    std::cin >> choix;
    std::cout << "" << std::endl;
    switch(choix)
    {
        case 1: jeu();
            break;
        case 2: aide();
            break;
        case 3: system("exit");
            break;
        default: menu();
    }
}

//================================= INTRO ==========================================================
void introduction()
{
    Sleep(500);
    //std::cout << "Bienvenue sur Fate/Grand Order" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "B";
    Sleep(100);
    std::cout << "i";
    Sleep(100);
    std::cout << "e";
    Sleep(100);
    std::cout << "n";
    Sleep(100);
    std::cout << "v";
    Sleep(100);
    std::cout << "e";
    Sleep(100);
    std::cout << "n";
    Sleep(100);
    std::cout << "u";
    Sleep(100);
    std::cout << "e";
    Sleep(100);
    std::cout << " ";
    Sleep(100);
    std::cout << "s";
    Sleep(100);
    std::cout << "u";
    Sleep(100);
    std::cout << "r";
    Sleep(100);
    std::cout << " ";
    Sleep(100);
    std::cout << "F";
    Sleep(100);
    std::cout << "a";
    Sleep(100);
    std::cout << "t";
    Sleep(100);
    std::cout << "e";
    Sleep(100);
    std::cout << "/";
    Sleep(100);
    std::cout << "G";
    Sleep(100);
    std::cout << "r";
    Sleep(100);
    std::cout << "a";
    Sleep(100);
    std::cout << "n";
    Sleep(100);
    std::cout << "d";
    Sleep(100);
    std::cout << " ";
    Sleep(100);
    std::cout << "O";
    Sleep(100);
    std::cout << "r";
    Sleep(100);
    std::cout << "d";
    Sleep(100);
    std::cout << "e";
    Sleep(100);
    std::cout << "r";
    Sleep(100);
    std::cout << " ";
    Sleep(100);
    std::cout << "V";
    Sleep(100);
    std::cout << "e";
    Sleep(100);
    std::cout << "r";
    Sleep(100);
    std::cout << "s";
    Sleep(100);
    std::cout << "u";
    Sleep(100);
    std::cout << "s";
    Sleep(100);
    std::cout << " ";
    Sleep(100);
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    system("pause");
    system("cls");
    std::cout << "Bonjour jeune Mage," << std::endl;
    Sleep(1500);
    std::cout << "vous êtes un Master nommé par le Saint Graal." << std::endl;
    Sleep(2000);
    std::cout << "" << std::endl;
    std::cout << "Vous pouvez invoquer vos Servants, les esprits mythiques afin de livrer un combat contre les autres Masters." << std::endl;
    Sleep(2000);
    std::cout << "Vos Servants devront affronter les Servants adverses durant la guerre du Saint Graal." << std::endl;
    Sleep(3000);
    std::cout << "" << std::endl;
    std::cout << "Il doit rester un seul Master pour obtenir le Saint Graal. " << std::endl;
    Sleep(2000);
    std::cout << "En effet, le Saint Graal offrira au vainqueur la possibilité d'exaucer son voeu le plus cher." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    Sleep(2000);
    std::cout << "Le combat est sur le point de reprendre." << std::endl;
    Sleep(1500);
    std::cout << "Préparez-vous et soyez determiné pour acquérir le Saint Graal." << std::endl;
    Sleep(1000);
    std::cout << "" << std::endl;
    std::cout << "J'espère que la victoire vous appartient !" << std::endl;
    Sleep(1000);
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    system("pause");
}

//================================= POSITION =========================================================
void gotoligcol(int lig, int col)
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

//================================= COULEURS =========================================================
void color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

//================================= SAUVEGARDE =========================================================
void sauvegarde(Combat *c)
{
    std::ofstream fichier("sauvegarde.txt",std::ios::app);
    if(!fichier.is_open())
    {
        std::cout << "Erreur d'ouverture du fichier" << std::endl;
    }
    else
    {
        fichier << c << std::endl;
        fichier.close();
    }
}

/*
//================================= CHOIX JOUEUR 1 =========================================================
void choixJoueur1()
{
    color(2,0);
    std::cout << "Joueur 1" << std::endl;
    std::cout << "Vous pouvez choisir 6 servants." << std::endl;
    std::cout << "" << std::endl;
    color(15,0);
    std::string choix;
    int compteur1=0;
    do
    {
        do
        {
        std::cout << "Veuillez choisir votre classe de Servant :" << std::endl;
        std::cin >> choix;

        }while(choix!="Saber" && choix!="Lancer" && choix!="Archer" && choix!="Caster" && choix!="Rider" && choix!="Assassin" && choix!="Berserker");
        if(choix=="Saber")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Artoria Pendragon" && nom_servant1!="Altera" && nom_servant1!="Mordred" && nom_servant1!="Okita Souji" && nom_servant1!="Gawain" && nom_servant1!="Nero Claudius" && nom_servant1!="Suzuka Gozen" && nom_servant1!="Siegfried" && nom_servant1!="Bedivere" && nom_servant1!="Gaius Julius Caesar");
            compteur1++;
        }
        if(choix=="Lancer")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Karna" && nom_servant1!="Ereshkigal" && nom_servant1!="Enkidu" && nom_servant1!="Li Shuwen" && nom_servant1!="Parvati" && nom_servant1!="Nezha" && nom_servant1!="Jaguar Warrior" && nom_servant1!="Cu Chulainn" && nom_servant1!="Diarmuid Ua Duibhne" && nom_servant1!="Leonidas");
            compteur1++;
        }
        if(choix=="Archer")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Gilgamesh" && nom_servant1!="Ishtar" && nom_servant1!="Emiya" && nom_servant1!="Chiron" && nom_servant1!="Oda Nobunaga" && nom_servant1!="Euryale" && nom_servant1!="David" && nom_servant1!="Tawara Touta" && nom_servant1!="Robin des bois" && nom_servant1!="Arash");
            compteur1++;
        }
        if(choix=="Caster")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Xuanzang Sanzang" && nom_servant1!="Zhuge Liang" && nom_servant1!="Tamamo-No-Mae" && nom_servant1!="Merlin" && nom_servant1!="Scathach-Skadi" && nom_servant1!="Sieg" && nom_servant1!="Nitocris" && nom_servant1!="Medea" && nom_servant1!="Gilles de Rais" && nom_servant1!="Hans Christian Andersen");
            compteur1++;
        }
        if(choix=="Rider")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Achilles" && nom_servant1!="Iskandar" && nom_servant1!="Drake" && nom_servant1!="Ozymandias" && nom_servant1!="Astolfo" && nom_servant1!="Marie Antoinette" && nom_servant1!="Medusa" && nom_servant1!="Ushiwakamaru" && nom_servant1!="Georgios" && nom_servant1!="Edward Teach");
            compteur1++;
        }
        if(choix=="Assassin")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Semiramis" && nom_servant1!="First Hassan" && nom_servant1!="Jack the Ripper" && nom_servant1!="Kiritsugu" && nom_servant1!="Ryougi Shiki" && nom_servant1!="Carmilla" && nom_servant1!="Hassan of the Hundred Personas" && nom_servant1!="Hassan Of Serenity" && nom_servant1!="Hassan of the Cursed Arm" && nom_servant1!="Sasaki Kojirou");
            compteur1++;
        }
        if(choix=="Berserker")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Vlad III" && nom_servant1!="Minamoto-No-Raikou" && nom_servant1!="Atalante Alter" && nom_servant1!="Lancelot" && nom_servant1!="Heracles" && nom_servant1!="Frankenstein" && nom_servant1!="Darius III" && nom_servant1!="Lu Bu Fengxian" && nom_servant1!="Spartacus" && nom_servant1!="Paul Bunyan");
            compteur1++;
        }

    }while(compteur1!=6);
}



//================================= CHOIX JOUEUR 2 =========================================================
void choixJoueur2()
{
    color(3,0);
    std::cout << "Joueur 2" << std::endl;
    std::cout << "Vous pouvez choisir 6 servants." << std::endl;
    std::cout << "" << std::endl;
    color(15,0);
    std::string choix;
    int compteur1=0;
    do
    {
        do
        {
        std::cout << "Veuillez choisir votre classe de Servant :" << std::endl;
        std::cin >> choix;

        }while(choix!="Saber" && choix!="Lancer" && choix!="Archer" && choix!="Caster" && choix!="Rider" && choix!="Assassin" && choix!="Berserker");
        if(choix=="Saber")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Artoria Pendragon" && nom_servant1!="Altera" && nom_servant1!="Mordred" && nom_servant1!="Okita Souji" && nom_servant1!="Gawain" && nom_servant1!="Nero Claudius" && nom_servant1!="Suzuka Gozen" && nom_servant1!="Siegfried" && nom_servant1!="Bedivere" && nom_servant1!="Gaius Julius Caesar");
            compteur1++;
        }
        if(choix=="Lancer")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Karna" && nom_servant1!="Ereshkigal" && nom_servant1!="Enkidu" && nom_servant1!="Li Shuwen" && nom_servant1!="Parvati" && nom_servant1!="Nezha" && nom_servant1!="Jaguar Warrior" && nom_servant1!="Cu Chulainn" && nom_servant1!="Diarmuid Ua Duibhne" && nom_servant1!="Leonidas");
            compteur1++;
        }
        if(choix=="Archer")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Gilgamesh" && nom_servant1!="Ishtar" && nom_servant1!="Emiya" && nom_servant1!="Chiron" && nom_servant1!="Oda Nobunaga" && nom_servant1!="Euryale" && nom_servant1!="David" && nom_servant1!="Tawara Touta" && nom_servant1!="Robin des bois" && nom_servant1!="Arash");
            compteur1++;
        }
        if(choix=="Caster")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Xuanzang Sanzang" && nom_servant1!="Zhuge Liang" && nom_servant1!="Tamamo-No-Mae" && nom_servant1!="Merlin" && nom_servant1!="Scathach-Skadi" && nom_servant1!="Sieg" && nom_servant1!="Nitocris" && nom_servant1!="Medea" && nom_servant1!="Gilles de Rais" && nom_servant1!="Hans Christian Andersen");
            compteur1++;
        }
        if(choix=="Rider")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Achilles" && nom_servant1!="Iskandar" && nom_servant1!="Drake" && nom_servant1!="Ozymandias" && nom_servant1!="Astolfo" && nom_servant1!="Marie Antoinette" && nom_servant1!="Medusa" && nom_servant1!="Ushiwakamaru" && nom_servant1!="Georgios" && nom_servant1!="Edward Teach");
            compteur1++;
        }
        if(choix=="Assassin")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Semiramis" && nom_servant1!="First Hassan" && nom_servant1!="Jack the Ripper" && nom_servant1!="Kiritsugu" && nom_servant1!="Ryougi Shiki" && nom_servant1!="Carmilla" && nom_servant1!="Hassan of the Hundred Personas" && nom_servant1!="Hassan Of Serenity" && nom_servant1!="Hassan of the Cursed Arm" && nom_servant1!="Sasaki Kojirou");
            compteur1++;
        }
        if(choix=="Berserker")
        {
            std::string nom_servant1;
            std::cout << "Veuillez choisir votre Servant :" << std::endl;
            do
            {
            std::getline (std::cin,nom_servant1);
            }while(nom_servant1!="Vlad III" && nom_servant1!="Minamoto-No-Raikou" && nom_servant1!="Atalante Alter" && nom_servant1!="Lancelot" && nom_servant1!="Heracles" && nom_servant1!="Frankenstein" && nom_servant1!="Darius III" && nom_servant1!="Lu Bu Fengxian" && nom_servant1!="Spartacus" && nom_servant1!="Paul Bunyan");
            compteur1++;
        }

    }while(compteur1!=6);
}

//================================= JOUEUR 1 ==========================================================
void joueur1()
{
    system("cls");
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    const char *filename = "servants.txt";
    std::ifstream ifs(filename);
    if(!ifs)
    {
        std::cout << "Le fichier [" << filename << "] n'existe pas" << std::endl;
    }
    std::string line;
    while(std::getline(ifs,line)) std::cout << line << std::endl;
    ifs.close();
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    const char *f = "craftEssence.txt";
    std::ifstream file(f);
    if(!file)
    {
        std::cout << "Le fichier [" << f << "] n'existe pas" << std::endl;
    }
    std::string ligne;
    while(std::getline(file,ligne)) std::cout << ligne << std::endl;
    file.close();
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    choixJoueur1();
}
//================================= JOUEUR 2 ==========================================================
void joueur2()
{
    system("cls");
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    const char *filename = "servants.txt";
    std::ifstream ifs(filename);
    if(!ifs)
    {
        std::cout << "Le fichier [" << filename << "] n'existe pas" << std::endl;
    }
    std::string line;
    while(std::getline(ifs,line)) std::cout << line << std::endl;
    ifs.close();
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    choixJoueur2();

}


//================================= JEU ==========================================================
void jeu()
{
    joueur1();
    joueur2();
}


*/
