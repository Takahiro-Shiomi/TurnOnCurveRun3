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

Int_t TurnoncurvE::TGC_Run2(float offline_pt)
{
    double pT=99999999;
    float dR=100;
    bool StationFlag=false;

    for(int j=0;j!=tgc_coin_n;j++){
        if(tgc_coin_type->at(j)!=2)continue;
        if(tgc_coin_isForward->at(j)==true)continue;

        int TGC_pt=tgc_coin_pt->at(j);
        double Run3_pt=999999; 
        //15 threshold
        if(TGC_pt==1){Run3_pt=1;}
        if(TGC_pt==2){Run3_pt=2;}
        if(TGC_pt==3){Run3_pt=3;}
        if(TGC_pt==4){Run3_pt=4;}
        if(TGC_pt==5){Run3_pt=5;}
        if(TGC_pt==6){Run3_pt=6;}

        float TGC_x=tgc_coin_x_Out->at(j);
        float TGC_y=tgc_coin_y_Out->at(j);
        float TGC_z=tgc_coin_z_Out->at(j);
        TVector3 v1;
        v1.SetXYZ(TGC_x,TGC_y,TGC_z);
        float TGC_eta=v1.PseudoRapidity();
        float TGC_phi=v1.Phi();

        float delta_eta;
        float delta_phi;
        float TGC_dR;
        delta_eta=(extTGCEta-TGC_eta);
        delta_phi=TVector2::Phi_mpi_pi(extTGCPhi-TGC_phi);
        TGC_dR=sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
        if(TGC_dR<dR){
            dR=TGC_dR;
            pT=Run3_pt;
        }
    }
    tgc_dr->Fill(offline_pt, dR);

    if(dR<=0.045){return pT;}
    else{return 0;}
}
