#include "../include/TurnoncurvE.h"
#include "/home/shiomi/RootUtils/src/rootlogon.C"
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include "TString.h"
#include "TFile.h"
#include "TChain.h"
#include "TTree.h"

int main(int argc, char *argv[])
{
    rootlogon();

    std::cout<<"<<Run START>>"<<std::endl;
    TChain *tree1 = new TChain("physics", "physics");

    TString PdfLabel = argv[1];
    tree1->Add(argv[2]);
    Int_t limit_entry = atoi(argv[3]);

    TFile *fout = new TFile(Form("./rootfile/%s.root", PdfLabel.Data()), "recreate");

    TurnoncurvE tls(tree1);
    std::cout<<"<<Loop START>>"<<std::endl;
    tls.Loop(limit_entry);
    std::cout<<"<<Draw START>>"<<std::endl;
    tls.DrawHist("./pdf/Draw_" + PdfLabel + ".pdf");
    fout -> Write();
    std::cout<<"<<Run END>>"<<std::endl;
    tls.EndHist();

    return 0;
}
