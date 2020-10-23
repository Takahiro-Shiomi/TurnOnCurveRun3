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

    h_dr->Draw("colz");
    c1->Print(pdf,"pdf");

    c1->Clear();
    c1->Divide(3,2);
    for(int i=0;i!=6;i++){
        c1->cd(i+1);
        h_offline->Draw();
        h_offline->SetFillColor(kGreen);
        h_rpc[i]->Draw("same");
        h_rpc[i]->SetFillColor(kYellow);
        //h_offline->GetXaxis()->SetRangeUser(0,15);
    }
    c1->Print(pdf,"pdf");
    c1->Clear();

    int color[6];
    for(int j=0;j<6;j++){
        h_turn[j]->Divide(h_rpc[j],h_offline,1,1);
        color[j]=9-j;
    }
    h_turn[0]->Draw("LP");
    h_turn[0]->SetMarkerColor(9);
    h_turn[0]->SetMarkerStyle(8);
    h_turn[0]->SetLineColor(9);
    h_turn[0]->SetLineWidth(1);
    h_turn[0]->SetLineStyle(7);
    //h_turn[0]->Write();
    for(int i=1;i!=6;i++){
        h_turn[i]->Draw("LP same");
        h_turn[i]->SetMarkerColor(color[i]);
        h_turn[i]->SetMarkerStyle(8);
        h_turn[i]->SetLineColor(color[i]);
        h_turn[i]->SetLineWidth(1);
        h_turn[i]->SetLineStyle(7);
        //h_turn[i]->Write();
    }
    c1->Print(pdf,"pdf");

    c1 -> Print( pdf + "]", "pdf" );
    delete c1;
}
