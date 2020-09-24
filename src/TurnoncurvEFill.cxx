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
        if(abs(offline_eta)<=1.05){continue;}
        if(abs(offline_eta)>=2.4){continue;}
        if(Offline(i, ext_mu_size->at(i))==false)continue;
        h_offline->Fill(offline_pt/1000);

        //TGC Run-3 Start
        int pT = TGC_Run3(offline_pt/1000);
        //int pT = TGC_Run2(offline_pt/1000);
        //TGC_Run3 End
        if(pT>=1&&pT<=15){
            for(int j=1;j<16;j++){
                if(pT>=j){
                    h_tgc[j-1]->Fill(offline_pt/1000);
                }
            }
        }
    }
}
