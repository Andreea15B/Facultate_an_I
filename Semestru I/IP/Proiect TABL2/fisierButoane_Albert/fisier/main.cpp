#include <iostream>
#include <fstream>
#include <graphics.h>
#include <cstring>
using namespace std;

void test(){
    cout<<"Yep.First button was pressed"<<endl;
}

void altTest(){
    cout<<"Yep.Second button was pressed"<<endl;
}

struct point{
    int x;
    int y;
};

struct button{
    point topLeft;
    point bottomDown;
    int index;
    char text;
};

struct linkButton{
    point topLeft;
    point bottomDown;
    int index;
    char text;
    unsigned int indexOfNextPage;
};

struct page{
    unsigned int index;

    button buttons[20];
    linkButton linkButtons[20];

    unsigned int nrButtons;
    unsigned int nrLinkButtons;
};

struct aplication{
    page curentPage;
    linkButton linkButtonsOfAplication[100];
};

struct ocurence{
    page pageOfOcurence;
    point pointOfOcurence;
};



bool isButton(point pointOcurence,button buttonToCheck){
    if((buttonToCheck.topLeft.x<=pointOcurence.x&&pointOcurence.x<=buttonToCheck.bottomDown.x)&&
       (buttonToCheck.topLeft.y<=pointOcurence.y&&pointOcurence.y<=buttonToCheck.bottomDown.y))
        return true;
    return false;
}

bool isLinkButton(point pointOcurence,linkButton buttonToCheck){
    if((buttonToCheck.topLeft.x<=pointOcurence.x&&pointOcurence.x<=buttonToCheck.bottomDown.x)&&
       (buttonToCheck.topLeft.y<=pointOcurence.y&&pointOcurence.y<=buttonToCheck.bottomDown.y))
        return true;
    return false;
}

void findButtonInPage(ocurence clickOcurence,button &foundButton){
    unsigned int i;
    for(i=0;i<clickOcurence.pageOfOcurence.nrButtons;i++){
        if(isButton(clickOcurence.pointOfOcurence,clickOcurence.pageOfOcurence.buttons[i]))
            {foundButton = clickOcurence.pageOfOcurence.buttons[i];
             break;
            }}
    if(i==clickOcurence.pageOfOcurence.nrButtons)
      foundButton.index = 0;
}

void findLinkButtonInPage(ocurence clickOcurence,linkButton &foundLinkButton){
    unsigned int i;
    for(i=0;i<clickOcurence.pageOfOcurence.nrLinkButtons;i++){
        if(isLinkButton(clickOcurence.pointOfOcurence,clickOcurence.pageOfOcurence.linkButtons[i]))
            {foundLinkButton = clickOcurence.pageOfOcurence.linkButtons[i];
             break;
            }}
    if(i==clickOcurence.pageOfOcurence.nrLinkButtons)
      foundLinkButton.index = 0;
}

void inverseaza(unsigned int number,unsigned int &invers){
    unsigned int copie = number;
    invers = 0;
    while(copie){
        invers = invers*10 + copie%10;
        copie/=10;
    }
}

void nrCifre(unsigned int number,unsigned int &nrCaractere){

    if(number!=0){
        unsigned int copie = number;
        nrCaractere = 0;
        while(copie){
            copie/=10;
            nrCaractere++;
        }
    }
    else nrCaractere = 1;
}

void toString(unsigned int number,char convertedString[4]){
    unsigned int nrCaractere = 0;
    unsigned int invers = 0;

    nrCifre(number,nrCaractere);
    inverseaza(number,invers);


    unsigned int i;

    for(i=0;i<nrCaractere;i++){
        convertedString[i]=invers%10+'0';
        number/=10;
    }
}

void getButtonsForCurentPage(aplication &tabl){

    char numeFisier[20];
    char pageId[4];

    toString(tabl.curentPage.index,pageId);
    strcpy(numeFisier,pageId);
    strcat(numeFisier,"_butoane.txt");


    ifstream fin(numeFisier);
    fin>>tabl.curentPage.nrButtons;

    unsigned int i;

    for(i=0;i<tabl.curentPage.nrButtons;i++){
        button buttonFromFile;
        fin>>buttonFromFile.index;
        fin>>buttonFromFile.topLeft.x;
        fin>>buttonFromFile.topLeft.y;
        fin>>buttonFromFile.bottomDown.x;
        fin>>buttonFromFile.bottomDown.y;

        tabl.curentPage.buttons[i].index = buttonFromFile.index;
        tabl.curentPage.buttons[i].topLeft = buttonFromFile.topLeft;
        tabl.curentPage.buttons[i].bottomDown = buttonFromFile.bottomDown;
    }
    fin.close();
}

