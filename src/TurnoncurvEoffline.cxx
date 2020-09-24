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

    float Z=9999;
    bool Flag=false;
    if(ext_mu_type->at(i)==1){
        for(int ext=0;ext<j;ext++){
            int extTarget=ext_mu_targetVec->at(i).at(ext);
            float extDistance=ext_mu_targetDistanceVec->at(i).at(ext);

            if(extTarget!=1)continue;
            if(abs(extDistance)<15000 || abs(extDistance)>15300)continue;

            float exteta=ext_mu_targetEtaVec->at(i).at(ext);
            float extphi=ext_mu_targetPhiVec->at(i).at(ext);

            //if(abs(exteta)<=1.05)continue;
            //if(abs(exteta)>=2.4)continue;
            if(abs(extphi)>(TMath::Pi()))continue;
            if(abs(15280-abs(extDistance))<Z){
                Z=abs(15280-abs(extDistance));
                extEta=exteta;
                extPhi=extphi;
                Flag=true;
            }
        }
    }
    return Flag;
}


