#include "../include/TurnoncurvE.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TurnoncurvE::FillHist()
{
    //Offline Start
    for(int i=0;i!=muon_n;i++){
        if(muon_author->at(i)!=1 || muon_Type->at(i)!=0)continue;
        float offline_pt=muon_pt->at(i);
        float offline_eta =muon_eta->at(i);
        float offline_phi =muon_phi->at(i);
        if(!Offline(i, ext_mu_size->at(i)))continue;

        int TGCpT = 0;
        bool isTGC = false;
        if(extTGC){
            tgc_offline->Fill(offline_pt/1000);
            TGCpT = TGC_Run3(offline_pt/1000);
            //pT = TGC_Run2(offline_pt/1000);
            if(TGCpT>0){isTGC = true;}
        }

        int RPCpT = 0;
        bool isRPC = false;
        if(extRPC){
            rpc_offline->Fill(offline_pt/1000);
            RPCpT = RPC_Run3(offline_pt/1000);
            //pT = RPC_Run2(offline_pt/1000);
            if(RPCpT>0){isRPC = true;}
        }

        if(isTGC && (TGCpT>=11&&TGCpT<=15)){h_tgc->Fill(offline_pt/1000);}
        if(isRPC && RPCpT==6){h_rpc->Fill(offline_pt/1000);}
    }
}