void getLinkButtonsForCurentPage(aplication &tabl){

    char numeFisier[20];
    char pageId[4];

    toString(tabl.curentPage.index,pageId);
    strcpy(numeFisier,pageId);
    strcat(numeFisier,"_butoaneLink.txt");
//cout<<"pagelink"<<numeFisier<<endl;

    ifstream fin(numeFisier);
    fin>>tabl.curentPage.nrLinkButtons;

    unsigned int i;

    for(i=0;i<tabl.curentPage.nrButtons;i++){
        linkButton buttonFromFile;
        fin>>buttonFromFile.index;
        fin>>buttonFromFile.topLeft.x;
        fin>>buttonFromFile.topLeft.y;
        fin>>buttonFromFile.bottomDown.x;
        fin>>buttonFromFile.bottomDown.y;
        fin>>buttonFromFile.indexOfNextPage;

        tabl.curentPage.linkButtons[i].index = buttonFromFile.index;
        tabl.curentPage.linkButtons[i].topLeft = buttonFromFile.topLeft;
        tabl.curentPage.linkButtons[i].bottomDown = buttonFromFile.bottomDown;
        tabl.curentPage.linkButtons[i].indexOfNextPage = buttonFromFile.indexOfNextPage;
    }
    fin.close();
}

void resetButtons(aplication &tabl){

    unsigned int i;

    for(i=0;i<tabl.curentPage.nrButtons;i++){
        tabl.curentPage.buttons[i].bottomDown.x = 0;
        tabl.curentPage.buttons[i].bottomDown.y = 0;
        tabl.curentPage.buttons[i].topLeft.x = 0;
        tabl.curentPage.buttons[i].topLeft.y = 0;
        tabl.curentPage.buttons[i].index = 0;
    }
    tabl.curentPage.nrButtons = 0;
}
void resetLinkButtons(aplication &tabl){

    unsigned int i;

    for(i=0;i<tabl.curentPage.nrLinkButtons;i++){
        tabl.curentPage.linkButtons[i].bottomDown.x = 0;
        tabl.curentPage.linkButtons[i].bottomDown.y = 0;
        tabl.curentPage.linkButtons[i].topLeft.x = 0;
        tabl.curentPage.linkButtons[i].topLeft.y = 0;
        tabl.curentPage.linkButtons[i].index = 0;
        tabl.curentPage.linkButtons[i].indexOfNextPage = 0;
    }

    tabl.curentPage.nrLinkButtons = 0;
}

void redirectToNextPage(unsigned int indexOfNextPage,aplication &tabl){
    cout<<"Redirect"<<endl;
    //reseteaza butoane
    resetButtons(tabl);
    resetLinkButtons(tabl);
    //reseteaza pagina
    tabl.curentPage.index = indexOfNextPage;
    //obtine butoanele noi
    getButtonsForCurentPage(tabl);
    getLinkButtonsForCurentPage(tabl);
    //sterge afisajul curent
    cleardevice();
    //afiseaza noul ecran
    bar(tabl.curentPage.buttons[0].topLeft.x,tabl.curentPage.buttons[0].topLeft.y,tabl.curentPage.buttons[0].bottomDown.x,tabl.curentPage.buttons[0].bottomDown.y);

}

void checkButton(ocurence clickOcurence,aplication &tabl){

    button foundButton;

    switch(clickOcurence.pageOfOcurence.index){

    case 1:

        findButtonInPage(clickOcurence,foundButton);

        switch(foundButton.index){

        case 1:
            test();
        break;

        case 2:
            altTest();
        break;

        };
        if(foundButton.index==0/*a button was not found*/){
            linkButton foundLinkButton;
            findLinkButtonInPage(clickOcurence,foundLinkButton);

            switch(foundLinkButton.index){

            case 0:
            break;

            default:
                redirectToNextPage(foundLinkButton.indexOfNextPage,tabl);
            break;

            };
        }
    break;

    case 2:

        findButtonInPage(clickOcurence,foundButton);

        switch(foundButton.index){

        case 1:
            test();
        break;
        }
    break;
    };
}



int main()
{
    aplication tabl;

    //set
    tabl.curentPage.index = 1;

    getButtonsForCurentPage(tabl);
    getLinkButtonsForCurentPage(tabl);

    initwindow(200,200);



//AFISARE BUTOANE---si altele...in curand
bar(tabl.curentPage.buttons[0].topLeft.x,tabl.curentPage.buttons[0].topLeft.y,tabl.curentPage.buttons[0].bottomDown.x,tabl.curentPage.buttons[0].bottomDown.y);
bar(tabl.curentPage.buttons[1].topLeft.x,tabl.curentPage.buttons[1].topLeft.y,tabl.curentPage.buttons[1].bottomDown.x,tabl.curentPage.buttons[1].bottomDown.y);
bar(tabl.curentPage.linkButtons[0].topLeft.x,tabl.curentPage.linkButtons[0].topLeft.y,tabl.curentPage.linkButtons[0].bottomDown.x,tabl.curentPage.linkButtons[0].bottomDown.y);



    menu:
        if(ismouseclick(WM_LBUTTONDOWN)){
            int x,y;
            getmouseclick(WM_LBUTTONDOWN,x,y);

            ocurence clickOcurence;
            clickOcurence.pointOfOcurence = {x,y};
            clickOcurence.pageOfOcurence = tabl.curentPage;//cout<<tabl.curentPage.buttons[1].index;

            button presedButton;
            checkButton(clickOcurence,tabl);
        }
        goto menu;


    return 0;
}
