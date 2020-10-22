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
    tgc_dr = new TH2D("tgc_dr","",100,0,40,100,0,0.1);
    tgc_offline = new TH1D("tgc_offline","",40,0,40);
    tgc_turn=new TH1D("tgc_turn","",40,0,40);
    tgc_turn->SetXTitle("p^{offline}_{T} [GeV]");
    tgc_turn->SetYTitle("Efficiency");
    h_tgc=new TH1D("h_tgc","",40,0,40);

    rpc_dr = new TH2D("rpc_dr","",100,0,40,100,0,0.5);
    rpc_offline = new TH1D("rpc_offline","",40,0,40);
    rpc_turn=new TH1D("rpc_turn","",40,0,40);
    rpc_turn->SetXTitle("p^{offline}_{T} [GeV]");
    rpc_turn->SetYTitle("Efficiency");
    h_rpc=new TH1D("h_rpc","",40,0,40);
}

void TurnoncurvE::EndHist(){
    if(tgc_dr!=0){delete tgc_dr;}
    if(rpc_dr!=0){delete rpc_dr;}
    if(tgc_offline!=0){delete tgc_offline;}
    if(rpc_offline!=0){delete rpc_offline;}
    if(tgc_turn!=0){delete tgc_turn;}
    if(h_tgc!=0){delete h_tgc;}
    if(rpc_turn!=0){delete rpc_turn;}
    if(h_rpc!=0){delete h_rpc;}
}

