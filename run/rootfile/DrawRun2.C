#include "/home/shiomi/RootUtils/RootUtils/TLegend_addfunc.h"
#include "/home/shiomi/RootUtils/RootUtils/TCanvas_opt.h"
#include "TStyle.h"
#include "TF1.h"
#include "TLegend.h"
#include "TMath.h"
#include "/home/shiomi/RootUtils/AtlasUtils.C"

using namespace std;

void datasetText()
{
  //myText(0.2, 0.83, 1, "Single #mu, 1.05<|#eta^{offline}|<2.4 (TGC), 3-station coincidence w/ hot RoI mask");
  //myText(0.2, 0.83, 1, "Single #mu, 1.05<|#eta^{offline}|<2.4 (TGC), 3-station coincidence");
  myText(0.2, 0.82, 1, "Single #mu, 1.05<|#eta^{offline}|<2.4 (TGC)");
  //myText(0.2, 0.83, 1, "Single #mu, 1.05<|#eta^{offline}|<2.4 (TGC), 2-station coincidence, p_{T} threshold=3 GeV");
}
void datasetText1()
{
  myText(0.2, 0.83, 1, "The TGC performance");
}

void DrawRun2()
{

    TFile *file = new TFile("TurnOnCurve_15thre_SingleMuon_Run3_NewCWCleaner1.root", "read");
    TH1D *h_tgc[15];
    TH1D *h_offline;
    h_offline= (TH1D*)file->Get("h_offline");
    for(int i=0;i!=15;i++){h_tgc[i]= (TH1D*)file->Get(Form("h_tgc%d",i));}
    //Histgram
    TH1D *pEff[15];
    for(int i=0;i!=15;i++){
        pEff[i] = new TH1D(Form("pEff%d",i),"",40,0,40);
        pEff[i]->Divide(h_tgc[i],h_offline,1,1);
    }
    
    TFile *file0 = new TFile("TurnOnCurve_15thre_SingleMuon_Run3_NewCWCleaner2.root", "read");
    TH1D *h_tgc0[15];
    TH1D *h_offline0;
    h_offline0= (TH1D*)file0->Get("h_offline");
    for(int i=0;i!=15;i++){h_tgc0[i]= (TH1D*)file0->Get(Form("h_tgc%d",i));}
    //Histgram
    TH1D *pEff0[15];
    for(int i=0;i!=15;i++){
        pEff0[i] = new TH1D(Form("pEff1%d",i),"",40,0,40);
        pEff0[i]->Divide(h_tgc0[i],h_offline0,1,1);
    }
    
    TFile *file1 = new TFile("TurnOnCurve_15thre_SingleMuon_Run3_NewCW.root", "read");
    TH1D *h_tgc1[15];
    TH1D *h_offline1;
    h_offline1= (TH1D*)file1->Get("h_offline");
    for(int i=0;i!=15;i++){h_tgc1[i]= (TH1D*)file1->Get(Form("h_tgc%d",i));}
    //Histgram
    TH1D *pEff1[15];
    for(int i=0;i!=15;i++){
        pEff1[i] = new TH1D(Form("pEff1%d",i),"",40,0,40);
        pEff1[i]->Divide(h_tgc1[i],h_offline1,1,1);
    }
    
    TFile *file2 = new TFile("TurnOnCurve_15thre_SingleMuon_Run3_NewCWCleaner4.root", "read");
    TH1D *h_tgc2[15];
    TH1D *h_offline2;
    h_offline2= (TH1D*)file2->Get("h_offline");
    for(int i=0;i!=15;i++){h_tgc2[i]= (TH1D*)file2->Get(Form("h_tgc%d",i));}
    //Histgram
    TH1D *pEff2[15];
    for(int i=0;i!=15;i++){
        pEff2[i] = new TH1D(Form("pEff2%d",i),"",40,0,40);
        pEff2[i]->Divide(h_tgc2[i],h_offline2,1,1);
    }
    
    TFile *file3 = new TFile("TurnOnCurve_15thre_SingleMuon_Run3_NewCWCleaner5.root", "read");
    TH1D *h_tgc3[15];
    TH1D *h_offline3;
    h_offline3= (TH1D*)file3->Get("h_offline");
    for(int i=0;i!=15;i++){h_tgc3[i]= (TH1D*)file3->Get(Form("h_tgc%d",i));}
    //Histgram
    TH1D *pEff3[15];
    for(int i=0;i!=15;i++){
        pEff3[i] = new TH1D(Form("pEff3%d",i),"",40,0,40);
        pEff3[i]->Divide(h_tgc3[i],h_offline3,1,1);
    }
    
    TF1 *erf[5];
    for(int i=0;i!=5;i++){
        erf[i] = new TF1(Form("erf%d",i),"[0]+0.5*[1]*(1+TMath::Erf((x-[2])/(TMath::Sqrt(x)*[3])))",0,40);
        erf[i]->SetParameter(0,0);
        erf[i]->SetParameter(1,1);
        erf[i]->SetParameter(2,7);
        erf[i]->SetParameter(3,1);
    }
    erf[0]->SetLineColor(kPink);
    erf[1]->SetLineColor(kOrange+1);
    erf[2]->SetLineColor(kGreen+1);
    erf[3]->SetLineColor(kBlue+1);
    erf[4]->SetLineColor(kMagenta);

    TCanvas *c2 = new TCanvas("c2","c2",1200,800);
    pEff[5]->Draw("P");
    pEff[5]->SetTitle(";p^{offline}_{T} [GeV];Efficiency");
    pEff[5]->SetMarkerColor(kPink);
    pEff[5]->SetLineColor(kPink);
    pEff[5]->SetLineWidth(1);
    pEff[5]->SetLineStyle(7);
    pEff[5]->GetYaxis()->SetRangeUser(0,1.2);
    pEff[5]->Fit(Form("erf%d",0),"","",0,40);

    pEff0[5]->Draw("P same");
    pEff0[5]->SetMarkerColor(kOrange+1);
    pEff0[5]->SetLineColor(kOrange+1);
    pEff0[5]->SetLineWidth(1);
    pEff0[5]->SetLineStyle(7);
    pEff0[5]->Fit(Form("erf%d",1),"","",0,40);

    pEff1[5]->Draw("P same");
    pEff1[5]->SetMarkerColor(kGreen+1);
    pEff1[5]->SetLineColor(kGreen+1);
    pEff1[5]->SetLineWidth(1);
    pEff1[5]->SetLineStyle(7);
    pEff1[5]->Fit(Form("erf%d",2),"","",0,40);

    pEff2[5]->Draw("P same");
    pEff2[5]->SetMarkerColor(kBlue+1);
    pEff2[5]->SetLineColor(kBlue+1);
    pEff2[5]->SetLineWidth(1);
    pEff2[5]->SetLineStyle(7);
    pEff2[5]->Fit(Form("erf%d",3),"","",0,40);

    pEff3[5]->Draw("P same");
    pEff3[5]->SetMarkerColor(kMagenta);
    pEff3[5]->SetLineColor(kMagenta);
    pEff3[5]->SetLineWidth(1);
    pEff3[5]->SetLineStyle(7);
    pEff3[5]->Fit(Form("erf%d",4),"","",0,40);

    TLegend* legend =new TLegend(0.65,0.50,0.90,0.30);
    legend->SetHeader("   p_{T} Threshold");
    legend->AddEntry(pEff[5],"MU8FH(Cleaner1)","LP");
    legend->AddEntry(pEff0[5],"MU8FH(Cleaner2)","LP");
    legend->AddEntry(pEff1[5],"MU8FH(Cleaner3)","LP");
    legend->AddEntry(pEff2[5],"MU8FH(Cleaner4)","LP");
    legend->AddEntry(pEff3[5],"MU8FH(Cleaner5)","LP");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->Draw("same L");

    c2->Print("./../pdf/turnoncurve_15thre_TGC_Cleaner_MU8.png");
    
    
    
}

