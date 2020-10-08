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

    h_dr_2d->Draw("colz");
    c1->Print(pdf,"pdf");

    c1->Clear();
    c1->Divide(3,3);
    for(int i=0;i!=15;i++){
        int Num=(i+1)%9;
        if(Num==0){Num=9;}
        c1->cd(Num);
        h_offline->Draw();
        h_offline->SetFillColor(kGreen);
        h_tgc[i]->Draw("same");
        h_tgc[i]->SetFillColor(kYellow);
        h_offline->GetXaxis()->SetRangeUser(0,15);
        if(Num==9 || i==14){
            c1->Print(pdf,"pdf");
            c1->Clear();
            c1->Divide(3,3);
        }
    }
    c1->Clear();

    int color[15];
    for(int j=0;j<15;j++){
        h_turn[j]->Divide(h_tgc[j],h_offline,1,1);
        color[j]=49-j;
    }
    h_turn[0]->Draw("LP");
    h_turn[0]->SetMarkerColor(50);
    h_turn[0]->SetMarkerStyle(8);
    h_turn[0]->SetLineColor(50);
    h_turn[0]->SetLineWidth(1);
    h_turn[0]->SetLineStyle(7);
    //h_turn[0]->Write();
    for(int i=1;i!=15;i++){
        h_turn[i]->Draw("LP same");
        h_turn[i]->SetMarkerColor(color[i]);
        h_turn[i]->SetMarkerStyle(8);
        h_turn[i]->SetLineColor(color[i]);
        h_turn[i]->SetLineWidth(1);
        h_turn[i]->SetLineStyle(7);
        //h_turn[i]->Write();
    }
    c1->Print(pdf,"pdf");
/*
    TEfficiency *pEff[15];
    if(TEfficiency::CheckConsistency(*h_tgc[0], *h_offline)){
        pEff[0] = new TEfficiency(*h_tgc[0], *h_offline);
        pEff[0]->Draw("ALP");
        pEff[0]->SetTitle(";p^{offline}_{T} [GeV];Efficiency");
        pEff[0]->SetMarkerColor(color[0]);
        pEff[0]->SetMarkerStyle(8);
        pEff[0]->SetLineColor(color[0]);
        pEff[0]->SetLineWidth(1);
        pEff[0]->SetLineStyle(7);
        pEff[0]->Write();
    }
    for(int i=1;i!=15;i++){
        if(TEfficiency::CheckConsistency(*h_tgc[i], *h_offline)){
            pEff[i] = new TEfficiency(*h_tgc[i], *h_offline);
            pEff[i]->Draw("LP same");
            pEff[i]->SetMarkerColor(color[i]);
            pEff[i]->SetMarkerStyle(8);
            pEff[i]->SetLineColor(color[i]);
            pEff[i]->SetLineWidth(1);
            pEff[i]->SetLineStyle(7);
            pEff[i]->Write();
        }
    }
    c1->Print(pdf,"pdf");
    c1->Clear();
    */

    c1 -> Print( pdf + "]", "pdf" );
    delete c1;
}
