#define TurnoncurvE_cxx
#include "../include/TurnoncurvE.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TurnoncurvE::Loop(int Nevents)
{
   if (fChain == 0) return;


   int nLoop = (Nevents == -1) ? fChain->GetEntries() : Nevents;
   //Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nLoop;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if((int)jentry % ((int)nLoop/10)==0){
          std::cout<<"JOBS....."<<(int)jentry / ((int)nLoop/100)<<"%....COMPLETE"<<std::endl;
      }
      FillHist();
   }
}
