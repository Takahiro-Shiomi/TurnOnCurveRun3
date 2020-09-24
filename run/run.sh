#!/bin/sh
rm TurnoncurvE.out
cp ../build/test/TurnoncurvE.out .

PDF_LABEL="TurnOnCurve_15thre_SingleMuon_FH_Run3"
#PDF_LABEL="TurnOnCurve_15thre_Fit_etacut_PP_0714"

#INPUT_NTUPLE="/gpfs/fs7001/shiomi/ATLAS/Residual/Ntuple/L1TGCNtupleRun3/run/CW_MC_BE_Thre_SingleMuon_inEXTBarrel_Run3_0618forPublicPlot_Histgram.root"
INPUT_NTUPLE="/gpfs/fs7001/shiomi/ATLAS/Residual/Ntuple/L1TGCNtupleRun3/run/CW_MC_BE_Thre_SingleMuon_inEXTBarrel_Run3_0624forPublicPlot_Histgram.root"

#LIMIT_ENTRY=200
LIMIT_ENTRY=-1
#TRIG_CHAIN=0

echo ""
echo "PDF_LABEL: "${PDF_LABEL}
echo "INPUT_NTUPLE: "${INPUT_NTUPLE}
echo ""

COMMAND="./TurnoncurvE.out ${PDF_LABEL} ${INPUT_NTUPLE} ${LIMIT_ENTRY}"

eval ${COMMAND} 2>&1

#eof
