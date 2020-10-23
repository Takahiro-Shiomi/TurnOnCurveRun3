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

Int_t TurnoncurvE::RPC_Run3(float offline_pt)
{
    double pT=99999999;
    float dR=100;
    for(int j=0;j!=muctpi_ndatawords;j++){
        if(muctpi_source->at(j)!=0)continue;
        if(muctpi_candidateVetoed->at(j)==1)continue;
        
        int rpc_pt=muctpi_thrNumber->at(j);
        float Run3_pt=9999999;
        if(rpc_pt==1){Run3_pt=1;}
        if(rpc_pt==2){Run3_pt=2;}
        if(rpc_pt==3){Run3_pt=3;}
        if(rpc_pt==4){Run3_pt=4;}
        if(rpc_pt==5){Run3_pt=5;}
        if(rpc_pt==6){Run3_pt=6;}
        if(Run3_pt>6){continue;}

        float rpc_eta = (*muctpi_eta)[j];
        float rpc_phi = (*muctpi_phi)[j];

        float delta_eta;
        float delta_phi;
        float RPC_dR;
        delta_eta=(extEta-rpc_eta);
        delta_phi=TVector2::Phi_mpi_pi(extPhi-rpc_phi);
        RPC_dR=sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
        if(RPC_dR<dR){
            dR=RPC_dR;
            pT=Run3_pt;
        }
    }
    h_dr->Fill(offline_pt, dR);

    if(dR<=0.1){return pT;}
    else{return 0;}
}
