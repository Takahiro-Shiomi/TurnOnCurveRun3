#include "../include/TurnoncurvE.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include "TH1F.h"
#include "TF1.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TROOT.h"
#include "TFile.h"
#include "THStack.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TTree.h"
#include "TChain.h"
#include "TMath.h"
#include "TString.h"
#include "TProfile.h"
#include "TColor.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TPaveText.h"
#include "TText.h"
#include "TLatex.h"
#include "TGraphErrors.h"
#include "TApplication.h"
#include "TVector3.h"
#include "TVector2.h"
#include "TH1.h"

using namespace std;

Bool_t TurnoncurvE::Offline(int i, int j)
{
    extEta=-100;
    extPhi=-100;

    bool Flag=false;
    float eta = 0;
    float phi = 0;
    int can = 0;
    if(ext_mu_type->at(i)==1){
        for(int ext=0;ext<j;ext++){
            int extTarget=ext_mu_targetVec->at(i).at(ext);
            float extDistance=ext_mu_targetDistanceVec->at(i).at(ext);

            if(extTarget!=2)continue;
            if(abs(extDistance)<6500||abs(extDistance)>10500)continue;

            float exteta=ext_mu_targetEtaVec->at(i).at(ext);
            float extphi=ext_mu_targetPhiVec->at(i).at(ext);

            //if(abs(exteta)>=1.06)continue;
            //if(abs(extphi)>(TMath::Pi()))continue;

            eta=eta+exteta;
            phi=phi+extphi;
            can=can+1;
        }
    }
    if(can>=1){
        extEta=eta/(float)can;
        extPhi=phi/(float)can;
        if(abs(extEta)<1.06 && abs(extPhi)<=TMath::Pi()){Flag=true;}
    }
    return Flag;
}


