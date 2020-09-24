#include "../include/TurnoncurvE.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include "TVector3.h"
#include "TVector2.h"
#include "TH1.h"

using namespace std;

Int_t TurnoncurvE::TGC_Run3(float offline_pt)
{
    double pT=99999999;
    float dR=100;
    bool HotRoIFlag=false;
    bool StationFlag=false;

    for(int j=0;j!=TGC_Run3_n;j++){
        if(TGC_Run3_type->at(j)!=2)continue;

        int station = TGC_Run3_station->at(j);
        bool flag = HotRoI(j);

        int TGC_pt=TGC_Run3_pt->at(j);
        double Run3_pt=999999; 
        //15 threshold
        if(TGC_pt==1){Run3_pt=1;}
        if(TGC_pt==2){Run3_pt=2;}
        if(TGC_pt==3){Run3_pt=3;}
        if(TGC_pt==4){Run3_pt=4;}
        if(TGC_pt==5){Run3_pt=5;}
        if(TGC_pt==6){Run3_pt=6;}
        if(TGC_pt==7){Run3_pt=7;}
        if(TGC_pt==8){Run3_pt=8;}
        if(TGC_pt==9){Run3_pt=9;}
        if(TGC_pt==10){Run3_pt=10;}
        if(TGC_pt==11){Run3_pt=11;}
        if(TGC_pt==12){Run3_pt=12;}
        if(TGC_pt==13){Run3_pt=13;}
        if(TGC_pt==14){Run3_pt=14;}
        if(TGC_pt==15){Run3_pt=15;}

        float TGC_x=TGC_Run3_x->at(j);
        float TGC_y=TGC_Run3_y->at(j);
        float TGC_z=TGC_Run3_z->at(j);
        TVector3 v1;
        v1.SetXYZ(TGC_x,TGC_y,TGC_z);
        float TGC_eta=v1.PseudoRapidity();
        float TGC_phi=v1.Phi();

        float delta_eta;
        float delta_phi;
        float TGC_dR;
        delta_eta=(extEta-TGC_eta);
        delta_phi=TVector2::Phi_mpi_pi(extPhi-TGC_phi);
        TGC_dR=sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
        if(TGC_dR<dR){
            dR=TGC_dR;
            pT=Run3_pt;
            HotRoIFlag=flag;
            if(station==0){StationFlag=true;}
        }
    }
    h_dr_2d->Fill(offline_pt, dR);

    //if(dR<=0.04){return pT;}
    if(dR<=0.04&&StationFlag==true){return pT;}
    //if(dR<=0.04&&HotRoIFlag==false&&StationFlag==true){return pT;}
    else{return 0;}
}
