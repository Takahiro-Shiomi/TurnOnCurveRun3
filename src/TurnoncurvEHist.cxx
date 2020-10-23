#include "../include/TurnoncurvE.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TROOT.h"
#include "TFile.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TTree.h"
#include "TChain.h"
#include "TMath.h"
#include "TString.h"
#include "TColor.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TText.h"
#include "TLatex.h"
#include "TGraphErrors.h"
#include "TApplication.h"
#include <vector>
#include <iostream>
#include "TH2Poly.h"
#include "TMultiGraph.h"
#include "TKey.h"
#include "TObject.h"

using namespace std;

void TurnoncurvE::InitHist(){
    h_dr = new TH2D("h_dr","",100,0,40,100,0,0.5);
    h_offline = new TH1D("h_offline","",40,0,40);
    for(int i=0;i!=6;i++){
        h_turn[i]=new TH1D(Form("h_turn%d",i),"",40,0,40);
        h_turn[i]->SetXTitle("p^{offline}_{T} [GeV]");
        h_turn[i]->SetYTitle("Efficiency");
        h_rpc[i]=new TH1D(Form("h_rpc%d",i),"",40,0,40);
    }
}

void TurnoncurvE::EndHist(){
    if(h_dr!=0){delete h_dr;}
    if(h_offline!=0){delete h_offline;}
    for(int i=0;i<6;i++){
        if(h_turn[i]!=0){delete h_turn[i];}
        if(h_rpc[i]!=0){delete h_rpc[i];}
    }
}

