#include "../include/TurnoncurvE.h"
#include "/home/shiomi/RootUtils/RootUtils/TLegend_addfunc.h"
#include "/home/shiomi/RootUtils/RootUtils/TCanvas_opt.h"
#include "TStyle.h"
#include "TF1.h"
#include "TEfficiency.h"
#include "TLegend.h"

using namespace std;

void TurnoncurvE::DrawHist(TString pdf)
{
    TCanvas_opt *c1 = new TCanvas_opt();
    gStyle->SetOptStat(0);
    //c1->SetGrid();
    c1->SetTopMargin(0.20);
    c1->Print(pdf + "[", "pdf");

    tgc_dr->Draw("colz");
    c1->Print(pdf,"pdf");

    rpc_dr->Draw("colz");
    c1->Print(pdf,"pdf");

    tgc_turn->Divide(h_tgc,tgc_offline,1,1); 
    rpc_turn->Divide(h_rpc,rpc_offline,1,1);

    TF1 *TGC_erf = new TF1("TGC_erf","[0]+0.5*[1]*(1+TMath::Erf((x-[2])/(TMath::Sqrt(x)*[3])))",0,40);
    TGC_erf->SetParameter(0,0);  //offset
    TGC_erf->SetParameter(1,1);  //plateau
    TGC_erf->SetParameter(2,12); //halfpoint
    TGC_erf->SetParameter(3,1);  //slope

    tgc_turn->Draw("LP"); 
    tgc_turn->SetMarkerColor(50);
    tgc_turn->SetMarkerStyle(8);
    tgc_turn->SetLineColor(50);
    tgc_turn->SetLineWidth(1);
    tgc_turn->SetLineStyle(7);
    tgc_turn->Fit("TGC_erf","","",0,40);
    c1->Print(pdf,"pdf");

    TF1 *RPC_erf = new TF1("RPC_erf","[0]+0.5*[1]*(1+TMath::Erf((x-[2])/(TMath::Sqrt(x)*[3])))",0,40);
    RPC_erf->SetParameter(0,0);
    RPC_erf->SetParameter(1,1);
    RPC_erf->SetParameter(2,13);
    RPC_erf->SetParameter(3,1);

    rpc_turn->Draw("LP"); 
    rpc_turn->SetMarkerColor(50);
    rpc_turn->SetMarkerStyle(8);
    rpc_turn->SetLineColor(50);
    rpc_turn->SetLineWidth(1);
    rpc_turn->SetLineStyle(7);
    rpc_turn->Fit("RPC_erf","","",0,40);
    c1->Print(pdf,"pdf");

    c1 -> Print( pdf + "]", "pdf" );
    delete c1;
}
